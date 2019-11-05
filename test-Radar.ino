/* This example shows how to use continuous mode to take
range measurements with the VL53L0X. It is based on
vl53l0x_ContinuousRanging_Example.c from the VL53L0X API.
The range readings are in units of mm. 
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


void setup()
{
  /* For testing , PC is connected to USB port and 5th Lidar is disabled  */
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);

  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(A0, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
  
  Serial.begin(57600);
  Wire.begin();
  
  delay(300);

// Lidar 1
  digitalWrite(2, HIGH);
  delay(50);
  sensor.init(true);
  delay(10);
  sensor.setAddress((uint8_t)01);
  Serial.println("Lidar 1 set");

// Lidar 2
  digitalWrite(3, HIGH);
  delay(50);
  sensor2.init(true);
  delay(10);
  sensor2.setAddress((uint8_t)02);
  Serial.println("Lidar 2 set");

//Lidar 3   
  digitalWrite(4, HIGH);
  delay(50);
  sensor3.init(true);
  delay(10);
  sensor3.setAddress((uint8_t)03);
  Serial.println("Lidar 3 set");

//Lidar 4
  digitalWrite(5, HIGH);
  delay(50);
  sensor4.init(true);
  delay(10);
  sensor4.setAddress((uint8_t)04);
  Serial.println("Lidar 4 set");;


//Liear 5
  digitalWrite(A0, HIGH);
  delay(150);
  sensor5.init(true);
  delay(100);
  sensor5.setAddress((uint8_t)05);
  Serial.println("Lidar 5 set");


//Lidar 6
  digitalWrite(A1, HIGH);
  delay(50);
  sensor6.init(true);
  delay(10);
  sensor6.setAddress((uint8_t)06);
  Serial.println("Lidar 6 set");

// Lidar 7
  digitalWrite(A2, HIGH);
  delay(50);
  sensor7.init(true);
  delay(10);
  sensor7.setAddress((uint8_t)07);
  Serial.println("Lidar 7 set");

// Lidar 8
  digitalWrite(A3, HIGH);
  delay(50);
  sensor8.init(true);
  delay(10);
  sensor8.setAddress((uint8_t)10);
  Serial.println("Lidar 8 set");

// Triger Lidars for continous ranging  
  sensor.startContinuous(10);
  sensor2.startContinuous(10);
  sensor3.startContinuous(10);
  sensor4.startContinuous(10);
  sensor5.startContinuous(10);
  sensor6.startContinuous(10);
  sensor7.startContinuous(10);
  sensor8.startContinuous(10); 
}

void loop()
{
  float cmMsec;

  if(angle < 0) {
    angle = 360;
  }
  
  Serial.print("{d:");
  Serial.print(cmMsec);
  Serial.print(",r:");
  Serial.print(angle);
  Serial.print("}");
  
  val = map(angle, 0, 360, 0, 359);
  angle -= 45;
 cmMsec = scanDistance(angle);
  delay(100);
}


 float scanDistance(int cntAngle)
{
 float Range;

switch (cntAngle)
{
  case 0:
   Range=sensor.readRangeContinuousMillimeters();
    break; 
  
   case 45:
   Range=sensor2.readRangeContinuousMillimeters(); 
   break; 
  
   case 90:
   Range=sensor3.readRangeContinuousMillimeters(); 
   break; 
  
   case 135:
   Range=sensor4.readRangeContinuousMillimeters();
   break; 
  
   case 180:
   Range=sensor5.readRangeContinuousMillimeters();  
   break; 
    
   case 225:
   Range=sensor6.readRangeContinuousMillimeters();
   break; 
  
  case 275:
   Range=sensor7.readRangeContinuousMillimeters();
   break; 
  
  case 315:
   Range=sensor8.readRangeContinuousMillimeters();   
   break;  
 } // case

return Range;
}
