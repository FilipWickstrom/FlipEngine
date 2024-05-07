#pragma once
#include "FlipEngine/Core/Window.h"
#include "FlipEngine/Renderer/Renderer.h"

// [TODO] check why PCH is not working correctly...
typedef double f64;
#include <memory>

namespace Flip
{

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
	virtual void Update(f64 dt) = 0;
	// Render the models
	virtual void Render() = 0;
	// Render imGUI stuff
	virtual void RenderGUI() = 0;

	// Start the "endless" loop
	void Run();

private:


private:
	bool m_IsRunning;


	// Handling the surface to draw on
	// and window size and resizing and so on.
	Window m_Window;

	// InputHandler
	// - Handling input

	// - Closest contact with the Graphics API
	std::unique_ptr<Renderer> m_Renderer;

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
