#include <Arduino.h>
#include <FastLED.h>

#include "constants.h"
#include "Player.h"
#include "World.h"
#include "fx/NuclearBlast.h"
#include "fx/Shield.h"
#include "fx/GameState.h"

void initializeGameOverWorld();
void initializePlayingWorld();
void initializeIdleWorld();

CRGB frameBuffer[NUM_PIXELS];

World world = World();
GameState gameState;

void setup() {
  CLEDController& ledController = FastLED.addLeds<SK9822, BGR>(frameBuffer, NUM_PIXELS);
  ledController.clearLeds(NUM_PIXELS);

  // setup serial port
  Serial.begin(9600); 

  // initialize digital pins for input
  pinMode(PIN_BUTTON_LEFT, INPUT_PULLUP);
  pinMode(PIN_BUTTON_RIGHT, INPUT_PULLUP);

  // world setup IDLE
  gameState = IDLE;

  // intialize world
  initializePlayingWorld();
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
  long seconds = lround(startMicros / 5000000);
  uint8_t modulo = seconds % 2;
  Serial.println(startMicros + " testing " +  modulo);
  switch(modulo) {
    case 0:
      initializeGameOverWorld();
    case 1:
      initializePlayingWorld();
  }

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

void initializePlayingWorld() {
  world = World();
  gameState = PLAYING;
  world.addNode(new Player(NUM_PIXELS / 2, 0, 100));
}

void initializeGameOverWorld() {
  world = World();
  gameState = GAMEOVER;
  world.addNode(new NuclearBlast(40.0f));
}

void initializeIdleWorld() {
  world = World();
  gameState = IDLE;
}