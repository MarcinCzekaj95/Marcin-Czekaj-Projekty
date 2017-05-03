#include "Window.h"
#include <iostream>


bool Window::Init(int width, int height, char * title)
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwInit();


	if (!glfwInit())
	{
		std::cout << "blad nie udalo sie zainicjowac glfw" << std::endl;
		return false;
	}

	m_window = glfwCreateWindow(width, height, title, nullptr, nullptr);

	if (m_window == nullptr)
	{
		std::cout << "nie udalo sie stworzyc okna" << std::endl;
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(m_window);

	glewExperimental = true;

	glewInit();

	if (glewInit() != GLEW_OK)
	{
		std::cout << "nie udalo sie zainicjowac glew" << std::endl;
		return false;
	}

	int frameX, frameY;
	glfwGetFramebufferSize(m_window, &frameX, &frameY);
	glViewport(0, 0, frameX, frameY);

	glfwSetKeyCallback(m_window, input.keyCallback);
	return true;
}

Window::Window(int width, int height, char * title)
{
	Init(width,height,title);
}


Window::~Window()
{
	glfwTerminate();
}

GLFWwindow * Window::getWindow()
{
	return m_window;
}

bool Window::CheckWindowClose()
{
	return glfwWindowShouldClose(m_window) == false;
}
