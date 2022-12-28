#include "SandboxApp.h"
// #include <iostream>
#include "FlipEngine/Core/Logger.h"

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
}

void SandboxApp::Update(double dt)
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