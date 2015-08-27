/*
 * BlockRenderer.h
 *
 *  Created on: 26. aug. 2015
 *      Author: larso
 */

#ifndef SRC_BLOCKRENDERER_H_
#define SRC_BLOCKRENDERER_H_

#include <SDL2/SDL.h>
#include "Block.h"
#include "SpriteSheet.h"

class BlockRenderer
{
public:
    int blockSize;

    BlockRenderer(SDL_Renderer* renderer);
    void SetBlockOrigin(SDL_Point blockOrigin);
    void SetPixelOrigin(SDL_Point pixelOrigin);
    void EnableWindow(SDL_Rect window);
    void DisableWindow();
    void RenderBlock(Block& block);

    SDL_Rect window();
    bool windowEnable();
    SDL_Point blockOrigin();
    SDL_Point pixelOrigin();

private:
    SpriteSheet sprites;
    SDL_Renderer* renderer;
    SDL_Rect _window;
    bool _windowEnable;
    SDL_Point _blockOrigin;
    SDL_Point _pixelOrigin;
};

#endif /* SRC_BLOCKRENDERER_H_ */
