#include "EnginePCH.h"

#ifdef FLIP_OPENGL
#include "OpenGLGraphics.h"

OpenGLGraphics::OpenGLGraphics(GLFWwindow* windowHandle)
	:m_WindowHandle(windowHandle)
{
}


bool OpenGLGraphics::Init()
{
	glfwMakeContextCurrent(m_WindowHandle);

	// Something is wrong here...
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		LOG_ENGINE_FATAL("Failed to load Glad...");
		return false;
	}

	return true;
}

void OpenGLGraphics::ClearScreen(glm::vec4 color)
{
	glad_glClearColor(color.r, color.g, color.b, color.a);
	glad_glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGLGraphics::SwapBuffers()
{
	//glBegin(GL_TRIANGLES);
	
	// Add some triangles

	//glEnd();

	glfwSwapBuffers(m_WindowHandle);
}

void OpenGLGraphics::Draw()
{
}

#endif