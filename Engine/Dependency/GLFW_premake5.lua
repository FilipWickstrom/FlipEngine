-- The Cherno wrote most of this, so all credit to him :)
-- https://www.youtube.com/watch?v=88dmtleVywk&ab_channel=TheCherno
-- Also got some help from: 
-- https://stackoverflow.com/questions/70199224/trouble-linking-with-glfw-using-premake-and-vs2019

project "glfw"
	kind "StaticLib"
	language "C"
	staticruntime "on"
	systemversion "latest"
	
	targetdir("glfw/Build/Bin/" .. outputdir .. "/%{prj.name}")
	objdir("glfw/Build/Bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		-- Header files
		"glfw/include/GLFW/glfw3.h",
		"glfw/include/GLFW/glfw3native.h",
		"glfw/src/internal.h",
		"glfw/src/platform.h",
		"glfw/src/mappings.h",
		"glfw/src/null_platform.h",
		"glfw/src/null_joystick.h",
		
		-- Source files
		"glfw/src/context.c",
		"glfw/src/init.c",
		"glfw/src/input.c",
		"glfw/src/monitor.c",
		"glfw/src/platform.c",
		"glfw/src/vulkan.c",
		"glfw/src/window.c",
		"glfw/src/egl_context.c",
		"glfw/src/osmesa_context.c",
		"glfw/src/null_init.c",
		"glfw/src/null_monitor.c",
		"glfw/src/null_window.c",
		"glfw/src/null_joystick.c",
	}
	
	filter "system:windows"
		
		files
		{
			"glfw/src/win32_init.c",
			"glfw/src/win32_joystick.c",
			"glfw/src/win32_module.c",
			"glfw/src/win32_monitor.c",
			"glfw/src/win32_thread.c",
			"glfw/src/win32_time.c",
			"glfw/src/win32_window.c",
			"glfw/src/wgl_context.c"
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
			"glfw/src/x11_init.c",
			"glfw/src/x11_monitor.c",
			"glfw/src/x11_window.c",
			"glfw/src/xkb_unicode.c",
			"glfw/src/posix_time.c",
			"glfw/src/posix_module.c",
			"glfw/src/posix_thread.c",
			"glfw/src/posix_poll.c",
			"glfw/src/glx_context.c",
			"glfw/src/egl_context.c",
			"glfw/src/osmesa_context.c",
			"glfw/src/linux_joystick.c"
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
	