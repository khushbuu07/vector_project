#include <renderer/renderer.hpp>
#include <renderer/ui.hpp>
#include <window/window.hpp>

#include <stdio.h>
#include <cstdlib>

Window window;

int main() {
	WindowCreateInfo wci{};
	wci.title = "Hello, World!";
	wci.width = 800;
	wci.height = 600;
	wci.fullscreen = false;
	wci.resizable = true;
	wci.vsync = true;
	wci.adaptive_resolution = true;

	window = CreateWindow(wci);
	if (!window) {
		printf("ERROR: Failed to create window!\n");
		return EXIT_FAILURE;
	}

	if (!CreateRenderer()) {
		printf("ERROR: Failed to create renderer!\n");
		return EXIT_FAILURE;
	}

	if (!CreateUIRenderer(window)) {
		printf("ERROR: Failed to create UI renderer!\n");
		return EXIT_FAILURE;
	}

	while (!ShouldCloseWindow(window)) {
		glClearColor(1.0, 0.5f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		StartUIFrame();

		if (ImGui::Begin("Dinosaur")) {
			ImGui::Text("Dinosaurs are the best!");
			ImGui::Button("Yes", ImVec2(80, 20));
			ImGui::Button("No", ImVec2(80, 20));
		}
		ImGui::End();

		EndUIFrame();

		UpdateWindow(window);
	}

	DestroyUIRenderer();
	DestroyRenderer();
	DestroyWindow(window);
}