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

int Block::x() const
{
    return _x;
}

int Block::y() const
{
    return _y;
}

const std::string& Block::type() const
{
    return _type;
}

bool operator<(const Block& a, const Block& b)
{
    return (a._x < b._x) ? true : ((a._x == b._x) ? (a._y < b._y) : false);
}

bool operator==(const Block& a, const Block& b)
{
    return a._x == b._x && a._y == b._y;
}
