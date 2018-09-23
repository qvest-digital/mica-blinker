#include <Arduino.h>
#include <FastLED.h>

#include "constants.h"
#include "Canvas.h"
#include "Player.h"
#include "World.h"
#include "state/Playing.h"
#include "state/Idle.h"

World world;
Canvas canvas;

State *state;

void setup() {

  // setup serial port
  Serial.begin(9600); 

  // initialize digital pins for input
  pinMode(PIN_BUTTON_LEFT, INPUT_PULLUP);
  pinMode(PIN_BUTTON_RIGHT, INPUT_PULLUP);

  // start application in idle mode
  // state = new Idle(world);
  state = new Playing(world);
}

static const unsigned long FRAME_MICROS = 1000000 / MAX_FPS;

void loop() {
  unsigned long startMicros = micros();

  /////////////////////////////////////////////////////////////////////////////

  // update world  
  world.tick();

  // update state
  State *newState = state->tick(world);

  // change state?
  if (newState != state) {
    delete state;
    state = newState;
  }

  // remove "dead" objects from the world
  world.cleanup();

  // reset canvas, render world and update LEDs
  canvas.clear();
  world.render(canvas);
  canvas.show();

  //////////////////////////////////////////////////////////////////////////////

  unsigned long stopMicros = micros();

  // sleep for remaining time of this frame to cap FPS
  if (stopMicros >= startMicros) {
    unsigned long durationMicros = stopMicros - startMicros;
    if (durationMicros < FRAME_MICROS) {
      delayMicroseconds(FRAME_MICROS - durationMicros);
    }
  }
}