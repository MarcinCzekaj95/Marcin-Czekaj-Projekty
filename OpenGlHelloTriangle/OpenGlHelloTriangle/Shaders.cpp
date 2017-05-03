#include "Shaders.h"
#include <iostream>



void Shaders::Init()
{
	GLint success;
	GLchar error[512];

	shaderProgramId = glCreateProgram();
	glAttachShader(shaderProgramId, m_vertexShader->getShaderID());
	glAttachShader(shaderProgramId, m_fragmentShader->getShaderID());
	glLinkProgram(shaderProgramId);

	glGetProgramiv(shaderProgramId, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgramId, 512, NULL, error);
		std::cerr << "nie udalo sie zlinkowac programu" << std::endl;
	}

}

Shaders::Shaders(std::shared_ptr<ShaderPrograms> vs, std::shared_ptr<ShaderPrograms> fs)
	:m_vertexShader(vs),m_fragmentShader(fs)
{
	Init();
}


Shaders::~Shaders()
{
}

GLuint Shaders::getProrgamID()
{
	return shaderProgramId;
}
