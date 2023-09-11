#include <string.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "spr.h"

extern SDL_Renderer* ren;

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
