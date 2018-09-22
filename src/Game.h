#ifndef _GAME_H
#define _GAME_H

#include "constants.h"
#include "World.h"
#include "Projectile.h"

#define MIN_VELOCITY 1
#define MAX_VELOCITY 100

#define GAME_DURATION 120

class Game {

    long frameCounter = 0;

    boolean spawn() {
        long probability = map(frameCounter, 0, MAX_FPS * GAME_DURATION, 0, 255);
        return random8() < probability;
    }

    float velocity() {
        long velocity = map(frameCounter, 0, MAX_FPS * GAME_DURATION, MIN_VELOCITY, MAX_VELOCITY);
        return velocity / 100.0f;
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
            Projectile *projectile = new Projectile(0.0f, velocity(), random8());
            world.addNode(projectile);
        }

        // increment counter
        frameCounter++;
    }

};

#endif