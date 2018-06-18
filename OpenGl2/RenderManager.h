#pragma once
#include <map>
#include "Render.h"
class RenderManager
{
private:
	static RenderManager *renderManager;
	std::map<int, Render*> rendersMap;
public:
	RenderManager();
	void Register(int& index,Render* render);
	void Remove(const int & index);
	void Find(const int &index)const;
	void RenderAll()const;
	void RenderOne(const int &index)const;
	~RenderManager();
};

