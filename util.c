#include <stdlib.h>
#include <string.h>
#include "world.h"
#include "spr.h"

extern const char* ASSET_PATH;
extern const char* CARD_NAMES[];
extern const int CARD_NUMBER;

Sprite**
load_assets(Sprite** sprites)
{

	int i;
	int total_length;
	char* tmp_name;
	char* concatenated;
	char* card_name;

	/* Sprites */
	tmp_name = (char*) malloc(sizeof(char)*100);

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

	/* Cursor */

	free(tmp_name);

	return sprites;
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
