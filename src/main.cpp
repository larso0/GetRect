/*
 * main.cpp
 *
 *  Created on: 24. aug. 2015
 *      Author: larso
 */

#include <iostream>
#include <SDL2/SDL.h>
#include "Block.h"
#include "BlockRenderer.h"

int main(int argc, char** argv)
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* win = SDL_CreateWindow("test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 200, 200, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    BlockRenderer blockRenderer(ren);
    Block block(10, 10, "WATER_FALLING");

    bool running = true;
    while(running)
    {
        SDL_Event e;
        while(SDL_PollEvent(&e))
        {
            switch(e.type)
            {
            case SDL_QUIT:
                running = false;
                break;
            default:;
            }
        }

        SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
        SDL_RenderClear(ren);
        blockRenderer.RenderBlock(block);
        SDL_RenderPresent(ren);
    }
    return 0;
}
