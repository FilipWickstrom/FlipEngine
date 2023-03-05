#include "EnginePCH.h"
#ifdef FLIP_D3D11
#include "D3D11Graphics.h"

D3D11Graphics::D3D11Graphics(GLFWwindow* windowHandle)
	:m_WindowHandle(windowHandle)
{
}

bool D3D11Graphics::Init()
{

	return true;
}

void D3D11Graphics::ClearScreen(glm::vec4 color)
{
}

void D3D11Graphics::SwapBuffers()
{
}

void D3D11Graphics::Draw()
{
}

#endif