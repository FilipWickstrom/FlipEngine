#include "EnginePCH.h"
#include "Window.h"

namespace Flip
{

Window::Window()
	: m_Window(nullptr)
	, m_Fullscreen(false)
	, m_VSync(true)
	, m_Caption("FlipEngine")
	, m_Size({ 0,0 })
{
}

Window::~Window()
{
	// Destroy the window
	glfwDestroyWindow(m_Window);

	// Cleans up GLFW
	glfwTerminate();
}


void GLFWKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if ((key == GLFW_KEY_ESCAPE) && (action == GLFW_PRESS)) 
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}

	/*if (glfwGetKey(m_Window, GLFW_KEY_W) == GLFW_PRESS)
	{
		LOG_ENGINE_INFO("Pressed once W");
	}*/
}

void GLFWwindowsizeCallback(GLFWwindow* window, int width, int height)
{
	// Do something more???
	LOG_ENGINE_INFO("Resized window to ({0}x{1})", width, height);
}

bool Window::Init()
{
	if (!glfwInit())
	{
		LOG_ENGINE_ERROR("GLFW: Init failed...");
		glfwTerminate();
		return false;
	}

	if (!glfwVulkanSupported())
	{
		LOG_ENGINE_ERROR("GLFW: Vulcan not supported...");
		glfwTerminate();
		return false;
	}

	// Get the primary monitor and check the properties of it
	GLFWmonitor* primaryMonitor	 = glfwGetPrimaryMonitor();
	const GLFWvidmode* videoMode = glfwGetVideoMode(primaryMonitor);

	m_Size.height	= videoMode->height;
	m_Size.width	= videoMode->width;

	// Should not scale the window content
	glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_FALSE);
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

	// If have chosen fullscreen, we will send 
	// in the monitor as well in window creation.
	GLFWmonitor* fullscreenMonitor = nullptr;
	if (m_Fullscreen)
	{
		fullscreenMonitor = primaryMonitor;
	}

	m_Window = glfwCreateWindow(m_Size.width,
								m_Size.height,
								m_Caption.c_str(),
								fullscreenMonitor,
								nullptr);
	

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
	glfwSetKeyCallback(m_Window, GLFWKeyCallback);
	glfwSetWindowSizeCallback(m_Window, GLFWwindowsizeCallback);
	//glfwSetMouseButtonCallback(m_Window, GLFWmousebuttonfun);
	//glfwSetScrollCallback(m_Window, GLFWscrollfun);
	//glfwSetWindowCloseCallback(m_Window, GLFWwindowclosefun);

	return true;
}

bool Window::IsOpen()
{
	// Is keept open as long as we have not sent an close event
	return !glfwWindowShouldClose(m_Window);
}

void Window::PollEvent()
{
	glfwPollEvents();

}

void Window::EnableVSync(bool toggle)
{
	m_VSync = toggle;
}

void Window::EnableFullscreen(bool toggle)
{
	m_Fullscreen = toggle;
	// [TODO] Some GLFW code to update the window
}

void Window::SetCaption(const std::string& caption)
{
	m_Caption = caption;
	glfwSetWindowTitle(m_Window, m_Caption.c_str());
}

GLFWwindow* Window::GetGLFWwindow() const
{
	return m_Window;
}

}