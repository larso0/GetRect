/*
 * Block.h
 *
 *  Created on: 31. aug. 2015
 *      Author: larso
 */

#ifndef SRC_BLOCK_H_
#define SRC_BLOCK_H_

#include "Item.h"
#include <vector>
#include <string>

class Block
{
public:
    Block(bool destructible, float health, std::string spriteKey);
    virtual ~Block();

    virtual void update(float delta);
    const std::string& getSpriteKey();
    bool isDestructible();
    bool isDestroyed();
    void damage(float dmg);
    std::vector<Item*> drop();
private:
    bool destructible;
protected:
    float health;
    std::vector<Item*> items;
    std::string spriteKey;

    void addItem(Item* item);
};

#endif /* SRC_BLOCK_H_ */
