///// ADC TEST PROCEDURE 
////  LIBRAY REQUIREMENTS : Adafruit_ADS1015.h  ,  Wire.h
////  SOFTWARE REQUIREMENTS : Arduino IDE
////  HARDWARE REQUIREMENTS : Multiplexer (74hc4051d cty20815 tod1835f) , Analog to Digital Convrter (ADS1115), MOSFET , ESP32 WROOM ,Connector
////  PIN CONNECTIONS : MULTIPLEXER : VCC->+5v , GND&VEE&E->GND(LOW) , S0&S1&S2->ACTIVE LOW INITIALLY 
////                    ADC         : VCC&ALT/RDY->+5V  , GND&ADDR->GND
////                    MOSFET      : LOGIC LEVEL SHIFTER 3.3V TO 5V (INITIALLY ACTIVE LOW) 
////                    ESP32       : GPIO14->S0,GPIO16->S1,GPIO17->S2,GPIO21(SDA)->SDA,GPIO22(SCL)->SCL 
////                    CONNECTOR   :
////                                  MUX1(U4)->CONNECTOR(J7)&(J8)            MUX2(U5)->CONNECTOR(J8)&(J6)            MUX3(U6)->CONNECTOR(J5)          MUX4(U7)->CONNECTOR(J4)
////                                      A0-2(J7)                                A0-5(J8)                                   A0-1(J5)                          A0-1(J4)
////                                      A1-3(J7)                                A1-6(J8)                                   A1-2(J5)                          A1-2(J4)   
////                                      A2-4(J7)                                A2-1(J6)                                   A2-3(J5)                          A2-3(J4)              
////                                      A3-5(J7)                                A3-2(J6)                                   A3-4(J5)                          A3-4(J4)
////                                      A4-6(J7)                                A4-3(J6)                                   A4-5(J5)                          A4-5(J4)     
////                                      A5-2(J8)                                A5-4(J6)                                   A5-6(J5)                          A5-6(J4)        
////                                      A6-3(J8)                                A6-5(J6)                                   A6-7(J5)                          A6-7(J4)                         
////                                      A7-4(J8)                                A7-6(J6)                                   A7-8(J5)                          A7-8(J4)            
////

#include <Wire.h>
#include <Adafruit_ADS1015.h>
Adafruit_ADS1115 ads(0x49);
float Voltage0 = 0.0;
float Voltage1 = 0.0;
float Voltage2 = 0.0;
float Voltage3 = 0.0;
const int selectPins[3] = {14, 16, 17}; // S0~8, S1~9, S2~10
int MultiplexerA[8]={0,0,0,0,0,0,0,0};
int MultiplexerB[8]={0,0,0,0,0,0,0,0};
int MultiplexerC[8]={0,0,0,0,0,0,0,0};
int MultiplexerD[8]={0,0,0,0,0,0,0,0};
int TTL = 1;
int Signal=0;
int16_t adc0; // we read from the ADC, we have a sixteen bit integer as a result
int16_t adc1;
int16_t adc2;
int16_t adc3;
void setup() 
{
  Serial.begin(115200); 
  ads.begin();
  Serial.print("TTL:"+String(TTL)+"\t"+"\t");
  Serial.print("TTL:"+String(TTL)+"\t"+"\t");
  for (int i=0; i<3; i++)
  {
    pinMode(selectPins[i], OUTPUT);
    digitalWrite(selectPins[i], HIGH);
    Serial.print("TTL:"+String(TTL)+"\t"+"\t");
  }
 }

