workspace "ReiEngine"
    architecture "x86_64"

    configurations { "Debug", "Release" }

    startproject "Game"    

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "ReiEngine"
include "Game"
