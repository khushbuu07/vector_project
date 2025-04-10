#include "renderer.hpp"

#include <GLFW/glfw3.h>

bool CreateRenderer() {
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		return false;
	}

	return true;
}

void DestroyRenderer() {

}