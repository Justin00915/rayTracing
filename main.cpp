#define SDL2
#ifdef SDL2
#include<SDL.h>
#endif // SDL2

//#define SDL3
#ifdef SDL3
#include<SDL3/SDL.h>
#endif // SDL3

#include<math.h>
#include<iostream>



#include"RayTracing.h"

void Run();
void GraphicsStep();
void HandleEvents(bool& running);

const int WINDOW_WIDTH = 1000;
const int WINDOW_HEIGHT = 600;

double fps = 15;
double timestep = 1000 / fps;

SDL_Event event;
SDL_Renderer* renderer;
SDL_Window* window;

int main()
{
#ifdef SDL2
	SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer);
	SDL_SetWindowTitle(window, "RayTracing SDL 2");
#endif // SDL2

#ifdef SDL3
	SDL_CreateWindowAndRenderer("RayTracing SDL 3", WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer);
#endif // SDL3

	

	Run();
}

void Run()
{
	
	bool running = true;
	while (running)
	{
		HandleEvents(running);
		for (int y = 0; y < WINDOW_HEIGHT; y++)
		{
			for (int x = 0; x < WINDOW_WIDTH; x++)
			{
				SDL_SetRenderDrawColor(renderer, x, y, x * y, 255);
				SDL_RenderPoint(renderer, x, y);
			}
		}

		std::cout << "Rendering pass complete" << std::endl;
		SDL_RenderPresent(renderer);

		////Perform processing

		//GraphicsStep();
	}
}

void GraphicsStep()
{
	SDL_RenderClear(renderer);

	Render(renderer, WINDOW_WIDTH, WINDOW_HEIGHT);
	SDL_RenderPresent(renderer);
}

void HandleEvents(bool& running)
{
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_EVENT_QUIT:
			running = false;
			break;
		case SDL_EVENT_KEY_DOWN:
			switch (event.key.key)
			{
			case SDLK_ESCAPE:
				running = false;
				break;
			}
		}
	}
}