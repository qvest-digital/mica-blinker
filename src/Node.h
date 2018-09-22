#ifndef _NODE_H
#define _NODE_H

#include <stdint.h>
#include <FastLED.h>

#include "constants.h"
#include "Canvas.h"

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

    virtual void render(const Canvas& canvas) = 0;

    uint8_t getPos() { return position; }

        virtual bool dead() {
            return false;
        }

};

#endif