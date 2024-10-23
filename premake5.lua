workspace("timewise")
configurations({ "Debug", "Release" })
platforms({ "Linux", "Windows", "MacOS" })

-- TimeWise project
project("timewise")
kind("WindowedApp")
language("C++")
targetdir("bin/%{cfg.buildcfg}/timewise")

-- Common include directories
includedirs({ "lib/imgui", "lib/imgui/backends" })

-- Common files
files({
	"src/**.h",
	"src/**.cpp",
	"lib/imgui/*.cpp",
	"lib/imgui/backends/imgui_impl_glfw.cpp",
	"lib/imgui/backends/imgui_impl_opengl3.cpp",
})

filter("configurations:Debug")
defines({ "DEBUG" })
symbols("On")

filter("configurations:Release")
defines({ "NDEBUG" })
optimize("On")

-- Linux-specific setup
filter("action:gmake")
defines({ "LINUX" })
buildoptions({ "-std=c++11", "-g", "-Wall", "-Wformat" })
links({ "GL", "glfw" })
linkoptions({ "`pkg-config --static --libs glfw3`" })
includedirs({ "`pkg-config --cflags glfw3`" })

-- Post-build command to copy the res folder on Linux
postbuildcommands({
	"{COPY} ./res %{cfg.targetdir}/res",
	"{COPY} imgui.ini %{cfg.targetdir}/imgui.ini",
})

-- Windows-specific setup for Visual Studio
filter("action:vs2022")
defines({ "WINDOWS" })
buildoptions({ "/std:c++17" }) -- Visual Studio uses MSVC syntax for build options
links({ "opengl32.lib", "glfw3.lib" })
includedirs({ "lib/imgui", "lib/imgui/backends", "deps/glfw/include", "src" }) -- Include source directories for Windows
libdirs({ "deps/glfw/lib" })

-- Post-build command to copy the res folder on Windows
postbuildcommands({
	"{COPY} ./res %{cfg.targetdir}\\res",
	"{COPY} imgui.ini %{cfg.targetdir}/imgui.ini",
})

-- Reset filters to avoid affecting other projects
filter({})
