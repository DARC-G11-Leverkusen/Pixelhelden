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

LiquidCrystal lcd(9,8,7,6,5,4);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, NEOPIN, NEO_GRBW + NEO_KHZ800);



int wc = 0;
int i,j;
int delayval = 500;

uint32_t oldcolor;
uint32_t newcolor;


void setup()  {
  strip.begin();
  strip.show();
  lcd.begin(16,2);
} 

void loop()  {

  int t;
  for (int i = 0; i < strip.numPixels(); i++) {
    wc++;
    strip.setPixelColor(i, Wheel(wc));
    t = i - 1;
    if (t < 0) t = strip.numPixels() - 1;
    strip.setPixelColor(t, strip.Color( 0, 0, 0));
    strip.show();
    delay(50);
  }
  for (int i = strip.numPixels()-1; i >= 0; i--) {
    wc++;
    strip.setPixelColor(i, Wheel(wc));
    t = i + 1;
    if (t >= strip.numPixels()) t = 0;
    strip.setPixelColor(t, strip.Color( 0, 0, 0));
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

