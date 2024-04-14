#pragma once
#include <wrl.h>

#include "DXGIAdapter.h"

namespace Engine {
	// https://learn.microsoft.com/de-de/windows/win32/prog-dx-with-com
	// https://learn.microsoft.com/de-de/windows/win32/direct3ddxgi/d3d10-graphics-reference-dxgi-interfaces
	class DXGIFactory : public Microsoft::WRL::ComPtr<IDXGIFactory2>
	{
	public:
		DXGIFactory();

		DXGIAdapter GetAdapter();
	};
}