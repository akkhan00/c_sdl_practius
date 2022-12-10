gcc -o build/game main.c $(pkg-config --cflags --libs sdl2) -lSDL2_image

./build/game
