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
  if( x>0 && x<5){r; g; b;}
  else if( x>5 && x<8){r; g; b;}
  else if( x>5 && x<8){r; g; b;}
  else if( x>8 && x<10){r; g; b;}
  else if( x>10 && x<13){r; g; b;}
  else if( x>13 && x<15){r; g; b;}
  else if( x>15 && x<18){r; g; b;}
  else if( x>18 && x<20){r; g; b;}
  else if( x>20 && x<22){r; g; b;}
  else if( x>22 && x<24){r; g; b;}
  else if( x>24 && x<27){r; g; b;}
  else if( x>27 && x<30){r; g; b;}
  else if( x>30 && x<32){r; g; b;}
  else if( x>32 && x<34){r; g; b;}
  else if( x>34 && x<36){r; g; b;}
  else if( x>36 && x<38){r; g; b;}
  else if( x>38 && x<40){r; g; b;}
  else if( x>40 && x<41){r; g; b;}
  else if( x>41 && x<42){r; g; b;}
  else if( x>42 && x<43){r; g; b;}
  else if( x>43 && x<44){r; g; b;}
  else if( x>44 && x<45){r; g; b;}
  else if( x>45 && x<46){r; g; b;}

  for(int i=0; i<NUM_LEDS; i++){
    leds[i] = CRGB(r, g, b);
    FastLED.show();
  }
}
void loop() {
    x = Serial.read();
    for(int i=0; i<50; i++){
        create(273.3-x);
        delay(100);
    }
}