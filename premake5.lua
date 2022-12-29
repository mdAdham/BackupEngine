workspace "BackupEngine"
	architecture "x64"
	startproject "SandBox"
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include Directories
IncludeDir = {}
IncludeDir["GLFW"] = "BackupEngine/vendor/GLFW/include"

include "BackupEngine/vendor/GLFW"


project "BackupEngine"
	location "BackupEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/"..outputdir.."/%{prj.name}")
	objdir ("bin-int/"..outputdir.."/%{prj.name}")

	pchheader "enpch.h"
	pchsource "BackupEngine/src/enpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib",
		"user32",
		"gdi32",
		"shell32",
		"kernel32"
	}

	defines
	{
		
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"

		defines
		{
			"EN_PLATFORM_WINDOWS",
			"EN_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
		}

	filter "configurations:Debug"
		defines "EN_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "EN_RELEASE"
		optimize "on"

	filter "configurations:Dist"
		defines "EN_DIST"
		optimize "on"

project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/BackupEngine/vendor/spdlog/include",
		"BackupEngine/src"
	}

	defines
	{
		"EN_PLATFORM_WINDOWS"
	}

	links
	{
		"BackupEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"

		defines
		{
			"EN_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "EN_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "EN_RELEASE"
		optimize "on"

	filter "configurations:Dist"
		defines "EN_DIST"
		optimize "on"