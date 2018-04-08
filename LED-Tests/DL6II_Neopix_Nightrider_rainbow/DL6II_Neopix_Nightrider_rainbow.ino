/*
** Rotary Encoder Example
** Use the Sparkfun Rotary Encoder to vary brightness of LED
  int white = min(red, green);
  white = min(white, blue);
  red = red - white;
  green = green - white;
  blue = blue - white;
** Sample the encoder at 200Hz using the millis() function
*/

#include <LiquidCrystal.h>
#include <Adafruit_NeoPixel.h>

#define NEOPIN 0
#define NUMPIXELS 16

LiquidCrystal lcd(13,12,11,10,9,8);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, NEOPIN, NEO_GRBW + NEO_KHZ800);



int wc = 0;
int i,j;
int delayval = 500;

uint32_t oldcolor;
uint32_t newcolor;


void setup()  {
  strip.begin();
  strip.setBrightness(60);
  strip.show();
  lcd.begin(16,2);
} 

void loop()  {

  int t;
  for (int i = 0; i < strip.numPixels(); i++) {
    wc++;
    strip.setPixelColor(i, Wheel(wc));

    strip.show();
    delay(50);
  }
  for (int i = strip.numPixels()-1; i >= 0; i--) {
    wc++;
    strip.setPixelColor(i, Wheel(wc));

    strip.show();
    delay(50);
  }
  //wc++;
  if (wc>255) wc=0;
}

uint32_t Wheel(byte WheelPos) {
  if (WheelPos < 85) {
    return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
    WheelPos -= 170;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
                          
}

