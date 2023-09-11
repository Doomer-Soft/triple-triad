all:
	cc -O3 -g -std=c89 *.c -L/usr/local/lib -I/usr/local/include -lSDL2_image -lSDL2 -o bin/tt	
