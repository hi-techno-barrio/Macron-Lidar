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
//VL53L0X sensor5;
VL53L0X sensor6;
VL53L0X sensor7;
VL53L0X sensor8;

/* Lidar distance variable */
int L1;
int L2;
int L3;
int L4;
//int L5;
int L6;
int L7;
int L8;


void setup()
{
  /* For testing , PC is connected to USB port and 5th Lidar is disabled  */
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
 // pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);

  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
 // digitalWrite(A0, LOW);
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

/*
Liear 5
  digitalWrite(A0, HIGH);
  delay(150);
  sensor5.init(true);
  delay(100);
  sensor5.setAddress((uint8_t)05);
  Serial.println("Lidar 5 set");
*/

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
 // sensor5.startContinuous(10);
  sensor6.startContinuous(10);
  sensor7.startContinuous(10);
  sensor8.startContinuous(10);

/*
 * Derive from Pululo samples
  sensor.setTimeout(500);
  if (!sensor.init())
  {
    Serial.println("Failed to detect and initialize sensor!");
    while (1) {}
  }

  // Start continuous back-to-back mode (take readings as
  // fast as possible).  To use continuous timed mode
  // instead, provide a desired inter-measurement period in
  // ms (e.g. sensor.startContinuous(100)).
  sensor.startContinuous();  */
  
}

void loop()
{
  // get the distances
    L1=sensor.readRangeContinuousMillimeters();
    Serial.print(L1);
    Serial.print(" ");
    
    L2=sensor2.readRangeContinuousMillimeters();
    Serial.print(L2);
    Serial.print(" ");
    
    L3=sensor3.readRangeContinuousMillimeters();
    Serial.print(L3);
    Serial.print(" ");
    
    L4=sensor4.readRangeContinuousMillimeters();
    Serial.print(L4);
    Serial.print(" ");
   /* 
    L5=sensor5.readRangeContinuousMillimeters();
    Serial.print(L5);
    Serial.print(" ");
  */  
    L6=sensor6.readRangeContinuousMillimeters();
    Serial.print(L6);
    Serial.print(" ");
    
    L7=sensor7.readRangeContinuousMillimeters();
    Serial.print(L7);
    Serial.print(" ");
    
    L8=sensor8.readRangeContinuousMillimeters();
    Serial.println(L8);
    delay(50);

}
