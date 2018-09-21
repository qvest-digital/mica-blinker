#include <Arduino.h>
#include <FastLED.h>

#include "constants.h"
#include "Player.h"

Player player = Player(10, 10, 100);;

CRGB frameBuffer[NUM_PIXELS];

void setup() {
  CLEDController &controller = FastLED.addLeds<SK9822, BGR>(frameBuffer, NUM_PIXELS);
  controller.clearLeds(NUM_PIXELS);
}

void loop() {
  player.tick();
  player.render(frameBuffer);
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