workspace "FlipEngine"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"		--Final build with no logging
	}

startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- All the dependency files that we need
IncludeDir = {}
IncludeDir["glfw"] 		= "Engine/Dependency/glfw/include"
IncludeDir["spdlog"] 	= "Engine/Dependency/spdlog/include"
IncludeDir["glm"] 		= "Engine/Dependency/glm/"


project "Engine"
	location		"Engine"
	kind			"StaticLib"
	language		"C++"
	staticruntime	"on"
	systemversion	"latest"

	targetdir("Build/Bin/" .. outputdir .. "/%{prj.name}")
	objdir("Build/Bin-int/" .. outputdir .. "/%{prj.name}")

	-- Precompiled header files
	pchheader "EnginePCH.h"
	pchsource "%{prj.name}/Source/EnginePCH.cpp"

	files
	{
		"%{prj.name}/Source/**.h",
		"%{prj.name}/Source/**.cpp"
	}

	includedirs 
	{
		"%{prj.name}/Source/",
		"%{IncludeDir.glfw}",
		"%{IncludeDir.spdlog}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"glfw"
	}

	filter "system:windows"
		cppdialect "C++20"

		defines
		{
			"GLFW_INCLUDE_NONE",
			"FLIP_WINDOWS",
			"FLIP_BUILD_STATIC"
		}
		
		links
		{
			"d3d11"
		}

		postbuildcommands
		{
			-- If we are going to make the engine a DLL we can copy it to the sandbox on postbuild
			--("{COPY} %{cfg.buildtarget.relpath} ../Build/Bin" .. outputdir .. "/Sandbox")
		}

	filter "system:linux"
		cppdialect	"C++2a"
		pic			"On"

		defines
		{
			"GLFW_INCLUDE_NONE",
			"FLIP_LINUX",
			"FLIP_BUILD_STATIC"
		}

	filter "configurations:Debug"
		defines "FLIP_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "FLIP_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "FLIP_DIST"
		optimize "On"

	-- Solutions for 3rd party libs
	include "Engine/Dependency/GLFW_premake5"


project "Sandbox"
	location		"Sandbox"
	kind			"ConsoleApp"
	language		"C++"
	staticruntime	"on"
	systemversion	"latest"

	targetdir("Build/Bin/" .. outputdir .. "/%{prj.name}")
	objdir("Build/Bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/Source/**.h",
		"%{prj.name}/Source/**.cpp"
	}

	includedirs 
	{
		"Engine/Source",
		"%{IncludeDir.glfw}",
		"%{IncludeDir.spdlog}",
		"%{IncludeDir.glm}"
	}
	
	links
	{
		"Engine",
		"glfw"
	}

	filter "system:windows"
		cppdialect "C++20"

		defines
		{
			"FLIP_WINDOWS"
		}

		postbuildcommands
		{
			-- If we are going to make the engine a DLL we can copy it to the sandbox on postbuild
			--("{COPY} %{cfg.buildtarget.relpath} ../Build/Bin" .. outputdir .. "/Sandbox")
		}

	filter "system:linux"
		cppdialect "C++2a"

		defines
		{
			"FLIP_LINUX",
			"_X11"
		}
		
		links
		{
			"dl",
			"pthread"
		}

	filter "configurations:Debug"
		runtime "Debug"
		defines "FLIP_DEBUG"
		symbols "On"

	filter "configurations:Release"
		runtime "Release"
		defines "FLIP_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		runtime "Release"
		defines "FLIP_DIST"
		optimize "On"

	-- Solutions for 3rd party libs
	include "Engine/Dependency/GLFW_premake5"


-- Cleaning project
newaction {
	trigger		= "clean",
	description = "Removing solutionfiles",
	execute     = function()
		print("Removing binaries and intermediate binaries")
		os.rmdir("Build/Bin")
		os.rmdir("Build/Bin-int")

		print("Removing Visual Studio files")
		os.rmdir(".vs")
		os.remove("**.sln")
		os.remove("**.vcxproj")
		os.remove("**.vcxproj.filters")
		os.remove("**.vcxproj.user")

		print("Removing makefiles")
		os.remove("**Makefile")

		print("Cleaning: Done")
	end
}