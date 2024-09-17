workspace("timewise")
configurations({ "Debug", "Release" })
platforms({ "Linux", "Windows", "MacOS" })

-- TimeWise project
project("timewise")
kind("WindowedApp")
language("C++")
targetdir("bin/%{cfg.buildcfg}/timewise")

includedirs({ "lib/imgui", "lib/imgui/backends" })

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

filter("system:linux")
defines({ "LINUX" })
buildoptions({ "-std=c++11", "-g", "-Wall", "-Wformat" })
links({ "GL", "glfw" })
linkoptions({ "`pkg-config --static --libs glfw3`" })
includedirs({ "`pkg-config --cflags glfw3`" })

filter("system:windows")
defines({ "WINDOWS" })
buildoptions({ "-std=c++11" })
links({ "glfw3", "gdi32", "opengl32", "imm32" })

filter("system:macosx")
defines({ "MACOS" })
buildoptions({ "-std=c++11" })
links({ "OpenGL.framework", "Cocoa.framework", "IOKit.framework", "CoreVideo.framework", "glfw" })
includedirs({ "/usr/local/include", "/opt/local/include", "/opt/homebrew/include" })
libdirs({ "/usr/local/lib", "/opt/local/lib", "/opt/homebrew/lib" })

-- Reset filters to avoid affecting other projects
filter({})
