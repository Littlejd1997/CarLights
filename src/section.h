#define FASTLED_INTERNAL
#include <FastLED.h>
#include "Arduino.h"
#ifndef Section_h
#define Section_h
class Section
{
public:
  Section(int num_leds);
  Section();
  void rainbow();
  void juggle();
  void setColor(CRGB color);
  void setHue(int hue);
  void setBrightness(int brightness);
  void getLEDS(CRGB *array);
  void confetti();

  int gHue = 200;
private:
  void confetti2();
  int num_leds;
  int _brightness = 0;
  CRGB* leds;
};
#endif
