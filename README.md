# mica-blinker

Arduino + LEDs = ❤️

A 1-dimensional action game where the player has to parry colorful projectiles coming in from both sides.

This project was created during the tarent MICA 2018 hackathon and is a joint effort of [@walternummerdrei](https://github.com/walternummerdrei), [@charbul](https://github.com/charbul), [@abe-frickelbude](https://github.com/abe-frickelbude) and [@hannesrohde](https://github.com/hannesrohde).

## Hardware

- Arduino Nano V3 or compatible
- SK9822 LED strip (1m, 144 LEDs)

The LED strip is attached to the ICSP port of the Nano:

- +vcc  -> ICSP pin 2
- clock -> ICSP pin 3
- data  -> ICSP pin 4
- gnd   -> ICSP pin 6

For game controls, two push-buttons (or the x-axis of a joystick) are connected between the digital pins D3/D5 and GND.

```
             |
      o------+ GND
      |      | D2
      o--/ --+ D3
      |      | D4
      o--/ --+ D5
             |

```

## Use of third-party software

- [Arduino](https://www.arduino.cc/) framework
- [FastLED](https://github.com/FastLED/FastLED) (MIT license)

## Release Notes / Changelog

### Version 1.0.0 / 2018-09-22
  
first release shown during the MICA hackathon results presentation
