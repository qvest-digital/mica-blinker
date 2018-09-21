#ifndef _OPPONENT_H
#define _OPPONENT_H

#include <stdint.h>
#include <math.h>
#include <FastLED.h>

#include "constants.h"
#include "Node.h"
#include "Direction.h"

class Opponent : public Node {

    public:

        Opponent(const float position, const float velocity, const uint8_t hue) : Node(position, velocity, hue) {

        }
    
        virtual void tick() {

        }

        virtual void render(CRGB pixels[NUM_PIXELS]) {

             uint8_t pos = static_cast<uint8_t>(lround(position));
            if(pos > NUM_PIXELS - 1) {
                pos = 0;
                position = 0;
            }

            pixels[pos] = CHSV(hue, saturation, value);
        }
};

#endif