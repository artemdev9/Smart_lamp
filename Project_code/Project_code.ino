#include <FastLED.h>
#include <TimeLib.h>

#define TIME_HEADER  "T"   
#define TIME_REQUEST  7    

#define NUM_LEDS 9

#define data0 0
#define data1 1
#define data2 2
#define data3 3
#define data4 4
#define data5 5
#define data6 6
#define data7 7
#define data8 8
#define data9 9
#define data10 10

#define ldrPin A0

CRGB leds0[NUM_LEDS];
CRGB leds1[NUM_LEDS];
CRGB leds2[NUM_LEDS];
CRGB leds3[NUM_LEDS];
CRGB leds4[NUM_LEDS];
CRGB leds5[NUM_LEDS];
CRGB leds6[NUM_LEDS];
CRGB leds7[NUM_LEDS];
CRGB leds8[NUM_LEDS];
CRGB leds9[NUM_LEDS];
CRGB leds10[NUM_LEDS];
int ambcount;
int thresh = 1000;

void setup() {
  FastLED.addLeds<WS2812, data0, RGB>(leds0, NUM_LEDS); // GRB ordering is assumed
  FastLED.addLeds<WS2812, data1, RGB>(leds1, NUM_LEDS); 
  FastLED.addLeds<WS2812, data2, RGB>(leds2, NUM_LEDS); 
  FastLED.addLeds<WS2812, data3, RGB>(leds3, NUM_LEDS); 
  FastLED.addLeds<WS2812, data4, RGB>(leds4, NUM_LEDS); 
  FastLED.addLeds<WS2812, data5, RGB>(leds5, NUM_LEDS);
  FastLED.addLeds<WS2812, data6, RGB>(leds6, NUM_LEDS); 
  FastLED.addLeds<WS2812, data7, RGB>(leds7, NUM_LEDS);
  FastLED.addLeds<WS2812, data8, RGB>(leds8, NUM_LEDS); 
  FastLED.addLeds<WS2812, data9, RGB>(leds9, NUM_LEDS); 
  FastLED.addLeds<WS2812, data10, RGB>(leds10, NUM_LEDS); 

  Serial.begin(9600);
  while (!Serial) ; 

  Serial.println("Waiting for sync message");

  pinMode( ldrPin, INPUT );

  ambcount = 0;

}

void loop() {
  if (Serial.available()) {
    //processSyncMessage();
  }
  if (timeStatus() != timeNotSet) {
    //digitalClockDisplay();
  }

  int hours = hour() + 1;
  int mins = minute();

  int minTens;
  int minOnes;
  int hrTens;
  int hrOnes;

  minTens = mins / 10;
  minOnes = mins % 10;
  hrTens = hours / 10;
  hrOnes = hours % 10;

  int ldr = analogRead( ldrPin );
  Serial.println(ldr);

  //if (ldr <= thresh) {
    lb();
    FastLED.clear();

    //showtimeM(minOnes, 5);
    //showtimeM(minTens, 0);
    //showtimeH(hrOnes, 5);
    //showtimeH(hrTens, 0);

    FastLED.show();
   // mb();
  //} else if (ldr > thresh) {
    amb();
  //}

}



void amb() {

  if (ambcount == 0) {
    lb();
    violet();
    mb();

    ambcount++;
  } else if (ambcount == 1) {
    lb();
    orange();
    mb();

    ambcount++;
  } else if (ambcount == 2) {
    lb();
    teal();
    mb();

    ambcount++;
  } else if (ambcount == 3) {
    lb();
    blue();
    mb();

    ambcount++;
  } else if (ambcount == 4) {
    lb();
    green();
    mb();

    ambcount++;
  } else if (ambcount == 5) {
    lb();
    yellow();
    mb();

    ambcount++;
  } else if (ambcount == 6) {
    lb();
    rainbow_right_to_left();
    lb();
    mb();

    ambcount++;
  } else if (ambcount == 7) {
    lb();
    violet();
    mb();

    ambcount++;
  } else if (ambcount == 8) {
    lb();
    orange();
    mb();

    ambcount++;
  } else if (ambcount == 9) {
    lb();
    teal();
    mb();

    ambcount++;
  } else if (ambcount == 10) {
    lb();
    blue();
    mb();

    ambcount++;
  } else if (ambcount == 11) {
    lb();
    green();
    mb();

    ambcount++;
  } else if (ambcount == 12) {
    lb();
    yellow();
    mb();

    ambcount++;
  } else if (ambcount == 13) {
    mb();
    squares();
    lb();
    mb();

    ambcount = 0;
  }

}


