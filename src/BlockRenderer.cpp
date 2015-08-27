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
    sprites.Load("textures/blocks.bmp", "textures/blocks.meta", renderer);
    blockSize = 16;
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
    SDL_Rect dst;
    dst.x = (block.x() + _blockOrigin.x) * blockSize + _pixelOrigin.x;
    dst.y = (block.y() + _blockOrigin.y) * blockSize + _pixelOrigin.y;
    dst.w = dst.h = blockSize;
    SDL_Rect src = sprites.GetSrc(block.type());
    if(_windowEnable)
    {
        int tmp = _window.x + _window.w;
        if(dst.x < _window.x)
        {
            src.x = ((_window.x - dst.x)*src.w)/blockSize;
            src.w -= src.x;
            dst.w -= _window.x - dst.x;
            dst.x = _window.x;
            if(src.w < 1 || dst.w < 1) return;
        }
        else if(dst.x > tmp - blockSize)
        {
            dst.w = tmp - dst.x;
            src.w = (dst.w*src.w)/blockSize;
            if(src.w < 1 || dst.w < 1) return;
        }

        tmp = _window.y + _window.h;
        if(dst.y < _window.y)
        {
            src.y = ((_window.y - dst.y)*src.h)/blockSize;
            src.h -= src.y;
            dst.h -= _window.y - dst.y;
            dst.y = _window.y;
            if(src.h < 1 || dst.h < 1) return;
        }
        else if(dst.y > tmp - blockSize)
        {
            dst.h = tmp - dst.y;
            src.h = (dst.h*src.h)/blockSize;
            if(src.h < 1 || dst.h < 1) return;
        }
    }
    sprites.Render(block.type(), &src, &dst, renderer);
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
