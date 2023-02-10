#pragma once

#ifdef FLIP_WINDOWS
	// Disable warning about APIENTRY in GLFW.h and minwindef.h being redefined
	#pragma warning( disable : 4005 )
#endif
#include <GLFW/glfw3.h>
#include <string>
#include "FlipEngine/Math/Vec2.h"

namespace Flip
{
	class Window
	{
	public:
		Window();
		~Window();
	
		// Should not be possible to copy or assign.
		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;

		// Setup the GLFW window
		bool Initialize();

		// Basic - needed in most cases
		bool IsOpen();
		void PollEvent();
		void Display();

		// Settings from file
		void EnableVSync(bool toggle = true);
		void EnableFullscreen(bool toggle = true);
		void SetCaption(const std::string& caption);
		//void SetClearColor(vec4);

	private:
		// Window callback events


		void ProcessEvents();

	private:
		GLFWwindow* m_Window;
		bool		m_Fullscreen;
		bool		m_VSync;
		std::string m_Caption;
		Vec2i		m_Size;

	};
}