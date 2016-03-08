#include "main.h"

void setup() {
  Serial.begin(9600);
  sizes[0] = 75;
  sizes[1] = 150/2;
  sizes[2] = 26;
  for (int i = 0; i != NUM_SECTIONS;i++){
    sections[i] = Section(sizes[i]);
  }
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  sections[0].setBrightness(BRIGHTNESS);
  sections[1].setBrightness(BRIGHTNESS);
}

void loop() {
  inputAudio = analogRead(0);
  if (inputAudio < previousRead && upwards){
      int brightness = map(previousRead,0,65,10,100);
    if (brightness >currentBrightness+10 ){
      if (lastSetMills+200 < millis()){
        lastSetMills = millis();
        randomPerSection();
      }
      currentBrightness = brightness;
    }else if(brightness <currentBrightness-10){
      currentBrightness = brightness;
    }
    upwards = false;
  }
  if (inputAudio > previousRead){
    upwards =true;
  }
  previousRead = inputAudio;
  combineArrays();
  FastLED.show();
}

void combineArrays(){
  for (int s = 0; s != NUM_SECTIONS; s++){
    CRGB temp[sizes[s]];
    int padding = 0;
    for (int x = 0; x != s; x++){
      padding += sizes[x];
    }
    sections[s].getLEDS(temp);
    for(int i = 0; i != sizes[s]; i++){
      leds[padding+i] = temp[i];
    }
  }

}
void randomPerSection(){
    sections[random(0,NUM_SECTIONS)].setHue(random8(0,255));
}
