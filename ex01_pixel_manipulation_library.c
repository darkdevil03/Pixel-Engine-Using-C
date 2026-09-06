#include <stdio.h>
#include<stdlib.h>
#include <SDL3/SDL.h>

#define WIDTH 320
#define HEIGHT 200

uint32_t framebuffer[320*200];

int main(void) {
    SDL_Init(SDL_INIT_VIDEO );

    SDL_Window  *window = SDL_CreateWindow("SDL Window",WIDTH,HEIGHT,0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, nullptr);
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_XRGB8888, SDL_TEXTUREACCESS_TARGET, WIDTH, HEIGHT);

    framebuffer[0] = 0x00FF00;
    framebuffer[1] = 0xFF0000;
    framebuffer[2] = 0x00FF00;
    framebuffer[3] = 0xFF0000;
    framebuffer[4] = 0x00FF00;
    framebuffer[5] = 0xFF0000;

    while(true) {

        SDL_UpdateTexture(texture,nullptr,framebuffer,0);

        SDL_RenderClear(renderer);
        SDL_RenderTexture(renderer,texture,nullptr,nullptr);
        SDL_RenderPresent(renderer);

    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();


    return 0;
}
