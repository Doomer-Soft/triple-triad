#pragma once

#include <SDL2/SDL.h>
#include "spr.h"

struct Board {
	int cards_drawn;
	SDL_Rect** rectangles;

};

typedef struct Board Board;

struct Mouse {
	int x;
	int y;
};

typedef struct Mouse Mouse;

void init_game();
