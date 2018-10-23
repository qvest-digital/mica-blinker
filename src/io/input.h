#ifndef _INPUT_H
#define _INPUT_H

#include <Arduino.h>
#include "constants.h"

namespace Keys
{
    enum Key
    {
        TOP = PIN_BUTTON_TOP,
        RIGHT = PIN_BUTTON_RIGHT,
        BOTTOM = PIN_BUTTON_BOTTOM,
        LEFT = PIN_BUTTON_LEFT,
        LEFT_FIRE = PIN_BUTTON_FIRE_1,
        RIGHT_FIRE = PIN_BUTTON_FIRE_2
    };
}

static void initInputs() {
  // initialize digital pins for input
  pinMode(PIN_BUTTON_TOP, INPUT_PULLUP);
  pinMode(PIN_BUTTON_RIGHT, INPUT_PULLUP);
  pinMode(PIN_BUTTON_BOTTOM, INPUT_PULLUP);
  pinMode(PIN_BUTTON_LEFT, INPUT_PULLUP);
  pinMode(PIN_BUTTON_FIRE_1, INPUT_PULLUP);
  pinMode(PIN_BUTTON_FIRE_2, INPUT_PULLUP);
}

static bool isPressed(Keys::Key key)
{
    switch(key)
    {
        case Keys::TOP:
        case Keys::RIGHT:
        case Keys::BOTTOM:
        case Keys::LEFT:
            return (digitalRead(key) == LOW);
        default:
            return false;
    }
}

#endif