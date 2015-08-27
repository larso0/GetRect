/*
 * Chunk.h
 *
 *  Created on: 27. aug. 2015
 *      Author: larso
 */

#ifndef SRC_CHUNK_H_
#define SRC_CHUNK_H_

#include <list>
#include <string>
#include "Block.h"
#include "BlockRenderer.h"

class Chunk
{
public:
    Chunk(int x, int y, unsigned w, unsigned h);

    void Add(Block block);
    void Render(BlockRenderer& blockRenderer);

    int x();
    int y();
    unsigned width();
    unsigned height();
private:
    int _x, _y;
    unsigned w, h;
    std::list<std::list<Block>> blocks;

    std::list<Block>& GetBlockList(std::string key);
};

#endif /* SRC_CHUNK_H_ */
