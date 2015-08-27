/*
 * Block.h
 *
 *  Created on: 26. aug. 2015
 *      Author: larso
 */

#ifndef SRC_BLOCK_H_
#define SRC_BLOCK_H_

#include <string>

class Block
{
public:
    Block(int x, int y, std::string type);
    int x();
    int y();
    const std::string& type();
private:
    int _x, _y;
    std::string _type;
};

#endif /* SRC_BLOCK_H_ */
