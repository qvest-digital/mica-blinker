#ifndef _PLAYING_H
#define _PLAYING_H

#include "State.h"
#include "../World.h"

class Playing : public State
{

    long frameCounter = 0;
    bool gameOver = false;

    boolean spawn();
    float velocity();
    void detectCollisions(World& world);

    public:

    Playing(World &world);

    virtual State *tick(World& world);

};

#endif