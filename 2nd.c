#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>

int main(int argc, char *argv[]){
  SDL_Init(SDL_INIT_EVERYTHING);

  SDL_Window *win = SDL_CreateWindow("hello world from me",
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    400,400, 0);
  Uint32 render_flag = SDL_RENDERER_ACCELERATED;
  SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, render_flag);

  while (1);
  return 0;
}
