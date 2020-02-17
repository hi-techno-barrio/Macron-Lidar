 
/* This example shows how to use continuous mode to take
range measurements with the VL53L0X. It is based on
vl53l0x_ContinuousRanging_Example.c from the VL53L0X API.
The range readings are in units of mm. 
Using MKR Zero, Arduino Zero Mini (Cortex-M0)
-----------------------------------------------------------
e-LIDAR  V-1.0
By:
Christopher Coballes
Hi-Techno Barrio
-----------------------------------------------------------
*/

#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;
VL53L0X sensor2;
VL53L0X sensor3;
VL53L0X sensor4;
VL53L0X sensor5;
VL53L0X sensor6;
VL53L0X sensor7;
VL53L0X sensor8;

/* Lidar distance variable */
int L1;
int L2;
int L3;
int L4;
int L5;
int L6;
int L7;
int L8;


void setup()
{
  /* For testing , PC is connected to USB port and 5th Lidar is disabled  */
  pinMode(A5, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);

  digitalWrite(A5, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  digitalWrite(A0, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
  digitalWrite(A4, LOW);
  
  SerialUSB.begin(115200);
  Wire.begin();
  
  delay(30);

// Lidar 1
  digitalWrite(A1, HIGH);
  delay(50);
  sensor.init(true);
  delay(10);
  sensor.setAddress((uint8_t)01);
  SerialUSB.println("Lidar 1 set");

// Lidar 2
  digitalWrite(A2, HIGH);
  delay(50);
  sensor2.init(true);
  delay(10);
  sensor2.setAddress((uint8_t)02);
  SerialUSB.println("Lidar 2 set");

//Lidar 3   
  digitalWrite(A3, HIGH);
  delay(50);
  sensor3.init(true);
  delay(10);
  sensor3.setAddress((uint8_t)03);
  SerialUSB.println("Lidar 3 set");

//Lidar 4
  digitalWrite(A4, HIGH);
  delay(50);
  sensor4.init(true);
  delay(10);
  sensor4.setAddress((uint8_t)04);
  SerialUSB.println("Lidar 4 set");;

/*
Lidar 5 */
  digitalWrite(A5, HIGH);
  delay(150);
  sensor5.init(true);
  delay(100);
  sensor5.setAddress((uint8_t)05);
  SerialUSB.println("Lidar 5 set");


//Lidar 6
  digitalWrite(12, HIGH);
  delay(50);
  sensor6.init(true);
  delay(10);
  sensor6.setAddress((uint8_t)06);
  SerialUSB.println("Lidar 6 set");

// Lidar 7
  digitalWrite(13, HIGH);
  delay(50);
  sensor7.init(true);
  delay(10);
  sensor7.setAddress((uint8_t)07);
  SerialUSB.println("Lidar 7 set");

// Lidar 8
  digitalWrite(A0, HIGH);
  delay(50);
  sensor8.init(true);
  delay(10);
  sensor8.setAddress((uint8_t)10);
  SerialUSB.println("Lidar 8 set");

// Triger Lidars for continous ranging  
  sensor.startContinuous(10);
  sensor2.startContinuous(10);
  sensor3.startContinuous(10);
  sensor4.startContinuous(10);
  sensor5.startContinuous(10);
  sensor6.startContinuous(10);
  sensor7.startContinuous(10);
  sensor8.startContinuous(10);

 delay(250); 
}

void loop()
{
  // get the distances
    L1=sensor.readRangeContinuousMillimeters();
    SerialUSB.print("A:");
    SerialUSB.print(L1);
    
    L2=sensor2.readRangeContinuousMillimeters();
    SerialUSB.print("  B:");
    SerialUSB.print(L2);
    
    L3=sensor3.readRangeContinuousMillimeters();
    SerialUSB.print(" C:");
    SerialUSB.print(L3);
    
    L4=sensor4.readRangeContinuousMillimeters();
    SerialUSB.print(" D:");
    SerialUSB.print(L4);
    
    L5=sensor5.readRangeContinuousMillimeters();
    SerialUSB.print(" E:");
    SerialUSB.print(L5);
    
    L6=sensor6.readRangeContinuousMillimeters();
    SerialUSB.print(" F:");
    SerialUSB.print(L6);
    
    L7=sensor7.readRangeContinuousMillimeters();
    SerialUSB.print(" G:");
    SerialUSB.print(L7);
    
    L8=sensor8.readRangeContinuousMillimeters();
    SerialUSB.print(" H:");
    SerialUSB.println(L8);
    delay(50);

}
