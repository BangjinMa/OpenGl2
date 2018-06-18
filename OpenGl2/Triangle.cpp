#include "Triangle.h"

Triangle::Triangle()
{
	
}

void  Triangle::render() {
	// draw our first triangle
	UseShader();
	
	xOffSet += 0.005;
	if (xOffSet > 2)
		xOffSet = 0;
	shader->setFloat("xOffSet", xOffSet);
	glBindVertexArray(arrayID); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
/*
初始化VAO和VBO
@Param index 绑定VAO和VBO的ID
*/
void Triangle::InitVAOAndVBO()
{
	unsigned int VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
	arrayID = VAO;
}

Triangle::~Triangle()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	std::cout << "Triangle 析构" << std::endl;
}
