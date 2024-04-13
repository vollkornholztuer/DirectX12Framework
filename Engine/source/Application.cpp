#include "pch.h"
#include "Application.h"

#include <windowsx.h>
#include <iostream>

namespace Engine {

	// define Callback function
	LRESULT CALLBACK WindProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {

		switch (msg) {
		case WM_NCCREATE: {
			std::cout << "Created a window" << std::endl;
			break;
		}
		}


		// default handling of window process
		return DefWindowProc(hwnd, msg, wparam, lparam);
	}


	bool Application::Initialize()
	{
		// define window properties
		WNDCLASS wndClass = {}; // https://learn.microsoft.com/de-de/windows/win32/api/winuser/ns-winuser-wndclassexw
		wndClass.lpszClassName = L"BaseWindowClass"; // reference to CreateWindow Class
		wndClass.style = 0;
		wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
		wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		wndClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
		wndClass.lpszMenuName = 0; // for window inside a window, example: menu (but we don't need that --> 0)
		wndClass.lpfnWndProc = WindProc; // callback function to a function that handles OS-messages
		wndClass.cbClsExtra = 0; // no storing of extra information
		wndClass.cbWndExtra = 0; // -"-

		// tell Windows that "BaseWindowClass" is available
		RegisterClass(&wndClass);

		// create Windows
		mWindowHandle = CreateWindow(L"BaseWindowClass", L"YOUTUBE ENGINE WINDOW", WS_OVERLAPPEDWINDOW, 200, 200, 1280, 720, 0, 0, 0, 0); // refer back to the lParam stuff later

		// Check if pointer is not valid
		if (!mWindowHandle) {
			return false;
		}

		// actually show window
		ShowWindow(mWindowHandle, SW_SHOW);
		UpdateWindow(mWindowHandle);

		mIsRunning = true;

		return true;
	}

	void Application::Update()
	{
		
	}
}