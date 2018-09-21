#ifndef _EXPLOSION_H
#define _EXPLOSION_H

#include <stdio.h>
#include <FastLED.h>

class Explosion : public Node {

    public:
        uint8_t phase;

        Explosion(const float position, const float velocity, const uint8_t hue, uint8_t phase) : Node(position, velocity, hue) {
        };

        virtual void tick() {
        }

        virtual void render(CRGB pixels[NUM_PIXELS]) {
            uint8_t pos = static_cast<uint8_t>(lround(position));
            pixels[pos] = CHSV(hue, 100, 100);
            for (int i = 0;i < phase; i++) {
                pixels[pos + i] = CHSV(hue, 100, 50);
                pixels[pos - i] = CHSV(hue, 100, 50);
            }
        }
};

#endif