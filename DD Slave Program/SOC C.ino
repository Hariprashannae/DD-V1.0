#include <Wire.h>
#include <Adafruit_ADS1015.h>
Adafruit_ADS1115 ads(0x49);
float Voltage = 0.0;
#include <Adafruit_Sensor.h> 
#include <Adafruit_ADXL345_U.h>
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified();
int neram = 1;
//int Signal=0;
void setup() 
{
  Serial.begin(9600); // Initialize the serial port
  ads.begin();
  if(!accel.begin())
   {
      Serial.println("No ADXL345 sensor detected.");
     while(1);
   }
}

void loop() 
{ 
   sensors_event_t event; 
   accel.getEvent(&event);
  int inputValue = analogRead(A0); // and read Z
  int16_t adc0; // we read from the ADC, we have a sixteen bit integer as a result
  adc0 = ads.readADC_SingleEnded(0);
  Voltage = (adc0 * 0.1875)/1000; 
  Serial.print("\n"); 
  Serial.print("Time:"+String(neram)+"\t");//+"\n");
  Serial.print("AIN0: "+String(adc0)+"\t");//+"\n");
  Serial.print("Analog"+String(inputValue)+"\t");//+"\n" );
  Serial.print("Voltage: "+String(Voltage)+"\t");//+"\n");
  Serial.print("X: "+String(event.acceleration.x)+"\t");//+"\n");
  Serial.print("Y: "+String(event.acceleration.y)+"\t");//+"\n");
  Serial.print("Z: "+String(event.acceleration.z)+"\t");//+"\n");
  Serial.print("\n");
  delay(1000);
  neram=neram+1;
  if(neram==81)
  {
    neram=0;
  }
}


