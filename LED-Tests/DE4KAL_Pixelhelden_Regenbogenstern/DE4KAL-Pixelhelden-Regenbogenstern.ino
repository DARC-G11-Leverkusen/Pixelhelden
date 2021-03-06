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

#define NEOPIN 0                        // Pin von dem die Neopixels ihre Daten bekommen
#define NUMPIXELS 16                    // Anzahl der LEDs

//LiquidCrystal lcd(9,8,7,6,5,4);       // Pins vom LCD Display, nur zum Debugging gedacht
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, NEOPIN, NEO_GRBW + NEO_KHZ800);  // Hier wird definiert was für eine Sorte von "Neopixel"-LED's wir ansteuern und an welchem Pin.

uint32_t r = strip.Color( 255,   0,   0,   0);          // Hier legen wir alle verwendeten Farben in der Reihenfolge RGBW (Rot, Grün, Blau, Weiß) fest          
uint32_t o = strip.Color( 255, 144,  36,   0);          // Hier legen wir alle verwendeten Farben in der Reihenfolge RGBW (Rot, Grün, Blau, Weiß) fest          
uint32_t a = strip.Color( 255, 255,   0,   0);          // Hier legen wir alle verwendeten Farben in der Reihenfolge RGBW (Rot, Grün, Blau, Weiß) fest          
uint32_t g = strip.Color( 173, 255,   0,   0);          // Hier legen wir alle verwendeten Farben in der Reihenfolge RGBW (Rot, Grün, Blau, Weiß) fest          
uint32_t t = strip.Color(   0, 191, 255,   0);          // Hier legen wir alle verwendeten Farben in der Reihenfolge RGBW (Rot, Grün, Blau, Weiß) fest          
uint32_t b = strip.Color(   0,   0, 205,   0);          // Hier legen wir alle verwendeten Farben in der Reihenfolge RGBW (Rot, Grün, Blau, Weiß) fest          
uint32_t l = strip.Color( 138,  43, 226,   0);          // Hier legen wir alle verwendeten Farben in der Reihenfolge RGBW (Rot, Grün, Blau, Weiß) fest          
uint32_t p = strip.Color( 255,  20, 147,   0);          // Hier legen wir alle verwendeten Farben in der Reihenfolge RGBW (Rot, Grün, Blau, Weiß) fest          
uint32_t w = strip.Color(   0,   0,   0, 255);          // Hier legen wir alle verwendeten Farben in der Reihenfolge RGBW (Rot, Grün, Blau, Weiß) fest

uint32_t ausgabe[16][17] = {
     // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16 //
/* 0*/{ 0, 0, 0, 0, 0, 0, 0, 0, r, 0, 0, 0, 0, 0, 0, 0, 0},
/* 1*/{ 0, 0, 0, 0, 0, 0, 0, r, r, o, 0, 0, 0, 0, 0, 0, 0},
/* 2*/{ 0, 0, 0, 0, 0, 0, 0, r, o, o, 0, 0, 0, 0, 0, 0, 0},
/* 3*/{ 0, 0, 0, 0, 0, 0, r, o, o, a, a, 0, 0, 0, 0, 0, 0},
/* 4*/{ 0, 0, 0, 0, 0, 0, o, o, o, a, a, 0, 0, 0, 0, 0, 0},
/* 5*/{ 0, 0, 0, 0, 0, o, o, o, a, a, g, g, 0, 0, 0, 0, 0},
/* 6*/{ r, r, r, r, o, o, 0, a, a, 0, g, g, g, t, t, t, b},
/* 7*/{ 0, r, r, o, o, o, 0, a, a, 0, g, g, t, t, t, b, 0},
/* 8*/{ 0, 0, o, o, o, a, 0, a, g, 0, g, t, t, t, b, 0, 0},
/* 9*/{ 0, 0, 0, o, a, a, a, g, g, g, t, t, t, b, 0, 0, 0},
/*10*/{ 0, 0, 0, 0, a, a, g, g, g, t, t, t, b, 0, 0, 0, 0},
/*11*/{ 0, 0, 0, 0, a, g, g, g, t, t, t, b, b, 0, 0, 0, 0},
/*12*/{ 0, 0, 0, a, g, g, g, t, t, t, b, b, b, l, 0, 0, 0},
/*13*/{ 0, 0, 0, g, g, g, t, 0, 0, 0, b, b, l, l, 0, 0, 0},
/*14*/{ 0, 0, g, g, g, 0, 0, 0, 0, 0, 0, 0, l, l, p, 0, 0},
/*15*/{ 0, 0, g, g, 0, 0, 0, 0, 0, 0, 0, 0, 0, p, p, 0, 0},
     // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16 //
};

const int NUMSPALTEN = 17;      // Anzahl der Spalten
int countdown = 10000;          // Zeit bis die Animation startet
int geschwindigkeit = 50;       // Abspielgeschwindigkeit
int pixel;                      // Adresse des anzusteuernden Pixels
int spalte;                     // Adresse der anzusteuernden Spalte
int i;                          // Zähler


