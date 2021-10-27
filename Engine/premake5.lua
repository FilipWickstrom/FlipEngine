project "Engine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "off"
	
	targetdir ("%{wks.location}/Engine/build/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/Engine/build/bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "EnginePCH.h"
	pchsource "src/EnginePCH.cpp"
	
	
	files 
	{
        	"src/**.h",
        	"src/**.cpp",
        	"**.hlsl", 
        	"**.hlsli"
    	}	


	--Filter
	vpaths 
	{
		["Engine"] = { "**EnginePCH.*" },
			["Engine/Resources"] 	= {},
			["Engine/Shaders"] 	= {},
			["Engine/Renderer"] 	= {}
	}
	
	links
	{
		"dxgi"
	}
	
	
	filter "system:windows"
		systemversion "latest"
		defines
		{
		}
		
	filter "configurations:Debug"
		defines "_DEBUG"
		runtime "Debug"
		symbols "on"



	filter "configurations:Release"
		defines "HZ_RELEASE"
		runtime "Release"
		optimize "on"

		
	-- filter "*"
        -- local ws = "../Game/%%(Filename).cso"
        
        -- files("*.hlsl")
            -- shadermodel("5.0")
            -- shaderobjectfileoutput(ws)

        -- filter("files:**_vs.hlsl")
            -- shadertype("Vertex")

        -- filter("files:**_ps.hlsl")
            -- shadertype("Pixel")
            
        -- filter("files:**_gs.hlsl")
            -- shadertype("Geometry")
           
        -- filter("files:**_cs.hlsl")
            -- shadertype("Compute")