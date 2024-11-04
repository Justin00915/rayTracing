#pragma once
#include<vector>
#include<math.h>

#include"Object.h"
class Scene
{
public:
	Scene() {}
	void AddObject(Object object);
	void AddObjects(std::vector<Object> objects);

	std::vector<Object> objects;
};

void Scene::AddObject(Object object)
{
	objects.push_back(object);
}

void Scene::AddObjects(std::vector<Object> objects)
{
	this->objects.insert(this->objects.end(), objects.begin(), objects.end());
}