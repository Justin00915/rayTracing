#include<thread>

#include"RayTracing.h"

void Render(SDL_Renderer* renderer, const int windowWidth, const int windowHeight)
{
	for (int y = 0; y < windowHeight; y++)
	{
		for (int x = 0; x < windowWidth; x++)
		{
			SDL_SetRenderDrawColor(renderer, x, y, x * y, 255);
			SDL_RenderPoint(renderer, x, y);
		}
	}
}