#pragma once
#include <GLFW/glfw3.h>
#include <string>

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
		void ProcessEvents();

	private:
		GLFWwindow* m_Window;
		bool		m_Fullscreen;
		bool		m_VSync;
		std::string m_Caption;

		// [TODO] Later using a vector2 or something simular
		struct size
		{
			int width;
			int height;
		} m_Size;

	};
}