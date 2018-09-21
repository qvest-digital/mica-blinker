#include <Arduino.h>
#include <FastLED.h>

#include "constants.h"
#include "Player.h"
#include "fx/NuclearBlast.h"

Player player = Player(0, 0.25f, 100);
// NuclearBlast blast = NuclearBlast(40.0f);

CRGB frameBuffer[NUM_PIXELS];

void setup() {
  CLEDController& ledController = FastLED.addLeds<SK9822, BGR>(frameBuffer, NUM_PIXELS);
  ledController.clearLeds(NUM_PIXELS);

  // setup serial port
  Serial.begin(9600); 

  // initialize digital pins for input
  pinMode(PIN_BUTTON_LEFT, INPUT_PULLUP);
  pinMode(PIN_BUTTON_RIGHT, INPUT_PULLUP);

  // smoke test
  player.move(Direction::FORWARD);
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

  player.tick();
  player.render(frameBuffer);
  // blast.tick();
  // blast.render(frameBuffer);

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