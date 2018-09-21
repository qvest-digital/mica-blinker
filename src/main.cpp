#include <Arduino.h>
#include <FastLED.h>

#include "constants.h"
#include "Player.h"

Player player = Player(0, 0.01, 100);;

CRGB frameBuffer[NUM_PIXELS];
//CLEDController& ledController;
void  blink(int);

void setup() {
  CLEDController& ledController = FastLED.addLeds<SK9822, BGR>(frameBuffer, NUM_PIXELS);
  ledController.clearLeds(NUM_PIXELS);
  pinMode(13, OUTPUT);

}

void loop() {
  player.tick();

  fill_solid(frameBuffer, NUM_PIXELS, CRGB::Black);
  player.render(frameBuffer);

  delay(10);
  FastLED.show();
  
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