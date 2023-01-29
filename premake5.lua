workspace "Sledge"
    architecture "x64"
    startproject "Sandbox"

    configurations {
        "Debug",
        "Release"
    }

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

includeDir = {}
includeDir["GLFW"] = "Sledge/vendor/GLFW/include"
includeDir["Glad"] = "Sledge/vendor/Glad/include"
includeDir["ImGui"] = "Sledge/vendor/imgui"
includeDir["glm"] = "Sledge/vendor/glm"

group "Dependencies"
    include "Sledge/vendor/GLFW"
    include "Sledge/vendor/Glad"
    include "Sledge/vendor/imgui"
group ""

project "Sledge"
    location "Sledge"
    kind "SharedLib"
    language "C++"
    staticruntime "off"

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
        "%{includeDir.GLFW}",
        "%{includeDir.Glad}",
        "%{includeDir.ImGui}",
        "%{includeDir.glm}"
    }

    links 
    {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

        defines 
        {
            "SL_PLATFORM_WINDOWS",
            "SL_BUILD_DLL",
            "GLFW_INCLUDE_NONE",
            "IMGL3W_IMPL"
        }

        postbuildcommands 
        {
            ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputDir .. "/Sandbox/\"")
        }
        
    filter "configurations:Debug"
        runtime "Debug"
		symbols "on"
        defines {
            "SL_DEBUG"
        }

    filter "configurations:Release"
        defines "SL_RELEASE"
        runtime "Release"
		optimize "on"
        
project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    staticruntime "off"

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
        "Sledge/src",
        "%{includeDir.glm}"
    }

    links 
    {
        "Sledge"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

        defines 
        {
            "SL_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "SL_DEBUG"
        symbols "On"
        runtime "Debug"
        

    filter "configurations:Release"
        defines "SL_RELEASE"
        optimize "On"
        runtime "Release"
        