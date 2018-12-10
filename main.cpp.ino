#include <Wire.h>//Library that handles I2C protocol
#include "RTC1307.h" //Includes the RTC1307 class based library that I made
#define BAUD_RATE 115200 // setting of the baudrate

void setup(){
  Serial.begin(BAUD_RATE);//Initiate the serial
  Wire.begin();//Initiate the Wire library and join the I2C bus as a master
}

void loop() {
  int i;// Used for for loops

  Serial.println("Test for RTC1307 Library");
  delay(2000);
  //Code for test 1
  Serial.println("Test 1: The Object rtc has been called with the default constructor.");
  delay(2000);
  Serial.println("Time printing should be 0 seconds 0 minutes 0 hours");
  delay(2000);
  Serial.println("and then print the time once a second, for 10 seconds");
  delay(2000);
  RTC1307 rtc;//Makes an object of the RTC1307 with the default constructor

  for(i = 0; i<11;i++){
    Serial.print(rtc.getSeconds());
    Serial.print(" seconds, ");
    Serial.print(rtc.getMinutes());
    Serial.print(" minutes, ");
    Serial.print(rtc.getHours());
    Serial.println(" hours");
    delay(1000);
  }
  
  //Code for test 2
  delay(2000);
  Serial.println("Test 2: Now we test the overload constructor");
  delay(2000);
  Serial.println("it will be called with 12 hours 12 minutes and 12 seconds");
  delay(2000);
  Serial.println("and then print the time once a second, for 10 seconds");
  delay(2000);
  RTC1307 rtc1(12,12,12);
  for(i = 0; i<11;i++){
    Serial.print(rtc1.getSeconds());
    Serial.print(" seconds, ");
    Serial.print(rtc1.getMinutes());
    Serial.print(" minutes, ");
    Serial.print(rtc1.getHours());
    Serial.println(" hours");
    delay(1000);
  }
  //Code for test 3
  delay(2000);
  Serial.println("Test 3: Here we will test the 3 Mutator functions");
  delay(2000);
  Serial.println("Time will be set to 1 hour, 2 minutes and 3 seconds");
  delay(2000);
  Serial.println("and then print the time once a second, for 10 seconds");
  delay(2000);
  rtc1.setHours(1);
  rtc1.setMinutes(2);
  rtc1.setSeconds(3);
  for(i = 0; i<11;i++){
    Serial.print(rtc1.getSeconds());
    Serial.print(" seconds, ");
    Serial.print(rtc1.getMinutes());
    Serial.print(" minutes, ");
    Serial.print(rtc1.getHours());
    Serial.println(" hours");
    delay(1000);
  }
  Serial.println("Tests completed");
  delay(1000);
  exit(0);// Exits the loop
}
