#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Render.h"
class Triangle :public Render
{
private:
	float vertices[18] = {
		-1.0f,-1.0f, 0.0f, 0.0f,0.0f, 1.0f, // left  
		0.5f, -0.5f, 0.0f, 0.0f,1.0f, 0.0f, // right 
		0.0f,  0.5f, 0.0f, 1.0f,0.0f, 0.0f // top   
	};
	unsigned int VBO, VAO;
	float xOffSet = 0.0f;
public:
	Triangle();
	void render();
	void InitVAOAndVBO();
	~Triangle();
};
#endif //MAENGINE_LEARNOPENGL1_H