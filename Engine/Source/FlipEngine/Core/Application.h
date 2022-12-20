#pragma once
#include "Window.h"		//#include "Flip/Core/Window.h"

namespace Flip
{
	enum class GraphicsAPI
	{
		D3D11,
		//D3D12,		//Maybe far in the future
		//OPENGL,		//Maybe far in the future
		//VULKAN,		//Maybe far in the future
		NR_OF,
	};

	class Application
	{
	public:
		Application(GraphicsAPI api);
		~Application();

		// Should not be possible to copy or assign.
		Application(const Application&) = delete;
		Application& operator=(const Application&) = delete;

		// One version is to make this a static lib.
		// Then we can create an application that inherit 
		// from this. 
		//https://github.com/Shot511/RapidGL/blob/master/src/core/core_app.h
		//virtual void Input() = 0;
		//virtual void Update(double dt) = 0;
		//virtual void Render() = 0;
		//virtual void RenderGUI() = 0;


		void Run();
		// - Read in the scene and all the objects
		// - Start the loop (update, render...)

	private:
		// void Update(); // Specific for the application.
		// - Update as long as we have not tried to stop the application
		// - Checking the input
		// - Checking window specific stuff - resize, not in focus and so on?
		// - Update the scene if needed.

		// void Render();
		// - Draw every mesh that we have.

	private:

		// Window
		Window m_window;
		// - Searching for the largest resolution to use at startup.
		// - Handling window size and resizing and so on.
		// 

		// InputHandler
		// - Handling input

		// Renderer
		// - Closest contact with the Graphics API
		// 

		// Scenehandler
		// - Using an ECS with all the components.
		// 

		/*
			ECS - looping through all the entities with these components.
		*/

		// ScriptComponent
		// - Update anything if needed

	};
}
