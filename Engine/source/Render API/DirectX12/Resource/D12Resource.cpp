#include "pch.h"
#include "D12Resource.h"

namespace Engine {
	D12Resource::~D12Resource()
	{
		Release();
	}

	void Engine::D12Resource::Initialize(ID3D12Device* pDevice, const unsigned int numBytes, D3D12_HEAP_TYPE heapType, D3D12_RESOURCE_STATES initialState)
	{
		// set heap properties
		D3D12_HEAP_PROPERTIES heapProp = {};
		heapProp.Type = heapType;
		heapProp.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
		heapProp.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;
		heapProp.CreationNodeMask = 0; // no use of Dual GPUs
		heapProp.VisibleNodeMask = 0; // no use of Dual GPUs

		// create Resource description
		D3D12_RESOURCE_DESC resourceDesc = {}; // https://learn.microsoft.com/en-us/windows/win32/api/d3d12/ns-d3d12-d3d12_resource_desc
		resourceDesc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER; // https://learn.microsoft.com/en-us/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_dimension
		resourceDesc.Alignment = 0;
		resourceDesc.Width = numBytes;
		resourceDesc.Height = 1;
		resourceDesc.DepthOrArraySize = 1;
		resourceDesc.MipLevels = 1;
		resourceDesc.Format = DXGI_FORMAT_UNKNOWN; // https://learn.microsoft.com/en-us/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format
		resourceDesc.SampleDesc = { 1, 0 }; // Sampling Count: 1, Sampling Quality: 0
		resourceDesc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
		resourceDesc.Flags = D3D12_RESOURCE_FLAG_NONE;

		YT_EVAL_HR(pDevice->CreateCommittedResource(&heapProp, D3D12_HEAP_FLAG_NONE, &resourceDesc, initialState, 0, IID_PPV_ARGS(GetAddressOf())), "Error creating a resource");
	}

	void D12Resource::Release()
	{
		if (Get()) {
			Reset();
		}
	} 
}