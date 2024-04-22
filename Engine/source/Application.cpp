#include "pch.h"
#include "Application.h"

// #include <windowsx.h>

#include "Render API/DirectX12/Debug/DXGIDebug.h"

namespace Engine {

	// define Callback function
	LRESULT CALLBACK WindProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {

		switch (msg) {
		case WM_NCCREATE: {
			LPCREATESTRUCT param = reinterpret_cast<LPCREATESTRUCT>(lparam);
			Application* pointer = reinterpret_cast<Application*>(param->lpCreateParams);
			SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pointer));
			std::cout << "Create message sent" << std::endl;
			break;
		}
		case WM_CREATE: {
			Application* pointer = reinterpret_cast<Application*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
			pointer->OnCreate(hwnd);
			break;
		}
		case WM_DESTROY: {
			Application* pointer = reinterpret_cast<Application*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
			pointer->OnDestroy();
			PostQuitMessage(0); // quit message saying: everything is fine
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

		// create Window
		mWindowHandle = CreateWindow(L"BaseWindowClass", L"YOUTUBE ENGINE WINDOW", WS_OVERLAPPEDWINDOW, 200, 200, mWidth, mHeight, 0, 0, 0, this); // refer back to the lParam stuff later

		// Check if pointer is not valid
		if (!mWindowHandle) {
			return false;
		}

		// display window
		ShowWindow(mWindowHandle, SW_SHOW);
		UpdateWindow(mWindowHandle);

		mIsRunning = true;

		return true;
	}

	void Application::OnCreate(HWND hwnd)
	{
		std::cout << "Window created" << std::endl;
		mRenderer.Initialize(hwnd, mWidth, mHeight); // initialize Renderer API when creating window
	}

	void Application::Update()
	{
		// message handling
		MSG message;
		
		// makes window responsive to moving etc.
		while (PeekMessage(&message, 0, 0, 0, PM_REMOVE)) {
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		
		if (mIsRunning) {
			mRenderer.UpdateDraw();
		}
	}

	void Application::OnDestroy()
	{
		mIsRunning = false;
		std::cout << "Closed the window - shutting down application" << std::endl;
		
		mRenderer.Release();
		DXGIDebug::Get().GetLiveObjects();
	}
}