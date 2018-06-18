#include "Light.h"



Light::Light()
{
}
glm::vec3 lightPos1(1.2f, 1.0f, 2.0f);
void Light::render()
{
	std::cout << glGetError() << std::endl;
	UseShader();
	Camera *camera = new Camera();
	camera->Position = glm::vec3(0, 0, 10);

	glm::mat4 model, projection;

	model = glm::mat4();
	model = glm::translate(model, lightPos1);
	model = glm::scale(model, glm::vec3(0.2f));

	projection = glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 0.1f, 100.0f);
	std::cout << glGetError() << std::endl;
	shader->setMat4("model",model);
	shader->setMat4("projection", projection);
	shader->setMat4("view", camera->GetViewMatrix());

	glBindVertexArray(lightVAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	std::cout << glGetError() << std::endl;
}

void Light::InitVAOAndVBO()
{
	std::cout << glGetError() << std::endl;
	glGenVertexArrays(1, &lightVAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(lightVAO);
	// 2. 把我们的顶点数组复制到一个顶点缓冲中，供OpenGL使用
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// 4. 设定顶点属性指针
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	std::cout << glGetError() << std::endl;
}


Light::~Light()
{
}
