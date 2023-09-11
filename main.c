/* Triple Triad Clone */

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <time.h>

#include "spr.h"
#include "world.h"
#include "util.h"

SDL_Window* win;
SDL_Renderer* ren;
SDL_Event event;
Mouse* mouse;

extern const int CARD_NUMBER;

int
main()
{
	uint32_t counter;
	int i; 
	unsigned int seed = 0x12fa32a1; 

	SDL_Rect* tmp;
	SDL_Rect** array;
	Sprite** sprites;

	srand_deterministic(seed);

	mouse = malloc(sizeof(Mouse));
	mouse->x = 0;
	mouse->y = 0;
	counter = 0;
	array = malloc(sizeof(SDL_Rect*)*100);
	sprites = malloc(sizeof(Sprite*)*CARD_NUMBER);

	init_game();
	load_assets(sprites);

	while (game_is_running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN) {
				SDL_KeyboardEvent ke = event.key;
				switch(ke.keysym.sym) {
					case SDLK_s:
						array[counter++] = create_rect(rand_r(&seed));
						break;
					case SDLK_q:
						game_is_running = 0;
						break;
					case SDLK_UP:
						SDL_Log("You pressed UP");
						break;
					case SDLK_LEFT:
						SDL_Log("You pressed LEFT");
						break;
					case SDLK_DOWN:
						SDL_Log("You pressed DOWN");
						break;
					case SDLK_RIGHT:
						SDL_Log("You pressed RIGHT");
						break;
					default:
						break;
				}
			}
			if (event.type == SDL_MOUSEMOTION) {
				SDL_GetMouseState(&mouse->x, &mouse->y);
			}
		}

		SDL_SetRenderDrawColor(ren, 0x11, 0x11, 0x11, 0xff);
		SDL_RenderClear(ren);
		for (i = 0; i < counter; i++) {
			tmp = array[i];
			SDL_SetRenderDrawColor(ren, 0xff, tmp->x % 255, tmp->y % 255, 0xff);
			SDL_RenderFillRect(ren, tmp);
		}

		SDL_RenderCopy(ren, sprites[0]->tex, NULL, &(SDL_Rect){10, 10, sprites[0]->w, sprites[0]->h});
		SDL_RenderPresent(ren);
		SDL_Delay(33);
	}

	for (i = 0; i<counter;i++) {
		free(array[i]);
	}

	for (i = 0; i<110;i++) {
		SDL_DestroyTexture(sprites[i]->tex);
		free(sprites[i]->name);
		free(sprites[i]);
	}

	free(sprites);
	free(array);
	free(mouse);

	SDL_DestroyWindow(win);
	SDL_DestroyRenderer(ren);
	SDL_Quit();

	return 0;
}
