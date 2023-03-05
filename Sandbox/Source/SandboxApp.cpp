#include "SandboxApp.h"
#include "FlipEngine.h"

SandboxApp::SandboxApp(const std::string& nameOfApp)
	:Application(nameOfApp)
{
}

void SandboxApp::Init()
{
	// Load assets
	LOG_INFO("Sandbox Initalized");
}

void SandboxApp::Clean()
{
	// Clean up assets and stuff
	LOG_INFO("Sandbox has been cleaned up");
}

void SandboxApp::Input()
{
	// What happens if we press "W"?

	/*
	if (Flip::Keyboard::IsKeypressed(flip::Keyboard::W))

	if (Flip::Mouse::IsKeypressed(flip::Mouse::Left))

	*/

}

void SandboxApp::Update(f64 dt)
{
	// std::cout << "DT: " << dt << std::endl;
}

void SandboxApp::Render()
{
	// Render a cube?
}

void SandboxApp::RenderGUI()
{
	// Render ImGUI
}
