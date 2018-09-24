#ifndef _STATE_H
#define _STATE_H

#include "../World.h"

class State {

    public:

    State(World &world) { }

    virtual ~State() {}

    virtual State *tick(World& world) = 0;

};

#endif