void squares() {

  FastLED.clear();
  FastLED.setBrightness(255);

  // green
  for (int i = 0; i < 4; i++ ) {
    leds0[i] = CRGB(255, 0, 0); // grb
    leds1[i] = CRGB(255, 0, 0);
    leds2[i] = CRGB(255, 0, 0);
    leds3[i] = CRGB(255, 0, 0);
    leds4[i] = CRGB(255, 0, 0);
    leds5[i] = CRGB(255, 255, 255);
    leds6[i] = CRGB(255, 0, 0);
    leds7[i] = CRGB(255, 0, 0);
    leds8[i] = CRGB(255, 0, 0);
    leds9[i] = CRGB(255, 0, 0);
    leds10[i] = CRGB(255, 0, 0);

    FastLED.show();
    delay(200);

  }

  //red
  for (int i = 8; i > 4; i-- ) {
    leds0[i] = CRGB(0, 255, 0);  // grb
    leds1[i] = CRGB(0, 255, 0);
    leds2[i] = CRGB(0, 255, 0);
    leds3[i] = CRGB(0, 255, 0);
    leds4[i] = CRGB(0, 255, 0);
    leds5[i] = CRGB(255, 255, 255);
    leds6[i] = CRGB(0, 255, 0);
    leds7[i] = CRGB(0, 255, 0);
    leds8[i] = CRGB(0, 255, 0);
    leds9[i] = CRGB(0, 255, 0);
    leds10[i] = CRGB(0, 255, 0);

    FastLED.show();
    delay(200);

  }

  // blue
  for (int i = 0; i < 4; i++ ) {
    leds0[i] = CRGB(0, 0, 255); // grb
  }
  leds0[4] = CRGB(255, 255, 255);
  FastLED.show();
  delay(200);
  for (int i = 0; i < 4; i++ ) {
    leds1[i] = CRGB(0, 0, 255);
  }
  leds1[4] = CRGB(255, 255, 255);
  FastLED.show();
  delay(200);
  for (int i = 0; i < 4; i++ ) {
    leds2[i] = CRGB(0, 0, 255);
  }
  leds2[4] = CRGB(255, 255, 255);
  FastLED.show();
  delay(200);
  for (int i = 0; i < 4; i++ ) {
    leds3[i] = CRGB(0, 0, 255);
  }
  leds3[4] = CRGB(255, 255, 255);
  FastLED.show();
  delay(200);
  for (int i = 0; i < 4; i++ ) {
    leds4[i] = CRGB(0, 0, 255);
  }
  leds4[4] = CRGB(255, 255, 255);
  FastLED.show();
  delay(200);

  // yellow
  for (int i = 8; i > 4; i-- ) {
    leds10[i] = CRGB(255, 255, 0); // grb
  }
  leds10[4] = CRGB(255, 255, 255);
  FastLED.show();
  delay(200);
  for (int i = 8; i > 4; i-- ) {
    leds9[i] = CRGB(255, 255, 0);
  }
  leds9[4] = CRGB(255, 255, 255);
  FastLED.show();
  delay(200);
  for (int i = 8; i > 4; i-- ) {

    leds8[i] = CRGB(255, 255, 0);
  }
  leds8[4] = CRGB(255, 255, 255);
  FastLED.show();
  delay(200);
  for (int i = 8; i > 4; i-- ) {
    leds7[i] = CRGB(255, 255, 0);
  }
  leds7[4] = CRGB(255, 255, 255);
  FastLED.show();
  delay(200);
  for (int i = 8; i > 4; i-- ) {
    leds6[i] = CRGB(255, 255, 0);
  }
  leds6[4] = CRGB(255, 255, 255);
  leds5[4] = CRGB(255, 255, 255);
  FastLED.show();

  delay(1000);
}







