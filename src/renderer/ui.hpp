#pragma once

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

bool CreateUIRenderer(void*);

void StartUIFrame();
void EndUIFrame();

void DestroyUIRenderer();