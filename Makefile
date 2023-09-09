all:
	cc -g -std=c89 tt.c -L/usr/local/lib -I/usr/local/include -lSDL2_image -lSDL2 -o tetris	
