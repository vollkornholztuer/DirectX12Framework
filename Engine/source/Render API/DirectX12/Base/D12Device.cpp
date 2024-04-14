#include "pch.h"
#include "D12Device.h"

namespace Engine {
	D12Device::D12Device(IDXGIAdapter* pAdapter)
	{
		Init(pAdapter);
	}
	void D12Device::Init(IDXGIAdapter* pAdapter)
	{
		// DX12 Feature Levels overview: https://en.wikipedia.org/wiki/Feature_levels_in_Direct3D
		YT_EVAL_HR(D3D12CreateDevice(pAdapter, D3D_FEATURE_LEVEL_12_1, IID_PPV_ARGS(GetAddressOf())), "Error creating D12 device");

	}
}