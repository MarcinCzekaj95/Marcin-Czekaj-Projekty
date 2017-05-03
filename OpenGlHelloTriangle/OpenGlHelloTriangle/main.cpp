#include "Window.h"
#include "VAO.h"
#include "Shaders.h"
#include "glm-0.9.6.3\glm\glm\glm.hpp"



int main()
{
	Window * window = new Window(800, 600, "Hello Triangle");

	vertex vert[]
	{
		{ glm::vec3(0.5f,0.0f,0.0f)},
		{ glm::vec3(0.0f,0.5f,0.0)},
		{ glm::vec3(-0.5f,0.0f,0.0f)},
		{ glm::vec3(0.0f,-0.5f,0.0) },
	};

	GLuint indicies[]
	{
		0,1,2,
		0,3,2
	};

	GLuint indicies2[]
	{
		0,3,2
	};

	std::shared_ptr<ShaderPrograms> vs(new ShaderPrograms("GLSL.vlsl", vertexShader));
	std::shared_ptr<ShaderPrograms> fs(new ShaderPrograms("FLSL.flsl", fragmentShader));
	std::shared_ptr<ShaderPrograms> fs2(new ShaderPrograms("FLSL2.flsl", fragmentShader));

	VAO vao(new std::vector<vertex>(vert, std::end(vert)), new std::vector<GLuint>(indicies, std::end(indicies)));
	VAO vao2(new std::vector<vertex>(vert, std::end(vert)), new std::vector<GLuint>(indicies2, std::end(indicies2)));

	Shaders program(vs, fs);

	Shaders program2(vs, fs2);


	while (window->CheckWindowClose())
	{
		glfwPollEvents();
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(program.getProrgamID());
		glBindVertexArray(vao.getVAO());
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, NULL);
		glBindVertexArray(0);
		glUseProgram(program2.getProrgamID());
		glBindVertexArray(vao2.getVAO());
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT,NULL);
		glBindVertexArray(0);
		glfwSwapBuffers(window->getWindow());
	}



	return 0;
}