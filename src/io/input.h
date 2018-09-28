#ifndef _INPUT_H
#define _INPUT_H

#include <Arduino.h>
#include "constants.h"

namespace Keys
{
    enum Key
    {
        TOP,
        RIGHT = PIN_BUTTON_RIGHT,
        BOTTOM,
        LEFT = PIN_BUTTON_LEFT,
        LEFT_FIRE = PIN_BUTTON_FIRE_1,
        RIGHT_FIRE = PIN_BUTTON_FIRE_2
    };
}

static bool isPressed(Keys::Key key)
{
    switch(key)
    {
        case Keys::LEFT:
        case Keys::RIGHT:
            return (digitalRead(key) == LOW);
        default:
            return false;
    }
}

#endif