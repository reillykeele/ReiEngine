project "ReiEngine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "Off"
        
    targetdir  ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir     ("%{wks.location}/obj/" .. outputdir .. "/%{prj.name}")

    pchheader "reipch.h"
    pchsource "Source/reipch.cpp"

    files 
    { 
        "Source/**.h", 
        "Source/**.cpp",        
    }

    includedirs
    {
        "Source",
        "ThidParty",
        "ThirdParty/SDL2/Include"
    }

    links
    {
        "ThirdParty/SDL2/lib/x64/SDL2.lib",
        "ThirdParty/SDL2/lib/x64/SDL2main.lib"
    }

    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        defines { "DEBUG" }
        runtime "Debug"
        symbols "On"
    
    filter "configurations:Release"
        defines { "NDEBUG" }
        runtime "Release"
        optimize "On"
