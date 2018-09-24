#ifndef _SHIELD_H
#define _SHIELD_H

#include <math.h>
#include <FastLED.h>

#include "../Node.h"
#include "Direction.h"

class Shield {

    uint8_t baseColor = 160;
    uint8_t currentColor;

    uint8_t baseValue = 0;
    uint8_t currentValue;

    uint8_t frameCounter;

    public:

        Shield() {
            currentColor = baseColor;
            currentValue = baseValue;
            frameCounter = 0;
        }

        void hit(uint8_t projectileColor) {
            frameCounter = 5;
            currentColor = baseColor + (baseColor - projectileColor) / 2;  
            currentValue = 80;
        }

        void render(const Canvas& canvas, const uint8_t position, const Direction direction) {

            if (frameCounter > 0) {
                frameCounter--;
            } else {
                currentColor = baseColor;
                currentValue = baseValue;
            }

            uint16_t pos = static_cast<uint16_t>(lround(position));
            
            if (direction == FORWARD) {
                canvas.addPixel(pos + 1, CHSV(currentColor, 0, currentValue));
                canvas.addPixel(pos + 2, CHSV(currentColor, 0, currentValue + 20));
                canvas.addPixel(pos + 3, CHSV(currentColor, 200, currentValue + 120));
            } else if (direction == BACKWARD) {
                canvas.addPixel(pos - 1, CHSV(currentColor, 0, currentValue));
                canvas.addPixel(pos - 2, CHSV(currentColor, 0, currentValue + 20));
                canvas.addPixel(pos - 3, CHSV(currentColor, 200, currentValue + 120));
            }
        }
};

#endif