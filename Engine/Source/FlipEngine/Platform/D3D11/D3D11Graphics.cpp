#include "EnginePCH.h"
#ifdef FLIP_D3D11
#include "D3D11Graphics.h"

D3D11Graphics::D3D11Graphics(GLFWwindow* windowHandle)
	:m_WindowHandle(windowHandle)
{
}

bool D3D11Graphics::Init()
{
	/*
		Create a DXGI factory
	*/
	HRESULT result = CreateDXGIFactory1(IID_PPV_ARGS(&m_DXGIFactory));
	if (FAILED(result))
	{
		LOG_ENGINE_FATAL("Failed to create DXGIFactory...");
		return false;
	}


	constexpr D3D_FEATURE_LEVEL deviceFeatureLevel = D3D_FEATURE_LEVEL::D3D_FEATURE_LEVEL_11_1; 

	/*
		Creating the device and device context
	*/
	result = D3D11CreateDevice(
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


	/*
		Creating the swapchain
	*/
	DXGI_SWAP_CHAIN_DESC1 swapChainDesc = {};
	int width;
	int height;
	glfwGetWindowSize(m_WindowHandle, &width, &height);
	swapChainDesc.Width					= width;
	swapChainDesc.Height				= height;
	swapChainDesc.Format				= DXGI_FORMAT::DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.SampleDesc.Count		= 1;
	swapChainDesc.SampleDesc.Quality	= 0;
	swapChainDesc.BufferUsage			= DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.BufferCount			= 2;
	swapChainDesc.SwapEffect			= DXGI_SWAP_EFFECT::DXGI_SWAP_EFFECT_FLIP_DISCARD;
	swapChainDesc.Scaling				= DXGI_SCALING::DXGI_SCALING_STRETCH;
	swapChainDesc.Flags					= {};

	DXGI_SWAP_CHAIN_FULLSCREEN_DESC swapChainFullDesc = {};
	swapChainFullDesc.Windowed = true;

	result = m_DXGIFactory->CreateSwapChainForHwnd(
		m_Device.Get(),
		glfwGetWin32Window(m_WindowHandle),
		&swapChainDesc,
		&swapChainFullDesc,
		nullptr,
		&m_SwapChain
	);

	if (FAILED(result))
	{
		LOG_ENGINE_FATAL("D3D11: Failed to create swapchain...");
		return false;
	}

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