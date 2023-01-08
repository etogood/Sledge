workspace "Sledge"
    architecture "x64"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

includeDir = {}
includeDir["GLFW"] = "Sledge/vendor/GLFW/include"

include "Sledge/vendor/GLFW"

project "Sledge"
    location "Sledge"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputDir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

    pchheader "slpch.h"
    pchsource "Sledge/src/slpch.cpp"

    files 
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs 
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{includeDir.GLFW}"
    }

    links 
    {
        "GLFW",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines 
        {
            "SL_PLATFORM_WINDOWS",
            "SL_BUILD_DLL"
        }

        postbuildcommands 
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "/Sandbox")
        }
    filter "configurations:Debug"
        defines "SL_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "SL_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "SL_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputDir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

    files 
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs 
    {
        "Sledge/vendor/spdlog/include",
        "Sledge/src"
    }

    links 
    {
        "Sledge"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines 
        {
            "SL_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "SL_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "SL_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "SL_DIST"
        optimize "On"