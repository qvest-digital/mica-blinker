#ifndef _PLAYER_H
#define _PLAYER_H

#include <stdint.h>
#include <math.h>
#include <FastLED.h>

#include "Node.h"
#include "Direction.h"
#include "io/input.h"
#include "fx/Shield.h"

class Player : public Node {

    bool _dead = false;

    public:

        Direction direction;
        Shield shield = Shield();

        Player(const float position, const float velocity, const uint8_t hue) : Node(position, velocity, hue) {

        }

        void move(const Direction& direction) {
            this->direction = direction;
        }
    
        virtual void tick() {
            if (isPressed(Keys::BOTTOM)) {
                direction = BACKWARD;
            } else if (isPressed(Keys::TOP)) {
                direction = FORWARD;
            } else {
                direction = NO_MOVE;
            }
        }

        void die() {
            this->_dead = true;
        }

        virtual bool dead() {
            return this->_dead;
        }

        virtual void render(const Canvas& canvas) {
            
            if (direction != NO_MOVE) {
                shield.render(canvas, position, direction);
            }
            
            uint8_t pos = static_cast<uint8_t>(lround(position));

            canvas.setPixel(pos, CHSV(0, 0, 60));
        }

        void shieldHit(uint8_t hue) {
            shield.hit(hue);
        }

};

#endif