#pragma once
#include <glm/vec4.hpp>

class Renderer
{
public:
	virtual bool Init() = 0;
	virtual void ClearScreen(glm::vec4 color) = 0;
	virtual void SwapBuffers() = 0;
	virtual void Draw() = 0;
};