void lb() { // less bright

  for (int i = 255; i > 10; i--) {
    FastLED.setBrightness(i);
    delay(15);
    FastLED.show();
  }
}


void mb() { // more bright

  for (int i = 10; i < 255; i++) {
    FastLED.setBrightness(i);
    delay(15);
    FastLED.show();
  }
}

void green() {
  for (int i = 0; i < 9; i++) {
    leds0[i] = CRGB(255, 20, 20); // g r b
    leds1[i] = CRGB(255, 20, 20);
    leds2[i] = CRGB(255, 20, 20);
    leds3[i] = CRGB(255, 20, 20);
    leds4[i] = CRGB(255, 20, 20);
    leds5[i] = CRGB(255, 20, 20);
    leds6[i] = CRGB(255, 20, 20);
    leds7[i] = CRGB(255, 20, 20);
    leds8[i] = CRGB(255, 20, 20);
    leds9[i] = CRGB(255, 20, 20);
    leds10[i] = CRGB(255, 20, 20);
  }
  FastLED.show();
}


void yellow() {
  for (int i = 0; i < 9; i++) {
    leds0[i] = CRGB(255, 255, 0); // g r b
    leds1[i] = CRGB(255, 255, 0);
    leds2[i] = CRGB(255, 255, 0);
    leds3[i] = CRGB(255, 255, 0);
    leds4[i] = CRGB(255, 255, 0);
    leds5[i] = CRGB(255, 255, 0);
    leds6[i] = CRGB(255, 255, 0);
    leds7[i] = CRGB(255, 255, 0);
    leds8[i] = CRGB(255, 255, 0);
    leds9[i] = CRGB(255, 255, 0);
    leds10[i] = CRGB(255, 255, 0);
  }
  FastLED.show();
}

void red() {
  for (int i = 0; i < 9; i++) {
    leds0[i] = CRGB(0, 255, 0); // g r b
    leds1[i] = CRGB(0, 255, 0);
    leds2[i] = CRGB(0, 255, 0);
    leds3[i] = CRGB(0, 255, 0);
    leds4[i] = CRGB(0, 255, 0);
    leds5[i] = CRGB(0, 255, 0);
    leds6[i] = CRGB(0, 255, 0);
    leds7[i] = CRGB(0, 255, 0);
    leds8[i] = CRGB(0, 255, 0);
    leds9[i] = CRGB(0, 255, 0);
    leds10[i] = CRGB(0, 255, 0);
  }
  FastLED.show();
}


void teal() {
  for (int i = 0; i < 9; i++) {
    leds0[i] = CRGB(155, 38, 182); // g r b
    leds1[i] = CRGB(155, 38, 182);
    leds2[i] = CRGB(155, 38, 182);
    leds3[i] = CRGB(155, 38, 182);
    leds4[i] = CRGB(155, 38, 182);
    leds5[i] = CRGB(155, 38, 182);
    leds6[i] = CRGB(155, 38, 182);
    leds7[i] = CRGB(155, 38, 182);
    leds8[i] = CRGB(155, 38, 182);
    leds9[i] = CRGB(155, 38, 182);
    leds10[i] = CRGB(155, 38, 182);
  }
  FastLED.show();
}

void violet() {
  for (int i = 0; i < 9; i++) {
    leds0[i] = CRGB(130, 238, 238); // g r b
    leds1[i] = CRGB(130, 238, 238);
    leds2[i] = CRGB(130, 238, 238);
    leds3[i] = CRGB(130, 238, 238);
    leds4[i] = CRGB(130, 238, 238);
    leds5[i] = CRGB(130, 238, 238);
    leds6[i] = CRGB(130, 238, 238);
    leds7[i] = CRGB(130, 238, 238);
    leds8[i] = CRGB(130, 238, 238);
    leds9[i] = CRGB(130, 238, 238);
    leds10[i] = CRGB(130, 238, 238);
  }
  FastLED.show();
}


