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
#include "Chunk.h"

int main(int argc, char** argv)
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* win = SDL_CreateWindow("test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 200, 200, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    Chunk chunk(0, 0, 10, 10);
    chunk.Add(Block(0, 5, "DIRT_SURFACE_GRASS"));
    chunk.Add(Block(1, 5, "DIRT_SURFACE_GRASS"));
    chunk.Add(Block(0, 6, "DIRT"));
    chunk.Add(Block(1, 6, "DIRT"));
    BlockRenderer blockRenderer(ren);
    blockRenderer.EnableWindow({0, 0, 200, 200});

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
            case SDL_WINDOWEVENT:
                if(e.window.event== SDL_WINDOWEVENT_RESIZED)
                {
                    blockRenderer.EnableWindow({0, 0, e.window.data1, e.window.data2});
                }
                break;
            default:;
            }
        }

        SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
        SDL_RenderClear(ren);
        chunk.Render(blockRenderer);
        SDL_RenderPresent(ren);
    }
    return 0;
}
