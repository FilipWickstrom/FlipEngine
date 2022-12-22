#include "EnginePCH.h"
#include "Application.h"
#include "Timer.h"

Flip::Application::Application(const std::string& nameOfApp)
	:m_Window()
{
	// [TODO] Read from settingsfile
	m_Window.EnableVSync(true);
	m_Window.EnableFullscreen(false);
	m_Window.SetCaption(nameOfApp);
	m_Window.Initialize();
}

void Flip::Application::Run()
{
	// Initialize the application with scenes and assets
	Init();

	Timer timer;
	double dt = 0;

	// The "Game-loop"
	while (m_Window.IsOpen())
	{
		// Start timer
		timer.Start();

		// Handling input
		Input();

		// Getting window events
		m_Window.PollEvent();

		// Update code
		Update(dt);

		// Render to screen
		Render();
		RenderGUI();

		// End timer
		timer.Stop();
		dt = timer.GetMilliseconds();
	}

	// Cleaning up the application
	Clean();
}
