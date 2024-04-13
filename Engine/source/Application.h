#pragma once
#include <Windows.h>

#include "EngineMin.h"


namespace Engine {

	// Application should be able to run in the background (console)
	class YT_API Application 
	{
	public:
		Application() = default;

		bool Initialize();

		void OnCreate(HWND hwnd);

		void Update();

		void OnDestroy();

		inline bool IsRunning() { return mIsRunning; }


	private:
		HWND mWindowHandle = nullptr;
		bool mIsRunning = false; // check if application is running
	};
}