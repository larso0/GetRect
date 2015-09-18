/*
 * World.cpp
 *
 *  Created on: 31. aug. 2015
 *      Author: larso
 */

#include "World.h"
#include <string>
#include <sstream>

using namespace std;

World::World()
{
}

World::~World()
{
    for(auto iter = blocks.begin(); iter != blocks.end(); iter++)
    {
        delete iter->second;
    }
    for(auto iter = items.begin(); iter != items.end(); iter++)
    {
        delete iter->second;
    }
}

void World::load(istream in)
{
    string line;
    while(getline(in, line))
    {
        if(line[0] == '.') return;
        stringstream ss(line);
        int x, y;
        ss >> x >> y;
        string type = ss.str();
        blocks[{x, y}] = new Block(true, 100, type);
    }
}

void World::save(std::ostream out)
{
    for(auto iter = blocks.begin(); iter != blocks.end(); iter++)
    {
        out << iter->first.first << ' ' << iter->first.second;
        out << ' ' << iter->second->getSpriteKey() << endl;
    }
    out << ".\n";
}
