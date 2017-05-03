#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <string>

enum ShaderType
{
	vertexShader = GL_VERTEX_SHADER,
	fragmentShader = GL_FRAGMENT_SHADER
};

#pragma once
class ShaderPrograms
{
	void LoadFromFile(const char * source, ShaderType sType);

	std::string ShaderSource;

	GLuint m_shaderID;

	ShaderType shaderType;

	

public:
	ShaderPrograms(const char * source,ShaderType sType);


	~ShaderPrograms();

	GLuint getShaderID();
};

