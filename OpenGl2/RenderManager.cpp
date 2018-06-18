#include "RenderManager.h"



RenderManager::RenderManager()
{
	
}

void RenderManager::Register(int& index, Render * render)
{
	rendersMap[index] = render;
}

void RenderManager::Remove(const int & index)
{
}

void RenderManager::Find(const int & index) const
{
}

void RenderManager::RenderAll() const
{
}

void RenderManager::RenderOne(const int & index) const
{
}


RenderManager::~RenderManager()
{
}