void blue() {
  for (int i = 0; i < 9; i++) {
    leds0[i] = CRGB(0, 0, 255); // g r b
    leds1[i] = CRGB(0, 0, 255);
    leds2[i] = CRGB(0, 0, 255);
    leds3[i] = CRGB(0, 0, 255);
    leds4[i] = CRGB(0, 0, 255);
    leds5[i] = CRGB(0, 0, 255);
    leds6[i] = CRGB(0, 0, 255);
    leds7[i] = CRGB(0, 0, 255);
    leds8[i] = CRGB(0, 0, 255);
    leds9[i] = CRGB(0, 0, 255);
    leds10[i] = CRGB(0, 0, 255);
  }
  FastLED.show();
}

void orange() {
  for (int i = 0; i < 9; i++) {
    leds0[i] = CRGB(192, 255, 203); // g r b
    leds1[i] = CRGB(192, 255, 203);
    leds2[i] = CRGB(192, 255, 203);
    leds3[i] = CRGB(192, 255, 203);
    leds4[i] = CRGB(192, 255, 203);
    leds5[i] = CRGB(192, 255, 203);
    leds6[i] = CRGB(192, 255, 203);
    leds7[i] = CRGB(192, 255, 203);
    leds8[i] = CRGB(192, 255, 203);
    leds9[i] = CRGB(192, 255, 203);
    leds10[i] = CRGB(192, 255, 203);
  }
  FastLED.show();
}




void rainbow_right_to_left() {

  FastLED.clear();
  FastLED.setBrightness(255);

  // RED
  for (int i = 0; i < 9; i++) {
    leds0[i] = CRGB(0, 255, 0); // g r b
    delay(100);
    FastLED.show();
  }

  // ORANGE
  for (int i = 0; i < 9; i++) {
    leds1[i] = CRGB(100, 255, 0);
    delay(100);
    FastLED.show();
  }

  // YELLOW
  for (int i = 0; i < 9; i++) {
    leds2[i] = CRGB(255, 255, 0);
    delay(100);
    FastLED.show();
  }

  // GREEN
  for (int i = 0; i < 9; i++) {
    leds3[i] = CRGB(255, 0, 0);
    delay(100);
    FastLED.show();
  }

  // BLUE
  for (int i = 0; i < 9; i++) {
    leds4[i] = CRGB(0, 0, 255);
    delay(100);
    FastLED.show();
  }

  // INDIGO
  for (int i = 0; i < 9; i++) {
    leds5[i] = CRGB(0, 50, 200);
    delay(100);
    FastLED.show();
  }

  // VIOLET
  for (int i = 0; i < 9; i++) {
    leds6[i] = CRGB(38, 155, 182);
    delay(100);
    FastLED.show();
  }


  // RED
  for (int i = 0; i < 9; i++) {
    leds7[i] = CRGB(0, 255, 0); // g r b
    delay(100);
    FastLED.show();
  }

  // ORGANGE
  for (int i = 0; i < 9; i++) {
    leds8[i] = CRGB(100, 255, 0);
    delay(100);
    FastLED.show();
  }

  // YELLOW
  for (int i = 0; i < 9; i++) {
    leds9[i] = CRGB(255, 255, 0);
    delay(100);
    FastLED.show();
  }

  // GREEN
  for (int i = 0; i < 9; i++) {
    leds10[i] = CRGB(255, 0, 0);
    delay(100);
    FastLED.show();
  }

}




