#include <stdint.h>
#include <stdio.h>
#include<stdlib.h>
#include <SDL3/SDL.h>

#define WIDTH 320
#define HEIGHT 200

uint32_t framebuffer[320*200];

int main(void) {
    if (!SDL_Init(SDL_INIT_VIDEO )) {
        fprintf(stdin,"SDL_Init is failed %s\n",SDL_GetError());
        return EXIT_FAILURE;
    }

    printf("SDL_Init is Sucess %s\n",SDL_GetError());
    SDL_Quit();

    return EXIT_SUCCESS;
}
