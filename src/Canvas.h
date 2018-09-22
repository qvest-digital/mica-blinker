#ifndef _CANVAS_H
#define _CANVAS_H

#include <FastLED.h>
#include "constants.h"

class Canvas {

    private:
    CRGB frameBuffer[NUM_PIXELS];

    public:

        Canvas() {
            CLEDController&  controller = FastLED.addLeds<SK9822, BGR>(frameBuffer, NUM_PIXELS);
            controller.clearLeds(NUM_PIXELS);
        }

        void clear() {
              fill_solid(frameBuffer, NUM_PIXELS, CRGB::Black);
        }

        void show() {
              FastLED.show();
        }

        void addPixel(const uint8_t position, const CHSV& color) {
            if (position >= 0 && position < NUM_PIXELS) {
                frameBuffer[position] += color;
            }
        }

        void setPixel(const uint8_t position, const CHSV& color) {
            if (position >= 0 && position < NUM_PIXELS) {
                frameBuffer[position] = color;
            }
        }
};

#endif