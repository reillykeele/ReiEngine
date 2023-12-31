project "ReiEngine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "Off"
        
    targetdir  ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir     ("%{wks.location}/obj/" .. outputdir .. "/%{prj.name}")

    pchheader "reipch.h"
    pchsource "src/reipch.cpp"

    files 
    { 
        "src/**.h", 
        "src/**.cpp",        
    }

    includedirs
    {
        "src",
        "third_party/SDL2/include",
        "third_party/Glad/include"
    }

    links
    {
        "%{Library.SDL2}",
        "Glad"
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
