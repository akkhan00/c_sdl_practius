// for initializing and shutdonw functions
#include <SDL2/SDL.h>

// for rendering images and graphics on screen
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>

// for using SDL_Dely() functions
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>

int main(int argc, char *argv[]){
  // return zero on success else non-zero
  if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
    printf("error initializing sdl:\n"); 
  }
  SDL_Window *win = SDL_CreateWindow("Gamer",
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    1000, 1000, 0);
  // triggers the program that control your graphics hardware and set flags
  Uint32 render_flags = SDL_RENDERER_ACCELERATED;

  // creates a renderer to render our images
  SDL_Renderer * rend = SDL_CreateRenderer(win, -1, render_flags);

  // create a surface to load an image into the main memory
  SDL_Surface * surface;

  // please provide a path to your image
  surface = IMG_Load("./img/first.png");

  // loads image to our graphics hardware memory.
  SDL_Texture * tex = SDL_CreateTextureFromSurface(rend, surface);

  // clears main-memory
  SDL_FreeSurface(surface);

  // let us contorl our image position
  // so that we can move it with our keyboard.
  SDL_Rect dest;

  // connects our texture with dest to contorl posiition
  SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h);

  // adjust height and width of our image box.
  dest.w /=6;
  dest.h /= 6;

  // sets initital x-position of object
  dest.x = (1000 - dest.w)/2;

  // sets initital y-position of object
  dest.y = (1000 - dest.h)/2;

  // controls animation loop
  int close = 0;

  int speed = 300;

  // animation loop
  while (!close){
    SDL_Event event;
    
    // Events managment
    while (SDL_PollEvent(&event)){
      switch(event.type){
        case SDL_QUIT:
          // handling of close button
          close = 1;
          break;
        
        // handle escape key close
        case SDL_KEYDOWN:

          // keyboard API for key pressed
          switch(event.key.keysym.scancode){
          
            // handle escape 
            case SDL_SCANCODE_ESCAPE:
              close = 1;
              break;
            case SDL_SCANCODE_W:
            case SDL_SCANCODE_UP:
              dest.y -= speed / 30;
              break;

            case SDL_SCANCODE_A:
            case SDL_SCANCODE_LEFT:
              dest.x -= speed/30;
              break;
            
            case SDL_SCANCODE_S:
            case SDL_SCANCODE_DOWN:
              dest.y += speed/30;
              break;

            case SDL_SCANCODE_D:
            case SDL_SCANCODE_RIGHT:
              dest.x += speed / 30;
              break;

            default:
              break;
          }

      }
    }

    // right boundary
    if (dest.x + dest.w > 1000){
      dest.x = 1000 - dest.w;
    }

    // let boundary
    if (dest.x < 0)
      dest.x = 0;

    // bottom boundary
    if(dest.y + dest.h > 1000){
      dest.y = 1000 - dest.h;
    }

    // upper boundary
    if(dest.y < 0)
      dest.y = 0;
    

    // clears the screen
    SDL_RenderClear(rend);
    SDL_RenderCopy(rend, tex, NULL, &dest);

    // triggers the double buffers
    // for multiple rendering
    SDL_RenderPresent(rend);

    // calculates to 60 fps
    SDL_Delay(1000/60);
  }

  // destroy texture
  SDL_DestroyTexture(tex);

  // destroy renderer
  SDL_DestroyRenderer(rend);

  // destory windows
  SDL_DestroyWindow(win);

  // close SDL
  SDL_Quit();

  return 0;
}

