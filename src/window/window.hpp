#pragma once

struct WindowCreateInfo {
    const char* title;
    int width;
    int height;
    bool resizable;
    bool fullscreen;
    bool adaptive_resolution;
    bool vsync;
};

typedef void* Window;

Window CreateWindow(WindowCreateInfo& wci);

void UpdateWindow(Window wp);

bool ShouldCloseWindow(Window wp);

void DestroyWindow(Window wp);