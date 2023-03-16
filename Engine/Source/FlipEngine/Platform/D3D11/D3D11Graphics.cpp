#include "EnginePCH.h"
#ifdef FLIP_D3D11
#include "D3D11Graphics.h"

D3D11Graphics::D3D11Graphics(GLFWwindow* windowHandle)
	:m_WindowHandle(windowHandle)
{
}

bool D3D11Graphics::Init()
{

	constexpr D3D_FEATURE_LEVEL deviceFeatureLevel = D3D_FEATURE_LEVEL::D3D_FEATURE_LEVEL_11_1; 

	HRESULT result = D3D11CreateDevice(
		nullptr,
		D3D_DRIVER_TYPE::D3D_DRIVER_TYPE_HARDWARE,
		nullptr,
		0,
		&deviceFeatureLevel,
		1,
		D3D11_SDK_VERSION,
		&m_Device,
		nullptr,
		&m_DeviceContext
	);

	if (FAILED(result))
	{
		LOG_ENGINE_FATAL("D3D11: Failed to create device and device context...");
		return false;
	}

	DXGI_SWAP_CHAIN_DESC swapChainDesc = {};


	//glfwGetWindowSize()

	return true;
}

void D3D11Graphics::ClearScreen(glm::vec4 color)
{
	m_DeviceContext->ClearRenderTargetView(m_MainRenderTarget.Get(), &color[0]);
}

void D3D11Graphics::SwapBuffers()
{
}

void D3D11Graphics::Draw()
{
}

#endif