void showtimeM(int mi, int pos) {

  if (mi == 1) {
    leds6[3 + pos] = CRGB(255, 255, 255);
    leds6[2 + pos] = CRGB(255, 255, 255);
    leds7[3 + pos] = CRGB(255, 255, 255);
    leds8[3 + pos] = CRGB(255, 255, 255);
    leds9[3 + pos] = CRGB(255, 255, 255);
    leds10[3 + pos] = CRGB(255, 255, 255);

  } else if (mi == 2) {
    leds6[0 + pos] = CRGB(255, 255, 255);
    leds6[1 + pos] = CRGB(255, 255, 255);
    leds6[2 + pos] = CRGB(255, 255, 255);
    leds6[3 + pos] = CRGB(255, 255, 255);
    leds7[0 + pos] = CRGB(255, 255, 255);
    leds7[3 + pos] = CRGB(255, 255, 255);
    leds8[2 + pos] = CRGB(255, 255, 255);
    leds9[1 + pos] = CRGB(255, 255, 255);
    leds10[0 + pos] = CRGB(255, 255, 255);
    leds10[1 + pos] = CRGB(255, 255, 255);
    leds10[2 + pos] = CRGB(255, 255, 255);
    leds10[3 + pos] = CRGB(255, 255, 255);

  } else if (mi == 3) {
    leds6[0 + pos] = CRGB(255, 255, 255);
    leds6[1 + pos] = CRGB(255, 255, 255);
    leds6[2 + pos] = CRGB(255, 255, 255);
    leds6[3 + pos] = CRGB(255, 255, 255);
    leds7[3 + pos] = CRGB(255, 255, 255);
    leds8[0 + pos] = CRGB(255, 255, 255);
    leds8[1 + pos] = CRGB(255, 255, 255);
    leds8[2 + pos] = CRGB(255, 255, 255);
    leds8[3 + pos] = CRGB(255, 255, 255);
    leds9[3 + pos] = CRGB(255, 255, 255);
    leds10[0 + pos] = CRGB(255, 255, 255);
    leds10[1 + pos] = CRGB(255, 255, 255);
    leds10[2 + pos] = CRGB(255, 255, 255);
    leds10[3 + pos] = CRGB(255, 255, 255);

  } else if (mi == 4) {
    leds6[0 + pos] = CRGB(255, 255, 255);
    leds6[3 + pos] = CRGB(255, 255, 255);
    leds7[0 + pos] = CRGB(255, 255, 255);
    leds7[3 + pos] = CRGB(255, 255, 255);
    leds8[0 + pos] = CRGB(255, 255, 255);
    leds8[1 + pos] = CRGB(255, 255, 255);
    leds8[2 + pos] = CRGB(255, 255, 255);
    leds8[3 + pos] = CRGB(255, 255, 255);
    leds9[3 + pos] = CRGB(255, 255, 255);
    leds10[3 + pos] = CRGB(255, 255, 255);


  } else if (mi == 5) {
    leds6[0 + pos] = CRGB(255, 255, 255);
    leds6[1 + pos] = CRGB(255, 255, 255);
    leds6[2 + pos] = CRGB(255, 255, 255);
    leds6[3 + pos] = CRGB(255, 255, 255);
    leds7[0 + pos] = CRGB(255, 255, 255);
    leds8[0 + pos] = CRGB(255, 255, 255);
    leds8[1 + pos] = CRGB(255, 255, 255);
    leds8[2 + pos] = CRGB(255, 255, 255);
    leds8[3 + pos] = CRGB(255, 255, 255);
    leds9[3 + pos] = CRGB(255, 255, 255);
    leds10[0 + pos] = CRGB(255, 255, 255);
    leds10[1 + pos] = CRGB(255, 255, 255);
    leds10[2 + pos] = CRGB(255, 255, 255);
    leds10[3 + pos] = CRGB(255, 255, 255);


  } else if (mi == 6) {
    leds6[0 + pos] = CRGB(255, 255, 255);
    leds6[1 + pos] = CRGB(255, 255, 255);
    leds6[2 + pos] = CRGB(255, 255, 255);
    leds6[3 + pos] = CRGB(255, 255, 255);
    leds7[0 + pos] = CRGB(255, 255, 255);
    leds8[0 + pos] = CRGB(255, 255, 255);
    leds8[1 + pos] = CRGB(255, 255, 255);
    leds8[2 + pos] = CRGB(255, 255, 255);
    leds8[3 + pos] = CRGB(255, 255, 255);
    leds9[0 + pos] = CRGB(255, 255, 255);
    leds9[3 + pos] = CRGB(255, 255, 255);
    leds10[0 + pos] = CRGB(255, 255, 255);
    leds10[1 + pos] = CRGB(255, 255, 255);
    leds10[2 + pos] = CRGB(255, 255, 255);
    leds10[3 + pos] = CRGB(255, 255, 255);


  } else if (mi == 7) {
    leds6[0 + pos] = CRGB(255, 255, 255);
    leds6[1 + pos] = CRGB(255, 255, 255);
    leds6[2 + pos] = CRGB(255, 255, 255);
    leds6[3 + pos] = CRGB(255, 255, 255);
    leds7[3 + pos] = CRGB(255, 255, 255);
    leds8[3 + pos] = CRGB(255, 255, 255);
    leds9[3 + pos] = CRGB(255, 255, 255);
    leds10[3 + pos] = CRGB(255, 255, 255);

  } else if (mi == 8) {
    leds6[0 + pos] = CRGB(255, 255, 255);
    leds6[1 + pos] = CRGB(255, 255, 255);
    leds6[2 + pos] = CRGB(255, 255, 255);
    leds6[3 + pos] = CRGB(255, 255, 255);
    leds7[0 + pos] = CRGB(255, 255, 255);
    leds7[3 + pos] = CRGB(255, 255, 255);
    leds8[0 + pos] = CRGB(255, 255, 255);
    leds8[1 + pos] = CRGB(255, 255, 255);
    leds8[2 + pos] = CRGB(255, 255, 255);
    leds8[3 + pos] = CRGB(255, 255, 255);
    leds9[0 + pos] = CRGB(255, 255, 255);
    leds9[3 + pos] = CRGB(255, 255, 255);
    leds10[0 + pos] = CRGB(255, 255, 255);
    leds10[1 + pos] = CRGB(255, 255, 255);
    leds10[2 + pos] = CRGB(255, 255, 255);
    leds10[3 + pos] = CRGB(255, 255, 255);


  } else if (mi == 9) {
    leds6[0 + pos] = CRGB(255, 255, 255);
    leds6[1 + pos] = CRGB(255, 255, 255);
    leds6[2 + pos] = CRGB(255, 255, 255);
    leds6[3 + pos] = CRGB(255, 255, 255);
    leds7[0 + pos] = CRGB(255, 255, 255);
    leds7[3 + pos] = CRGB(255, 255, 255);
    leds8[0 + pos] = CRGB(255, 255, 255);
    leds8[1 + pos] = CRGB(255, 255, 255);
    leds8[2 + pos] = CRGB(255, 255, 255);
    leds8[3 + pos] = CRGB(255, 255, 255);
    leds9[3 + pos] = CRGB(255, 255, 255);
    leds10[0 + pos] = CRGB(255, 255, 255);
    leds10[1 + pos] = CRGB(255, 255, 255);
    leds10[2 + pos] = CRGB(255, 255, 255);
    leds10[3 + pos] = CRGB(255, 255, 255);


  } else if (mi == 0) {
    leds6[0 + pos] = CRGB(255, 255, 255);
    leds6[1 + pos] = CRGB(255, 255, 255);
    leds6[2 + pos] = CRGB(255, 255, 255);
    leds6[3 + pos] = CRGB(255, 255, 255);
    leds7[0 + pos] = CRGB(255, 255, 255);
    leds8[0 + pos] = CRGB(255, 255, 255);
    leds9[0 + pos] = CRGB(255, 255, 255);
    leds7[3 + pos] = CRGB(255, 255, 255);
    leds8[3 + pos] = CRGB(255, 255, 255);
    leds9[3 + pos] = CRGB(255, 255, 255);
    leds10[0 + pos] = CRGB(255, 255, 255);
    leds10[1 + pos] = CRGB(255, 255, 255);
    leds10[2 + pos] = CRGB(255, 255, 255);
    leds10[3 + pos] = CRGB(255, 255, 255);

  }



}

