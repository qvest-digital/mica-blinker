#ifndef _PLAYER_H
#define _PLAYER_H

#include <stdint.h>
#include <math.h>
#include <FastLED.h>

#include "constants.h"
#include "Node.h"

class Player : public Node {

    public:

    

        Player(const float position, const float velocity, const uint8_t hue) : Node(position, velocity, hue) {

        }
    
        // used to make status changes on each iteration
        virtual void tick() {
            hue = lround(position * 255 / 144);
            position += velocity;
            if(velocity < 3) {
                velocity += 0.01;
            }
        }

        // used to render nodes explosions
        virtual void render(CRGB pixels[NUM_PIXELS]) {

            uint8_t pos = static_cast<uint8_t>(lround(position));
            // reset rendering
            if(pos > NUM_PIXELS - 1) {
                pos = 0;
                position = 0;
                hue = 0;
                velocity = 0;
            }
        
            pixels[pos] = CHSV(hue, saturation, value);
        }
};

#endif