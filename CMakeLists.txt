cmake_minimum_required(VERSION 3.25)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(BearWM LANGUAGES CXX)
set(SRCS
    BearWM/src/BearWM/Core/BearWM.cpp
)
add_executable(BearWM ${SRCS})
set_property(TARGET BearWM PROPERTY CXX_STANDARD 20)

target_include_directories(BearWM PRIVATE
    BearWM/src
)

target_link_libraries(BearWM
    X11
)

