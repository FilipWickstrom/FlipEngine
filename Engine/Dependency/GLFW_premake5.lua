-- The Cherno wrote most of this, so all credit to him :)
-- https://www.youtube.com/watch?v=88dmtleVywk&ab_channel=TheCherno
-- Also got some help from: 
-- https://stackoverflow.com/questions/70199224/trouble-linking-with-glfw-using-premake-and-vs2019

project "GLFW"
	kind "StaticLib"
	language "C"
	staticruntime "on"
	systemversion "latest"
	
	targetdir("GLFW/Build/Bin/" .. outputdir .. "/%{prj.name}")
	objdir("GLFW/Build/Bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		-- Header files
		"GLFW/include/GLFW/glfw3.h",
		"GLFW/include/GLFW/glfw3native.h",
		"GLFW/src/internal.h",
		"GLFW/src/platform.h",
		"GLFW/src/mappings.h",
		"GLFW/src/null_platform.h",
		"GLFW/src/null_joystick.h",
		
		-- Source files
		"GLFW/src/context.c",
		"GLFW/src/init.c",
		"GLFW/src/input.c",
		"GLFW/src/monitor.c",
		"GLFW/src/platform.c",
		"GLFW/src/vulkan.c",
		"GLFW/src/window.c",
		"GLFW/src/egl_context.c",
		"GLFW/src/osmesa_context.c",
		"GLFW/src/null_init.c",
		"GLFW/src/null_monitor.c",
		"GLFW/src/null_window.c",
		"GLFW/src/null_joystick.c",
	}
	
	filter "system:windows"
		
		files
		{
			"GLFW/src/win32_init.c",
			"GLFW/src/win32_joystick.c",
			"GLFW/src/win32_module.c",
			"GLFW/src/win32_monitor.c",
			"GLFW/src/win32_thread.c",
			"GLFW/src/win32_time.c",
			"GLFW/src/win32_window.c",
			"GLFW/src/wgl_context.c"
		}
		
		defines
		{
			"_GLFW_WIN32",
			"_CRT_SECURE_NO_WARNINGS"
		}
		
	filter "system:linux"
		pic "On"

		files
		{
			"GLFW/src/x11_init.c",
			"GLFW/src/x11_monitor.c",
			"GLFW/src/x11_window.c",
			"GLFW/src/xkb_unicode.c",
			"GLFW/src/posix_time.c",
			"GLFW/src/posix_module.c",
			"GLFW/src/posix_thread.c",
			"GLFW/src/posix_poll.c",
			"GLFW/src/glx_context.c",
			"GLFW/src/egl_context.c",
			"GLFW/src/osmesa_context.c",
			"GLFW/src/linux_joystick.c"
		}

		defines
		{
			"_GLFW_X11"
		}

		
filter "configurations:Debug"
    runtime "Debug"
    symbols "On"

filter "configurations:Release"
    runtime "Release"
    optimize "On"
	