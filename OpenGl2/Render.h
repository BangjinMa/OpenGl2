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
	��ʼ��Shader
	@Param index ��Shader������ֵ
	@Param vertexShaderSource ������ɫ���Ĵ���
	@Param fragmentShaderSource Ƭ����ɫ���Ĵ���
	*/
	void CompileShader(const char * vertexShaderPath, const char * fragmentShaderPath);
	void UseShader();
	virtual void render() = 0;
	virtual void InitVAOAndVBO() = 0;
	virtual ~Render();
};


#endif //RENDER_H
