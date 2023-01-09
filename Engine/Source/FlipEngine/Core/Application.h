#pragma once
#include "Window.h"

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
		Application(const std::string& nameOfApp);
		~Application() = default;

		// Should not be possible to copy or assign.
		Application(const Application&) = delete;
		Application& operator=(const Application&) = delete;

		// Layout of application inspired by:
		// https://github.com/Shot511/RapidGL/blob/master/src/core/core_app.h
		
		// Setup data specific for this application
		virtual void Init() = 0;
		// Clean up data when closing application
		virtual void Clean() = 0;
		// Setup how input should be handled
		virtual void Input() = 0;
		// Update the scene with all the entities
		virtual void Update(double dt) = 0;
		// Render the models
		virtual void Render() = 0;
		// Render imGUI stuff
		virtual void RenderGUI() = 0;

		// Start the "endless" loop
		void Run();

	private:
		

	private:

		// Handling the surface to draw on.
		Window m_Window;
		// - Handling window size and resizing and so on.

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
