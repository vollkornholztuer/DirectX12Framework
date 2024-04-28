#pragma once
#include <wrl.h>

// Ressources should be possible to allocate in certain sizes

/* Creates both a resource and an implicit heap, such that the heap is big enough to contain 
the entire resource, and the resource is mapped to the heap.
https://learn.microsoft.com/en-us/windows/win32/api/d3d12/nf-d3d12-id3d12device-createcommittedresource 

This means: it creates a heap allocation on the gpu, which the resources will reside in
*/


namespace Engine {
	class D12Resource : public Microsoft::WRL::ComPtr<ID3D12Resource>
	{
	public:
		D12Resource() = default;
		~D12Resource();
		
		void Initialize(ID3D12Device* pDevice, const unsigned int numBytes, D3D12_HEAP_TYPE heapType, D3D12_RESOURCE_STATES initialState);

		void Release();
	};

}

