/*ORA BITAN*/
#include "Adafruit_VL53L0X.h"
#include <Servo.h>
#include "TFT9341Touch.h"
tft9341touch LcdTouch(10, 9, 7, 2);

Adafruit_VL53L0X lox = Adafruit_VL53L0X();
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int pos = 0;    // variable to store the servo position


void setup() {
  pinMode (3, OUTPUT);//ton
  noTone(3);
  // TuchScreem setUp
  LcdTouch.begin();
  LcdTouch.setRotation(0);//0,1,2,3
  LcdTouch.setTextSize (2);
  LcdTouch.setCursor (40, 40);

  if (LcdTouch.touched())
  {
    LcdTouch.print("press to set");
    LcdTouch.cal();
    while (1);
  }
  else
    LcdTouch.set(3780, 372, 489, 3811);
  screenMain();
  
  // servo setup
  Serial.begin(9600);
  myservo.attach(5);  // attaches the servo on pin 9 to the servo object
  
  //check if the radar ok
  while (! Serial) {
    delay(1);}
  Serial.println("Start My Test");
  delay(50);
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while (1);
  }
}

void loop()
{
if (LcdTouch.touched())//if (digitalRead(IRQ) == 0)
  {
    LcdTouch.readTouch();  //read my tuch

    int ButtonNum = LcdTouch.ButtonTouch(LcdTouch.xTouch, LcdTouch.yTouch);

   // if (ButtonNum == 1) // 110 > x > 20 , 70 > y > 20
    //{
     // screen1();
      //screenMain();
   // }
     if (ButtonNum == 2) //if (110 > x > 20 , 150 > y > 100
    {
      screen2();
      screenMain();
    }
  }
}
  void screenMain() {
  LcdTouch.fillScreen (WHITE);
  LcdTouch.drawCircle(150,100,10,BLUE);
  LcdTouch.drawCircle(150,100,20,GREEN);
  LcdTouch.drawCircle(150,100,30,RED);
   LcdTouch.drawCircle(150,100,40,BLACK);
  
  LcdTouch.println();
  LcdTouch.printheb(10, 20, "פרוייקט גמר משדר מקלט", 2, BLACK);
 // LcdTouch.println();
 // LcdTouch.drawButton(1, 20,  20, 90, 50, 10, RED, WHITE, "TEST", 2); // NumButton, x, y, width, height, r, Color, textcolor, label, textsize);
  LcdTouch.drawButton(2, 100, 150, 90, 50, 10, GREEN, WHITE, "START", 2);
}

  void screen1()
{
  LcdTouch.fillScreen (WHITE);
  LcdTouch.print(20, 100, "GOTO TEST Distance", 3, BLACK);
  delay(100);
  Test ();
}
void screen2()
{
  LcdTouch.fillScreen (WHITE);
  LcdTouch.print(20, 100, "THE RADAR IS STARTING...", 2, BLACK);
  delay(600);
  radarDraw();
  }
  
  
//  VL53L0X_RangingMeasurementData_t measure;
//  //The servo move and we read the measure frome the radar
//  for (pos = 60; pos <= 120; pos += 5) { // goes from 60 degrees to 120 degrees
//    // in steps of 5 degree
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(100);
//    Serial.print("Reading a measurement... ");
//    lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!
//    if ((measure.RangeStatus != 4) && (measure.RangeStatus <100) ) 
//    {  // phase failures have incorrect data,if the distance stay the sames num- drow.
//      Serial.print("Distance (mm): "); 
//      Serial.println(measure.RangeMilliMeter);
//      delay(100);
//    } 
//    else 
//    {
//      Serial.println(" out of range ");
//    }
//
//    delay(100);
//  }
//
//  //Serial.print("Reading a measurement... ");
//  // lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!
