#pragma once
#include "FlipEngine/Renderer/Renderer.h"

struct GLFWwindow;

class D3D11Graphics : public Renderer
{
public:
	D3D11Graphics(GLFWwindow* windowHandle);
	~D3D11Graphics() = default;

	virtual bool Init() override;
	virtual void ClearScreen(glm::vec4 color) override;
	virtual void SwapBuffers() override;
	virtual void Draw() override;

private:
	//bool Create

private:
	GLFWwindow*						m_WindowHandle;

	ComPtr<ID3D11Device>			m_Device;
	ComPtr<ID3D11DeviceContext>		m_DeviceContext;
	ComPtr<IDXGISwapChain1>			m_SwapChain;
	ComPtr<ID3D11RenderTargetView>	m_MainRenderTarget;
	ComPtr<IDXGIFactory2>			m_DXGIFactory;
	

};