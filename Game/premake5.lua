project "Game"    
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "Off"
        
    targetdir  ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir     ("%{wks.location}/obj/" .. outputdir .. "/%{prj.name}")

    files 
    { 
        "Source/**.h", 
        "Source/**.cpp" 
    }

    includedirs
    {
        "Source",
        "ThirdParty",
        "%{wks.location}/ReiEngine/Source",
        "%{wks.location}/ReiEngine/ThirdParty/**"
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
