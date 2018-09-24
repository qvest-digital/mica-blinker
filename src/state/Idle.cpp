#include "Idle.h"
#include "Playing.h"
#include "../constants.h"
#include "../io/input.h"
#include "../Projectile.h"

boolean Idle::spawn()
{
    // long probability = map(frameCounter, 0, MAX_FPS * GAME_DURATION, 1, 16);
    return random16() < 100;
}

float Idle::velocity()
{
    float velocity = map(random8(), 0, 255, MIN_PROJECTILE_VELOCITY, MAX_PROJECTILE_VELOCITY) / PROJECTILE_VELOCITY_DIVIDER;
    return velocity;
}

Idle::Idle(World &world) : State(world) { }

State *Idle::tick(World& world)
{
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

    if (isPressed(Keys::LEFT_FIRE) || isPressed(Keys::RIGHT_FIRE) || random16() <= 40) {
        return new Playing(world);
    } else {
        return this;
    }
}
