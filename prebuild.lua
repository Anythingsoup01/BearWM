workspace "BearWM"

project "BearWM"
    kind "ConsoleApp"
    language "C++"
    dialect "20"

    files
    {
        "BearWM/src/*.cpp",
        "BearWM/src/*.h",
    }

    includedirs
    {
        "BearWM/src"
    }

    links
    {
        "xcb",
    }