void showtimeH(int hr, int pos) {


  if (hr == 1) {
    leds0[3 + pos] = CRGB(255, 255, 255);
    leds0[2 + pos] = CRGB(255, 255, 255);
    leds1[3 + pos] = CRGB(255, 255, 255);
    leds2[3 + pos] = CRGB(255, 255, 255);
    leds3[3 + pos] = CRGB(255, 255, 255);
    leds4[3 + pos] = CRGB(255, 255, 255);

  } else if (hr == 2) {
    leds0[0 + pos] = CRGB(255, 255, 255);
    leds0[1 + pos] = CRGB(255, 255, 255);
    leds0[2 + pos] = CRGB(255, 255, 255);
    leds0[3 + pos] = CRGB(255, 255, 255);
    leds1[0 + pos] = CRGB(255, 255, 255);
    leds1[3 + pos] = CRGB(255, 255, 255);
    leds2[2 + pos] = CRGB(255, 255, 255);
    leds3[1 + pos] = CRGB(255, 255, 255);
    leds4[0 + pos] = CRGB(255, 255, 255);
    leds4[1 + pos] = CRGB(255, 255, 255);
    leds4[2 + pos] = CRGB(255, 255, 255);
    leds4[3 + pos] = CRGB(255, 255, 255);

  } else if (hr == 3) {
    leds0[0 + pos] = CRGB(255, 255, 255);
    leds0[1 + pos] = CRGB(255, 255, 255);
    leds0[2 + pos] = CRGB(255, 255, 255);
    leds0[3 + pos] = CRGB(255, 255, 255);
    leds1[3 + pos] = CRGB(255, 255, 255);
    leds2[0 + pos] = CRGB(255, 255, 255);
    leds2[1 + pos] = CRGB(255, 255, 255);
    leds2[2 + pos] = CRGB(255, 255, 255);
    leds2[3 + pos] = CRGB(255, 255, 255);
    leds3[3 + pos] = CRGB(255, 255, 255);
    leds4[0 + pos] = CRGB(255, 255, 255);
    leds4[1 + pos] = CRGB(255, 255, 255);
    leds4[2 + pos] = CRGB(255, 255, 255);
    leds4[3 + pos] = CRGB(255, 255, 255);

  } else if (hr == 4) {
    leds0[0 + pos] = CRGB(255, 255, 255);
    leds0[3 + pos] = CRGB(255, 255, 255);
    leds1[0 + pos] = CRGB(255, 255, 255);
    leds1[3 + pos] = CRGB(255, 255, 255);
    leds2[0 + pos] = CRGB(255, 255, 255);
    leds2[1 + pos] = CRGB(255, 255, 255);
    leds2[2 + pos] = CRGB(255, 255, 255);
    leds2[3 + pos] = CRGB(255, 255, 255);
    leds3[3 + pos] = CRGB(255, 255, 255);
    leds4[3 + pos] = CRGB(255, 255, 255);


  } else if (hr == 5) {
    leds0[0 + pos] = CRGB(255, 255, 255);
    leds0[1 + pos] = CRGB(255, 255, 255);
    leds0[2 + pos] = CRGB(255, 255, 255);
    leds0[3 + pos] = CRGB(255, 255, 255);
    leds1[0 + pos] = CRGB(255, 255, 255);
    leds2[0 + pos] = CRGB(255, 255, 255);
    leds2[1 + pos] = CRGB(255, 255, 255);
    leds2[2 + pos] = CRGB(255, 255, 255);
    leds2[3 + pos] = CRGB(255, 255, 255);
    leds3[3 + pos] = CRGB(255, 255, 255);
    leds4[0 + pos] = CRGB(255, 255, 255);
    leds4[1 + pos] = CRGB(255, 255, 255);
    leds4[2 + pos] = CRGB(255, 255, 255);
    leds4[3 + pos] = CRGB(255, 255, 255);


  } else if (hr == 6) {
    leds0[0 + pos] = CRGB(255, 255, 255);
    leds0[1 + pos] = CRGB(255, 255, 255);
    leds0[2 + pos] = CRGB(255, 255, 255);
    leds0[3 + pos] = CRGB(255, 255, 255);
    leds1[0 + pos] = CRGB(255, 255, 255);
    leds2[0 + pos] = CRGB(255, 255, 255);
    leds2[1 + pos] = CRGB(255, 255, 255);
    leds2[2 + pos] = CRGB(255, 255, 255);
    leds2[3 + pos] = CRGB(255, 255, 255);
    leds3[0 + pos] = CRGB(255, 255, 255);
    leds3[3 + pos] = CRGB(255, 255, 255);
    leds4[0 + pos] = CRGB(255, 255, 255);
    leds4[1 + pos] = CRGB(255, 255, 255);
    leds4[2 + pos] = CRGB(255, 255, 255);
    leds4[3 + pos] = CRGB(255, 255, 255);


  } else if (hr == 7) {
    leds0[0 + pos] = CRGB(255, 255, 255);
    leds0[1 + pos] = CRGB(255, 255, 255);
    leds0[2 + pos] = CRGB(255, 255, 255);
    leds0[3 + pos] = CRGB(255, 255, 255);
    leds1[3 + pos] = CRGB(255, 255, 255);
    leds2[3 + pos] = CRGB(255, 255, 255);
    leds3[3 + pos] = CRGB(255, 255, 255);
    leds4[3 + pos] = CRGB(255, 255, 255);



  } else if (hr == 8) {
    leds0[0 + pos] = CRGB(255, 255, 255);
    leds0[1 + pos] = CRGB(255, 255, 255);
    leds0[2 + pos] = CRGB(255, 255, 255);
    leds0[3 + pos] = CRGB(255, 255, 255);
    leds1[0 + pos] = CRGB(255, 255, 255);
    leds1[3 + pos] = CRGB(255, 255, 255);
    leds2[0 + pos] = CRGB(255, 255, 255);
    leds2[1 + pos] = CRGB(255, 255, 255);
    leds2[2 + pos] = CRGB(255, 255, 255);
    leds2[3 + pos] = CRGB(255, 255, 255);
    leds3[0 + pos] = CRGB(255, 255, 255);
    leds3[3 + pos] = CRGB(255, 255, 255);
    leds4[0 + pos] = CRGB(255, 255, 255);
    leds4[1 + pos] = CRGB(255, 255, 255);
    leds4[2 + pos] = CRGB(255, 255, 255);
    leds4[3 + pos] = CRGB(255, 255, 255);


  } else if (hr == 9) {
    leds0[0 + pos] = CRGB(255, 255, 255);
    leds0[1 + pos] = CRGB(255, 255, 255);
    leds0[2 + pos] = CRGB(255, 255, 255);
    leds0[3 + pos] = CRGB(255, 255, 255);
    leds1[0 + pos] = CRGB(255, 255, 255);
    leds1[3 + pos] = CRGB(255, 255, 255);
    leds2[0 + pos] = CRGB(255, 255, 255);
    leds2[1 + pos] = CRGB(255, 255, 255);
    leds2[2 + pos] = CRGB(255, 255, 255);
    leds2[3 + pos] = CRGB(255, 255, 255);
    leds3[3 + pos] = CRGB(255, 255, 255);
    leds4[0 + pos] = CRGB(255, 255, 255);
    leds4[1 + pos] = CRGB(255, 255, 255);
    leds4[2 + pos] = CRGB(255, 255, 255);
    leds4[3 + pos] = CRGB(255, 255, 255);


  } else if (hr == 0) {
    leds0[0 + pos] = CRGB(255, 255, 255);
    leds0[1 + pos] = CRGB(255, 255, 255);
    leds0[2 + pos] = CRGB(255, 255, 255);
    leds0[3 + pos] = CRGB(255, 255, 255);
    leds1[0 + pos] = CRGB(255, 255, 255);
    leds2[0 + pos] = CRGB(255, 255, 255);
    leds3[0 + pos] = CRGB(255, 255, 255);
    leds1[3 + pos] = CRGB(255, 255, 255);
    leds2[3 + pos] = CRGB(255, 255, 255);
    leds3[3 + pos] = CRGB(255, 255, 255);
    leds4[0 + pos] = CRGB(255, 255, 255);
    leds4[1 + pos] = CRGB(255, 255, 255);
    leds4[2 + pos] = CRGB(255, 255, 255);
    leds4[3 + pos] = CRGB(255, 255, 255);

  }

}

// from the custom library: time
void digitalClockDisplay() {
  Serial.print(hour() + 1);
  Serial.print(minute());
  Serial.print(" ");
}


void processSyncMessage() { 
  unsigned long pctime;
  const unsigned long DEFAULT_TIME = 1357041600; 

  if (Serial.find(TIME_HEADER)) {
    pctime = Serial.parseInt();
    if ( pctime >= DEFAULT_TIME) { 
      setTime(pctime); 
    }
  }
}
