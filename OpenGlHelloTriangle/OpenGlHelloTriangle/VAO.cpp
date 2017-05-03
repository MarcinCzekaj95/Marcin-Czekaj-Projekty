#include "VAO.h"



void VAO::Init()
{
	glGenVertexArrays(1, &m_VAO);

	glGenBuffers(1, &m_VBO);
	glGenBuffers(1, &m_EBO);


	glBindVertexArray(m_VAO);

	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferDataV(GL_ARRAY_BUFFER, *m_vertexBuffer, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
	glBufferDataV(GL_ELEMENT_ARRAY_BUFFER, *m_elementBuffer, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (GLvoid*)0);

	glEnableVertexAttribArray(0);

	glBindVertexArray(0);

	
}

VAO::VAO(std::vector<vertex> * vBuf, std::vector<GLuint> * eBuf)
	:m_vertexBuffer(vBuf),m_elementBuffer(eBuf)
{
	Init();
}

GLuint VAO::getVAO()
{
	return m_VAO;
}

GLuint VAO::getVBO()
{
	return m_VBO;
}

GLuint VAO::getEBO()
{
	return m_EBO;
}


VAO::~VAO()
{
	glDeleteVertexArrays(1, &m_VAO);
	glDeleteBuffers(1, &m_VBO);
	glDeleteBuffers(1, &m_EBO);
}
