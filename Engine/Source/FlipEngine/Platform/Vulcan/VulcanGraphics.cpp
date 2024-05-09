#include "EnginePCH.h"
#include "VulcanGraphics.h"

VulcanGraphics::VulcanGraphics(GLFWwindow* windowHandle)
	: m_WindowHandle(windowHandle)
{
}

bool VulcanGraphics::Init()
{
	VkApplicationInfo appInfo = {};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "Name of the app";		// TODO: Connect to application somehow?
	appInfo.pEngineName		 = "FlipEngine";
	appInfo.apiVersion		 = VK_API_VERSION_1_3;

	VkInstanceCreateInfo instanceInfo = {};
	instanceInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	instanceInfo.pApplicationInfo = &appInfo;

	VkInstance instance;
	VkResult result = vkCreateInstance(&instanceInfo, 0, &instance);
	if (result == VK_SUCCESS)
	{
		LOG_ENGINE_INFO("Successfully created vulkan instance");
	}

	return true;
}

void VulcanGraphics::ClearScreen(glm::vec4 color)
{
}

void VulcanGraphics::SwapBuffers()
{
}

void VulcanGraphics::Draw()
{
}
