#include "GameOver.h"
#include "Idle.h"
#include "../fx/NuclearBlast.h"

GameOver::GameOver(World &world) : State(world)
{
    // create explosion at the player position:
    Player* player = world.getPlayer();
    world.addNode(new NuclearBlast(player->position));
    world.setPlayer(NULL);
    player->die();
}

State *GameOver::tick(World& world)
{
    // wait until all nodes have disappeared before going to idle mode:
    if (world.getNodeCount() == 0) {
        return new Idle(world);
    } else {
        return this;
    }
}
