#pragma once
#include "EnginePCH.h"

class Renderer
{
public:
	Renderer();
	~Renderer();

	Renderer(const Renderer&) = delete;
	Renderer& operator=(const Renderer&) = delete;

private:
	ID3D11Device*			m_device;
	ID3D11DeviceContext*	m_deviceContext;
	IDXGISwapChain*			m_swapChain;
	ID3D11RenderTargetView* m_mainRenderTarget;

};