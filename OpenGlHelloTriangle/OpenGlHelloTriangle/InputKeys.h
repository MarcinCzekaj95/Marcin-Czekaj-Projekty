#pragma once
#include <GLFW\glfw3.h>

class InputKeys
{
	

public:
	InputKeys();

	~InputKeys();

	static void keyCallback(GLFWwindow * window, int key, int scancode, int action, int cos);
};

