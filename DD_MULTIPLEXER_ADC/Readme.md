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
