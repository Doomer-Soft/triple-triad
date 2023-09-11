#include <SDL2/SDL.h>

extern SDL_Window* win;
extern SDL_Renderer* ren;

void
init_game()
{

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "this is an error");
	};

	SDL_CreateWindowAndRenderer(800, 600, 0, &win, &ren);
	SDL_SetWindowResizable(win, 1);

}
