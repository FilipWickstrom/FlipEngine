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
IncludeDir["GLFW"] = "Engine/Dependency/GLFW/include"

-- Includes premake files
include "Engine/Dependency/GLFW"

project "Engine"
	location "Engine"
	kind "StaticLib"
	language "C++"

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
		"%{IncludeDir.GLFW}"
	}
	
	links
	{
		"d3d11",
		"GLFW"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"GLFW_INCLUDE_NONE",
			"FE_PLATFORM_WINDOWS",
			"FE_BUILD_STATIC"
		}

		postbuildcommands
		{
			-- If we are going to make the engine a DLL we can copy it to the sandbox on postbuild
			--("{COPY} %{cfg.buildtarget.relpath} ../Build/Bin" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "FE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "FE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "FE_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

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
		"%{IncludeDir.GLFW}"
	}
	
	links
	{
		"Engine",
		"GLFW"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"FE_PLATFORM_WINDOWS"
		}

		postbuildcommands
		{
			-- If we are going to make the engine a DLL we can copy it to the sandbox on postbuild
			--("{COPY} %{cfg.buildtarget.relpath} ../Build/Bin" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		runtime "Debug"
		defines "FE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		runtime "Release"
		defines "FE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		runtime "Release"
		defines "FE_DIST"
		optimize "On"


-- Cleaning project
newaction {
	trigger		= "clean",
	description = "Removing solutionfiles",
	execute     = function()
		print("Removing binaries and intermediate binaries")
		os.rmdir("Build/Bin")
		os.rmdir("Build/Bin-int")

		print("Removing project files")
		os.rmdir(".vs")
		os.remove("**.sln")
		os.remove("**.vcxproj")
		os.remove("**.vcxproj.filters")
		os.remove("**.vcxproj.user")

		print("Cleaning: Done")
	end
}