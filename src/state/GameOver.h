#ifndef _GAME_OVER_H
#define _GAME_OVER_H

#include "State.h"

#include "../constants.h"
#include "../World.h"
#include "../fx/NuclearBlast.h"

class GameOver : public State {

    long frameCounter = 0;

    public:

    GameOver(World &world) : State(world) {
        // create explosion at the player position:
        Player* player = world.getPlayer();
        world.addNode(new NuclearBlast(player->position));
        world.setPlayer(NULL);
        player->die();
    }

    State *tick(World& world) {

        // increment counter
        frameCounter++;

        return this;
    }

};

#endif