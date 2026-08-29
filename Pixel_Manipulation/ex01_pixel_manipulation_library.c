#include <stdio.h>
#include <SDL3/SDL.h>

int main(void) {
    SDL_Init(SDL_INIT_VIDEO );

    SDL_Window  *window = SDL_CreateWindow("SDL Window", 320,200,SDL_WINDOWPOS_CENTERED);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    SDL_Texture *texture = SDL_CreateTexture(renderer,);

    uint32_t framebuffer[320*200];

    framebuffer[0] = 0x00FF00;

    SDL_UpdateTexture(texture,NULL,framebuffer,sizeof(framebuffer));

    SDL_RenderClear(renderer);
    SDL_RenderTexture(renderer,texture,framebuffer,sizeof(framebuffer));
    SDL_RenderPresent(renderer);


    return 0;
}
