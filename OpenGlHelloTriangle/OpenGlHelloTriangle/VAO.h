#include <GL\glew.h>
#include <glm.hpp>
#include <vector>
#pragma once

template<typename T>
void glBufferDataV(GLenum target, const std::vector<T> & buffer, GLenum type)
{
	glBufferData(target, sizeof(T)*buffer.size(), &buffer[0], type);
}


struct vertex
{
	glm::vec3 position;
};

class VAO
{
	void Init();

	GLuint m_VAO;
	GLuint m_VBO;
	GLuint m_EBO;

	std::vector<vertex> * m_vertexBuffer;
	std::vector<GLuint> * m_elementBuffer;

public:

	VAO(std::vector<vertex> * vBuf, std::vector<GLuint> * eBuf);

	GLuint getVAO();

	GLuint getVBO();

	GLuint getEBO();

	~VAO();
};

