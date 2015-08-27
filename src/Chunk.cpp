/*
 * Chunk.cpp
 *
 *  Created on: 27. aug. 2015
 *      Author: larso
 */

#include "Chunk.h"
#include <stdexcept>

Chunk::Chunk(int x, int y, unsigned w, unsigned h)
{
    this->_x = x;
    this->_y = y;
    this->w = w;
    this->h = h;
}

void Chunk::Add(Block block)
{
    if(block.x() < _x || block.x() >= _x + (int)w
            || block.y() < _y || block.y() >= _y + (int)h)
    {
        throw std::out_of_range("Tried to insert block outside of chunk.");
    }
    auto iter = blocks.find(block);
    if(iter == blocks.end())
    {
        blocks.insert(block);
    }
}

const Block* Chunk::Get(int x, int y)
{
    Block block(x, y, "");
    auto iter = blocks.find(block);
    if(iter == blocks.end()) return nullptr;
    else return &(*iter);
}

void Chunk::Render(BlockRenderer& blockRenderer)
{
    for(auto i = blocks.begin(); i != blocks.end(); i++)
    {
        blockRenderer.RenderBlock(*i);
    }
}

int Chunk::x()
{
    return _x;
}

int Chunk::y()
{
    return _y;
}

unsigned Chunk::width()
{
    return w;
}

unsigned Chunk::height()
{
    return h;
}
