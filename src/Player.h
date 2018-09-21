#ifndef _PLAYER_H
#define _PLAYER_H

#include <stdint.h>
#include <math.h>
#include <FastLED.h>

#include "constants.h"
#include "Node.h"
#include "Explosion.h"

class Player : public Node {

    public:
        
        Explosion explosion = Explosion(77, 0, 0, 10);

        Player(const float position, const float velocity, const uint8_t hue) : Node(position, velocity, hue) {
        }
    
        // used to make status changes on each iteration
        virtual void tick() {
            hue = lround(position * 255 / 144);
            position += velocity;
            if(velocity < 3) {
                velocity += 0.001;
            }
        }

        // used to render nodes explosions
        virtual void render(CRGB pixels[NUM_PIXELS]) {

            uint8_t pos = static_cast<uint8_t>(lround(position));
                
            // reset rendering
            if(pos > NUM_PIXELS - 1) {
                pos = 0;
                position = 0;
                hue = 0;
                velocity = 0;
            }

            if(pos < 100 && pos > 70) {
                // pixels[100 - pos] = CHSV(0, lround(255 * pos / 144), value);
                explosion.phase = pos - 70;
                explosion.position = 50;
                explosion.render(pixels);
            } else {
                // pixels[pos] = CHSV(hue, lround(255 * pos / 144), value);
            }
        }
};

#endif