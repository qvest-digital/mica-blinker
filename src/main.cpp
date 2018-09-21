#include <Arduino.h>
#include <FastLED.h>

#include "constants.h"
#include "Player.h"

Player player = Player(0, 1, 100);;

CRGB frameBuffer[NUM_PIXELS];

void setup() {
  CLEDController& ledController = FastLED.addLeds<SK9822, BGR>(frameBuffer, NUM_PIXELS);
  ledController.clearLeds(NUM_PIXELS);

  // smoke test
  player.move(Direction::FORWARD);

}

void loop() {

  player.tick();

  fill_solid(frameBuffer, NUM_PIXELS, CRGB::Black);
  player.render(frameBuffer);

  FastLED.show();
  delay(50);
}


// #include <FastLED.h>

// #define MAX_FPS  200
// #define NUM_LEDS 144


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