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
        
        // player->shieldHit(160);

        uint16_t playerPos = lround(player->getPosition());
        Direction playerDir = player->direction;
        
        for (uint16_t i = 0; i < MAX_NODES; i++) {
            NodePtr node = nodes[i];
            if (node != NULL && node != player) {
                uint16_t nodePos = lround(node->getPosition());

                if (playerPos == nodePos) {
                    Serial.println("player hit");
        //         //     player->hue = 0;
                    player->shieldHit(160);
        //         //     // node.die();
        //         // } else
        //         // if (playerDir == FORWARD /*&& playerPos + 3 == nodePos*/) {
        //             // player->hue = 96;
        //             // node->velocity = abs(node->velocity);
        //         // } else {
        //         //     player->hue = 160;
                }
            }
        }
    }

};

#endif