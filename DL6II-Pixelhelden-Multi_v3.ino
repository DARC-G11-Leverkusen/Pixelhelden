/*
Pixelhelden von Vincent Stallbaum, DL6II
Entwickelt für die jugendgruppe von IGEL e.V. und DARC e.V. OV G11 Leverkusen

Mit diesem Programm können Pixelgrafiken zum Lightpainten erzeugt werden. 
Die Ausgabe erfolgt auf einem beliebigen NeoPixel LED's.
Der Beispielcode geht von einem 16 Pixel langem RGBW Stripe aus.

Weitergabe und Weiterentwicklungen sind herzlich willkommen
Kontakt: dl6ii@vsas.de
*/


#include <Adafruit_NeoPixel.h>

#define NEOPIN 0
#define NUMPIXELS 16

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, NEOPIN, NEO_GRBW + NEO_KHZ800);
char _ = 0;   // aus 

#define NUMPIXELS1 11
#define NUMSPALTEN1 14 
char ausgabe1[NUMPIXELS1][NUMSPALTEN1] = {
//      0 1 2 3 4 5 6 7 8 9 a b e d
/* 0 */{_,_,_,_,_,_,_,_,_,_,4,4,_,_},  // 0
/* 1 */{_,_,_,_,_,_,_,_,_,4,6,4,4,4},  // 1
/* 2 */{_,_,_,_,_,_,_,_,4,4,4,4,6,_},  // 2
/* 3 */{1,9,_,9,1,9,_,_,_,4,5,6,6,4},  // 3
/* 4 */{_,1,1,9,7,_,_,_,_,4,2,3,_,_},  // 4
/* 5 */{9,9,1,7,7,1,_,_,_,_,8,_,_,_},  // 5
/* 6 */{_,_,2,2,_,_,_,_,_,8,2,_,_,_},  // 6
/* 7 */{_,_,2,3,2,3,_,_,_,_,3,2,_,_},  // 7
/* 8 */{3,2,2,3,3,_,_,_,_,_,_,2,8,_},  // 8
/* 9 */{_,3,2,3,_,_,_,_,_,_,8,3,_,_},  // 9
/* a */{_,_,2,3,_,_,_,_,_,_,_,3,_,_}   // a
//      0 1 2 3 4 5 6 7 8 9 a b e d
};

#define NUMPIXELS2 15
#define NUMSPALTEN2 28
int monster = 0;
char ausgabe2[NUMPIXELS2][NUMSPALTEN2] = {
//      0 1 2 3 4 5 6 7 8 9 a b c d  e f  g h i j k l m n o p q r 
/* 0 */{_,_,_,_,_,4,4,4,4,_,_,_,_,_, _,_ ,_,_,_,_,_,_,_,_,_,_,_,_},  // 0
/* 1 */{_,_,_,4,4,4,4,4,4,4,4,_,_,_, _,_ ,_,_,_,9,9,9,9,9,_,_,_,_},  // 1
/* 2 */{_,_,4,4,4,4,4,4,4,4,4,4,_,_, _,_ ,_,9,9,9,9,9,9,9,9,_,_,_},  // 2
/* 3 */{_,4,4,4,1,1,4,4,4,4,1,1,4,_, _,_ ,9,9,9,9,9,9,9,9,9,9,_,_},  // 3
/* 4 */{_,4,4,1,1,1,1,4,4,1,1,1,1,_, _,_ ,9,9,9,9,9,9,9,9,9,9,9,_},  // 4
/* 5 */{_,4,4,1,1,3,3,4,4,1,1,3,3,_, _,_ ,_,_,9,9,9,9,9,9,9,9,9,9},  // 5
/* 6 */{4,4,4,1,1,3,3,4,4,1,1,3,3,4, _,_ ,_,_,_,_,_,9,9,9,9,9,9,9},  // 6
/* 7 */{4,4,4,4,1,1,4,4,4,4,1,1,4,4, 8,8 ,_,_,_,_,_,_,_,9,9,9,9,9},  // 7
/* 8 */{4,4,4,4,4,4,4,4,4,4,4,4,4,4, 8,8 ,_,_,_,_,_,9,9,9,9,9,9,9},  // 8
/* 9 */{4,4,4,4,4,4,4,4,4,4,4,4,4,4, _,_ ,_,_,9,9,9,9,9,9,9,9,9,9},  // 9
/* a */{4,4,4,4,4,4,4,4,4,4,4,4,4,4, _,_ ,9,9,9,9,9,9,9,9,9,9,9,_},  // a
/* b */{4,4,4,4,4,4,4,4,4,4,4,4,4,4, _,_ ,9,9,9,9,9,9,9,9,9,9,_,_},  // b
/* c */{4,4,4,4,4,4,4,4,4,4,4,4,4,4, _,_ ,_,9,9,9,9,9,9,9,9,_,_,_},  // c
/* d */{4,4,_,4,4,4,_,_,4,4,4,_,4,4, _,_ ,_,_,_,9,9,9,9,9,_,_,_,_},  // d
/* e */{4,_,_,_,4,4,_,_,4,4,_,_,_,4, _,_ ,_,_,_,_,_,_,_,_,_,_,_,_}   // e
//      0 1 2 3 4 5 6 7 8 9 a b c d  e f  g h i j k l m n o p q r 
};

