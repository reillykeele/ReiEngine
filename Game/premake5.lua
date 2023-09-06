project "Game"    
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "Off"
        
    targetdir  ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir     ("%{wks.location}/obj/" .. outputdir .. "/%{prj.name}")

    files 
    { 
        "src/**.h", 
        "src/**.cpp" 
    }

    includedirs
    {
        "src",
        "third_party",
        "%{wks.location}/ReiEngine/src",
        "%{wks.location}/ReiEngine/third_party"
    }

    links
    {        
        "ReiEngine"
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
