#ifndef _PLAYING_H
#define _PLAYING_H

#include "State.h"
#include "GameOver.h"

#include "../constants.h"
#include "../World.h"
#include "../Projectile.h"
#include "../Player.h"

class Playing : public State {

    long frameCounter = 0;

    boolean spawn() {
        // long probability = map(frameCounter, 0, MAX_FPS * GAME_DURATION, 1, 16);
        return random16() < 100;
    }

    float velocity() {
        float velocity = map(random8(), 0, 255, MIN_PROJECTILE_VELOCITY, MAX_PROJECTILE_VELOCITY) / PROJECTILE_VELOCITY_DIVIDER;
        return velocity;
    }

    void detectCollisions(World& world) {

        Player* player = world.getPlayer();
        NodePtr* nodes = world.getNodes();
        
        uint8_t playerPos = NUM_PIXELS / 2;
        Direction playerDir = player->direction;
        
        for (uint8_t i = 0; i < MAX_NODES; i++) {
            NodePtr node = nodes[i];
            if (node != NULL && node != player) {
                uint8_t nodePos = lround(node->getPosition());

                if (playerDir == FORWARD && playerPos + 3 == nodePos) {
                    player->shieldHit(node->hue);
                    node->velocity *= -1.0f;
                    node->position += 10 * node->velocity;
                } else if (playerDir == BACKWARD && playerPos - 3 == nodePos) {
                    player->shieldHit(node->hue);
                    node->velocity *= -1.0f;
                    node->position += 10 * node->velocity;
                } else if (playerPos == nodePos && !gameOver) {
                    gameOver = true;
                }
            }
        }
    }

    public:

    Playing(World &world) : State(world) {
        // put a new player in the center
        Player *player = new Player(NUM_PIXELS / 2, 0, 100);
        world.addNode(player);
        world.setPlayer(player);
    }

    bool gameOver = false;

    State *tick(World& world) {

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

        detectCollisions(world);

        // increment counter
        frameCounter++;

        if (gameOver) {
            return new GameOver(world);
        } else {
            return this;
        }
    }

};

#endif