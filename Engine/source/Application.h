#pragma once
#include "EngineMin.h"

#include <Windows.h>

#include "Render API/RenderAPI.h"



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

	private: // subsystems:
		RenderAPI mRenderer; 


	private: // variables:
		HWND mWindowHandle = nullptr;
		bool mIsRunning = false; // check if application is running

	private:
		UINT mWidth = 1280;
		UINT mHeight = 720;
	};
}