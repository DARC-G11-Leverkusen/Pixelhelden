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

uint32_t a = strip.Color( 251, 230, 188,   0);         //(Rot, Grün, Blau, Weiß)
uint32_t b = strip.Color( 175, 132,  68,   0);         //(Rot, Grün, Blau, Weiß)
uint32_t c = strip.Color( 143, 104,  48,   0);         //(Rot, Grün, Blau, Weiß)
uint32_t d = strip.Color( 238, 193, 106,   0);         //(Rot, Grün, Blau, Weiß)
uint32_t e = strip.Color( 209, 158,  61,   0);         //(Rot, Grün, Blau, Weiß)
uint32_t f = strip.Color( 186, 121,  21,   0);         //(Rot, Grün, Blau, Weiß)
uint32_t g = strip.Color( 154,  85,   0,   0);         //(Rot, Grün, Blau, Weiß)
uint32_t z = strip.Color(  51, 167, 251,   0);         //(Rot, Grün, Blau, Weiß)
uint32_t k = strip.Color( 134, 134, 134,   0);         //(Rot, Grün, Blau, Weiß)
uint32_t l = strip.Color( 167, 167, 167,   0);         //(Rot, Grün, Blau, Weiß)
uint32_t m = strip.Color( 191, 191, 191,   0);         //(Rot, Grün, Blau, Weiß)
uint32_t n = strip.Color( 110, 116, 112,   0);         //(Rot, Grün, Blau, Weiß)
uint32_t o = strip.Color(  82,  63,  41,   0);         //(Rot, Grün, Blau, Weiß)
uint32_t p = strip.Color(  58,  39,   6,   0);         //(Rot, Grün, Blau, Weiß)
uint32_t q = strip.Color( 102, 102, 102,   0);         //(Rot, Grün, Blau, Weiß)
uint32_t r = strip.Color( 114,  17,  16,   0);         //(Rot, Grün, Blau, Weiß)
uint32_t s = strip.Color( 135, 110,  26,   0);         //(Rot, Grün, Blau, Weiß)
uint32_t t = strip.Color( 102, 102,  51,   0);         //(Rot, Grün, Blau, Weiß)
uint32_t u = strip.Color( 227, 144,  29,   0);         //(Rot, Grün, Blau, Weiß)
uint32_t v = strip.Color( 244, 179,  63,   0);         //(Rot, Grün, Blau, Weiß)
uint32_t w = strip.Color( 226,  18,  18,   0);         //(Rot, Grün, Blau, Weiß)
uint32_t x = strip.Color(  32,  32,  32,   0);         //(Rot, Grün, Blau, Weiß)
uint32_t y = strip.Color(  51,  51,  51,   0);         //(Rot, Grün, Blau, Weiß)

uint32_t ausgabe[16][17] = {
       /* 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16 */
  /* 0*/{ 0, 0, z, x, x, x, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  /* 1*/{ 0, r, 0, 0, 0, x, x, 0, 0, x, x, x, 0, 0, 0, 0, 0},
  /* 2*/{ 0, r, 0, g, e, e, x, x, x, 0, 0, x, x, 0, 0, 0, 0},
  /* 3*/{ q, q, g, e, e, d, d, d, e, p, q, q, x, 0, 0, 0, 0},
  /* 4*/{ 0, g, f, e, d, b, a, a, d, m, l, m, q, 0, 0, 0, 0},
  /* 5*/{ 0, g, f, e, b, a, a, b, q, l, l, q, l, q, 0, 0, 0},
  /* 6*/{ 0, g, f, e, d, d, a, a, l, t, u, v, q, q, d, 0, 0},
  /* 7*/{ 0, g, f, e, e, b, d, a, w, q, u, u, q, 0, e, 0, 0},
  /* 8*/{ 0, 0, g, f, e, c, c, d, x, l, k, q, l, p, e, 0, 0},
  /* 9*/{ 0, 0, 0, f, f, e, b, d, d, x, y, y, x, e, 0, 0, 0},
  /*10*/{ 0, 0, 0, 0, f, f, f, e, o, n, q, e, e, 0, 0, 0, 0},
  /*11*/{ 0, 0, 0, 0, 0, 0, f, f, f, q, e, e, x, 0, 0, 0, 0},
  /*12*/{ 0, 0, 0, 0, 0, 0, 0, q, 0, 0, q, 0, 0, x, 0, 0, 0},
  /*13*/{ 0, 0, 0, 0, 0, 0, r, r, s, x, x, x, x, 0, 0, 0, 0},
  /*14*/{ 0, 0, 0, 0, 0, q, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  /*15*/{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       /* 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16 */
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
  delay(geschwindigkeit * 10);       // Kurz je nach Ablaufgeschwindigkeit warten


  for (spalte = 0; spalte < NUMSPALTEN; spalte++) {           // Wir beginnen mit Spalte 0, zählen bei jedem Durchgang 1 dazu und durchlaufen die Schleife bis wir die Konstante "NUMSPALTEN" erreicht haben
    for (pixel = 0; pixel < NUMPIXELS; pixel++) {             // Innerhalb der aktuellen Spalte beginnen wir jeweils mit Pixel 0, zählen bei jedem Durchgang 1 dazu und durchlaufen die Schleife bis wir die Konstante "NUMPIXELS" erreicht haben
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

  for (i = 0; i < NUMPIXELS; i++) {                           // Nachdem alle Reihen ausgegeben wurden schalten wir den LED Stripe wieder aus
    strip.setPixelColor(i, 0, 0, 0, 0);                       // Dazu übergeben wir den Farbcode 0,0,0,0 an die NeoPixel-Funktion für alle Pixel von 0 bis 17
  }
  strip.show();                                               // Ausgabe der Spalte über die NeoPixel Funktion
  digitalWrite(LED_BUILTIN, LOW);                             // Ausschalten der OnBoard LED
  delay(countdown);                                           // Eine Zeit lang warten bis die Animation erneut startet


}

