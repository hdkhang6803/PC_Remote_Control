#include "libwebp-1.3.0-windows-x64/include/webp/encode.h"
#include "libwebp-1.3.0-windows-x64/include/webp/decode.h"
#include "screenshot_process.h"

#define SCREENSHOT_PORT 5000



//SERVER FUNCTIONS
vector<uint8_t> capture_screenshot(){
    
    int nScreenWidth = GetSystemMetrics(SM_CXSCREEN);
    int nScreenHeight = GetSystemMetrics(SM_CYSCREEN);
    HWND hDesktopWnd = GetDesktopWindow();
    HDC hDesktopDC = GetDC(hDesktopWnd);
    // Create a compatible memory device context to store the screenshot
    HDC hMemoryDC = CreateCompatibleDC(hDesktopDC);
    // Create a compatible bitmap to store the screenshot
    HBITMAP hBitmap = CreateCompatibleBitmap(hDesktopDC, nScreenWidth, nScreenHeight);
    // Select the bitmap into the memory device context
    HGDIOBJ hOldObject = SelectObject(hMemoryDC, hBitmap);
    // Copy the screen contents into the memory device context
    BitBlt(hMemoryDC, 0, 0, nScreenWidth, nScreenHeight, hDesktopDC, 0, 0, SRCCOPY|CAPTUREBLT);

    // Convert the bitmap to vector of bytes
    CImage image;
    image.Attach(hBitmap);
    IStream* pStream = NULL;
    HRESULT hr = CreateStreamOnHGlobal(NULL, TRUE, &pStream);
    image.Save(pStream, Gdiplus::ImageFormatJPEG);
    STATSTG statstg = {};
    pStream->Stat(&statstg, STATFLAG_NONAME);
    std::vector<uint8_t> buffer(statstg.cbSize.LowPart);
    LARGE_INTEGER seek = {};
    seek.QuadPart = 0;
    pStream->Seek(seek, STREAM_SEEK_SET, NULL);
    pStream->Read(buffer.data(), buffer.size(), NULL);
    pStream->Release();

    // Release the screen device context
    ReleaseDC(hDesktopWnd, hDesktopDC);
    DeleteDC(hMemoryDC);
    DeleteObject(hBitmap);

    //return image;
    return buffer;
}

HRESULT VectorToStream(const std::vector<uint8_t>& buffer, IStream** ppStream)
{
    // Create an IStream object that uses a global memory block as its backing store
    HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, buffer.size());
    if (!hGlobal)
        return E_OUTOFMEMORY;

    LPVOID pvData = GlobalLock(hGlobal);
    if (!pvData)
    {
        GlobalFree(hGlobal);
        return E_OUTOFMEMORY;
    }

    memcpy(pvData, buffer.data(), buffer.size());

    GlobalUnlock(hGlobal);

    if (FAILED(CreateStreamOnHGlobal(hGlobal, TRUE, ppStream)))
    {
        GlobalFree(hGlobal);
        return E_FAIL;
    }

    return S_OK;
}
//CLIENT FUNCTIONS
void display_jpeg_image(const vector<uint8_t>& buffer)
{
    // Load the bytes vector into a CImage object
    CImage image;
    IStream* pStream = nullptr;
    if (SUCCEEDED(VectorToStream(buffer, &pStream)))
    {
        std::cout << "converted!\n";
        image.Load(pStream);
        pStream->Release();
    }

    // Get the device context for the window
    HDC hdc = GetDC(NULL);

    // Display the image on the screen
    image.Draw(hdc, 10, 10, image.GetWidth() / 2.5, image.GetHeight() / 2.5);

    // Release the device context
    ReleaseDC(NULL, hdc);
}

void save_to_jpeg(const std::vector<uint8_t>& buffer, const std::string& filename)
{
    std::ofstream ofs(filename, std::ios::out | std::ios::binary);
    ofs.write(reinterpret_cast<const char*>(buffer.data()), buffer.size());
    ofs.close();
}

