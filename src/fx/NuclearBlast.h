#ifndef _NUCLEAR_BLAST_H
#define _NUCLEAR_BLAST_H

#include <math.h>
#include <FastLED.h>

#include "../Node.h"

class NuclearBlast : public Node {

    uint16_t elapsedFrames = 0;

    // start-frames of the different explosion stages
    enum {
        STAGE_EXPANSION = 0,
        STAGE_SHOCKWAVE = STAGE_EXPANSION + (MAX_FPS / 2),
        STAGE_END = STAGE_SHOCKWAVE + NUM_PIXELS*2
    };

    public:

        NuclearBlast(const float position) : Node(position, 0.0f, 0) {
        }

        virtual void tick() {
            elapsedFrames++;
        }

        virtual bool dead() {
            return elapsedFrames >= STAGE_END;
        }

        virtual void render(const Canvas& canvas) {

            uint16_t pos = static_cast<uint16_t>(lround(position));
            if (elapsedFrames < STAGE_SHOCKWAVE) {
              // stage: EXPANSION
              // transition HSV(0, 0, 100) -> HSV(0, 0, 255) while growing 1px -> 7px
              long brightness = map(elapsedFrames, 0, STAGE_SHOCKWAVE, 0, 255);
              long size = map(elapsedFrames, 0, STAGE_SHOCKWAVE, 0, 3);
              for (int i=0; i<=size; i++) {
                canvas.addPixel(pos+i, CHSV(0, 0, brightness));
                canvas.addPixel(pos-i, CHSV(0, 0, brightness));
              }
            } else if (elapsedFrames < STAGE_END) {
              // stage: SHOCKWAVE
              // explosion center fades out
              long brightness = constrain(
                  map(elapsedFrames, STAGE_SHOCKWAVE, STAGE_SHOCKWAVE + (STAGE_END - STAGE_SHOCKWAVE) / 4, 255, 0),
                  0, 160);
              long size = constrain(
                  map(elapsedFrames, STAGE_SHOCKWAVE, STAGE_SHOCKWAVE + (STAGE_END - STAGE_SHOCKWAVE) / 4, 3, 0),
                  0, 3);
              for (int i=0; i<=size; i++) {
                 canvas.addPixel(pos+i, CHSV(0, 0, brightness));
                 canvas.addPixel(pos-i, CHSV(0, 0, brightness));
              }
              // shockwave travels from center to edges
              long dist = map(elapsedFrames, STAGE_SHOCKWAVE, STAGE_END, 3, NUM_PIXELS);
              for (int i=dist; i>=dist-10; i--) {
                if (i >= 4) {
                  long brightness = map(i, dist-10, dist, 10, 100);
                   canvas.addPixel(pos+i, CHSV(0, 0, brightness));
                   canvas.addPixel(pos-i, CHSV(0, 0, brightness));
                }
              }
            }
        }
};

#endif