#define FASTLED_INTERNAL
#include "Arduino.h"
#include <avr/interrupt.h>
#include "section.h"
#include <FastLED.h>
#define DATA_PIN    5
#define BRIGHTNESS 50
#define LED_TYPE    WS2812
#define COLOR_ORDER GRB
#define NUM_LEDS    176
#define NUM_SECTIONS 3
int sizes[NUM_SECTIONS];
int inputAudio = 0;
int previousRead = 0;
int upwards = true;
uint64_t lastSetMills = 0;
int currentBrightness = 0;
CRGB leds[NUM_LEDS];
Section sections[NUM_SECTIONS];
void combineArrays();
void randomPerSection();
