#include "SandboxApp.h"
// #include <iostream>

SandboxApp::SandboxApp(const std::string& nameOfApp)
	:Application(nameOfApp)
{
}

void SandboxApp::Init()
{
	// Load assets
}

void SandboxApp::Clean()
{
	// Clean up assets and stuff
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