void setup()  {                 // Das "setup" ist ein Programm dass der Arduino nach dem Einschalten einmal durchläuft
  strip.begin();                // LED Streifen wird initialisiert
  strip.setBrightness(60);      // LED Streifen wird in der Helligkeit gedrosselt
  strip.show();                 // LED Variablen werden ausgegeben. Diese stehen noch auf 0, also wird erstmal alles ausgeschaltet 
//  lcd.begin(16,2);            // Display zum Debuggen initialisieren
//  lcd.setCursor(0,0);
  pinMode(LED_BUILTIN, OUTPUT); // Pin für die OnBoard LED initialisieren
} 


void loop()  {                       // Das "void" ist ein Programm dass der Arduino nach dem Einschalten unendlich oft durchläuft
                                     // Dieser Timer zeigt Euch wann ihr mit der Bewegung des LED Stabs anfangen könnt  
  digitalWrite(LED_BUILTIN, HIGH);   // schaltet eine Gelbe LED auf dem Arduino Board an
  delay(1000);                       // eine Sekunde warten
  digitalWrite(LED_BUILTIN, LOW);    // LED aus
  delay(1000);                       // eine Sekunde warten 
  digitalWrite(LED_BUILTIN, HIGH);   // LED an
  delay(geschwindigkeit*10);         // Kurz je nach Ablaufgeschwindigkeit warten
   
    
  for(spalte=0;spalte<NUMSPALTEN;spalte++){                   // Wir beginnen mit Spalte 0, zählen bei jedem Durchgang 1 dazu und durchlaufen die Schleife bis wir die Konstante "NUMSPALTEN" erreicht haben
    for(pixel=0;pixel<NUMPIXELS;pixel++){                     // Innerhalb der aktuellen Spalte beginnen wir jeweils mit Pixel 0, zählen bei jedem Durchgang 1 dazu und durchlaufen die Schleife bis wir die Konstante "NUMPIXELS" erreicht haben
      strip.setPixelColor(pixel, ausgabe[pixel][spalte]);     // Aus unserem 2D-Array übergeben wir den hinterlegten Farbcode an die NeoPixel-Funktion
/*                                                            // Hiermit lässt sich der ganze Prozess extrem verlangsamen und am LDC Display beobachten
      lcd.setCursor(0,0);                   // Curser auf Zeichen 0 in der Reihe 0 setzen
      lcd.print("Pixl:");                   // "Pixl:" ausgeben
      if (pixel < 10) lcd.print("0");       // 0 in der Ausgabe ergänzen, falls die Pixeladresse einstellig ist
      lcd.print(pixel);                     // Adresse des gerade geschriebenen Pixels ausgeben
      lcd.setCursor(7,0);                   // Curser auf Zeichen 7 in der Reihe 0 setzen
      lcd.print(" Clmn:");                  // "Clmn:" ausgeben, gemeint ist Column, also Spalte
      if (spalte < 10) lcd.print("0");      // 0 in der Ausgabe ergänzen, falls die Spaltenadresse einstellig ist
      lcd.print(spalte);                    // Adresse der gerade im Aufbau befindlichen Spalte ausgeben
      lcd.setCursor(0,1);                   // Curser auf Zeichen 0 in der Reihe 1 setzen
      lcd.print("Farbe:          ");        // "Farbe:" ausgeben und alle danach kommenden Stellen mit Leerzeichen überschreiben
      lcd.setCursor(6,1);                   // Curser auf Zeichen 6 in der Reihe 1 setzen
      lcd.print(ausgabe[spalte][pixel]);    // Ausgabe des Farbcodes so wie er aus dem uint32_t 2D-Array an die NeoPixel-Funktion übergeben wird
      delay(150);                           // Verzögern der Schleife mit wir überhaupt eine Chance haben zu sehen was am Display bzw. im Programm passiert
*/
    }
    strip.show();                                             // Ausgabe einer kompletten Spalte über die NeoPixel Funktion
    delay(geschwindigkeit);                                   // Verzögerug, also Leuchtdauer, bis die nächsten Reihe angezeigt wird
  }

  for(i=0;i<NUMPIXELS;i++){                                   // Nachdem alle Reihen ausgegeben wurden schalten wir den LED Stripe wieder aus 
    strip.setPixelColor(i, 0,0,0,0);                          // Dazu übergeben wir den Farbcode 0,0,0,0 an die NeoPixel-Funktion für alle Pixel von 0 bis 17    
  }
  strip.show();                                               // Ausgabe der Spalte über die NeoPixel Funktion
  digitalWrite(LED_BUILTIN, LOW);                             // Ausschalten der OnBoard LED
  delay(countdown);                                           // Eine Zeit lang warten bis die Animation erneut startet

                           
}

