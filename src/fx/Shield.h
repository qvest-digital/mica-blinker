#ifndef _SHIELD_H
#define _SHIELD_H

// #include <stdint.h>
#include <math.h>
#include <FastLED.h>

// #include "constants.h"
#include "../Node.h"
#include "Direction.h"

class Shield {

    uint8_t color = 160;

    public:

        Shield() {
        }

        // void addPixelIfInRange(CRGB pixels[NUM_PIXELS], int pos, CHSV color) {
        //     if (pos >= 0 && pos < NUM_PIXELS) {
        //         pixels[pos] += color;
        //     }
        // }

        // void setPixelIfInRange(CRGB pixels[NUM_PIXELS], int pos, CHSV color) {
        //     if (pos >= 0 && pos < NUM_PIXELS) {
        //         pixels[pos] = color;
        //     }
        // }

        void render(const Canvas& canvas, const uint8_t position, const Direction direction) {

            uint16_t pos = static_cast<uint16_t>(lround(position));
            
            if (direction == FORWARD) {

                canvas.addPixel(pos + 2, CHSV(color, 0, 20));
                canvas.addPixel(pos + 3, CHSV(color, 200, 120));
                canvas.addPixel(pos + 3, CHSV(color, 200, 120));

                //addPixelIfInRange(pixels, pos + 2, CHSV(color, 0, 20));
                //addPixelIfInRange(pixels, pos + 3, CHSV(color, 200, 120));
                //pixels[pos + 3] += CHSV(color, 200, 120);
                
            } else if (direction == BACKWARD) {

                canvas.addPixel(pos - 2, CHSV(color, 0, 20));
                canvas.addPixel(pos - 3, CHSV(color, 200, 120));
                
                //addPixelIfInRange(pixels, pos - 2, CHSV(color, 0, 20));
                //addPixelIfInRange(pixels, pos - 3, CHSV(color, 200, 120));
            }
        }
};

#endif