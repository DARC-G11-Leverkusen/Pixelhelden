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

const int NUMSPALTEN = 28;

const int __ = 0;   // aus
const int WS = 1;   // weiss
const int SZ = 2;   // schwarz
const int AN = 3;   // blau (Augen)
const int RT = 4;   // rot
const int GO = 8;   // gold
const int GE = 9;   // gold

int ausgabe[NUMPIXELS][NUMSPALTEN] = {
//      0  1  2  3  4  5  6  7  8  9 10 11 12 13  14 15  16 17 18 19 20 21 22 23 24 25 26 27
/* 0*/{__,__,__,__,__,RT,RT,RT,RT,__,__,__,__,__, __,__ ,__,__,__,__,__,__,__,__,__,__,__,__},  // 0
/* 1*/{__,__,__,RT,RT,RT,RT,RT,RT,RT,RT,__,__,__, __,__ ,__,__,__,GE,GE,GE,GE,GE,__,__,__,__},  // 1
/* 2*/{__,__,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,__,__, __,__ ,__,GE,GE,GE,GE,GE,GE,GE,GE,__,__,__},  // 2
/* 3*/{__,RT,RT,RT,WS,WS,RT,RT,RT,RT,WS,WS,RT,__, __,__ ,GE,GE,GE,GE,GE,GE,GE,GE,GE,GE,__,__},  // 3
/* 4*/{__,RT,RT,WS,WS,WS,WS,RT,RT,WS,WS,WS,WS,__, __,__ ,GE,GE,GE,GE,GE,GE,GE,GE,GE,GE,GE,__},  // 4
/* 5*/{__,RT,RT,WS,WS,AN,AN,RT,RT,WS,WS,AN,AN,__, __,__ ,__,__,GE,GE,GE,GE,GE,GE,GE,GE,GE,GE},  // 5
/* 6*/{RT,RT,RT,WS,WS,AN,AN,RT,RT,WS,WS,AN,AN,RT, __,__ ,__,__,__,__,__,GE,GE,GE,GE,GE,GE,GE},  // 6
/* 7*/{RT,RT,RT,RT,WS,WS,RT,RT,RT,RT,WS,WS,RT,RT, GO,GO ,__,__,__,__,__,__,__,GE,GE,GE,GE,GE},  // 7
/* 8*/{RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT, GO,GO ,__,__,__,__,__,GE,GE,GE,GE,GE,GE,GE},  // 8
/* 9*/{RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT, __,__ ,__,__,GE,GE,GE,GE,GE,GE,GE,GE,GE,GE},  // 9
/*10*/{RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT, __,__ ,GE,GE,GE,GE,GE,GE,GE,GE,GE,GE,GE,__},  //10
/*11*/{RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT, __,__ ,GE,GE,GE,GE,GE,GE,GE,GE,GE,GE,__,__},  //11
/*12*/{RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT, __,__ ,__,GE,GE,GE,GE,GE,GE,GE,GE,__,__,__},  //12
/*13*/{RT,RT,__,RT,RT,RT,__,__,RT,RT,RT,__,RT,RT, __,__ ,__,__,__,GE,GE,GE,GE,GE,__,__,__,__},  //13
/*14*/{RT,__,__,__,RT,RT,__,__,RT,RT,__,__,__,RT, __,__ ,__,__,__,__,__,__,__,__,__,__,__,__},  //14
/*15*/{__,__,__,__,__,__,__,__,__,__,__,__,__,__, __,__ ,__,__,__,__,__,__,__,__,__,__,__,__}   //15
//      0  1  2  3  4  5  6  7  8  9 10 11 12 13  14 15  16 17 18 19 20 21 22 23 24 25 26 27 

};

int countdown = 10000;
int geschwindigkeit = 50;
int pixel;
int spalte;
int monster = 0;
int i;


void setup()  {
  strip.begin();
  strip.setBrightness(60);
  strip.show();
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  pinMode(LED_BUILTIN, OUTPUT);
} 


void stripeoff()  {
  for(i=0;i<NUMPIXELS;i++){
    strip.setPixelColor(i, 0,0,0,0);
    strip.show();
  }
}

void loop()  {
  
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second 
  digitalWrite(LED_BUILTIN, HIGH);
  delay(geschwindigkeit*10);
   
    
  for (spalte=0;spalte<NUMSPALTEN;spalte++){
    if (spalte==14){
      if (monster<3){
        monster = monster+1;
        spalte = 0;
        stripeoff();
        delay(geschwindigkeit*10);
      }else{
        stripeoff();
        delay(geschwindigkeit*5);
      }
    }
    if (spalte==16){
      if (monster>0){
        monster = monster-1;
        spalte = 14;
        stripeoff();
        delay(geschwindigkeit*5);
      }else{
        stripeoff();
        delay(geschwindigkeit*5);
      }
    }
    for (pixel=0;pixel<NUMPIXELS;pixel++){
      switch (ausgabe[pixel][spalte]){ 
        case 0:{
          strip.setPixelColor(pixel, 0, 0, 0, 0);       // aus
        } break;                          
        case 1:{
          strip.setPixelColor(pixel, 0, 0, 0, 255);     // weiss
        } break;
        case 2:{
          strip.setPixelColor(pixel, 0, 0, 0, 1);       // schwarz
        } break; 
        case 3:{
          strip.setPixelColor(pixel, 3, 36, 113, 60);   // blau (Augen)          
        } break;
        case 4:{
          switch (monster){
            case 0:{
              strip.setPixelColor(pixel, 255, 0, 0, 0);     // rot
            } break; 
            case 1:{
              strip.setPixelColor(pixel, 0, 255, 222, 0);   // tuerkis
            } break;    
            case 2:{
              strip.setPixelColor(pixel, 255, 145, 233, 0);   // rosa
            } break;  
            case 3:{
              strip.setPixelColor(pixel, 255, 80, 0, 0); // orange
            } break;  
          }
        } break;  
        case 8:{
          strip.setPixelColor(pixel, 155, 84, 122, 100);// gold
        } break;   
        case 9:{
          strip.setPixelColor(pixel, 255, 150, 0, 0); // gelb
        } break;   
        default:{ 
          strip.setPixelColor(pixel, 0, 0, 0, 0);
        } break;
      }   


    }
    strip.show();
    delay(geschwindigkeit);
  }

  stripeoff();
  digitalWrite(LED_BUILTIN, LOW);      
  delay(countdown);
                          
}





