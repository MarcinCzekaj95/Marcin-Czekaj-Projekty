#include "InputKeys.h"



InputKeys::InputKeys()
{
}


InputKeys::~InputKeys()
{
}

void InputKeys::keyCallback(GLFWwindow * window, int key, int scancode, int actions, int cos)
{
	if (key == GLFW_KEY_ESCAPE && actions == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}
