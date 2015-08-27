/*
 * Chunk.cpp
 *
 *  Created on: 27. aug. 2015
 *      Author: larso
 */

#include "Chunk.h"
#include <stdexcept>
#include <cstdio>

Chunk::Chunk()
{
    _x = 0;
    _y = 0;
    w = 0;
    h = 0;
}

Chunk::Chunk(int x, int y, unsigned w, unsigned h)
{
    _x = x;
    _y = y;
    this->w = w;
    this->h = h;
}

void Chunk::Load(std::string fileName)
{
    if(blocks.size() > 0) throw std::runtime_error("Tried to load chunk file after blocks have been added.");
    FILE* file = fopen(fileName.c_str(), "r");
    if(file == nullptr) throw std::runtime_error("Could not open chunk file \"" + fileName + "\".");

    int xpos = 0, ypos = 0;
    char nameBuf[512];
    int tmp = fscanf(file, "%d %d %d %d\n", &_x, &_y, &w, &h);
    if(tmp < 4)
    {
        fclose(file);
        throw std::runtime_error("Invalid chunk format.");
    }
    char c;
    tmp = fscanf(file, "%c", &c);
    while(tmp != EOF)
    {
        if(c == ':')
        {
            tmp = fscanf(file, "%d %d %s\n", &xpos, &ypos, nameBuf);
            if(tmp < 3)
            {
                fclose(file);
                throw std::runtime_error("Invalid chunk format");
            }
            Add(Block(xpos, ypos, std::string(nameBuf)));
        }
        else if(c == '.')
        {
            break;
        }
        else
        {
            fclose(file);
            throw std::runtime_error("Invalid chunk format.");
        }
        tmp = fscanf(file, "%c", &c);
    }
    fclose(file);
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
