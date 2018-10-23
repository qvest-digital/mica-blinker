#ifndef _CONSTANTS_H
#define _CONSTANTS_H

#define MAX_FPS  200                // cap for frames-per-second
#define NUM_PIXELS 144              // number of pixels in strip

#define MAX_NODES 50                // maximum number of Nodes in the world

#define PIN_BUTTON_TOP 2            // digital pin D2
#define PIN_BUTTON_RIGHT 3          // digital pin D3
#define PIN_BUTTON_BOTTOM 4         // digital pin D4
#define PIN_BUTTON_LEFT 5           // digital pin D5
#define PIN_BUTTON_FIRE_1 6         // digital pin D6
#define PIN_BUTTON_FIRE_2 7         // digital pin D7

#define MIN_PROJECTILE_VELOCITY 40
#define MAX_PROJECTILE_VELOCITY 240
#define MIN_IDLE_VELOCITY 60
#define MAX_IDLE_VELOCITY 150
#define PROJECTILE_VELOCITY_DIVIDER 400.0f

#define IDLE_SPAWN_RATE 300
#define PLAYING_SPAWN_RATE 100

#define GAME_DURATION 1200

#endif