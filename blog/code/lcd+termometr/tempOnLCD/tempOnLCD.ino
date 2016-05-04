// scrolltext demo for Adafruit RGBmatrixPanel library.
// Demonstrates double-buffered animation on our 16x32 RGB LED matrix:
// http://www.adafruit.com/products/420

// Written by Limor Fried/Ladyada & Phil Burgess/PaintYourDragon
// for Adafruit Industries.
// BSD license, all text above must be included in any redistribution.

#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library

#define F2(progmem_ptr) (const __FlashStringHelper *)progmem_ptr


#define CLK 11  // MUST be on PORTB!
#define LAT 10
#define OE  9
#define A   A0
#define B   A1
#define C   A2

// Last parameter = 'true' enables double-buffering, for flicker-free,
// buttery smooth animation.  Note that NOTHING WILL SHOW ON THE DISPLAY
// until the first call to swapBuffers().  This is normal.
RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, true);
#define Task_t 10          // Task Time in milli seconds


int readPin=A5;//pin from we read voltage
int value=0;
int lastData=0;
int sensorValue=0;
int hue=0;
//char   str[]="fklm";
//char constText[19] ="Temp: ";
char dataText[5]="";


void setup() {
   matrix.begin();
   matrix.setTextWrap(false); // Allow text to run off right edge
 //  matrix.setCursor(textX,0);
//      matrix.setTextWrap(false); // Allow text to run off right edge
 matrix.setTextSize(1);
   Serial.begin(9600);
 // Wire.begin();
  //   dt = millis();
  //compass_init(2);
//  compass_debug = 1;
 // compass_offset_calibration(3);
//matrix.fillRect(0, 0, 32, 16, matrix.Color333(0, 7, 0));
}

void loop() {
byte i;
sensorValue = analogRead(readPin);
  roundData();
  
  
  // Clear background
  matrix.fillScreen(0);
  matrix.setTextColor(matrix.ColorHSV(hue, 255, 255, true));
  matrix.setCursor(1, 0);
//    matrix.print(F2(constText));
      matrix.print('T');
      matrix.print('e');
      matrix.print('m');
      matrix.print('p');
      matrix.print(':');
      matrix.setCursor(1, 9);
       // compareText();
        for(int i=0;i<5;i++){
          matrix.print(dataText[i]);
          //Serial.print(dataText[i]);
        }
  // Move text left (w/wrap), increase hue
//if((--textX) < textMin) textX = matrix.width();
   
   
  // Update display
 matrix.swapBuffers(false);
 hue+=7;
 if(hue>255){hue=0;}
 delay(500);
}

void roundData(){
   float newData=lastData*5/10+sensorValue*5/10;//średnia krocząca
   //aby wygładzić dane bierzemy część średniej ostatniego pomiaru
   //oraz część nowego - sprawdza się przy temp bo nie ma zbyt
   //dużych skoków
 //  Serial.print('newdata: ');
  //Serial.println(newData);
  lastData=sensorValue;
  float n=(newData/40)+18;//transcription value to temp
//  dataText=[];
dtostrf(n, 4, 2, dataText);//change float into string
Serial.println(n);
// return; 
}

