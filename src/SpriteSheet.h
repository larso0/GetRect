/*
 * SpriteSheet.h
 *
 *  Created on: 24. aug. 2015
 *      Author: larso
 */

#ifndef SRC_SPRITESHEET_H_
#define SRC_SPRITESHEET_H_

#include <SDL2/SDL.h>
#include <map>
#include <string>

class SpriteSheet
{
public:
    SpriteSheet();
    SpriteSheet(std::string sheetFile, std::string metaFile, SDL_Renderer* renderer);
    ~SpriteSheet();

    void load(std::string sheetFile, std::string metaFile, SDL_Renderer* renderer);
    SDL_Rect getSrc(std::string key);
    void render(std::string key, SDL_Rect* clip, SDL_Rect* dst, SDL_Renderer* ren);
private:
    SDL_Texture* sheetTexture;
    std::map<std::string, SDL_Rect> sprites;
    std::pair<std::string, SDL_Rect> cache;

    SDL_Rect& getSrcCache(std::string& key);
};

#endif /* SRC_SPRITESHEET_H_ */
