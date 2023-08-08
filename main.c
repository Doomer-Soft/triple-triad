#include <stdio.h>
#include <raylib.h>
//#include <raymath.h>

#include "assets/edea.h"
#define VARNAME(a) #a

/* GLOBALS */
Texture2D edeatex;
Image img;
Vector2 mouse_pos;

struct Sprite {
	char* name;
	int x;
	int y;
	Texture2D tex;
	bool dragging;
};

typedef struct Sprite Sprite;

Sprite s;
Sprite sprites[10];

extern struct Asset{};

extern struct Asset* get_assets();

void
input()
{
	Vector2 tmp;

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		mouse_pos = GetMousePosition();
		s.dragging = !s.dragging;
		TraceLog(LOG_ALL, "%f - %f\n", mouse_pos.x, mouse_pos.y);
	}

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
new_sprite(char* name)
{

	Image tmp;
	Sprite spr;

	tmp = LoadImageFromMemory(".png", EDEA_CARD, sizeof(EDEA_CARD));
	spr.x = 10;
	spr.y = 10;
	spr.name = name;
	spr.tex = LoadTextureFromImage(tmp);
	spr.dragging = 0;

	return spr;
}

void
init()
{
	InitWindow(800, 600, "Hello");
	SetWindowState(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	SetTraceLogLevel(LOG_ALL);
}

void
load_assets()
{
	s = new_sprite(VARNAME(EDEA_CARD));
	TraceLog(LOG_ALL, "%s", s.name);

	//img = LoadImageFromMemory(".png", VARNAME(EDEA_CARD), sizeof(EDEA_CARD));
	//Texture2D edeatex = LoadTextureFromImage(img);
	////SetTextureFilter(edeatex, TEXTURE_FILTER_BILINEAR);
	//s = (Sprite){VARNAME(EDEA_CARD), 10, 10, edeatex, (bool)0};
}

void
DrawTextures()
{

}

void
drawing()
{
	BeginDrawing();
		ClearBackground(BLACK);
		DrawTextures();
		DrawTextureEx(s.tex, (Vector2){s.x, s.y}, 0 , 1.5, WHITE);
	EndDrawing();
}

int
main()
{
	struct Asset* ass = get_assets();
	init();
	load_assets();
	while (!WindowShouldClose()) {
		input();
		drawing();
	}
	UnloadTexture(edeatex);
	CloseWindow();
}
