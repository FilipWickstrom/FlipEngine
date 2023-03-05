#pragma once
#include "FlipEngine/Renderer/Renderer.h"

struct GLFWwindow;

class OpenGLGraphics : public Renderer
{
public:
	OpenGLGraphics(GLFWwindow* windowHandle);
	~OpenGLGraphics() = default;

	virtual bool Init() override;
	virtual void ClearScreen(glm::vec4 color) override;
	virtual void SwapBuffers() override;
	virtual void Draw() override;

private:
	GLFWwindow* m_WindowHandle;

};