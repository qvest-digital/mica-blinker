#ifndef _GAME_OVER_H
#define _GAME_OVER_H

#include "State.h"
#include "../World.h"

class GameOver : public State {

    public:

    GameOver(World &world);

    State *tick(World& world);

};

#endif