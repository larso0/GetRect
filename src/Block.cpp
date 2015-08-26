/*
 * Block.cpp
 *
 *  Created on: 26. aug. 2015
 *      Author: larso
 */

#include "Block.h"

Block::Block(int x, int y, std::string type)
{
    _x = x;
    _y = y;
    _type = type;
}

int Block::x()
{
    return _x;
}

int Block::y()
{
    return _y;
}

const std::string& Block::type()
{
    return _type;
}
