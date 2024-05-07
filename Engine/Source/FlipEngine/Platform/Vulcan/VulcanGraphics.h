#pragma once
#include "FlipEngine/Renderer/Renderer.h"

struct GLFWwindow;

class VulcanGraphics : public Renderer
{
public:
	VulcanGraphics(GLFWwindow* windowHandle);
	~VulcanGraphics() = default;

	virtual bool Init() override;
	virtual void ClearScreen(glm::vec4 color) override;
	virtual void SwapBuffers() override;
	virtual void Draw() override;

private:
	GLFWwindow* m_WindowHandle;


};