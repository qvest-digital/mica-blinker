#ifndef _SHIELD_H
#define _SHIELD_H

// #include <stdint.h>
#include <math.h>
#include <FastLED.h>

// #include "constants.h"
#include "../Node.h"
#include "Direction.h"

class Shield {

    uint8_t baseColor = 160;
    uint8_t currentColor = baseColor;

    uint8_t baseValue = 0;
    uint8_t currentValue = baseValue;

    uint8_t frameCounter = 0;

    public:

        Shield() {
        }

        void addPixelIfInRange(CRGB pixels[NUM_PIXELS], int pos, CHSV color) {
            if (pos >= 0 && pos < NUM_PIXELS) {
                pixels[pos] += color;
            }
        }

        void setPixelIfInRange(CRGB pixels[NUM_PIXELS], int pos, CHSV color) {
            if (pos >= 0 && pos < NUM_PIXELS) {
                pixels[pos] = color;
            }
        }

        void hit(uint8_t projectileColor) {
            frameCounter = 5;
            currentColor = baseColor + (baseColor - projectileColor) / 2;  
            currentValue = 80;
        }

        void render(CRGB pixels[NUM_PIXELS], uint8_t position, Direction direction) {
            if (frameCounter > 0) {
                frameCounter--;
            } else {
                currentColor = baseColor;
                currentValue = baseValue;
            }


            uint16_t pos = static_cast<uint16_t>(lround(position));
            
            if (direction == FORWARD) {
                addPixelIfInRange(pixels, pos + 1, CHSV(currentColor, 0, currentValue));
                addPixelIfInRange(pixels, pos + 2, CHSV(currentColor, 0, currentValue + 20));
                addPixelIfInRange(pixels, pos + 3, CHSV(currentColor, 200, currentValue + 120));
            } else if (direction == BACKWARD) {
                addPixelIfInRange(pixels, pos - 1, CHSV(currentColor, 0, currentValue));
                addPixelIfInRange(pixels, pos - 2, CHSV(currentColor, 0, currentValue + 20));
                addPixelIfInRange(pixels, pos - 3, CHSV(currentColor, 200, currentValue + 120));
            }
        }
};

#endif