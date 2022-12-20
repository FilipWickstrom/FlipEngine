#include "EnginePCH.h"
#include "Window.h"

Flip::Window::Window(int width, int height, const std::string& caption)
{
	m_Fullscreen	= false;
	m_VSync			= true;
	m_MaxFPS		= 0;

	if (!glfwInit())
	{
		// [TODO] Log instead later?
		std::cout << "GLFW: Init failed..." << std::endl;
		return;
	}

	// Get the primary monitor and check the properties of it
	GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* videoMode = glfwGetVideoMode(primaryMonitor);

	m_Size.height	= static_cast<uint>(videoMode->height);
	m_Size.width	= static_cast<uint>(videoMode->width);
	m_MaxFPS		= static_cast<uint>(videoMode->refreshRate);

	// Should not scale the window content
	glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_FALSE);
	
	// We dont want GLFW to create a context for us.
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

	m_Window = glfwCreateWindow
		(
			m_Size.width,
			m_Size.height,
			caption.c_str(),
			nullptr,
			nullptr
		);
}

Flip::Window::~Window()
{
	// Destroy the window
	glfwDestroyWindow(m_Window);

	// Close down GLFW
	glfwTerminate();
}
