/*
 * Chunk.cpp
 *
 *  Created on: 27. aug. 2015
 *      Author: larso
 */

#include "Chunk.h"
#include <algorithm>
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
    std::list<Block>& list = GetBlockList(block.type());
    std::list<Block>::iterator iter = std::find_if(
            list.begin(),list.end(),
            [&block](Block& b){ return block.x() == b.x() && block.y() == b.y(); }
    );
    if(iter == list.end())
    {
        list.push_back(block);
    }
}

void Chunk::Render(BlockRenderer& blockRenderer)
{
    for(auto i = blocks.begin(); i != blocks.end(); i++)
    {
        for(auto j = i->begin(); j != i->end(); j++)
        {
            blockRenderer.RenderBlock(*j);
        }
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

std::list<Block>& Chunk::GetBlockList(std::string key)
{
    std::list<std::list<Block> >::iterator iter = blocks.begin();
    for(; iter != blocks.end() && iter->begin()->type() != key; iter++);
    if(iter == blocks.end())
    {
        blocks.push_back(std::list<Block>());
        return blocks.back();
    }
    return *iter;
}
