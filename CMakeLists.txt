cmake_minimum_required(VERSION 3.30)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(BearWM LANGUAGES CXX)
set(SRCS
    BearWM/src/BearWM/Core/BearWM.cpp
    BearWM/src/BearWM/Core/WindowManager.cpp
    BearWM/src/BearWM/Core/WindowManager.h
)
add_executable(BearWM ${SRCS})
set_property(TARGET BearWM PROPERTY CXX_STANDARD 20)

target_include_directories(BearWM PRIVATE
    BearWM/src
)

target_link_libraries(BearWM
    xcb
)

