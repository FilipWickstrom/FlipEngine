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
	GLFWwindow*								m_WindowHandle;

	/*
	std::unique_ptr<ID3D11Device>			m_Device;
	std::unique_ptr<ID3D11DeviceContext>	m_DeviceContext;
	std::unique_ptr<IDXGISwapChain>			m_SwapChain;
	std::unique_ptr<ID3D11RenderTargetView> m_MainRenderTarget;
	*/

};