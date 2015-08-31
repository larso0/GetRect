/*
 * Block.cpp
 *
 *  Created on: 31. aug. 2015
 *      Author: larso
 */

#include "Block.h"

Block::Block(bool destructible, float health, std::string spriteKey)
{
    this->destructible = destructible;
    this->health = health;
    this->spriteKey = spriteKey;
}

Block::~Block()
{
}

void Block::update(float delta)
{
}

const std::string& Block::getSpriteKey()
{
    return spriteKey;
}

bool Block::isDestructible()
{
    return destructible;
}

bool Block::isDestroyed()
{
    return destructible ? health <= 0.f : false;
}

void Block::damage(float dmg)
{
    if(dmg > 0.f)
    {
        health -= dmg;
    }
}

void Block::addItem(Item* item)
{
    if(item != nullptr)
    {
        items.push_back(item);
    }
}

std::vector<Item*> Block::drop()
{
    std::vector<Item*> dropped = items;
    items.clear();
    return dropped;
}
