/*
 * main.cpp
 *
 *  Created on: 24. aug. 2015
 *      Author: larso
 */

#include <iostream>
#include <SDL2/SDL.h>

using std::cout;

int main(int argc, char** argv)
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* win = SDL_CreateWindow("test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 200, 200, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    Uint32 time = SDL_GetTicks();

    bool running = true;
    while(running)
    {
        //Handle events
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
                }
                break;
            default:;
            }
        }

        //Calculate frame delta time in seconds
        Uint32 ntime = SDL_GetTicks();
        float delta = (float)(ntime-time)/1000.f;
        time = ntime;

        //Calculate game physics placeholder

        //Render frame
        SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
        SDL_RenderClear(ren);

        //Present the frame
        SDL_RenderPresent(ren);
    }
    return 0;
}