void loop() 
{ 

 /* adc0 = ads.readADC_SingleEnded(0);
  Voltage = (adc0 * 0.1875)/1000; 
  adc1 = ads.readADC_SingleEnded(0);
  Voltage = (adc1 * 0.1875)/1000; 
  adc2 = ads.readADC_SingleEnded(0);
  Voltage = (adc2 * 0.1875)/1000; 
  adc3 = ads.readADC_SingleEnded(0);
  Voltage = (adc3 * 0.1875)/1000; 

  //*   for (int n=0;n<8;n++)
  {*/
    if(TTL<=10){
      digitalWrite(selectPins[0], LOW);
      digitalWrite(selectPins[1], LOW);
      digitalWrite(selectPins[2], LOW);
      Signal=1;
  adc0 = ads.readADC_SingleEnded(0);
  Voltage0 = (adc0 * 0.1875)/1000; 
  adc1 = ads.readADC_SingleEnded(1);
  Voltage1 = (adc1 * 0.1875)/1000; 
  adc2 = ads.readADC_SingleEnded(2);
  Voltage2 = (adc2 * 0.1875)/1000; 
  adc3 = ads.readADC_SingleEnded(3);
  Voltage3 = (adc3 * 0.1875)/1000; 
  
  Serial.print("\n");
  Serial.print("Signal:"+String("MultiplexerA[0]")+"\t");
  Serial.print("AIN0: "+String(adc0)+"\t");//+"\n");
  Serial.print("Voltage0: "+String(Voltage0)+"\t");//+"\n");
  Serial.print("\n");

  Serial.print("\n");
  Serial.print("Signal:"+String("MultiplexerB[0]")+"\t");
  Serial.print("AIN1: "+String(adc1)+"\t");//+"\n");
  Serial.print("Voltage1: "+String(Voltage1)+"\t");//+"\n");
  Serial.print("\n");

  Serial.print("\n");
  Serial.print("Signal:"+String("MultiplexerC[0]")+"\t");
  Serial.print("AIN2: "+String(adc2)+"\t");//+"\n");
  Serial.print("Voltage2: "+String(Voltage2)+"\t");//+"\n");
  Serial.print("\n");

  Serial.print("\n");
  Serial.print("Signal:"+String("MultiplexerD[0]")+"\t");
  Serial.print("AIN3: "+String(adc3)+"\t");//+"\n");
  Serial.print("Voltage3: "+String(Voltage3)+"\t");//+"\n");
  Serial.print("\n");
    }
    else if(TTL<=20&&TTL>10) {
      digitalWrite(selectPins[0], LOW);
      digitalWrite(selectPins[1], LOW);
      digitalWrite(selectPins[2], HIGH);
      Signal=2;
      adc0 = ads.readADC_SingleEnded(0);
  Voltage0 = (adc0 * 0.1875)/1000; 
  adc1 = ads.readADC_SingleEnded(1);
  Voltage1 = (adc1 * 0.1875)/1000; 
  adc2 = ads.readADC_SingleEnded(2);
  Voltage2 = (adc2 * 0.1875)/1000; 
  adc3 = ads.readADC_SingleEnded(3);
  Voltage3 = (adc3 * 0.1875)/1000; 
  Serial.print("\n");
  Serial.print("Signal:"+String("MultiplexerA[1]")+"\t");
  Serial.print("AIN0: "+String(adc0)+"\t");//+"\n");
  Serial.print("Voltage0: "+String(Voltage0)+"\t");//+"\n");
  Serial.print("\n");

  Serial.print("\n");
  Serial.print("Signal:"+String("MultiplexerB[1]")+"\t");
  Serial.print("AIN1: "+String(adc1)+"\t");//+"\n");
  Serial.print("Voltage1: "+String(Voltage1)+"\t");//+"\n");
  Serial.print("\n");

  Serial.print("\n");
  Serial.print("Signal:"+String("MultiplexerC[1]")+"\t");
  Serial.print("AIN2: "+String(adc2)+"\t");//+"\n");
  Serial.print("Voltage2: "+String(Voltage2)+"\t");//+"\n");
  Serial.print("\n");

  Serial.print("\n");
  Serial.print("Signal:"+String("MultiplexerD[1]")+"\t");
  Serial.print("AIN3: "+String(adc3)+"\t");//+"\n");
  Serial.print("Voltage3: "+String(Voltage3)+"\t");//+"\n");
  Serial.print("\n");
      
      }
    else if(TTL<=30&&TTL>20) {
      digitalWrite(selectPins[0], LOW);
      digitalWrite(selectPins[1], HIGH);
      digitalWrite(selectPins[2], LOW);
      Signal=3;
      adc0 = ads.readADC_SingleEnded(0);
  Voltage0 = (adc0 * 0.1875)/1000; 
  adc1 = ads.readADC_SingleEnded(1);
  Voltage1 = (adc1 * 0.1875)/1000; 
  adc2 = ads.readADC_SingleEnded(2);
  Voltage2 = (adc2 * 0.1875)/1000; 
  adc3 = ads.readADC_SingleEnded(3);
  Voltage3 = (adc3 * 0.1875)/1000; 
  Serial.print("\n");
  Serial.print("Signal:"+String("MultiplexerA[2]")+"\t");
  Serial.print("AIN0: "+String(adc0)+"\t");//+"\n");
  Serial.print("Voltage0: "+String(Voltage0)+"\t");//+"\n");
  Serial.print("\n");

  Serial.print("\n");
  Serial.print("Signal:"+String("MultiplexerB[2]")+"\t");
  Serial.print("AIN1: "+String(adc1)+"\t");//+"\n");
  Serial.print("Voltage1: "+String(Voltage1)+"\t");//+"\n");
  Serial.print("\n");

  Serial.print("\n");
  Serial.print("Signal:"+String("MultiplexerC[2]")+"\t");
  Serial.print("AIN2: "+String(adc2)+"\t");//+"\n");
  Serial.print("Voltage2: "+String(Voltage2)+"\t");//+"\n");
  Serial.print("\n");

  Serial.print("\n");
  Serial.print("Signal:"+String("MultiplexerD[2]")+"\t");
  Serial.print("AIN3: "+String(adc3)+"\t");//+"\n");
  Serial.print("Voltage3: "+String(Voltage3)+"\t");//+"\n");
  Serial.print("\n");
      }      
    else if(TTL<=40&&TTL>30) {
      digitalWrite(selectPins[0], LOW);
      digitalWrite(selectPins[1], HIGH);
      digitalWrite(selectPins[2], HIGH);
      Signal=4;
      adc0 = ads.readADC_SingleEnded(0);
  Voltage0 = (adc0 * 0.1875)/1000; 
  adc1 = ads.readADC_SingleEnded(1);
  Voltage1 = (adc1 * 0.1875)/1000; 
  adc2 = ads.readADC_SingleEnded(2);
  Voltage2 = (adc2 * 0.1875)/1000; 
  adc3 = ads.readADC_SingleEnded(3);
  Voltage3 = (adc3 * 0.1875)/1000; 
  Serial.print("\n");
  Serial.print("Signal:"+String("MultiplexerA[3]")+"\t");
  Serial.print("AIN0: "+String(adc0)+"\t");//+"\n");
  Serial.print("Voltage0: "+String(Voltage0)+"\t");//+"\n");
  Serial.print("\n");

  Serial.print("\n");
  Serial.print("Signal:"+String("MultiplexerB[3]")+"\t");
  Serial.print("AIN1: "+String(adc1)+"\t");//+"\n");
  Serial.print("Voltage1: "+String(Voltage1)+"\t");//+"\n");
  Serial.print("\n");

  Serial.print("\n");
  Serial.print("Signal:"+String("MultiplexerC[3]")+"\t");
  Serial.print("AIN2: "+String(adc2)+"\t");//+"\n");
  Serial.print("Voltage2: "+String(Voltage2)+"\t");//+"\n");
  Serial.print("\n");

  Serial.print("\n");
  Serial.print("Signal:"+String("MultiplexerD[3]")+"\t");
  Serial.print("AIN3: "+String(adc3)+"\t");//+"\n");
  Serial.print("Voltage3: "+String(Voltage3)+"\t");//+"\n");
  Serial.print("\n");
      }
      else if(TTL<=50&&TTL>40) {
      digitalWrite(selectPins[0], HIGH);
      digitalWrite(selectPins[1], LOW);
      digitalWrite(selectPins[2], LOW);
      Signal=5;
      adc0 = ads.readADC_SingleEnded(0);
  Voltage0 = (adc0 * 0.1875)/1000; 
  adc1 = ads.readADC_SingleEnded(1);
  Voltage1 = (adc1 * 0.1875)/1000; 
  adc2 = ads.readADC_SingleEnded(2);
  Voltage2 = (adc2 * 0.1875)/1000; 
  adc3 = ads.readADC_SingleEnded(3);
  Voltage3 = (adc3 * 0.1875)/1000; 
  Serial.print("\n");
  Serial.print("Signal:"+String("MultiplexerA[4]")+"\t");
  Serial.print("AIN0: "+String(adc0)+"\t");//+"\n");
  Serial.print("Voltage0: "+String(Voltage0)+"\t");//+"\n");
  Serial.print("\n");

  Serial.print("\n");
  Serial.print("Signal:"+String("MultiplexerB[4]")+"\t");
  Serial.print("AIN1: "+String(adc1)+"\t");//+"\n");
  Serial.print("Voltage1: "+String(Voltage1)+"\t");//+"\n");
  Serial.print("\n");

  Serial.print("\n");
  Serial.print("Signal:"+String("MultiplexerC[4]")+"\t");
  Serial.print("AIN2: "+String(adc2)+"\t");//+"\n");
  Serial.print("Voltage2: "+String(Voltage2)+"\t");//+"\n");
  Serial.print("\n");

  Serial.print("\n");
  Serial.print("Signal:"+String("MultiplexerD[4]")+"\t");
  Serial.print("AIN3: "+String(adc3)+"\t");//+"\n");
  Serial.print("Voltage3: "+String(Voltage3)+"\t");//+"\n");
  Serial.print("\n");
      }
      else if(TTL<=60&&TTL>50) {
      digitalWrite(selectPins[0], HIGH);
      digitalWrite(selectPins[1], LOW);
      digitalWrite(selectPins[2], HIGH);
      Signal=6;
      adc0 = ads.readADC_SingleEnded(0);
  Voltage0 = (adc0 * 0.1875)/1000; 
  adc1 = ads.readADC_SingleEnded(1);
  Voltage1 = (adc1 * 0.1875)/1000; 
  adc2 = ads.readADC_SingleEnded(2);
  Voltage2 = (adc2 * 0.1875)/1000; 
  adc3 = ads.readADC_SingleEnded(3);
  Voltage3 = (adc3 * 0.1875)/1000; 
  Serial.print("\n");
  Serial.print("Signal:"+String("MultiplexerA[5]")+"\t");
  Serial.print("AIN0: "+String(adc0)+"\t");//+"\n");
  Serial.print("Voltage0: "+String(Voltage0)+"\t");//+"\n");
  Serial.print("\n");

  Serial.print("\n");
  Serial.print("Signal:"+String("MultiplexerB[5]")+"\t");
  Serial.print("AIN1: "+String(adc1)+"\t");//+"\n");
  Serial.print("Voltage1: "+String(Voltage1)+"\t");//+"\n");
  Serial.print("\n");

  Serial.print("\n");
  Serial.print("Signal:"+String("MultiplexerC[5]")+"\t");
  Serial.print("AIN2: "+String(adc2)+"\t");//+"\n");
  Serial.print("Voltage2: "+String(Voltage2)+"\t");//+"\n");
  Serial.print("\n");

  Serial.print("\n");
  Serial.print("Signal:"+String("MultiplexerD[5]")+"\t");
  Serial.print("AIN3: "+String(adc3)+"\t");//+"\n");
  Serial.print("Voltage3: "+String(Voltage3)+"\t");//+"\n");
  Serial.print("\n");
      }
      else if(TTL<=70&&TTL>60) {
      digitalWrite(selectPins[0], HIGH);
      digitalWrite(selectPins[1], HIGH);
      digitalWrite(selectPins[2], LOW);
      Signal=7;
      adc0 = ads.readADC_SingleEnded(0);
  Voltage0 = (adc0 * 0.1875)/1000; 
  adc1 = ads.readADC_SingleEnded(1);
  Voltage1 = (adc1 * 0.1875)/1000; 
  adc2 = ads.readADC_SingleEnded(2);
  Voltage2 = (adc2 * 0.1875)/1000; 
  adc3 = ads.readADC_SingleEnded(3);
  Voltage3 = (adc3 * 0.1875)/1000; 
  Serial.print("\n");
  Serial.print("Signal:"+String("MultiplexerA[6]")+"\t");
  Serial.print("AIN0: "+String(adc0)+"\t");//+"\n");
  Serial.print("Voltage0: "+String(Voltage0)+"\t");//+"\n");
  Serial.print("\n");

  Serial.print("\n");
  Serial.print("Signal:"+String("MultiplexerB[6]")+"\t");
  Serial.print("AIN1: "+String(adc1)+"\t");//+"\n");
  Serial.print("Voltage1: "+String(Voltage1)+"\t");//+"\n");
  Serial.print("\n");

  Serial.print("\n");
  Serial.print("Signal:"+String("MultiplexerC[6]")+"\t");
  Serial.print("AIN2: "+String(adc2)+"\t");//+"\n");
  Serial.print("Voltage2: "+String(Voltage2)+"\t");//+"\n");
  Serial.print("\n");

  Serial.print("\n");
  Serial.print("Signal:"+ String("MultiplexerD[6]")+"\t");
  Serial.print("AIN3: "+String(adc3)+"\t");//+"\n");
  Serial.print("Voltage3: "+String(Voltage3)+"\t");//+"\n");
  Serial.print("\n");
      }
      else {
      digitalWrite(selectPins[0], HIGH);
      digitalWrite(selectPins[1], HIGH);
      digitalWrite(selectPins[2], HIGH);
      Signal=8;
      adc0 = ads.readADC_SingleEnded(0);
  Voltage0 = (adc0 * 0.1875)/1000; 
  adc1 = ads.readADC_SingleEnded(1);
  Voltage1 = (adc1 * 0.1875)/1000; 
  adc2 = ads.readADC_SingleEnded(2);
  Voltage2 = (adc2 * 0.1875)/1000; 
  adc3 = ads.readADC_SingleEnded(3);
  Voltage3 = (adc3 * 0.1875)/1000; 
  Serial.print("\n");
  Serial.print("Signal:"+ String("MultiplexerA[7]")+"\t");
  Serial.print("AIN0: "+String(adc0)+"\t");//+"\n");
  Serial.print("Voltage0: "+String(Voltage0)+"\t");//+"\n");
  Serial.print("\n");

  Serial.print("\n");
  Serial.print("Signal:"+ String("MultiplexerB[7]")+"\t");
  Serial.print("AIN1: "+String(adc1)+"\t");//+"\n");
  Serial.print("Voltage1: "+String(Voltage1)+"\t");//+"\n");
  Serial.print("\n");

  Serial.print("\n");
  Serial.print("Signal:"+ String("MultiplexerC[7]")+"\t");
  Serial.print("AIN2: "+String(adc2)+"\t");//+"\n");
  Serial.print("Voltage2: "+String(Voltage2)+"\t");//+"\n");
  Serial.print("\n");

  Serial.print("\n");
  Serial.print("Signal:"+ String("MultiplexerD[7]") +"\t");
  Serial.print("AIN3: "+String(adc3)+"\t");//+"\n");
  Serial.print("Voltage3: "+String(Voltage3)+"\t");//+"\n");
  Serial.print("\n");
      }
      

  delay(1000);
  TTL=TTL+1;
  if(TTL==81)
  {
    TTL=0;
    Signal=0;
  } 
}


