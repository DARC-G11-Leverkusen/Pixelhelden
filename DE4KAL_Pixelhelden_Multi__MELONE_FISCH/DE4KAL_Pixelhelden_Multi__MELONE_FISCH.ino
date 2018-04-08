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
#define numpixelsA 13
#define numpixelsB 14

LiquidCrystal lcd(9,8,7,6,5,4);
Adafruit_NeoPixel stripA = Adafruit_NeoPixel(numpixelsA, NEOPIN, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel stripB = Adafruit_NeoPixel(numpixelsB, NEOPIN, NEO_GRBW + NEO_KHZ800);

const int numspaltenA = 13;
const int numspaltenB = 14;

///////////////////////////////////////////////////////////////////////////////////

const int a = 1;
const int b = 2;
const int c = 3;
const int d = 4;
const int e = 5;
const int f = 6;
const int g = 7;

const int h = 8;
const int o = 9;
const int w = 10;
const int z = 11;
const int q = 12;
const int r = 13;

int ausgabeA[numpixelsA][numspaltenA] = {
       /* 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12 */
  /* 0*/{ 0, 0, 0, 0, 0, 0, 0, 0, 0, h, f, 0, 0},
  /* 1*/{ 0, 0, 0, 0, 0, 0, 0, 0, r, q, h, f, 0},
  /* 2*/{ 0, 0, 0, 0, 0, 0, 0, r, r, z, q, h, g},
  /* 3*/{ 0, 0, 0, 0, 0, 0, o, r, 0, r, w, h, g},
  /* 4*/{ 0, 0, 0, 0, 0, o, r, r, r, o, w, h, f},
  /* 5*/{ 0, 0, 0, 0, z, r, r, 0, o, o, w, h, f},
  /* 6*/{ 0, 0, 0, o, r, r, r, o, r, o, w, h, g},
  /* 7*/{ 0, 0, z, r, r, 0, r, r, r, z, w, h, g},
  /* 8*/{ 0, z, r, 0, r, z, o, o, o, w, h, f, g},
  /* 9*/{ h, q, z, o, o, o, o, z, w, h, f, g, 0},
  /*10*/{ g, h, q, w, w, w, w, w, h, f, g, 0, 0},
  /*11*/{ 0, g, h, h, h, h, h, h, g, g, 0, 0, 0},
  /*12*/{ 0, 0, 0, g, g, f, f, g, 0, 0, 0, 0, 0},
       /* 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12 */
};

int ausgabeB[numpixelsB][numspaltenB] = {
       /* 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13 */
  /* 0*/{ 0, 0, 0, 0, 0, 0, 0, 0, 0, a, a, 0, 0, 0},
  /* 1*/{ 0, 0, 0, 0, 0, 0, 0, 0, 0, b, b, a, 0, 0},
  /* 2*/{ 0, 0, 0, 0, 0, 0, 0, 0, 0, b, b, b, a, 0},
  /* 3*/{ 0, 0, 0, e, e, 0, b, b, c, c, b, b, b, f},
  /* 4*/{ 0, 0, e, b, b, b, b, b, d, c, f, f, f, 0},
  /* 5*/{ 0, 0, e, g, b, b, b, b, b, b, 0, 0, 0, 0},
  /* 6*/{ 0, 0, e, d, d, g, b, b, b, b, 0, 0, 0, 0},
  /* 7*/{ 0, b, b, b, d, d, d, b, b, f, 0, 0, 0, 0},
  /* 8*/{ 0, g, b, b, b, b, d, d, b, 0, 0, 0, 0, 0},
  /* 9*/{ b, d, d, d, e, e, a, d, f, 0, 0, 0, 0, 0},
  /*10*/{ b, 0, b, d, a, a, b, f, 0, 0, 0, 0, 0, 0},
  /*11*/{ b, b, b, d, d, b, f, 0, 0, 0, 0, 0, 0, 0},
  /*12*/{ f, b, b, b, f, f, 0, 0, 0, 0, 0, 0, 0, 0},
  /*13*/{ 0, f, f, f, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       /* 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13 */
};

int geschwindigkeit = 50;
int pixel;
int spalte;
int i;
byte tasterStateA;
byte tasterStateB;

///////////////////////////////////////////////////////////////////////////////////

void setup()  {
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  
  stripA.begin();
  stripA.setBrightness(60);
  stripA.show();

  stripB.begin();
  stripB.setBrightness(60);
  stripB.show();
  
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  pinMode(LED_BUILTIN, OUTPUT);
} 

///////////////////////////////////////////////////////////////////////////////////

void wait() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second 
  digitalWrite(LED_BUILTIN, HIGH);
  delay(geschwindigkeit*10);
  }

///////////////////////////////////////////////////////////////////////////////////

void loop()  {

  tasterStateA = digitalRead(4);
  tasterStateB = digitalRead(3);

  if(tasterStateA == 1){
    wait();
    for(spalte=0;spalte<numspaltenA;spalte++){
      for(pixel=0;pixel<numpixelsA;pixel++){
        switch (ausgabeA[pixel][spalte]) {                       
          case 6:{
            stripA.setPixelColor(pixel,  89, 102,  26,   0);
          } break;
          case 7:{
            stripA.setPixelColor(pixel,  68,  79,  14,   0);
          } break; 
          case 8:{
            stripA.setPixelColor(pixel, 132, 137,  32,   0);        
          } break;
          case 9:{
            stripA.setPixelColor(pixel, 192,  52,  38,   0);
          } break; 
          case 10:{
            stripA.setPixelColor(pixel, 214, 182, 155,   0);
          } break;    
          case 11:{
            stripA.setPixelColor(pixel, 202, 113,  93,   0);
          } break;  
          case 12:{
            stripA.setPixelColor(pixel, 198, 146, 120,   0);
          } break;   
          case 13:{
            stripA.setPixelColor(pixel, 189,  36,  23,   0);
          } break;
          default:{ 
            stripA.setPixelColor(pixel, 0, 0, 0, 0);
          } break;
        }
      }
      stripA.show();
      delay(geschwindigkeit);
    }
    
    for(i=0;i<numpixelsA;i++){
      stripA.setPixelColor(i, 0,0,0,0);
      stripA.show();
    }
    digitalWrite(LED_BUILTIN, LOW);           
  }

  else if(tasterStateB == 1){
    wait();
    for(spalte=0;spalte<numspaltenB;spalte++){
      for(pixel=0;pixel<numpixelsB;pixel++){
        switch (ausgabeB[pixel][spalte]) {
          case 1:{
            stripB.setPixelColor(pixel, 136,  72,  36,   0);
          } break;                          
          case 2:{
            stripB.setPixelColor(pixel, 244, 111,  32,   0);   
          } break;
          case 3:{
            stripB.setPixelColor(pixel, 230, 198, 179,   0);
          } break; 
          case 4:{
            stripB.setPixelColor(pixel, 248, 213, 192,   0);          
          } break;
          case 5:{
            stripB.setPixelColor(pixel, 169,  75,  29,   0);
          } break; 
          case 6:{
            stripB.setPixelColor(pixel,  32,  32,  32,   0);   
          } break;    
          case 7:{
            stripB.setPixelColor(pixel, 225, 151, 109,   0); 
          } break;
          default:{ 
            stripB.setPixelColor(pixel, 0, 0, 0, 0);
          } break;
        }
      }
      stripB.show();
      delay(geschwindigkeit);
    }
    
    for(i=0;i<numpixelsB;i++){
      stripB.setPixelColor(i, 0,0,0,0);
      stripB.show();
    }
    digitalWrite(LED_BUILTIN, LOW);    
  }
}

