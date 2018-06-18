#include "Render.h"



Render::Render()
{

}


void Render::CompileShader(const char * vertexShaderPath, const char * fragmentShaderPath)
{
	shader = new Shader(vertexShaderPath,fragmentShaderPath);
	
}

void Render::UseShader() {
	shader->use();
}

void Render::render()
{
}

Render::~Render()
{
	delete(shader);
}
