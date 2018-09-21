#ifndef _PLAYER_H
#define _PLAYER_H

#include <stdint.h>
#include <math.h>
#include <FastLED.h>

#include "constants.h"
#include "Node.h"
#include "Direction.h"

class Player : public Node {

    Direction direction;

    public:

        Player(const float position, const float velocity, const uint8_t hue) : Node(position, velocity, hue) {

        }

        void move(const Direction& direction) {
            this->direction = direction;
        }
    
        // used to make status changes on each iteration
        virtual void tick() {
            position += velocity;
            if(velocity < 3) {
                velocity += 0.01;
            }
        }

        // used to render nodes explosions
        virtual void render(CRGB pixels[NUM_PIXELS]) {

             uint8_t pos = static_cast<uint8_t>(lround(position));
            if(pos > NUM_PIXELS - 1) {
                pos = 0;
                position = 0;
                velocity = 0;
            }
        
            pixels[pos] = CHSV(hue, saturation, value);
        }
};

#endif