#define NUMPIXELS3 12
#define NUMSPALTEN3 19
char ausgabe3[NUMPIXELS3][NUMSPALTEN3] = {
//      0 1 2 3 4 5 6 7 8 9 a b c d e f g h i
/* 0 */{_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,4,_,_,_},  // 0
/* 1 */{_,_,1,4,4,1,1,1,1,1,5,1,1,1,1,4,4,_,_},  // 1
/* 2 */{_,1,1,4,4,1,1,1,1,1,1,5,1,1,5,5,5,_,4},  // 2
/* 3 */{1,1,1,2,2,1,1,4,1,1,1,5,5,5,5,5,5,4,4},  // 3
/* 4 */{1,1,2,3,3,2,1,1,4,1,1,5,5,5,5,5,5,4,4},  // 4
/* 5 */{1,2,3,4,4,3,2,1,4,1,1,5,5,5,5,5,5,_,_},  // 5
/* 6 */{1,2,3,4,4,3,2,1,4,1,1,5,5,5,5,5,5,_,_},  // 6
/* 7 */{1,1,2,3,3,2,1,1,4,1,1,5,5,5,5,5,5,4,4},  // 7
/* 8 */{1,1,1,2,2,1,1,4,1,1,1,5,5,5,5,5,5,4,4},  // 8
/* 9 */{_,1,1,4,4,1,1,1,1,1,1,5,1,1,5,5,5,_,4},  // 9
/* a */{_,_,1,4,4,1,1,1,1,1,5,1,1,1,1,4,4,_,_},  // a
/* b */{_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,4,_,_,_}   // b
//      0 1 2 3 4 5 6 7 8 9 a b c d e f g h i
};

#define NUMPIXELS4 16
#define NUMSPALTEN4 18
char ausgabe4[NUMPIXELS4][NUMSPALTEN4] = {
//      0 1 2 3 4 5 6 7 8 9 a b c d e f g h
/* 0 */{_,_,_,_,_,_,_,_,_,_,1,1,1,1,1,_,_,_},  // 0
/* 1 */{_,1,1,1,_,1,1,1,_,1,3,3,3,3,3,1,_,_},  // 1
/* 2 */{1,2,2,8,1,2,2,8,1,3,3,3,4,4,3,3,1,_},  // 2
/* 3 */{1,1,2,8,1,1,2,8,1,3,3,3,3,3,3,3,3,1},  // 3
/* 4 */{1,8,8,8,1,8,8,8,1,3,4,3,3,3,3,4,3,1},  // 4
/* 5 */{_,1,1,1,1,1,1,1,3,3,3,3,3,3,3,3,3,1},  // 5
/* 6 */{_,1,5,1,1,5,5,1,3,3,3,3,3,6,6,3,4,1},  // 6
/* 7 */{_,1,5,1,1,5,1,3,3,4,3,3,6,3,3,6,3,1},  // 7
/* 8 */{_,1,5,1,1,5,1,3,3,3,3,6,3,3,3,6,3,1},  // 8
/* 9 */{_,1,5,1,5,5,1,3,3,3,3,6,3,3,6,3,3,1},  // 9
/* a */{_,1,5,1,5,1,1,1,3,3,3,6,3,6,3,3,1,_},  // a
/* b */{_,1,5,1,5,1,3,3,3,3,3,6,3,3,3,3,1,_},  // b
/* c */{_,1,1,1,5,1,1,1,3,3,3,6,3,3,3,1,_,_},  // c
/* d */{_,1,5,5,5,5,5,5,1,1,1,1,1,1,1,1,1,_},  // d
/* e */{1,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,1},  // e
/* f */{_,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}   // f
//      0 1 2 3 4 5 6 7 8 9 a b c d e f g h
};

