#ifndef _IDLE_H
#define _IDLE_H

#include "State.h"
#include "../World.h"

class Idle : public State
{

    boolean spawn();
    float velocity();

    public:

    Idle(World &world);

    virtual State *tick(World& world);

};

#endif