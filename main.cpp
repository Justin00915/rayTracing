#include<SDL3/SDL.h>
#include<math.h>

void Run();
void Render();
void HandleEvents(bool& running);

const int WINDOW_WIDTH = 300;
const int WINDOW_HEIGHT = 300;

double fps = 15;
double timestep = 1000 / fps;

SDL_Event event;
SDL_Renderer* renderer;
SDL_Window* window;

int main()
{
	SDL_CreateWindowAndRenderer("rayTracing", WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer);

	Run();
}

void Run()
{
	bool running = true;
	while (running)
	{
		HandleEvents(running);

		//Perform processing

		Render();

		SDL_Delay((Uint32)timestep);
	}
}

void Render()
{
	SDL_RenderClear(renderer);

	//Render

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