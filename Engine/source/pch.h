#ifndef PCH_H
#define PCH_H

#include <iostream>

// DirectX headers:
#include <d3d12.h>
#include <dxgi1_6.h>
#include <dxgidebug.h>

#include <DirectXMath.h>

// compiled lib files for d12

#pragma comment (lib, "dxgi.lib") // https://learn.microsoft.com/de-de/windows/win32/direct3ddxgi/d3d10-graphics-programming-guide-dxgi
#pragma comment (lib, "D3D12.lib")
#pragma comment (lib, "dxguid.lib")

#include "EngineMin.h"
#include "Helper.h"
#include "EngineSettings.h"

#endif