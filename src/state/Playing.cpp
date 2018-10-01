#include "Playing.h"
#include "GameOver.h"
#include "../constants.h"
#include "../Projectile.h"
#include "../Player.h"

boolean Playing::spawn()
{
    return random16() < PLAYING_SPAWN_RATE;
}

float Playing::velocity()
{
    float velocity = map(random8(), 0, 255, MIN_PROJECTILE_VELOCITY, MAX_PROJECTILE_VELOCITY) / PROJECTILE_VELOCITY_DIVIDER;
    return velocity;
}

void Playing::detectCollisions(World& world)
{
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

Playing::Playing(World &world) : State(world)
{
    // put a new player in the center
    Player *player = new Player(NUM_PIXELS / 2, 0, 100);
    world.addNode(player);
    world.setPlayer(player);
}

State *Playing::tick(World& world)
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

    detectCollisions(world);

    // increment counter
    frameCounter++;

    if (gameOver) {
        return new GameOver(world);
    } else {
        return this;
    }
}
