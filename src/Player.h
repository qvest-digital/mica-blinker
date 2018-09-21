#ifndef __INC_PLAYER_H
#define __INC_PLAYER_H

#include <Arduino.h>

class Player {

    uint8_t position;
    uint8_t speed;

    uint8_t hue;
    uint8_t saturation;
    uint8_t value;

    public:
        Player(uint8_t position, uint8_t hue): position(position), hue(hue){
            speed = 16;
            saturation = 64;
            value = 64;
        }

        void moveForwards() {
            position += speed;
        }

        void moveBackwards() {
            position -= speed;
        }

};

#endif