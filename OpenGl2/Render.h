#pragma once
#ifndef RENDER_H
#define RENDER_H
#include <iostream>
#include <glad/glad.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include "Shader.h"
#include "stb_image.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Render
{
protected:
	Shader * shader;
	unsigned int arrayID;
public:
	Render();
	/*
	初始化Shader
	@Param index 绑定Shader的特征值
	@Param vertexShaderSource 顶点着色器的代码
	@Param fragmentShaderSource 片段着色器的代码
	*/
	void CompileShader(const char * vertexShaderPath, const char * fragmentShaderPath);
	void UseShader();
	virtual void render() = 0;
	virtual void InitVAOAndVBO() = 0;
	virtual ~Render();
};


#endif //RENDER_H
