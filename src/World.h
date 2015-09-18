/*
 * World.h
 *
 *  Created on: 31. aug. 2015
 *      Author: larso
 */

#ifndef SRC_WORLD_H_
#define SRC_WORLD_H_

#include "Block.h"

#include <map>
#include <utility>
#include <iostream>

class World
{
public:
    World();
    ~World();

    void load(std::istream in);
    void save(std::ostream out);

private:
    typedef std::pair<int, int> BlockPosition;
    typedef std::pair<float, float> ItemPosition;

    std::map<BlockPosition, Block*> blocks;
    std::vector<std::pair<ItemPosition, Item*>> items;
};

#endif /* SRC_WORLD_H_ */
