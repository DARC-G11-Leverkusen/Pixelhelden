/*
Pixelhelden von Vincent Stallbaum, DL6II
Entwickelt für die jugendgruppe von IGEL e.V. und DARC e.V. OV G11 Leverkusen

Mit diesem Programm können Pixelgrafiken zum Lightpainten erzeugt werden. 
Die Ausgabe erfolgt auf einem beliebigen NeoPixel LED's.
Der Beispielcode geht von einem 16 Pixel langem RGBW Stripe aus.

Weitergabe und Weiterentwicklungen sind herzlich willkommen
Kontakt: dl6ii@vsas.de
*/

#include <LiquidCrystal.h>
#include <Adafruit_NeoPixel.h>

#define NEOPIN 0
#define NUMPIXELS 15

LiquidCrystal lcd(9,8,7,6,5,4);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, NEOPIN, NEO_GRBW + NEO_KHZ800);


uint32_t WS = strip.Color(0, 0, 0, 255);
uint32_t BN = strip.Color(9, 2, 0, 0);
uint32_t SZ = strip.Color(1, 1, 1, 0);
uint32_t HE = strip.Color(254, 74, 0, 32);
uint32_t __ = strip.Color(0, 0, 0, 0);
uint32_t ausgabe[15][28] = {
//      0  1  2  3  4  5  6  7  8  9  10 1 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27
/* 0*/{__,__,__,BN,BN,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__},    // 0
/* 1*/{BN,BN,BN,BN,BN,BN,BN,BN,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__},    // 2
/* 3*/{BN,BN,BN,BN,BN,BN,BN,BN,__,WS,WS,__,__,WS,WS,WS,__,WS,__,WS,__,WS,WS,WS,WS,__,WS,WS},    // 3
/* 4*/{BN,HE,HE,HE,HE,HE,HE,BN,__,WS,__,WS,__,WS,__,WS,__,WS,__,WS,__,__,WS,__,__,__,WS,__},    // 4
/* 5*/{HE,WS,SZ,HE,HE,SZ,WS,HE,__,WS,__,WS,__,WS,__,WS,__,WS,WS,WS,__,__,WS,WS,__,__,WS,__},    // 5
/* 6*/{HE,HE,HE,HE,HE,HE,HE,HE,__,WS,__,WS,__,WS,__,WS,__,__,__,WS,__,__,WS,__,__,__,WS,__},    // 6
/* 7*/{HE,HE,HE,SZ,SZ,SZ,HE,HE,__,WS,WS,__,__,WS,WS,WS,__,__,__,WS,__,__,WS,WS,WS,__,WS,WS},    // 7
/* 8*/{HE,HE,HE,HE,HE,HE,HE,HE,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__},    // 8
/* 9*/{__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,WS,WS,WS,WS,__,__,WS,__,__,WS,__,__},    // 9
/*10*/{WS,WS,WS,__,__,__,__,__,WS,WS,WS,__,__,__,__,__,WS,__,__,WS,__,WS,WS,__,WS,WS,__,__},    //10
/*11*/{__,__,WS,__,__,__,__,__,WS,__,__,__,__,__,__,__,WS,__,__,__,__,__,WS,__,__,WS,__,__},    //11
/*12*/{__,__,WS,__,WS,WS,WS,__,WS,WS,__,WS,__,WS,__,__,WS,__,WS,WS,__,__,WS,__,__,WS,__,__},    //12
/*13*/{WS,__,WS,__,WS,__,WS,__,WS,__,__,WS,__,WS,__,__,WS,__,__,WS,__,__,WS,__,__,WS,__,__},    //13
/*14*/{WS,WS,WS,__,WS,WS,WS,__,WS,__,__,WS,WS,WS,__,__,WS,WS,WS,WS,__,__,WS,__,__,WS,__,__},    //14

//      0  1  2  3  4  5  6  7  8
};
const int NUMSPALTEN = 28;
int countdown = 10;
int geschwindigkeit = 150;
int pixel;
int spalte;
int i;


void setup()  {
  strip.begin();
  strip.setBrightness(60);
  strip.show();
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  pinMode(LED_BUILTIN, OUTPUT);
} 


void loop()  {
  
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second 
  digitalWrite(LED_BUILTIN, HIGH);
  delay(geschwindigkeit*10);
   
    
  for(spalte=0;spalte<NUMSPALTEN;spalte++){
    for(pixel=0;pixel<NUMPIXELS;pixel++){
      strip.setPixelColor(pixel, ausgabe[pixel][spalte]);
/*      lcd.setCursor(0,0);
      lcd.print("Pixl:");
      if (pixel < 10) lcd.print("0");
      lcd.print(pixel);
      lcd.setCursor(7,0);
      lcd.print(" Clmn:");
      if (spalte < 10) lcd.print("0");
      lcd.print(spalte);
      lcd.setCursor(0,1); 
      lcd.print("Farbe:          ");
      lcd.setCursor(6,1);
      lcd.print(ausgabe[spalte][pixel]);
      delay(150); */
    }
    strip.show();
    delay(geschwindigkeit);
  }

  for(i=0;i<NUMPIXELS;i++){
    strip.setPixelColor(i, 0,0,0,0);
    strip.show();
  }
  digitalWrite(LED_BUILTIN, LOW);      
  delay(countdown);

                           
}

