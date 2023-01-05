void Test ()
{
  LcdTouch.fillScreen (WHITE);
  LcdTouch.print(20, 100, "Im In Test", 3, BLACK);
  delay(100);
    while (!LcdTouch.touched())
  {
  VL53L0X_RangingMeasurementData_t measure;
  //Serial.print("Reading a measurement... ");
  LcdTouch.fillScreen (WHITE);
  LcdTouch.print(20, 100, "Reading a measurement...", 2, BLACK);
  lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!
  if ((measure.RangeStatus != 4) && (measure.RangeStatus < 100) )
  { // phase failures have incorrect data,if the distance stay the sames num- drow.
    Serial.print("Distance (mm): ");
    //LcdTouch.fillScreen (WHITE);
   // LcdTouch.print(20, 100, "Distance (mm):", 3, BLACK);
    Serial.println(measure.RangeMilliMeter);
    delay(100);
  }
  else
  {
    Serial.println(" out of range ");
  }
}

}
