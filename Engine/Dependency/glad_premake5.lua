project "glad"
	kind "StaticLib"
	language "C"
	staticruntime "on"
	systemversion "latest"
	
	targetdir("glad/Build/Bin/" .. outputdir .. "/%{prj.name}")
	objdir("glad/Build/Bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
    {
        "glad/include/glad/glad.h",
        "glad/include/KHR/khrplatform.h",
        "glad/src/glad.c"
    }
	
	includedirs
    {
        "glad/include"
    }
	
	filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"
