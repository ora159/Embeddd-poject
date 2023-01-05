void radarDraw()
{
  int D, M,MYd,DM;
  char arr[30];
  char arr2[30];
  LcdTouch.fillScreen (WHITE);
  //LcdTouch.print(20, 100, "IM IN Try To Draw", 3, BLACK);
  //delay(100);

  LcdTouch.fillScreen (WHITE);
  LcdTouch.drawCircle(150,100,10,BLUE);
  LcdTouch.drawCircle(150,100,30,GREEN);
  LcdTouch.drawCircle(150,100,50,RED);
  LcdTouch.drawCircle(150,100,70,BLACK);
  LcdTouch.print(20, 200, "PLEAS WATE...", 3, BLACK);
  delay(600);
  //DRAW CYCLES
  while (!LcdTouch.touched())
  {
    VL53L0X_RangingMeasurementData_t measure;
    LcdTouch.fillScreen (WHITE);
    //The servo move and we read the measure frome the radar
    // in steps of 5 degrees.goes from 60 degrees to 120 degrees
    for (pos = 60; pos <= 120; pos += 5)
    {
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(100);
      lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!
      if (measure.RangeMilliMeter< 260)
      {
        // phase failures have incorrect data,if the distance stay the sames num- drow
        D = measure.RangeMilliMeter;
        //LcdTouch.print(20, 200, "Distance (mm):", 1, BLACK);
        sprintf(arr, "Distance:=%d  ", D);
        LcdTouch.print(50, 200, arr, 3, BLACK, WHITE);
        sprintf(arr2, "Degrees=%d  ", pos);
        LcdTouch.print(50, 10, arr2, 3, BLACK, WHITE);
        //draw the point
       if(pos<=90)
       {
        M=pos-30;
        D=D/2;
        LcdTouch.fillCircle (160,120, 3, BLUE);
        LcdTouch.fillCircle (160-D,M, 3, BLUE);
        //delay(600);
        LcdTouch.drawLine(160,120,160-D,M,BLACK);
        delay(600);
        LcdTouch.drawLine(160,120,160-D, M,WHITE);
        LcdTouch.fillCircle (160, 120, 3, WHITE);
        LcdTouch.fillCircle (160-D,M, 3, WHITE);
        
       }
       if(pos>90)
       {
        M=pos-30;
        D=D/2;
        LcdTouch.fillCircle (160,120, 3, BLUE);
        LcdTouch.fillCircle (160+D, M, 3, BLUE);
        //delay(600);
        LcdTouch.drawLine(160,120,160+D,M,BLACK);
        delay(600);
        LcdTouch.drawLine(160,120,160+D, M,WHITE);
        LcdTouch.fillCircle (160, 120, 3, WHITE);
        LcdTouch.fillCircle (160+D,M, 3, WHITE);
       
       }
        
        //LcdTouch.drawHLine(150+M,D,20,BLACK);
       // LcdTouch.drawLine(x0,y0,x1,y1,color)
        //delay(1000);
       // M = M + 2;
        //LcdTouch.fillCircle (150, D, 3, WHITE);
        //LcdTouch.fillCircle (D + M, D, 3, BLACK);
        //delay(600);
        //LcdTouch.fillCircle (D + M, D, 3, WHITE);
        //delay(100);
        //M = M + 2;
        //LcdTouch.drawHLine(150+M,D,10,BLACK);

        //PLAY THE TONE
        if (D < 15)
        {
          //LcdTouch.fillCircle (150+M, D, 3, BLUE);
          LcdTouch.fillScreen (WHITE);
          tone(3, 500 , 500);
          delay(50);
          LcdTouch.print(20, 100, "The object is close!!", 2, RED);
          //tone(3, 800, 500);
          tone(3, 500 , 500);
          delay(50);
          tone(3, 500 , 500);
          //delay(1000);
           delay(1000);
          //LcdTouch.print(20, 100, "The RADAR detected an object!", 2, BLACK);
          //The object is very close
          tone(3, 500, 500);
          noTone(3);
          LcdTouch.fillScreen (WHITE);
        }
        delay(1000);
      }
      else if (measure.RangeMilliMeter> 260)
      {
        LcdTouch.print(20, 100, "The object is out of range", 2, RED);
        delay(100);
        LcdTouch.fillScreen (WHITE);
        
      }
    }

    }

    
  }
