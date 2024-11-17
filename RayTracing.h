#pragma once
#include<vector>
//SDL 2
#include<SDL.h>

#include"Objects.h"

void Render(SDL_Renderer* renderer, int windowWidth, int windowHeight);
void RayTrace(std::vector<Object>& objects);