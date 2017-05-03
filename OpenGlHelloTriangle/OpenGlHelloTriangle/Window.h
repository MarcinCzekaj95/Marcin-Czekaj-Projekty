#pragma once
#include <GL\glew.h>
#include "InputKeys.h"


class Window
{
	GLFWwindow * m_window;

	bool Init(int width,int height,char * title);

	InputKeys input;

public:
	Window(int width, int height, char * title);

	~Window();

	GLFWwindow * getWindow();

	bool CheckWindowClose();

};

