#include <Arduino.h>
#include <FastLED.h>

#include "constants.h"
#include "Player.h"
#include "World.h"
#include "fx/NuclearBlast.h"
#include "fx/Shield.h"

CRGB frameBuffer[NUM_PIXELS];

World world = World();

void setup() {
  CLEDController& ledController = FastLED.addLeds<SK9822, BGR>(frameBuffer, NUM_PIXELS);
  ledController.clearLeds(NUM_PIXELS);

  // setup serial port
  Serial.begin(9600); 

  // initialize digital pins for input
  pinMode(PIN_BUTTON_LEFT, INPUT_PULLUP);
  pinMode(PIN_BUTTON_RIGHT, INPUT_PULLUP);

  // set player to center
  world.addNode(new Player(10.0f, 0, 100));
  world.addNode(new NuclearBlast(40.0f));

}

void handleInputs() {

  if (digitalRead(PIN_BUTTON_LEFT) == LOW) {
    Serial.println("LEFT");
  } else if (digitalRead(PIN_BUTTON_RIGHT) == LOW) {
    Serial.println("RIGHT");
  }
}

static const unsigned long FRAME_MICROS = 1000000 / MAX_FPS;

void loop() {
  unsigned long startMicros = micros();

  /////////////////////////////////////////////////////////////////////////////

  handleInputs();

  // reset all leds
  fill_solid(frameBuffer, NUM_PIXELS, CRGB::Black);

  world.tick();
  world.cleanup();
  world.render(frameBuffer);

  FastLED.show();

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