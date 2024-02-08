workspace "Domension"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Domension"
	location "Domension"
	kind "SharedLib"
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
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{

			"DOM_PLATFORM_WINDOWS",
			"DOM_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "DOM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DOM_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DOM_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
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
		"Domension/vendor/spdlog/include",
		"Domension/src"
	}

	links
	{
		"Domension"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{

			"DOM_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "DOM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DOM_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DOM_DIST"
		optimize "On"
