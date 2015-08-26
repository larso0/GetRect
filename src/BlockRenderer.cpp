/*
 * BlockRenderer.cpp
 *
 *  Created on: 26. aug. 2015
 *      Author: larso
 */

#include "BlockRenderer.h"

BlockRenderer::BlockRenderer(SDL_Renderer* renderer)
{
    this->renderer = renderer;
    sprites.load("textures/blocks.bmp", "textures/blocks.meta", renderer);
    _windowEnable = false;
    _blockOrigin.x = 0;
    _blockOrigin.y = 0;
    _pixelOrigin.x = 0;
    _pixelOrigin.y = 0;
}

void BlockRenderer::SetBlockOrigin(SDL_Point blockOrigin)
{
    _blockOrigin = blockOrigin;
}

void BlockRenderer::SetPixelOrigin(SDL_Point pixelOrigin)
{
    _pixelOrigin = pixelOrigin;
}

void BlockRenderer::EnableWindow(SDL_Rect window)
{
    _window = window;
    _windowEnable = true;
}

void BlockRenderer::DisableWindow()
{
    _windowEnable = false;
}

void BlockRenderer::RenderBlock(Block& block)
{
    SDL_Rect src, dst;
    dst.x = (block.x() + _blockOrigin.x) * BLOCK_SIZE + _pixelOrigin.x;
    dst.y = (block.y() + _blockOrigin.y) * BLOCK_SIZE + _pixelOrigin.y;
    dst.w = dst.h = src.w = src.h = BLOCK_SIZE;
    src.x = src.y = 0;
    if(_windowEnable)
    {
        int tmp = _window.x + _window.w;
        if(dst.x < _window.x)
        {
            src.x = _window.x - dst.x;
            src.w -= src.x;
            if(src.w < 1) return;
        }
        else if(dst.x > tmp - BLOCK_SIZE)
        {
            src.w -= tmp - dst.x;
            if(src.w < 1) return;
        }

        tmp = _window.y + _window.h;
        if(dst.y < _window.y)
        {
            src.y = _window.y - dst.y;
            src.h -= src.y;
            if(src.h < 1) return;
        }
        else if(dst.y > tmp - BLOCK_SIZE)
        {
            src.h -= tmp - dst.y;
            if(src.h < 1) return;
        }
    }
    sprites.render(block.type(), &src, &dst, renderer);
}

SDL_Rect BlockRenderer::window()
{
    return _window;
}

bool BlockRenderer::windowEnable()
{
    return _windowEnable;
}

SDL_Point BlockRenderer::blockOrigin()
{
    return _blockOrigin;
}

SDL_Point BlockRenderer::pixelOrigin()
{
    return _pixelOrigin;
}
