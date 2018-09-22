#ifndef _PROJECTILE_H
#define _PROJECTILE_H

#include <FastLED.h>

#include "constants.h"
#include "Node.h"

class Projectile : public Node {

public:

    Projectile(const float position, const float velocity, const uint8_t hue): Node(position, velocity, hue) {
    }

    virtual bool dead() {
        // projectile "dies" when leaving the playing field
        return position < 0 || position >= NUM_PIXELS;
    }

    virtual void tick() {
        position += velocity;
    }

    virtual void render(const Canvas& canvas) {
        uint8_t pos = static_cast<uint8_t>(lround(position));
        canvas.addPixel(pos, CHSV(hue, saturation, value));
    }

};

#endif