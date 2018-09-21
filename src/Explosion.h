#ifndef _EXPLOSION_H
#define _EXPLOSION_H

#include <stdio.h>
#include <FastLED.h>

class Explosion : public Node() {

    Explosion(const float position, const float velocity, const uint8_t hue) : Node(position, velocity, hue) {
    }

    virtual void tick() {

    }

    virtual void render(CRGB pixels[NUM_PIXELS]) {
        for (int i = 0;i < 4; i++) {
            pixels[pos + i] = CHSV(hue, saturation, 50 - i * 10);
            pixels[pos - i] = CHSV(hue, saturation, 50 - i * 10);
        }
    }

}

#endif