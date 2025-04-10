cmake_minimum_required(VERSION 3.10)

project(VectorProject)

set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glfw)

include_directories(external/glfw/include)
include_directories(external/imgui)
include_directories(src)
include_directories(external/glad/include/)

file(GLOB_RECURSE VP_SOURCE src/*.c src/*.cpp src/*.h src/*.hpp)

file(GLOB IMGUI_SOURCE_MAIN external/imgui/*.cpp external/imgui/*.h)
file(GLOB_RECURSE IMGUI_SOURCE_BACKEND external/imgui/backends/*.cpp external/imgui/backends/*.h)

add_library(imgui ${IMGUI_SOURCE_MAIN} ${IMGUI_SOURCE_BACKEND})

add_executable(VectorProject ${VP_SOURCE})

target_link_libraries(VectorProject glfw imgui)