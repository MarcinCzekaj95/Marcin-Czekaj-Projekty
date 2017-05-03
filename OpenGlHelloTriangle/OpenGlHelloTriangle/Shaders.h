#include "ShaderPrograms.h"
#include <memory>
#pragma once
class Shaders
{

	void Init();

	GLuint shaderProgramId;

	std::shared_ptr<ShaderPrograms> m_vertexShader;
	std::shared_ptr<ShaderPrograms> m_fragmentShader;

public:


	Shaders(std::shared_ptr<ShaderPrograms> vs,std::shared_ptr<ShaderPrograms> fs);


	~Shaders();

	GLuint getProrgamID();
};

