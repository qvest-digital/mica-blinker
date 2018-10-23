#include "Idle.h"
#include "Playing.h"
#include "../constants.h"
#include "../io/input.h"
#include "../Projectile.h"

boolean Idle::spawn()
{
    return random16() < IDLE_SPAWN_RATE;
}

float Idle::velocity()
{
    float velocity = map(random8(), 0, 255, MIN_IDLE_VELOCITY, MAX_IDLE_VELOCITY) / PROJECTILE_VELOCITY_DIVIDER;
    return velocity;
}

Idle::Idle(World &world) : State(world) { }

State *Idle::tick(World& world)
{
    if (spawn()) {
        // spawn projectiles from left:
        // Projectile *projectile = new Projectile(0.0f, velocity(), random8());
        // spawn projectiles from right:
        Projectile *projectile = new Projectile(NUM_PIXELS - 1, -1.0f * velocity(), random8());
        world.addNode(projectile);
    }

    if (isPressed(Keys::TOP) || isPressed(Keys::BOTTOM)) {
        return new Playing(world);
    } else {
        return this;
    }
}
