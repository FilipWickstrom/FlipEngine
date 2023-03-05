#pragma once
#include "FlipEngine/Core/Application.h"

class SandboxApp : public Flip::Application
{
public:
	SandboxApp(const std::string& nameOfApp);
	~SandboxApp() = default;

	// Inherited via Application
	virtual void Init() override;
	virtual void Clean() override;
	virtual void Input() override;
	virtual void Update(f64 dt) override;
	virtual void Render() override;
	virtual void RenderGUI() override;
};
