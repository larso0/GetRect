/*
 * SpriteSheet.h
 *
 *  Created on: 24. aug. 2015
 *      Author: larso
 */

#ifndef SRC_SPRITESHEET_H_
#define SRC_SPRITESHEET_H_

#include <SDL2/SDL.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>

class SpriteSheet
{
public:
    SpriteSheet();
    ~SpriteSheet();

    void load(std::string sheet, std::string meta, SDL_Renderer* ren);

    void render(std::string key, SDL_Rect* dst, SDL_Renderer* ren);
private:

    SDL_Texture* sheet_texture;
    std::map<std::string, SDL_Rect> sprites;
};

#endif /* SRC_SPRITESHEET_H_ */
