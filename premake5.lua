workspace "ReiEngine"
    architecture "x86_64"

    configurations { "Debug", "Release" }

    startproject "Game"    

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

LibraryDir = {}
LibraryDir["SDL2"] = "%{wks.location}/ReiEngine/third_party/SDL2/lib/x64/"

Library = {}
Library["SDL2"] = "%{LibraryDir.SDL2}/SDL2.lib"
-- Library["SDL2main"] = "%{LibraryDir.SDL2}/SDL2main.lib"

group "Dependencies"
    include "ReiEngine/third_party/Glad"

group "Source"
    include "ReiEngine"
    include "Game"
