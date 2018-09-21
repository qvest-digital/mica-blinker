#include <Arduino.h>
#include <FastLED.h>

#include "constants.h"
#include "Player.h"

Player player = Player(0, 1, 100);;

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

void loop() {

  handleInputs();

  player.tick();

  fill_solid(frameBuffer, NUM_PIXELS, CRGB::Black);
  player.render(frameBuffer);

  delay(500);
}


// #include <FastLED.h>

// #define MAX_FPS  200
// #define NUM_LEDS 144

// static unsigned long FRAME_MICROS = 1000000 / MAX_FPS;

// static CRGB leds[NUM_LEDS];

// void setup() {
//   CLEDController &controller = FastLED.addLeds<SK9822, BGR>(leds, NUM_LEDS);
//   controller.clearLeds(NUM_LEDS);
// }

// void loop() {
//   unsigned long startMicros = micros();

//   /////////////////////////////////////////////////////////////////////////////

//   // reset all leds
//   fill_solid(leds, NUM_LEDS, CRGB::Black);

//   // TODO

//   FastLED.show();

//   //////////////////////////////////////////////////////////////////////////////

//   unsigned long stopMicros = micros();

//   // sleep for remaining time of this frame to cap FPS
//   if (stopMicros >= startMicros) {
//     unsigned long durationMicros = stopMicros - startMicros;
//     if (durationMicros < FRAME_MICROS) {
//       delayMicroseconds(FRAME_MICROS - durationMicros);
//     }
//   }
// }