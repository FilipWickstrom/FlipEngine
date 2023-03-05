#include "EnginePCH.h"
#include "Application.h"
#include "Timer.h"

#include "FlipEngine/Platform/Platform.h"
#ifdef FLIP_OPENGL
#include "FlipEngine/Platform/OpenGL/OpenGLGraphics.h"
#elif defined(FLIP_D3D11)
#include "FlipEngine/Platform/D3D11/D3D11Graphics.h"
#endif

Flip::Application::Application(const std::string& nameOfApp)
	:m_Window(), m_IsRunning(true)
{
	// [TODO] Read from settingsfile
	m_Window.EnableVSync(true);
	m_Window.EnableFullscreen(false);
	m_Window.SetCaption(nameOfApp);
	if (!m_Window.Init())
	{
		LOG_ENGINE_FATAL("Window failed to initialize...");
	}

#ifdef FLIP_D3D11
	m_Renderer = std::make_unique<D3D11Graphics>(m_Window.GetGLFWwindow());
#else
	m_Renderer = std::make_unique<OpenGLGraphics>(m_Window.GetGLFWwindow());
#endif

	if (!m_Renderer->Init())
	{
		LOG_ENGINE_FATAL("Renderer failed to initialize...");
	}
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
		
		// Getting window events
		m_Window.PollEvent();

		m_Renderer->ClearScreen({ 1,0,0,1 });

		// [TODO] Handle Events

		// Handling input
		Input();

		// Update code
		Update(dt);

		// Render to screen
		Render();
		RenderGUI();

		m_Renderer->SwapBuffers();

		// End timer
		timer.Stop();
		dt = timer.GetMilliseconds();
	}

	// Cleaning up the application
	Clean();
}
