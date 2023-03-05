#pragma once

// Standard libraries
#include <iostream>
#include <memory>

#include <string>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>


// Good to have everywhere
#include "FlipEngine/Platform/Platform.h"
#include "FlipEngine/Core/Types.h"

// Third-party compiled libs
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>


// OpenGL-specific
#ifdef FLIP_OPENGL
	#include <glad/glad.h>

#elif defined(FLIP_D3D11)
	#include <d3d11.h>

#endif





// Singletons
#include "FlipEngine/Core/Logger.h"
