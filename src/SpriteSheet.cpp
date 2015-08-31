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
    sheetTexture = nullptr;
}

SpriteSheet::~SpriteSheet()
{
    if(sheetTexture != nullptr) SDL_DestroyTexture(sheetTexture);
}

void SpriteSheet::load(std::string bmp, std::string meta, SDL_Renderer* ren)
{
    if(ren == nullptr) throw std::invalid_argument("SDL renderer pointer was a null pointer.");
    SDL_Surface* surf = SDL_LoadBMP(bmp.c_str());
    if(surf == nullptr) throw std::runtime_error("Could not load sprite sheet bitmap file \"" + bmp + "\".");
    sheetTexture = SDL_CreateTextureFromSurface(ren, surf);
    SDL_FreeSurface(surf);
    if(sheetTexture == nullptr) throw std::runtime_error("Could not create the texture from the sprite sheet surface.");
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

SDL_Rect SpriteSheet::getSrc(std::string key)
{
    SDL_Rect& src = getSrcCache(key);
    return { 0, 0, src.w, src.h };
}

SDL_Rect& SpriteSheet::getSrcCache(std::string& key)
{
    if(cache.first != key)
    {
        auto iter = sprites.find(key);
        if(iter != sprites.end()) cache = *iter;
        else throw std::runtime_error("No match for sprite with key \"" + key + "\".");
    }
    return cache.second;
}

void SpriteSheet::render(std::string key, SDL_Rect* clip, SDL_Rect* dst, SDL_Renderer* ren)
{
    if(ren == nullptr) throw std::invalid_argument("SDL renderer pointer was a null pointer.");
    SDL_Rect src = getSrcCache(key);
    if(clip != nullptr)
    {
        src.w = clip->w;
        src.h = clip->h;
        src.x += clip->x;
        src.y += clip->y;
    }
    SDL_RenderCopy(ren, sheetTexture, &src, dst);
}