#define NUMPIXELS5 14
#define NUMSPALTEN5 17
char ausgabe5[NUMPIXELS5][NUMSPALTEN5] = {
//      0 1 2 3 4 5 6 7 8 9 a b c d e f g                                                     
/* 0 */{_,_,_,_,_,_,1,1,1,1,1,_,_,3,3,3,_},    // 0                     
/* 1 */{_,_,_,_,_,1,1,1,1,1,1,1,1,1,3,3,_},    // 1
/* 2 */{_,_,_,_,_,4,4,4,3,3,6,3,_,1,1,1,_},    // 2
/* 3 */{_,_,_,_,4,3,4,3,3,3,6,3,3,3,1,1,_},    // 3
/* 4 */{_,_,_,_,4,3,4,4,3,3,3,6,3,3,3,1,_},    // 4
/* 5 */{_,_,_,_,4,4,3,3,3,3,6,6,6,6,1,_,_},    // 5
/* 6 */{_,_,_,_,_,_,3,3,3,3,3,3,3,1,1,_,_},    // 6
/* 7 */{3,3,3,1,1,1,1,2,1,1,1,2,1,1,_,_,4},    // 7
/* 8 */{3,3,3,1,1,1,1,1,2,1,1,1,2,_,_,4,4},    // 8
/* 9 */{_,3,_,_,_,1,1,1,2,2,2,2,5,2,2,4,4},    // 9
/* a */{_,_,_,_,_,_,2,2,2,5,2,2,2,2,2,4,4},    // a
/* b */{_,_,4,4,_,_,2,2,2,2,2,2,2,2,2,4,4},    // b
/* c */{_,4,4,4,_,_,2,2,2,2,2,2,_,_,_,_,_},    // c
/* d */{_,4,4,_,_,_,_,_,_,_,_,_,_,_,_,_,_}     // d
//      0 1 2 3 4 5 6 7 8 9 a b c d e f g
};                                             

#define NUMPIXELS6 8
#define NUMSPALTEN6 17
char ausgabe6[NUMPIXELS6][NUMSPALTEN6] = {
//      0 1 2 3 4 5 6 7 8 9 a b c d e f e
/* 0 */{_,_,_,1,1,_,_,_,_,_,_,_,2,2,_,_,_},  // 0
/* 1 */{_,_,1,1,1,1,_,_,_,_,_,2,2,2,2,_,_},  // 1
/* 2 */{_,1,1,1,1,1,1,_,_,_,2,2,2,2,2,2,_},  // 2
/* 3 */{1,1,_,1,1,_,1,1,_,2,2,_,2,2,_,2,2},  // 3
/* 4 */{1,1,1,1,1,1,1,1,_,2,2,2,2,2,2,2,2},  // 4
/* 5 */{_,_,1,_,_,1,_,_,_,_,2,_,2,2,_,2,_},  // 5
/* 6 */{_,1,_,1,1,_,1,_,_,2,_,_,_,_,_,_,2},  // 6
/* 7 */{1,_,1,_,_,1,_,1,_,_,2,_,_,_,_,2,_},  // 7
//      0 1 2 3 4 5 6 7 8 9 a b c d e f e
};

