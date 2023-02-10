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
IncludeDir["GLFW"] 		= "Engine/Dependency/GLFW/include"
IncludeDir["spdlog"] 	= "Engine/Dependency/spdlog/include"
IncludeDir["glm"]		= "Engine/Dependency/glm/"

-- Includes premake files
include "Engine/Dependency/GLFW"

project "Engine"
	location "Engine"
	kind "StaticLib"
	language "C++"
	staticruntime "on"

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
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.spdlog}"
	}
	
	links
	{
		"GLFW"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	filter "system:windows"
		cppdialect "C++20"
		systemversion "latest"

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
		cppdialect "C++2a"
		systemversion "latest"
		pic "on"

		defines
		{
			"GLFW_INCLUDE_NONE",
			"FLIP_LINUX",
			"FLIP_BUILD_STATIC"
		}

	filter "configurations:Debug"
		defines "FLIP_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "FLIP_RELEASE"
		optimize "on"

	filter "configurations:Dist"
		defines "FLIP_DIST"
		optimize "on"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "on"

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
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.spdlog}",
		"%{IncludeDir.glm}"
	}
	
	links
	{
		"Engine",
		"GLFW"
	}

	filter "system:windows"
		cppdialect "C++20"
		systemversion "latest"

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
		systemversion "latest"

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
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		defines "FLIP_RELEASE"
		optimize "on"

	filter "configurations:Dist"
		runtime "Release"
		defines "FLIP_DIST"
		optimize "on"


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