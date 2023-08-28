#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>
#include <string.h>
#include <raymath.h>
#include <math.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

/* GLOBALS */
Vector2 mouse_pos;

const char* ASSET_PATH = "utils/cards/";
const char* CARD_NAMES[] = {"Abadon-Card.png", "Abyss-Worm.png", "Adamantoise-Card.png", "Alexander-Card.png", "Anacondaur-Card.png", "Angelo-Card.png", "Armadodo-Card.png", "BGH251F2-Card.png", "Bahamut-Card.png", "Behemoth-Card.png", "Belhelmel-Card.png", "Biggs,-Wedge-Card.png", "Bite-Bug-Card.png", "Blitz-Card.png", "Blobra-Card.png", "Blood-Soul-Card.png", "Blue-Dragon-Card.png", "Bomb-Card.png", "Buel-Card.png", "Cactuar-Card.png", "Carbuncle-Card.png", "Caterchipillar-Card.png", "Catoblepas-Card.png", "Cerberus-Card.png", "Chicobo-Card.png", "Chimera-Card.png", "Chubby-Chocobo-Card.png", "Cockatrice-Card.png", "Creeps-Card.png", "Death-Claw-Card.png", "Diablos-Card.png", "Doomtrain-Card.png", "Edea-Card.png", "Eden-Card.png", "Elastoid-Card.png", "Elnoyle-Card.png", "Elvoret-Card.png", "Fastitocalon-Card.png", "Fastitocalon-F-Card.png", "Forbidden-Card.png", "Fujin,-Raijin-Card.png", "Funguar-Card.png", "GIM47N-Card.png", "Gargantua-Card.png", "Gayla-Card.png", "Geezard-Card.png", "Gerogero-Card.png", "Gesper-Card.png", "Gilgamesh-Card.png", "Glacial-Eye-Card.png", "Granaldo-Card.png", "Grand-Mantis-Card.png", "Grat-Card.png", "Grendel-Card.png", "Hexadragon-Card.png", "Ifrit-Card.png", "Iguion-Card.png", "Imp-Card.png", "Iron-Giant-Card.png", "Irvine-Card.png", "Jelleye-Card.png", "Jumbo-Cactuar-Card.png", "Kiros-Card.png", "Krysta-Card.png", "Laguna-Card.png", "Leviathan-Card.png", "Malboro-Card.png", "Mesmerize-Card.png", "MiniMog-Card.png", "Minotaur-Card.png", "Mobile-Type-8-Card.png", "Ochu-Card.png", "Odin-Card.png", "Oilboyle-Card.png", "Pandemona-Card.png", "Phoenix-Card.png", "Propagator-Card.png", "PuPu-Card.png", "Quezacotl-Card.png", "Quistis-Card.png", "Red-Bat-Card.png", "Red-Giant-Card.png", "Rinoa-Card.png", "Ruby-Dragon-Card.png", "SAM08G-Card.png", "Sacred-Card.png", "Seifer-Card.png", "Selphie-Card.png", "Shiva-Card.png", "Shumi-Tribe-Card.png", "Siren-Card.png", "Snow-Lion-Card.png", "Sphinxara-Card.png", "Squall-Card.png", "T-Rexaur-Card.png", "Thrustaevis-Card.png", "Tiamat-Card.png", "Tonberry-Card.png", "Tonberry-King-Card.png", "Torama-Card.png", "Trauma-Card.png", "Tri-Face-Card.png", "Tri-Point-Card.png", "Turtapod-Card.png", "Ultima-Weapon-Card.png", "Vysage-Card.png", "Ward-Card.png", "Wendigo-Card.png", "X-ATM092-Card.png", "Zell-Card.png"};

struct Sprite {
	char* name;
	int x;
	int y;
	Texture2D tex;
	int points[4];

	bool dragging;
	bool isRendered;
};

struct Board {

};

typedef struct Sprite Sprite;

Sprite s;
Sprite* sprites;

void
input()
{
	Vector2 tmp;

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		mouse_pos = GetMousePosition();
		s.dragging = !s.dragging;
		TraceLog(LOG_ALL, "%f - %f\n", mouse_pos.x, mouse_pos.y);
	}

	//if (IsKeyPressed(KEY_A)) {
	//	TraceLog(LOG_ALL, "%s\n", CARD_NAMES[0]);
	//	TraceLog(LOG_ALL, "%d\n", sizeof(CARD_NAMES) / sizeof(CARD_NAMES[0]));
	//}

	if (s.dragging) {
		tmp = GetMousePosition();
		int dx = mouse_pos.x - tmp.x;
		int dy = mouse_pos.y - tmp.y;
		if (!Vector2Equals(mouse_pos, tmp)) {
			s.x -= dx;
			s.y -= dy;
		} 	
		mouse_pos.x = tmp.x;
		mouse_pos.y = tmp.y;
	}
	
}

Sprite
new_sprite(char* spr_name, char* flname)
{

	Sprite spr;

	spr.x = 0;
	spr.y = 0;
	spr.name = spr_name;
	spr.tex = LoadTexture(flname);
	spr.dragging = 0;

	return spr;
}

void
init()
{
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Triple-Triad");
	SetWindowState(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	SetTraceLogLevel(LOG_ALL);
}

void
load_assets()
{

	int i;
	int size = sizeof(CARD_NAMES) / sizeof(CARD_NAMES[0]);
	char* tmp_name = (char*) malloc(sizeof(char)*100);
	sprites = (Sprite*) malloc(sizeof(Sprite*)*size);

	for (i = 0; i < size; i++) {
		int totalLength = strlen(ASSET_PATH) + strlen(CARD_NAMES[i]) + 1;
		char* concatenated = (char*)malloc(totalLength);

		if (concatenated == NULL) {
				perror("Memory allocation failed");
				exit(EXIT_FAILURE);
		}

		strcpy(concatenated, ASSET_PATH);
		strcat(concatenated, CARD_NAMES[i]);
		TraceLog(LOG_ALL, "%s", concatenated);
		memcpy(tmp_name, CARD_NAMES[i], strlen(CARD_NAMES[i]));
		char* card_name = strtok(tmp_name, ".");
		sprites[i] = new_sprite(card_name,concatenated);
	}
}

void
drawing()
{
	BeginDrawing();
		ClearBackground(BLACK);
		//DrawTextureEx(sprites[2].tex, (Vector2){sprites[2].x, sprites[2].y}, 0 , 1.5, WHITE);
	EndDrawing();
}

int
main()
{
	init();
	load_assets();
	while (!WindowShouldClose()) {
		input();
		drawing();
	}
	CloseWindow();
}
