workspace "BearWM"

project "BearWM"
    kind "ConsoleApp"
    language "C"
    dialect "23"

    files
    {
        "BearWM/src/*.c",
        "BearWM/src/*.h",
    }

    includedirs
    {
        "BearWM/src"
    }

    links
    {
        "X11",
    }

