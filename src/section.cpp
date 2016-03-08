#include "section.h"

Section::Section(int nums)
{
  num_leds = nums;
  leds = new CRGB[nums];
  memset(leds, nums, nums*3);
  gHue = 0;
    EVERY_N_MILLISECONDS( 10 ) { gHue +=5; }

}
Section::Section(){

}
void Section::setColor(CRGB color){
  for (int i = 0; i != num_leds; i++){
    leds[i] = color;
  }
}
void Section::setBrightness(int brightness){
  _brightness = ((double) brightness/100)*255;
}
void Section::setHue(int hue){
  for (int i = 0; i != num_leds; i++){
    leds[i].setHSV(hue,255,_brightness);
  }
}
void Section::getLEDS(CRGB *array){
  for (int i = 0; i != num_leds;i++){
    array[i] = leds[i];
  }
}
void Section::rainbow(){
  gHue += 1;
  fill_rainbow( leds, num_leds, gHue, 7);
}
void Section::confetti()
{
    fadeToBlackBy( leds, num_leds, 1);
    confetti2();
}
void Section::confetti2()
{
  // random colored speckles that blink in and fade smoothly
//  fadeToBlackBy( leds, NUM_LEDS, 50);
  int pos = random16(num_leds);
  if (random(4) == 0){
    return;
  }
  leds[pos] = (random(2) == 0) ? CRGB::Purple : CRGB::Gold;
}
void Section::juggle(){
  // eight colored dots, weaving in and out of sync with each other
  fadeToBlackBy( leds, num_leds, 1);
  byte dothue = 0;
  for( int i = 0; i < 6; i++) {
//    leds[beatsin16(i+7,0,NUM_LEDS)] |= (dothue % 2 == 0) ? CHSV( 52, 255, 255) : CHSV(255,124,170);
leds[beatsin16(i+5,0,num_leds)] = (dothue % 2 == 0) ? CRGB::Gold : CRGB::Purple;
//    leds[beatsin16(i+7,0,NUM_LEDS)] |= ((dothue % 2 == 0) ? CRGB::Blue : CRGB::MediumPurple);
    dothue++;
  }
  confetti2();
}
