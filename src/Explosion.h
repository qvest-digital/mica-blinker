#ifndef _EXPLOSION_H
#define _EXPLOSION_H

#include <stdio.h>
#include <FastLED.h>
#include <math.h>

class Explosion : public Node {

    public:
        uint8_t phase;
        uint8_t phase_max = 30;

        Explosion(const float position, const float velocity, const uint8_t hue, uint8_t phase) : Node(position, velocity, hue) {
        };

        virtual void tick() {
        }

        virtual void render(CRGB pixels[NUM_PIXELS]) {
            uint8_t pos = static_cast<uint8_t>(lround(position));
            uint8_t explosion_value;
            uint8_t color;
            for (int i = 1;i < phase; i++) {
                color = lround(50 * (1 - i/phase));
                explosion_value = lround(200 * i/phase * expf(-3 * phase/phase_max));
                pixels[pos + i] = CHSV(color, 200, explosion_value);
                pixels[pos - i] = CHSV(color, 200, explosion_value);
            }
        }
};

#endif