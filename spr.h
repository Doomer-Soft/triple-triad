#pragma once

#include <SDL2/SDL.h>

struct Sprite {
	char* name;
	int x;
	int y;
	int w;
	int h;
	int points[4];
	int dragging;
	int isRendered;
	SDL_Texture* tex;
};

typedef struct Sprite Sprite;

Sprite* 	new_sprite(char*, char*);
SDL_Rect* create_rect(int);
Sprite* new_sprite(char*, char*);
