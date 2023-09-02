workspace "ReiEngine"
    architecture "x86_64"

    configurations { "Debug", "Release" }

    startproject "Game"    

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "ReiEngine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    
    location "%{prj.name}"
    targetdir  ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir     ("%{wks.location}/obj/" .. outputdir .. "/%{prj.name}")

    pchheader "reipch.h"
    pchsource "%{prj.name}/Source/reipch.cpp"

    files 
    { 
        "%{prj.name}/Source/**.h", 
        "%{prj.name}/Source/**.cpp",
        "%{prj.name}/ThirdParty/**.h", 
        "%{prj.name}/ThirdParty/**.cpp" 
    }

    includedirs
    {
        "%{prj.name}/Source",
        "%{prj.name}/ThirdParty"
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

project "Game"    
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    
    location "%{prj.name}"
    targetdir  ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir     ("%{wks.location}/obj/" .. outputdir .. "/%{prj.name}")

    files 
    { 
        "%{prj.name}/Source/**.h", 
        "%{prj.name}/Source/**.cpp" 
    }

    includedirs
    {
        "%{prj.name}/Source",
        "%{prj.name}/ThirdParty",
        "%{wks.location}/ReiEngine/Source",
        "%{wks.location}/ReiEngine/ThirdParty"
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
