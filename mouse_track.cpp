#include <Windows.h>
#include <iostream>
// Callback function to handle mouse movement events

LRESULT CALLBACK MouseHookProc(int nCode, WPARAM wParam, LPARAM lParam) {
    // Check if the message is a mouse click event
    if (nCode < HC_ACTION) 
        return CallNextHookEx(NULL, nCode, wParam, lParam);

    std::string eventType = "";

    if (wParam == WM_MOUSEMOVE || wParam == WM_LBUTTONDOWN || 
        wParam == WM_RBUTTONDOWN || wParam == WM_MBUTTONDOWN) {
        // Extract the mouse coordinates from the LPARAM
        POINT cursorPos;
        GetCursorPos(&cursorPos);

        // Print the mouse coordinates to the console
        switch (wParam)
        {
        case WM_MOUSEMOVE: 
            eventType = "move";
            break;
        case WM_LBUTTONDOWN: 
            eventType = "lclick";
            break;
        case WM_RBUTTONDOWN: 
            eventType = "rclick";
            break;
        case WM_MBUTTONDOWN: 
            eventType = "mclick";
            break;
        }

        std::cout << eventType << " at (" 
            << cursorPos.x << ", " 
            << cursorPos.y << ")\n";
    }
    else if (wParam == WM_MOUSEWHEEL || wParam == WM_MOUSEHWHEEL) {
        eventType = "wheel";

        switch (wParam)
        {
        case WM_MOUSEWHEEL:
            eventType = "vwheel";
            break;
        case WM_MOUSEHWHEEL:
            eventType = "hwheel";
            break;
        }
        
        MSLLHOOKSTRUCT* pMhs = (MSLLHOOKSTRUCT*)lParam;
        short zDelta = HIWORD(pMhs->mouseData);

        int scrollAmount = GET_WHEEL_DELTA_WPARAM(wParam);
        if (scrollAmount != 0)
            std::cout << eventType << " " << scrollAmount << " units\n";

        // Convert the scroll amount to lines or pages depending on the scroll bar orientation
        // int scrollLines = scrollAmount / WHEEL_DELTA;
        // int scrollPages = scrollAmount / (WHEEL_DELTA * 3);

        // Print out the scroll distance
        std::cout << eventType << " " << zDelta << " units\n";
    }

    // Call the next hook in the chain
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

int main() {
    HHOOK mouseHook = SetWindowsHookEx(WH_MOUSE_LL, MouseHookProc, NULL, 0);

    // Loop to keep the program running
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // Uninstall the mouse hook
    UnhookWindowsHookEx(mouseHook);

    // Move the mouse
    SetCursorPos(0,0);

    // Right click
    mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);

    // Left click
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);


    // Double click = left click x 2
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);    
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

    return 0;
}
