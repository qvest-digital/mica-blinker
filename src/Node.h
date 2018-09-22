#ifndef _NODE_H
#define _NODE_H

#include <stdint.h>
#include <FastLED.h>

#include "constants.h"

class Node {

public:

    float position;
    float velocity;

    // color state
    uint8_t hue;
    uint8_t saturation;
    uint8_t value;

        Node(const float position, const float velocity, const uint8_t hue): position(position), velocity(velocity), hue(hue) {
            saturation = 255;
            value = 50;
        }

        virtual ~Node() {}

        virtual void tick() = 0;

        virtual void render(CRGB pixels[NUM_PIXELS]) = 0;

        virtual bool dead() {
            return false;
        }

};

#endif