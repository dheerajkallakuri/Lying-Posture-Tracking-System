/*
  Arduino LSM9DS1 - Accelerometer Application

  This example reads the acceleration values as relative direction and degrees,
  from the LSM9DS1 sensor and prints them to the Serial Monitor or Serial Plotter.

  The circuit:
  - Arduino Nano 33 BLE Sense

  Created by Riccardo Rizzo

  Modified by Jose García
  27 Nov 2020

  This example code is in the public domain.
*/

#include <Arduino_LSM9DS1.h>
//initialize variables
float x, y, z,X,Y,Z;
int degreesX = 0;
int degreesY = 0;

void setup() {

  //begin Serial
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Started");
  pinMode(LED_BUILTIN, OUTPUT);
//check if IMU is initialized 
  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  Serial.print("Accelerometer sample rate = ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println("Hz");
}

void loop() {
//checking for IMU data
  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);

  }


//condition for supine position
  if (x >= 0 && z>=0 && (y<=0.05 && y>=-0.05)) {
    x = 100 * x;
    //convert raw data to degrees
    degreesX = map(x, 0, 97, 0, 90);
    Serial.println("Supine ");
//    Serial.print(degreesX);
//    Serial.println("  degrees");
    blk(1);                    
  }
//condition for prone position 
  if (x <= 0 && z<=0 && (y<=0.05 && y>=-0.05)) {
    x = 100 * x;
    //convert raw data to degrees
    degreesX = map(x, 0, -100, 0, 90);
    Serial.println("Prone ");
//    Serial.print(degreesX);
//    Serial.println("  degrees");
    blk(2);  
    
  }
  //condition for left side 
  if (y > 0.1) {
    y = 100 * y;
    //convert raw data to degrees
    degreesY = map(y, 0, 97, 0, 90);
    Serial.println("Left Side ");
//    Serial.print(degreesY);
//    Serial.println("  degrees");
    blk(3); 
  }
  //condition for right side
  if (y < -0.1) {
    y = 100 * y;
    //convert raw data to degrees
    degreesY = map(y, 0, -100, 0, 90);
    Serial.println("Right Side ");
//    Serial.print(degreesY);
//    Serial.println("  degrees");
    blk(3);
  }
  delay(500);
}

void blk(int n){
    switch(n){

      //1 times blink per sec
      case 1: 
      digitalWrite(LED_BUILTIN, HIGH);   
      delay(1000);                      
      digitalWrite(LED_BUILTIN, LOW);    
      delay(1000);
      break;
      
      //2 times blink per sec
      case 2: 
      digitalWrite(LED_BUILTIN, HIGH);   
      delay(500);                      
      digitalWrite(LED_BUILTIN, LOW);    
      delay(500);
      digitalWrite(LED_BUILTIN, HIGH);   
      delay(500);                      
      digitalWrite(LED_BUILTIN, LOW);    
      delay(500);
      break;  

      //3 times blink per sec
      case 3: 
      digitalWrite(LED_BUILTIN, HIGH);   
      delay(300);                      
      digitalWrite(LED_BUILTIN, LOW);    
      delay(300);
      digitalWrite(LED_BUILTIN, HIGH);   
      delay(300);                      
      digitalWrite(LED_BUILTIN, LOW);    
      delay(300);
      digitalWrite(LED_BUILTIN, HIGH);   
      delay(300);                      
      digitalWrite(LED_BUILTIN, LOW);    
      delay(300);
      break;  
      //default off
      default:
      digitalWrite(LED_BUILTIN, LOW);
      }
  }
