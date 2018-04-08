/*
Pixelhelden von Vincent Stallbaum, DL6II
Entwickelt für die jugendgruppe von IGEL e.V. und DARC e.V. OV G11 Leverkusen

Mit diesem Programm können Pixelgrafiken zum Lightpainten erzeugt werden. 
Die Ausgabe erfolgt auf einem beliebigen NeoPixel LED's.
Der Beispielcode geht von einem 16 Pixel langem RGBW Stripe aus.

Weitergabe und Weiterentwicklungen sind herzlich willkommen
Kontakt: dl6ii@vsas.de
*/

///////////////////////////////////////////////////////////////////////////////////

#include <Adafruit_NeoPixel.h>

#define NEOPIN 0
#define numpixelsA 13
#define numpixelsB 14
#define numpixelsC 12
#define numpixelsD 13
#define numpixelsE 13

Adafruit_NeoPixel stripA = Adafruit_NeoPixel(numpixelsA, NEOPIN, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel stripB = Adafruit_NeoPixel(numpixelsB, NEOPIN, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel stripC = Adafruit_NeoPixel(numpixelsC, NEOPIN, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel stripD = Adafruit_NeoPixel(numpixelsC, NEOPIN, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel stripE = Adafruit_NeoPixel(numpixelsC, NEOPIN, NEO_GRBW + NEO_KHZ800);

const int numspaltenA = 13;
const int numspaltenB = 14;
const int numspaltenC = 12;
const int numspaltenD = 13;
const int numspaltenE = 13;

char ausgabeState = 1;
int geschwindigkeit = 50;
int pixel;
int spalte;
int i;
byte tasterStateA;
byte tasterStateB;
byte tasterStateC;
int stopp = 320;

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

int ausgabeA[numspaltenA][numpixelsA] = {
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

int ausgabeB[numspaltenB][numpixelsB] = {
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

int ausgabeC[numpixelsC][numspaltenC] = {
       /* 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 */
  /* 0*/{ 0, 2, 0, 2, 0, 0, 2, 0, 2, 0},
  /* 1*/{ 0, 0, 2, 2, 2, 2, 2, 2, 0, 0},
  /* 2*/{ 0, 1, 4, 1, 1, 1, 1, 1, 1, 0},
  /* 3*/{ 1, 1, 4, 3, 1, 3, 1, 3, 1, 1},
  /* 4*/{ 1, 4, 1, 1, 1, 1, 1, 1, 1, 1},
  /* 5*/{ 1, 1, 1, 1, 3, 1, 3, 1, 1, 1},
  /* 6*/{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
  /* 7*/{ 0, 1, 1, 1, 1, 3, 1, 1, 1, 0},
  /* 8*/{ 0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
  /* 9*/{ 0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
  /*10*/{ 0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
  /*11*/{ 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
       /* 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 */
};

int ausgabeD[numpixelsD][numspaltenD] = {
       /* 0, 1, 2, 3, 4, 5, 6, 7, 8*/
  /* 0*/{ 3, 3, 3, 0, 0, 0, 0, 0, 0},
  /* 1*/{ 0, 3, 3, 3, 0, 0, 0, 0, 0},
  /* 2*/{ 0, 0, 0, 0, 4, 0, 0, 0, 0},
  /* 3*/{ 0, 0, 1, 1, 4, 1, 1, 0, 0},
  /* 4*/{ 0, 1, 1, 1, 1, 1, 1, 1, 0},
  /* 5*/{ 0, 1, 2, 1, 1, 1, 1, 1, 0},
  /* 6*/{ 1, 1, 2, 1, 1, 1, 1, 1, 1},
  /* 7*/{ 1, 2, 1, 1, 1, 1, 1, 1, 1},
  /* 8*/{ 1, 1, 1, 1, 1, 1, 1, 1, 1},
  /* 9*/{ 1, 1, 1, 1, 1, 1, 1, 1, 1},
  /*10*/{ 0, 1, 1, 1, 1, 1, 1, 1, 0},
  /*11*/{ 0, 1, 1, 1, 1, 1, 1, 1, 0},
  /*12*/{ 0, 0, 1, 1, 1, 1, 1, 0, 0},
       /* 0, 1, 2, 3, 4, 5, 6, 7, 8 */
};

int ausgabeE[numpixelsE][numspaltenE] = {
       /* 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10 */
  /* 0*/{ 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 0},
  /* 1*/{ 0, 0, 0, 0, 0, 0, 3, 3, 3, 0, 0},
  /* 2*/{ 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0},
  /* 3*/{ 0, 0, 1, 1, 1, 4, 1, 1, 1, 0, 0},
  /* 4*/{ 0, 1, 1, 2, 2, 1, 1, 1, 1, 1, 0},
  /* 5*/{ 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1},
  /* 6*/{ 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1},
  /* 7*/{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  /* 8*/{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  /* 9*/{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  /* 4*/{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
  /* 3*/{ 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
  /*12*/{ 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0},
       /* 0, 1, 2, 3, 4, 5, 6, 7, 8 */
};

///////////////////////////////////////////////////////////////////////////////////

void setup()  {
  pinMode(4, INPUT);
  pinMode(3, INPUT);
  pinMode(2, INPUT);
  
  stripA.begin();
  stripA.setBrightness(60);
  stripA.show();

  stripB.begin();
  stripB.setBrightness(60);
  stripB.show();

  stripC.begin();
  stripC.setBrightness(60);
  stripC.show();
  
  pinMode(LED_BUILTIN, OUTPUT);
} 

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

void loop(){
  tasterStateA = digitalRead(4);
  tasterStateB = digitalRead(3);
  tasterStateC = digitalRead(15);

  if(tasterStateB == HIGH){
    ausgabeState++;
    digitalWrite(LED_BUILTIN, HIGH);    // turn the LED off by making the voltage LOW
    delay(500);                       // wait for a second 
    digitalWrite(LED_BUILTIN, LOW);
  }
  if(ausgabeState > 5 || ausgabeState <= 0){
    ausgabeState = 1;
  }

  if(tasterStateA == 1 && ausgabeState == 1){
    wait();
    melone();
  }

  else if(tasterStateA == 1 && ausgabeState == 2){
    wait();
    fisch();
  }

  else if(tasterStateA == 1 && ausgabeState == 3){
    wait();
    erdbeere();
  }
  
  else if(tasterStateA == 1 && ausgabeState == 4){
    wait();
    pflaume();
  }

  else if(tasterStateA == 1 && ausgabeState == 5){
    wait();
    apfel();
  }

  if(tasterStateC == HIGH){
    wait();
    melone();
    delay(stopp);
    fisch();
    delay(stopp);
    erdbeere();
    delay(stopp);
    pflaume();
    delay(stopp);
    apfel();
  }
}

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

void melone(){
  digitalWrite(LED_BUILTIN, HIGH);
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

void fisch(){
  digitalWrite(LED_BUILTIN, HIGH);
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

void erdbeere(){
  digitalWrite(LED_BUILTIN, HIGH);
  for(spalte=0;spalte<numspaltenC;spalte++){
      for(pixel=0;pixel<numpixelsC;pixel++){
        switch (ausgabeC[pixel][spalte]) {                       
          case 1:{
            stripC.setPixelColor(pixel, 255,   0,   0,   0);
          } break;                          
          case 2:{
            stripC.setPixelColor(pixel,   0, 156,  64,   0);   
          } break;
          case 3:{
            stripC.setPixelColor(pixel, 235, 155,  94,   0);
          } break; 
          case 4:{
            stripC.setPixelColor(pixel, 241, 114, 123,   0);          
          } break;
          default:{ 
            stripC.setPixelColor(pixel, 0, 0, 0, 0);
          } break;
        }
      }
      stripC.show();
      delay(geschwindigkeit);
    }
    
    for(i=0;i<numpixelsC;i++){
      stripC.setPixelColor(i, 0,0,0,0);
      stripC.show();
    }
    digitalWrite(LED_BUILTIN, LOW);
}

void pflaume(){
  digitalWrite(LED_BUILTIN, HIGH);
  for(spalte=0;spalte<numspaltenD;spalte++){
      for(pixel=0;pixel<numpixelsD;pixel++){
        switch (ausgabeD[pixel][spalte]) {                       
          case 1:{
            stripD.setPixelColor(pixel, 147,  70, 102,   0);
          } break;                          
          case 2:{
            stripD.setPixelColor(pixel, 199, 120, 152,   0);   
          } break;
          case 3:{
            stripD.setPixelColor(pixel,  83, 150, 119,   0);
          } break; 
          case 4:{
            stripD.setPixelColor(pixel,  32,  32,  32,   0);          
          } break;
          default:{ 
            stripD.setPixelColor(pixel, 0, 0, 0, 0);
          } break;
        }
      }
      stripD.show();
      delay(geschwindigkeit);
    }
    
    for(i=0;i<numpixelsD;i++){
      stripD.setPixelColor(i, 0,0,0,0);
      stripD.show();
    }
    digitalWrite(LED_BUILTIN, LOW);
}

void apfel(){
  digitalWrite(LED_BUILTIN, HIGH);
  for(spalte=0;spalte<numspaltenE;spalte++){
      for(pixel=0;pixel<numpixelsE;pixel++){
        switch (ausgabeD[pixel][spalte]) {                       
          case 1:{
            stripE.setPixelColor(pixel, 255,   0,   0,   0);
          } break;                          
          case 2:{
            stripE.setPixelColor(pixel, 232, 122, 109,   0);   
          } break;
          case 3:{
            stripE.setPixelColor(pixel, 130, 195,  43,   0);
          } break; 
          case 4:{
            stripE.setPixelColor(pixel,  32,  32,  32,   0);          
          } break;
          default:{ 
            stripE.setPixelColor(pixel, 0, 0, 0, 0);
          } break;
        }
      }
      stripE.show();
      delay(geschwindigkeit);
    }
    
    for(i=0;i<numpixelsE;i++){
      stripE.setPixelColor(i, 0,0,0,0);
      stripE.show();
    }
    digitalWrite(LED_BUILTIN, LOW);
}


void wait(){
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second 
  delay(geschwindigkeit*10);
}


