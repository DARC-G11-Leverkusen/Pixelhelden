/*

*/

#include <LiquidCrystal.h>
#include <Adafruit_NeoPixel.h>

#define NEOPIN 0
#define NUMPIXELS 16

LiquidCrystal lcd(9,8,7,6,5,4);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, NEOPIN, NEO_GRBW + NEO_KHZ800);

uint32_t r = strip.Color(1, 0, 0, 0);
uint32_t g = strip.Color(0, 1, 0, 0);
uint32_t b = strip.Color(0, 0, 1, 0);
uint32_t w = strip.Color(1, 1, 1, 1);
uint32_t rgbw = strip.Color(0, 0, 0, 1);
uint32_t rr = strip.Color(255, 0, 0, 0);
uint32_t gg = strip.Color(0, 255, 0, 0);
uint32_t bb = strip.Color(0, 0, 255, 0);
uint32_t ww = strip.Color(0, 0, 0, 255);
uint32_t rrggbbww = strip.Color(255, 255, 255, 255);

const int NUMSPALTEN = 17;
int geschwindigkeit = 10;
int i;


void setup()  {
  strip.begin();
  strip.show();
  lcd.begin(16,2);
  lcd.setCursor(0,0);
} 


void loop()  {
      
  for(i=0;i<NUMPIXELS;i++){
      strip.setPixelColor(i, r);
      lcd.setCursor(0,0);
      lcd.print("Pixl:");
      if (i < 10) lcd.print("0");
      lcd.print(i);
      lcd.setCursor(0,1); 
      lcd.print("Test R 001      ");
      delay(geschwindigkeit*3);     
    strip.show();
    delay(geschwindigkeit);
  }
  
  for(i=0;i<NUMPIXELS;i++){
    strip.setPixelColor(i, 0,0,0,0);
    strip.show();
  }

  for(i=0;i<NUMPIXELS;i++){
      strip.setPixelColor(i, g);
      lcd.setCursor(0,0);
      lcd.print("Pixl:");
      if (i < 10) lcd.print("0");
      lcd.print(i);
      lcd.setCursor(0,1); 
      lcd.print("Test G 001      ");
      delay(geschwindigkeit*3);     
    strip.show();
    delay(geschwindigkeit);
  }

  for(i=0;i<NUMPIXELS;i++){
      strip.setPixelColor(i, b);
      lcd.setCursor(0,0);
      lcd.print("Pixl:");
      if (i < 10) lcd.print("0");
      lcd.print(i);
      lcd.setCursor(0,1); 
      lcd.print("Test B 001      ");
      delay(geschwindigkeit*3);     
    strip.show();
    delay(geschwindigkeit);
  }

    for(i=0;i<NUMPIXELS;i++){
      strip.setPixelColor(i, w);
      lcd.setCursor(0,0);
      lcd.print("Pixl:");
      if (i < 10) lcd.print("0");
      lcd.print(i);
      lcd.setCursor(0,1); 
      lcd.print("Test W 001      ");
      delay(geschwindigkeit*3);     
    strip.show();
    delay(geschwindigkeit);
  }

    for(i=0;i<NUMPIXELS;i++){
      strip.setPixelColor(i, rgbw);
      lcd.setCursor(0,0);
      lcd.print("Pixl:");
      if (i < 10) lcd.print("0");
      lcd.print(i);
      lcd.setCursor(0,1); 
      lcd.print("Test RGBW 001   ");
      delay(geschwindigkeit*3);     
    strip.show();
  }
  delay(geschwindigkeit*30);
    for(i=0;i<NUMPIXELS;i++){
      strip.setPixelColor(i, rr);
      lcd.setCursor(0,0);
      lcd.print("Pixl:");
      if (i < 10) lcd.print("0");
      lcd.print(i);
      lcd.setCursor(0,1); 
      lcd.print("Test R 255      ");
      delay(geschwindigkeit*3);     
    strip.show();
    delay(geschwindigkeit);
  }
  
  for(i=0;i<NUMPIXELS;i++){
    strip.setPixelColor(i, 0,0,0,0);
    strip.show();
  }

  for(i=0;i<NUMPIXELS;i++){
      strip.setPixelColor(i, gg);
      lcd.setCursor(0,0);
      lcd.print("Pixl:");
      if (i < 10) lcd.print("0");
      lcd.print(i);
      lcd.setCursor(0,1); 
      lcd.print("Test G 255      ");
      delay(geschwindigkeit*3);     
    strip.show();
    delay(geschwindigkeit);
  }

  for(i=0;i<NUMPIXELS;i++){
      strip.setPixelColor(i, bb);
      lcd.setCursor(0,0);
      lcd.print("Pixl:");
      if (i < 10) lcd.print("0");
      lcd.print(i);
      lcd.setCursor(0,1); 
      lcd.print("Test B 255      ");
      delay(geschwindigkeit*3);     
    strip.show();
    delay(geschwindigkeit);
  }

    for(i=0;i<NUMPIXELS;i++){
      strip.setPixelColor(i, ww);
      lcd.setCursor(0,0);
      lcd.print("Pixl:");
      if (i < 10) lcd.print("0");
      lcd.print(i);
      lcd.setCursor(0,1); 
      lcd.print("Test W 255      ");
      delay(geschwindigkeit*3);     
    strip.show();
    delay(geschwindigkeit);
  }

    for(i=0;i<NUMPIXELS;i++){
      strip.setPixelColor(i, rrggbbww);
      lcd.setCursor(0,0);
      lcd.print("Pixl:");
      if (i < 10) lcd.print("0");
      lcd.print(i);
      lcd.setCursor(0,1); 
      lcd.print("Test RGBW 255   ");
      delay(geschwindigkeit*3);     
    strip.show();
    delay(geschwindigkeit);
    }
  
  lcd.setCursor(0,0);
  lcd.print("Rainbowtest     ");
  lcd.setCursor(0,1); 
  lcd.print("                ");
    rainbowCycle(30);
}

void rainbowCycle(int SpeedDelay) {
  byte *c;
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< NUMPIXELS; i++) {
      c=Wheel(((i * 256 / NUMPIXELS) + j) & 255);
      setPixel(i, *c, *(c+1), *(c+2));
    }
    showStrip();
    delay(SpeedDelay);
  }
}

byte * Wheel(byte WheelPos) {
  static byte c[3];
  
  if(WheelPos < 85) {
   c[0]=WheelPos * 3;
   c[1]=255 - WheelPos * 3;
   c[2]=0;
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   c[0]=255 - WheelPos * 3;
   c[1]=0;
   c[2]=WheelPos * 3;
  } else {
   WheelPos -= 170;
   c[0]=0;
   c[1]=WheelPos * 3;
   c[2]=255 - WheelPos * 3;
  }

  return c;
}
// *** REPLACE TO HERE ***

void showStrip() {
 #ifdef ADAFRUIT_NEOPIXEL_H 
   // NeoPixel
   strip.show();
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H
   // FastLED
   FastLED.show();
 #endif
}

void setPixel(int Pixel, byte red, byte green, byte blue) {
 #ifdef ADAFRUIT_NEOPIXEL_H 
   // NeoPixel 
   strip.setPixelColor(Pixel, strip.Color(red, green, blue));
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H 
   // FastLED
   leds[Pixel].r = red;
   leds[Pixel].g = green;
   leds[Pixel].b = blue;
 #endif
}

void setAll(byte red, byte green, byte blue) {
  for(int i = 0; i < NUMPIXELS; i++ ) {
    setPixel(i, red, green, blue); 
  }
  showStrip();
                           
}

