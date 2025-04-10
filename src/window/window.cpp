#include "window.hpp"

#include <GLFW/glfw3.h>

Window CreateWindow(WindowCreateInfo& wci) {
    
    if (!glfwInit()) return nullptr;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, wci.resizable);
    
    GLFWwindow* win;

    if (wci.fullscreen) {
        GLFWmonitor* monitor = glfwGetPrimaryMonitor();
        if (!monitor) return nullptr;
        const GLFWvidmode* mode = glfwGetVideoMode(monitor);
        if (!mode) return nullptr;

        if (wci.adaptive_resolution) {
            win = glfwCreateWindow(mode->width, mode->height, wci.title, monitor, nullptr);
        }
        else {
            win = glfwCreateWindow(wci.width, wci.height, wci.title, monitor, nullptr);
        }
    }
    else {
        win = glfwCreateWindow(wci.width, wci.height, wci.title, nullptr, nullptr);
    }

    if (!win) return nullptr;

    glfwSwapInterval(wci.vsync);

    glfwMakeContextCurrent(win);

    return (Window)win;
}

void UpdateWindow(Window wp) {
    glfwPollEvents();
    glfwSwapBuffers((GLFWwindow*)wp);
}

bool ShouldCloseWindow(Window wp) {
    return glfwWindowShouldClose((GLFWwindow*)wp);
}

void DestroyWindow(Window wp) {
    glfwDestroyWindow((GLFWwindow*)wp);
    glfwTerminate();
}