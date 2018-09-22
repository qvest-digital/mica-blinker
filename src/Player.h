#ifndef _PLAYER_H
#define _PLAYER_H

#include <stdint.h>
#include <math.h>
#include <FastLED.h>

#include "constants.h"
#include "Node.h"
#include "Direction.h"
#include "fx/Shield.h"

class Player : public Node {

    

    public:

        Direction direction;
        Shield shield = Shield();

        Player(const float position, const float velocity, const uint8_t hue) : Node(position, velocity, hue) {

        }

        void move(const Direction& direction) {
            this->direction = direction;
        }
    
        virtual void tick() {

            switch(direction) {

                case FORWARD:
                position += velocity;
                break;

                case BACKWARD:
                position -= velocity;
                break;

                default:
                break;
            }
        }

        virtual void render(CRGB pixels[NUM_PIXELS]) {
            shield.render(pixels, position, direction);
            uint8_t pos = static_cast<uint8_t>(lround(position));
            if(pos > NUM_PIXELS - 1) {
                pos = 0;
                position = 0;
            }

            pixels[pos] = CHSV(hue, saturation, value);
        }

        void renderShield(CRGB pixels[NUM_PIXELS]) {
            uint8_t color = 160;
            uint16_t pos = static_cast<uint16_t>(lround(position));
            
            if (direction == FORWARD) {
                pixels[pos + 2] += CHSV(color, 0, 20);
                pixels[pos + 3] += CHSV(color, 200, 120);

                pixels[pos - 2] += CHSV(color, 0, 20);
                pixels[pos - 3] += CHSV(color, 200, 120);
            } else if (direction == BACKWARD) {
                pixels[pos - 2] += CHSV(color, 0, 20);
                pixels[pos - 3] += CHSV(color, 200, 120);
            }
        }
};

#endif