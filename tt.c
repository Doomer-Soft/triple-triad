/* Tetris Clone */

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <time.h>
#include "tt.h"

SDL_Window* win;
SDL_Renderer* ren;
Sprite** sprites;

Sprite*
new_sprite(char* spr_name, char* flname)
{

	Sprite* spr;
	spr = malloc(sizeof(Sprite));
	spr->x = 0;
	spr->y = 0;
	spr->w = 0;
	spr->h = 0;
	spr->name = (char*)malloc(sizeof(spr_name));
	strcpy(spr->name, spr_name);
	spr->tex = IMG_LoadTexture(ren, flname);
	spr->dragging = 0;
	if ((SDL_QueryTexture(spr->tex, NULL, NULL, &spr->w, &spr->h) < 0)) {
		const char* error = SDL_GetError();
		SDL_Log("%s", error);
		exit(1);
	}

	return spr;
}

void
load_assets()
{

	int i;
	int total_length;
	char* tmp_name;
	char* concatenated;
	char* card_name;

	SDL_Log("Size of Sprites is %d", CARD_NUMBER);
	tmp_name = (char*) malloc(sizeof(char)*100);
	sprites = malloc(sizeof(Sprite*)*CARD_NUMBER);

	for (i = 0; i < CARD_NUMBER; i++) {
		int total_length = strlen(ASSET_PATH) + strlen(CARD_NAMES[i]) + 1;
		concatenated = (char*)malloc(sizeof(char)*total_length);

		if (concatenated == NULL) {
			perror("Memory allocation failed");
			exit(EXIT_FAILURE);
		}

		strcpy(concatenated, ASSET_PATH);
		strcat(concatenated, CARD_NAMES[i]);
		memcpy(tmp_name, CARD_NAMES[i], strlen(CARD_NAMES[i]));
		card_name = strtok(tmp_name, ".");
		sprites[i] = new_sprite(card_name,concatenated);

		free(concatenated);
		card_name = NULL;
	}
	free(tmp_name);
}


SDL_Rect*
create_rect(int v)
{

	SDL_Rect* r = malloc(sizeof(SDL_Rect));
	SDL_Log("%d\n", v);
	r->x = v%800;
	r->y = v%600;
	r->w = v%100;
	r->h = v%100;

	return r;
}

void
init_game()
{

}

int
main()
{
	uint8_t game_is_running;
	uint32_t counter;
	int i; 
	unsigned int seed = 0x12fa32a1; 
	Mouse* mouse;
	SDL_Rect* tmp;
	SDL_Event event;
	SDL_Rect** array;

	srand_deterministic(seed);

	mouse = malloc(sizeof(Mouse));
	mouse->x = 0;
	mouse->y = 0;
	counter = 0;
	game_is_running = 1;
	array = malloc(sizeof(SDL_Rect*)*100);


	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "this is an error");
	};

	SDL_CreateWindowAndRenderer(800, 600, 0, &win, &ren);
	SDL_SetWindowResizable(win, 1);

	load_assets();

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

				default:
					break;
				}
			}
			/* Update Mouse State */
			if (event.type == SDL_MOUSEMOTION) {
				SDL_GetMouseState(&mouse->x, &mouse->y);
				/*SDL_Log("%d - %d", mouse->x, mouse->y);*/
			}

		}

		SDL_SetRenderDrawColor(ren, 0x11, 0x11, 0x11, 0xff);
		SDL_RenderClear(ren);
		for (i = 0; i < counter; i++) {
			tmp = array[i];
			SDL_SetRenderDrawColor(ren, 0xff, tmp->x % 255, tmp->y % 255, 0xff);
			SDL_RenderFillRect(ren, tmp);
		}
		init_game();

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
