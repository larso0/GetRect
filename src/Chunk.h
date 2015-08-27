/*
 * Chunk.h
 *
 *  Created on: 27. aug. 2015
 *      Author: larso
 */

#ifndef SRC_CHUNK_H_
#define SRC_CHUNK_H_

#include <set>
#include <string>
#include "Block.h"
#include "BlockRenderer.h"

class Chunk
{
public:
    Chunk();
    Chunk(int x, int y, unsigned w, unsigned h);

    void Load(std::string fileName);
    void Add(Block block);
    const Block* Get(int x, int y);
    void Render(BlockRenderer& blockRenderer);

    int x();
    int y();
    unsigned width();
    unsigned height();
private:
    int _x, _y;
    unsigned w, h;

    std::set<Block> blocks;
};

#endif /* SRC_CHUNK_H_ */
