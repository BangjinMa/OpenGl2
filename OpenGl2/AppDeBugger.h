#pragma once

#ifndef APPDEBUGGER_H
#define APPDEBUGGER_H

#include <glad/glad.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include "Triangle.h"
#include "RectangleRender.h"
#include "Light.h"

class AppDebugger
{
private:
	static AppDebugger * appDebuger;
	unsigned int width;
	unsigned int height;
protected:
	int	init();
	AppDebugger();

public:
	static AppDebugger* getInstance();
	void processInput(GLFWwindow *window);
	void Update(GLFWwindow *window);
	void SetWindows(int SCR_WIDTH, int SCR_HEIGHT);
	void ShowWindows();
	~AppDebugger();
};

#endif //MAENGINE_LEARNOPENGL1_H
