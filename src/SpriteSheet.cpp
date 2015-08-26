/*
 * SpriteSheet.cpp
 *
 *  Created on: 24. aug. 2015
 *      Author: larso
 */

#include "SpriteSheet.h"
#include <stdexcept>

#include <cstdio>

SpriteSheet::SpriteSheet()
{
    sheet_texture = nullptr;
}

SpriteSheet::~SpriteSheet()
{
    if(sheet_texture != nullptr) SDL_DestroyTexture(sheet_texture);
}

void SpriteSheet::load(std::string bmp, std::string meta, SDL_Renderer* ren)
{
    if(ren == nullptr) throw std::invalid_argument("SDL renderer pointer was a null pointer.");
    SDL_Surface* surf = SDL_LoadBMP(bmp.c_str());
    if(surf == nullptr) throw std::runtime_error("Could not load sprite sheet bitmap file \"" + bmp + "\".");
    sheet_texture = SDL_CreateTextureFromSurface(ren, surf);
    SDL_FreeSurface(surf);
    if(sheet_texture == nullptr) throw std::runtime_error("Could not create the texture from the sprite sheet surface.");
    FILE* file = fopen(meta.c_str(), "r");
    if(!file) throw std::runtime_error("Could not open sprite meta file \"" + meta + "\"." );
    char namebuf[512];
    SDL_Rect rect;
    int res = fscanf(file, "%s = %d %d %d %d\n", namebuf, &rect.x, &rect.y, &rect.w, &rect.h);
    while(res != EOF)
    {
        std::string name(namebuf);
        sprites[name] = rect;
        res = fscanf(file, "%s = %d %d %d %d\n", namebuf, &rect.x, &rect.y, &rect.w, &rect.h);
    }
    fclose(file);
}

void SpriteSheet::render(std::string key, SDL_Rect* dst, SDL_Renderer* ren)
{
    if(ren == nullptr) throw std::invalid_argument("SDL renderer pointer was a null pointer.");
    SDL_Rect src = sprites[key];
    SDL_RenderCopy(ren, sheet_texture, &src, dst);
}