volatile int held = 0;
int geschwindigkeit = 50;
int pixel;
int spalte;
int i;

volatile unsigned long alteZeit=0, entprellZeit=20;

void setup()  {
  strip.begin();
  strip.setBrightness(60);
  strip.show();
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2, INPUT);                     // Pin 2 ist INT0
  digitalWrite(2, HIGH);                // interner Pull up Widerstand auf 5V
  attachInterrupt(0, interruptRoutine, LOW);
} 


void stripeoff()  {
  for(i=0;i<NUMPIXELS;i++){
    strip.setPixelColor(i, 0,0,0,0);
    strip.show();
  }
}

void loop()  {
  for(i=0;i<held;i++){
  digitalWrite(LED_BUILTIN, HIGH);          // turn the LED on (HIGH is the voltage level)
  delay(50);                              // wait for a second
  digitalWrite(LED_BUILTIN, LOW);           // turn the LED off by making the voltage LOW
  delay(50);                              // wait for a second 
  }
  switch (held){
    case 0:{ 
    digitalWrite(LED_BUILTIN, HIGH);
      stripeoff();         
    } break;
    case 1:{
      for (spalte=0;spalte<NUMSPALTEN1;spalte++){
        for (pixel=0;pixel<NUMPIXELS1;pixel++){
          switch (ausgabe1[pixel][spalte]){ 
            case 0:{
              strip.setPixelColor(pixel, 0, 0, 0, 0);         // aus
            } break;                          
            case 1:{
              strip.setPixelColor(pixel, 182, 255, 0, 0);     
            } break;
            case 2:{
              strip.setPixelColor(pixel, 50, 255, 22, 1);       
            } break; 
            case 3:{
              strip.setPixelColor(pixel, 0, 127, 14, 0);             
            } break;
            case 4:{
              strip.setPixelColor(pixel, 255, 0, 0, 0);             
            } break;
            case 5:{
              strip.setPixelColor(pixel, 188, 0, 0, 0);           
            } break;
            case 6:{
              strip.setPixelColor(pixel, 147, 0, 0, 0);          
            } break;
            case 7:{
              strip.setPixelColor(pixel, 127, 106, 0, 0);            
            } break;
            case 8:{
              strip.setPixelColor(pixel, 18, 4, 0, 0);
            } break;   
            case 9:{
              strip.setPixelColor(pixel, 255, 216, 0, 0); 
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
    } break; 

    case 2:{ 
    delay(geschwindigkeit*180); 
      digitalWrite(LED_BUILTIN, HIGH);
    delay(geschwindigkeit*20);
    digitalWrite(LED_BUILTIN, LOW);   
    for (spalte=0;spalte<NUMSPALTEN2;spalte++){
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
      for (pixel=0;pixel<NUMPIXELS2;pixel++){
        switch (ausgabe2[pixel][spalte]){ 
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
    } break; 
    case 3:{ 
      delay(geschwindigkeit*80);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(geschwindigkeit*20);
      digitalWrite(LED_BUILTIN, LOW);
      for (spalte=0;spalte<NUMSPALTEN3;spalte++){
        for (pixel=0;pixel<NUMPIXELS3;pixel++){
          switch (ausgabe3[pixel][spalte]){ 
            case 0:{
              strip.setPixelColor(pixel, 0, 0, 0, 0);         // aus
            } break;                          
            case 1:{
              strip.setPixelColor(pixel, 255, 140, 0, 0);     
            } break;
            case 2:{
              strip.setPixelColor(pixel, 50, 50, 50, 0);       
            } break; 
            case 3:{
              strip.setPixelColor(pixel, 0, 0, 0, 200);             
            } break;
            case 4:{
              strip.setPixelColor(pixel, 8, 8, 8, 0);             
            } break;
            case 5:{
              strip.setPixelColor(pixel, 0, 38, 255, 0);           
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
    } break; 
    case 4:{ 
      delay(geschwindigkeit*30);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(geschwindigkeit*20);
      digitalWrite(LED_BUILTIN, LOW);  
      for (spalte=0;spalte<NUMSPALTEN4;spalte++){
        for (pixel=0;pixel<NUMPIXELS4;pixel++){
          switch (ausgabe4[pixel][spalte]){ 
            case 0:{
              strip.setPixelColor(pixel, 0, 0, 0, 0);         // aus
            } break;                          
            case 1:{
              strip.setPixelColor(pixel, 5, 5, 5, 0);     
            } break;
            case 2:{
              strip.setPixelColor(pixel, 255, 0, 0, 0);       
            } break; 
            case 3:{
              strip.setPixelColor(pixel, 155, 42, 111, 100);             
            } break;
            case 4:{
              strip.setPixelColor(pixel, 178, 0, 255, 0);             
            } break;
            case 5:{
              strip.setPixelColor(pixel, 0, 255, 255, 0);           
            } break; 
            case 6:{
              strip.setPixelColor(pixel, 255, 0, 110, 0);             
            } break;
            case 7:{
              strip.setPixelColor(pixel, 0, 255, 144, 0);           
            } break;
            case 8:{
              strip.setPixelColor(pixel, 0, 0, 0, 255);           
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
    } break; 
    case 5:{ 
      delay(geschwindigkeit*30);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(geschwindigkeit*20);
      digitalWrite(LED_BUILTIN, LOW);   
      for (spalte=0;spalte<NUMSPALTEN5;spalte++){
        for (pixel=0;pixel<NUMPIXELS5;pixel++){
          switch (ausgabe5[pixel][spalte]){ 
            case 0:{
              strip.setPixelColor(pixel, 0, 0, 0, 0);         // aus
            } break;                          
            case 1:{
              strip.setPixelColor(pixel, 255, 0, 0, 0);     
            } break;
            case 2:{
              strip.setPixelColor(pixel, 0, 12, 255, 0);       
            } break; 
            case 3:{
              strip.setPixelColor(pixel, 207, 74, 0, 32);             
            } break;
            case 4:{
              strip.setPixelColor(pixel, 9, 2, 0, 0);             
            } break;
            case 5:{
              strip.setPixelColor(pixel, 255, 172, 0, 0);           
            } break; 
            case 6:{
              strip.setPixelColor(pixel, 1, 1, 1, 0);             
            } break;      
          }   
        }
        strip.show();
        delay(geschwindigkeit);
      }
      stripeoff();  
    } break;
    case 6:{ 
      delay(geschwindigkeit*30);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(geschwindigkeit*20);
      digitalWrite(LED_BUILTIN, LOW);  
      for (spalte=0;spalte<NUMSPALTEN6;spalte++){
        for (pixel=0;pixel<NUMPIXELS6;pixel++){
          switch (ausgabe6[pixel][spalte]){ 
            case 0:{
              strip.setPixelColor(pixel, 0, 0, 0, 0);         // aus
            } break;                          
            case 1:{
              strip.setPixelColor(pixel, 40, 9, 102, 40);     
            } break;
            case 2:{
              strip.setPixelColor(pixel, 101, 159, 23, 40);       
            } break; 
            case 3:{
              strip.setPixelColor(pixel, 207, 74, 0, 32);             
            } break;
            case 4:{
              strip.setPixelColor(pixel, 9, 2, 0, 0);             
            } break;
            case 5:{
              strip.setPixelColor(pixel, 255, 172, 0, 0);           
            } break; 
            case 6:{
              strip.setPixelColor(pixel, 1, 1, 1, 0);             
            } break;      
          }   
        }
        strip.show();
        delay(geschwindigkeit);
      }
      stripeoff();  
    } break;  
    
    default:{ 
      for(i=0;i<NUMPIXELS;i++){
        strip.setPixelColor(i, 0,0,0,50);
    }
    strip.show(); 
    } break;         
  }                    
}


void interruptRoutine() {
  if((millis() - alteZeit) > entprellZeit) {        // innerhalb der entprellZeit nichts machen    
    if (held < 6) {
      held = held + 1;
    } else held = 0;    
    alteZeit = millis();                            // letzte Schaltzeit merken      
  }
}



