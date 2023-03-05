#include "EnginePCH.h"
#include "Window.h"

Flip::Window::Window()
{
	m_Fullscreen	= false;
	m_VSync			= true;
	m_Caption		= "FlipEngine";
}

Flip::Window::~Window()
{
	// Destroy the window
	glfwDestroyWindow(m_Window);

	// Cleans up GLFW
	glfwTerminate();
}

bool Flip::Window::Init()
{
	if (!glfwInit())
	{
		LOG_ENGINE_ERROR("GLFW: Init failed...");
		glfwTerminate();
		return false;
	}

	// Get the primary monitor and check the properties of it
	GLFWmonitor* primaryMonitor		= glfwGetPrimaryMonitor();
	const GLFWvidmode* videoMode	= glfwGetVideoMode(primaryMonitor);

	m_Size.height	= videoMode->height;
	m_Size.width	= videoMode->width;

	// Should not scale the window content
	glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_FALSE);

	
	// Deciding if we want GLFW to create a Opengl context for us
#ifdef FLIP_OPENGL
	glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
#else
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
#endif

	// If have chosen fullscreen, we will send 
	// in the monitor as well in window creation.
	GLFWmonitor* fullscreenMonitor = nullptr;
	if (m_Fullscreen)
	{
		fullscreenMonitor = primaryMonitor;
	}

	m_Window = glfwCreateWindow
	(
		m_Size.width,
		m_Size.height,
		m_Caption.c_str(),
		fullscreenMonitor,
		nullptr
	);
	

	if (!m_Window)
	{
		LOG_ENGINE_ERROR("GLFW: Failed to create window..");
		glfwTerminate();
		return false;
	}

	LOG_ENGINE_INFO("Created a window '{0}' ({1}x{2})", m_Caption, m_Size.width, m_Size.height);

	/*
		Initial callback functions for window
	*/
	//glfwSetKeyCallback(m_Window, GLFWkeyfun);
	//glfwSetMouseButtonCallback(m_Window, GLFWmousebuttonfun);
	//glfwSetScrollCallback(m_Window, GLFWscrollfun);
	//glfwSetWindowCloseCallback(m_Window, GLFWwindowclosefun);
	//glfwSetWindowSizeCallback(m_Window, GLFWwindowsizefun);

	return true;
}

bool Flip::Window::IsOpen()
{
	// Is keept open as long as we have not sent an close event
	return !glfwWindowShouldClose(m_Window);
}

void Flip::Window::PollEvent()
{
	glfwPollEvents();

	if (glfwGetKey(m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(m_Window, 1);
	}


	/*if (glfwGetKey(m_Window, GLFW_KEY_W) == GLFW_PRESS)
	{
		LOG_ENGINE_INFO("Pressed once W");
	}*/
}

void Flip::Window::EnableVSync(bool toggle)
{
	m_VSync = toggle;
}

void Flip::Window::EnableFullscreen(bool toggle)
{
	m_Fullscreen = toggle;
	// [TODO] Some GLFW code to update the window
}

void Flip::Window::SetCaption(const std::string& caption)
{
	m_Caption = caption;
	glfwSetWindowTitle(m_Window, m_Caption.c_str());
}

GLFWwindow* Flip::Window::GetGLFWwindow() const
{
	return m_Window;
}
