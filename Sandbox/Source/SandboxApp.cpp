#include "SandboxApp.h"
#include "FlipEngine/Core/Logger.h"

#include "FlipEngine/Math/Vec3.h"
#include "FlipEngine/Math/Operations.h"
#include "glm/glm.hpp"
#include "glm/gtx/quaternion.hpp"

SandboxApp::SandboxApp(const std::string& nameOfApp)
	:Application(nameOfApp)
{
}

void SandboxApp::Init()
{
	// Load assets
	LOG_INFO("Sandbox Initalized");

	float scalar(2.f);
	glm::quat quat(1.f, 0.f, 0.f, 0.f);

	glm::vec3 glm1(1.f, 2.f, -1.f);
	glm::vec3 glm2(-1.f,2.f,  1.f);
	glm::vec3 glmfinal;

	Vec3f vec1(1.f, 2.f, -1.f);
	Vec3f vec2(-1.f, 2.f, 1.f);
	Vec3f vecfinal;
	
	glmfinal = glm::cross(glm1, glm2);
	vecfinal = vec1.Cross(vec2);

	float distance = vec1.Distance(vec2);

	LOG_INFO("Distance: {0}", distance);

	LOG_TRACE("GLM3\t	({0}, {1}, {2})", glmfinal.x, glmfinal.y, glmfinal.z);
	LOG_TRACE("Vec2f\t	({0}, {1}, {2})", vecfinal.x, vecfinal.y, vecfinal.z);
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
