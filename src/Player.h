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

    bool dead = false;

    public:

        Direction direction;
        Shield shield = Shield();

        Player(const float position, const float velocity, const uint8_t hue) : Node(position, velocity, hue) {

        }

        void move(const Direction& direction) {
            this->direction = direction;
        }
    
        virtual void tick() {
            if (digitalRead(PIN_BUTTON_LEFT) == LOW) {
                direction = BACKWARD;
            } else if (digitalRead(PIN_BUTTON_RIGHT) == LOW) {
                direction = FORWARD;
            } else {
                direction = NO_MOVE;
            }
        }

        void die() {
            // this->dead = true;
        }

        virtual void render(const Canvas& canvas) {
            
            if (direction != NO_MOVE)
             shield.render(canvas, position, direction);
            
            uint8_t pos = static_cast<uint8_t>(lround(position));
            if(pos > NUM_PIXELS - 1) {
                pos = 0;
                position = 0;
            }

            canvas.setPixel(pos, CHSV(hue, saturation, value));
        }

        void shieldHit(uint8_t hue) {
            shield.hit(hue);
        }


};

#endif