#include<FastLED.h>
#define NUM_LEDS 60
#define PIN 6

int x;
CRGB leds[NUM_LEDS];

void setup() {

  FastLED.addLeds<NEOPIXEL, PIN>(leds, NUM_LEDS);

  LEDS.showColor(CRGB(255, 0, 0));
  delay(500);
  LEDS.showColor(CRGB(0, 255, 0));
  delay(500);
  LEDS.showColor(CRGB(0, 0, 255));
  delay(500);
  LEDS.showColor(CRGB(0, 0, 0));

  Serial.begin(9600);
}

void create(float x){
  int r;
  int g;
  int b;
  
  //0-20 is cold
  if( x >= 0 && x <= 20 ){
    r=0;  g=0; b=175;
  }
  
  //20-30 is pleasent
  else if( x > 20 && x <= 30 ){
    r=118; g=215; b=0;
  }
  
  //30-40 is hot and after it critical
  else if( x > 30 && x <= 40 ){
    r=175; g=143; b=41;
  }
  
  //too hot
  else if( x > 40 ){
    r=175; g=41; b=41;
  }
 
  for(int i=0; i<NUM_LEDS; i++){
    leds[i] = CRGB(r+x, g+x, b+x);
    FastLED.show();
  }
}

void loop() {
    x = Serial.read();
    for(int i=0; i<50; i++){
        create(273.3-x);
        delay(30);
    }
}
