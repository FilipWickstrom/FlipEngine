#pragma once
//#include "FlipEngine/EnginePCH.h"

#include <GLFW/glfw3.h>

#include <string>

typedef unsigned int uint;

namespace Flip
{
	class Window
	{
	public:
		Window(int width, int height, const std::string& caption = "FlipEngine");	// Change to vec2 later on
		~Window();
	
		// Should not be possible to copy or assign.
		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;

		// Basic - needed in most cases
		bool IsOpen();
		void PollEvent();
		void Display();

		// Settings
		void EnableVSync(bool toggle = true);
		void EnableFullscreen(bool toggle = true);
		void SetMaxFramerate(uint maxFPS);
		//void SetClearColor(vec4);

	private:
		void ProcessEvents();

	private:
		GLFWwindow* m_Window;

		bool m_Fullscreen;
		bool m_VSync;
		uint m_MaxFPS;

		struct size
		{
			uint width;
			uint height;
		} m_Size;
		std::string m_caption;

	};
}