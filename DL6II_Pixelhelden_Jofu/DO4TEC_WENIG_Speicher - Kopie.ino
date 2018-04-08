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
#define NUMPIXELS 16

LiquidCrystal lcd(9,8,7,6,5,4);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, NEOPIN, NEO_GRBW + NEO_KHZ800);

uint32_t lila = strip.Color(40, 9, 102, 40);
uint32_t gruen = strip.Color(101, 159, 23, 40);
uint32_t schwarz = strip.Color(0, 0, 0, 0);
int ausgabe[16][17] = {
//      0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 
/* 0*/{0,0,0,1,1,0,0,0,0,0,0,0,2,2,0,0,0},    // 0
/* 1*/{0,0,1,1,1,1,0,0,0,0,0,2,2,2,2,0,0},    // 1
/* 2*/{0,1,1,1,1,1,1,0,0,0,2,2,2,2,2,2,0},    // 2
/* 3*/{1,1,0,1,1,0,1,1,0,2,2,0,2,2,0,2,2},    // 3
/* 4*/{1,1,1,1,1,1,1,1,0,2,2,2,2,2,2,2,2},    // 4
/* 5*/{0,0,1,0,0,1,0,0,0,0,2,0,2,2,0,2,0},    // 5
/* 6*/{0,1,0,1,1,0,1,0,0,2,0,0,0,0,0,0,2},    // 6
/* 7*/{1,0,1,0,0,1,0,1,0,0,2,0,0,0,0,2,0},    // 7
/* 8*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},    // 8
/* 9*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},    // 9
/*10*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},    //10
/*11*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},    //11
/*12*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},    //12
/*13*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},    //13
/*14*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},    //14
/*15*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}     //15
//      0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 
};

const int NUMSPALTEN = 17;
int countdown = 10000;
int geschwindigkeit = 50;
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
      switch (ausgabe[pixel][spalte]) { 
        case 0:{
          strip.setPixelColor(pixel, schwarz);
        } break;                          
        case 1:{
          strip.setPixelColor(pixel, lila);
        } break;
        case 2:{
          strip.setPixelColor(pixel, gruen); 
        } break; 
        case 3:{
          strip.setPixelColor(pixel, schwarz);
        } break;
        case 4:{
          strip.setPixelColor(pixel, schwarz);
        } break; 
        case 5:{
          strip.setPixelColor(pixel, schwarz);
        } break;       
        default:{ 
          strip.setPixelColor(pixel, schwarz);
        } break;
      }   

      
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

