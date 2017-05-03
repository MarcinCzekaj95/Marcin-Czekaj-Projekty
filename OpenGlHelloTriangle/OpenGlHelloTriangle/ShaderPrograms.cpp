#include "ShaderPrograms.h"
#include <fstream>
#include <sstream>
#include <iostream>



void ShaderPrograms::LoadFromFile(const char * source, ShaderType sType)
{
	std::fstream file;
	std::stringstream sstream;
	file.open(source,std::ios::in);
	if (!file.good())
	{
		std::cerr << "Fialed to opne file with shader" << std::endl;
		return;
	}

	sstream << file.rdbuf();


	file.close();

	std::string str = sstream.str();

	const char * Ssource = str.c_str();

	std::cout << Ssource << std::endl;

	GLint success;
	GLchar error[512];

	m_shaderID = glCreateShader(sType);

	glShaderSource(m_shaderID, 1, &Ssource, NULL);
	glCompileShader(m_shaderID);

	glGetShaderiv(m_shaderID, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(m_shaderID, 512, NULL, error);
		std::cerr << "nie udalo sie skompilowac shadera: " << error << std::endl;
	}


}

ShaderPrograms::ShaderPrograms(const char * source, ShaderType sType)
	:shaderType(sType)
{
	LoadFromFile(source,sType);
}


ShaderPrograms::~ShaderPrograms()
{

}

GLuint ShaderPrograms::getShaderID()
{
	return m_shaderID;
}
