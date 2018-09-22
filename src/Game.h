#ifndef _GAME_H
#define _GAME_H

#include "constants.h"
#include "World.h"
#include "Projectile.h"

class Game {

    long frameCounter = 0;

    boolean spawn() {
        // long probability = map(frameCounter, 0, MAX_FPS * GAME_DURATION, 1, 16);
        return random16() < 100;
    }

    float velocity() {
        float velocity = map(random8(), 0, 255, MIN_PROJECTILE_VELOCITY, MAX_PROJECTILE_VELOCITY) / PROJECTILE_VELOCITY_DIVIDER;
        return velocity;
    }

    public:

    void tick(World& world) {
        // spawn projectiles from left:
        if (spawn()) {
            Projectile *projectile = new Projectile(0.0f, velocity(), random8());
            world.addNode(projectile);
        }
        // spawn projectiles from right:
        if (spawn()) {
            Projectile *projectile = new Projectile(NUM_PIXELS-1, -velocity(), random8());
            world.addNode(projectile);
        }

        // increment counter
        frameCounter++;
    }

    void detectCollisions(World& world) {
        Player* player = world.getPlayer();
        NodePtr* nodes = world.getNodes();
        
        uint8_t playerPos = lround(player->getPosition());

        for (uint16_t i = 0; MAX_NODES; i++) {
            NodePtr node = nodes[i];
            if (node != dynamic_cast<Node*>(player) && node != NULL) {
                uint8_t nodePos = lround(node->getPosition());

                if (nodePos < )
                Direction playerDir = player->direction;
                if (playerPos == nodePos) {
                    player.hit();
                    
                }
            }
        }
    }

};

#endif