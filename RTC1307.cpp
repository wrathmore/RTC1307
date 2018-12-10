// Class function definiton
#include "RTC1307.h"

//default constructor
RTC1307::RTC1307(){
  Wire.beginTransmission(DS1307_RTC_ADDRESS);//Begins a transmission to the I2C slave device with the given address
  Wire.write(0);//This sets the the the 00h spot in the registry, because for each write it increments automaticly
  Wire.write(decToBcd(0));//Queues byte for transmission for setting the seconds to 0
  Wire.write(decToBcd(0));//Queues byte for transmission for setting the minutes to 0
  Wire.write(decToBcd(0));//Queues byte for transmission for setting the hours to 0
  Wire.endTransmission();//Transmits the queued bytes
  // Sets the time on the RTC module to 00:00:00
}

//overload constructor
RTC1307::RTC1307(int Hours,int Minutes,int Seconds){
  Wire.beginTransmission(DS1307_RTC_ADDRESS);//Begins a transmission to the I2C slave device with the given address
  Wire.write(0);//This sets the adress to 00h spot in the registry, because for each Wire.write it increments automaticly
  Wire.write(decToBcd(Seconds));//Queues byte for transmission for setting the seconds to the parameter
  Wire.write(decToBcd(Minutes));//Queues byte for transmission for setting the minutes to the parameter
  Wire.write(decToBcd(Hours));//Queues byte for transmission for setting the hours to the parameter
  Wire.endTransmission();//Transmits the queued bytes
  //Sets the time on the RTC module to the parameter call
}

//destructor
RTC1307::~RTC1307(){
  //deletes an instance of an object
}

//bcdToDec function
byte RTC1307::bcdToDec(byte val){
  return ( (val/16*10) + (val%16) );
  //converts binary coded decimal to decimal and returns the value in a byte
}

//decToBcd function
byte RTC1307::decToBcd(byte val){
  return( (val/10*16) + (val%10) );
  //converts decimal to binary coded decimal and returns the value in a byte
}

//getSeconds function: Returns the seconds from the RTC module
byte RTC1307::getSeconds(){
  Wire.beginTransmission(DS1307_RTC_ADDRESS);//Begins a transmission to the I2C slave device with the given address
  Wire.write(0);// Sets registry adress to 00h were seconds is stored
  Wire.endTransmission();//Transmits the queued bytes
  Wire.requestFrom(DS1307_RTC_ADDRESS, 1);//Master requests 1 byte from the slave
  return(bcdToDec(Wire.read()));//Reads byte transmitted from the slave to the master and returns it converted to decimal
}

//getMinutes function: Returns the minutes from the RTC module
byte RTC1307::getMinutes(){
  Wire.beginTransmission(DS1307_RTC_ADDRESS);//Begins a transmission to the I2C slave device with the given address
  Wire.write(1);// Sets registry adress to 01h were minutes is stored
  Wire.endTransmission();//Transmits the queued bytes
  Wire.requestFrom(DS1307_RTC_ADDRESS, 1);//Master requests 1 byte from the slave
  return(bcdToDec(Wire.read()));//Reads byte transmitted from the slave to the master and returns it converted to decimal
}

//getHours function: Returns the Hours from the RTC module
byte RTC1307::getHours(){
  Wire.beginTransmission(DS1307_RTC_ADDRESS);//Begins a transmission to the I2C slave device with the given address
  Wire.write(2);// Sets registry adress to 02h were hours is stored
  Wire.endTransmission();//Transmits the queued bytes
  Wire.requestFrom(DS1307_RTC_ADDRESS, 1);//Master requests 1 byte from the slave
  return(bcdToDec(Wire.read()));//Reads byte transmitted from the slave to the master and returns it converted to decimal
}

//setSeconds function
void RTC1307::setSeconds(int Seconds){
  Wire.beginTransmission(DS1307_RTC_ADDRESS);//Begins a transmission to the I2C slave device with the given address
  Wire.write(0);//This sets the adress to 00h spot in the registry for setting the seconds
  Wire.write(decToBcd(Seconds));//Queues byte of seconds in decimal, converted to binary coded decimal
  Wire.endTransmission();//Transmits the queued bytes
}

//setMinutes function
void RTC1307::setMinutes(int Minutes){
  Wire.beginTransmission(DS1307_RTC_ADDRESS);//Begins a transmission to the I2C slave device with the given address
  Wire.write(1);//This sets the adress to 01h spot in the registry for setting the minutes
  Wire.write(decToBcd(Minutes));//Queues byte of minutes in decimal, converted to binary coded decimal
  Wire.endTransmission();//Transmits the queued bytes
}

//setHours function
void RTC1307::setHours(int Hours){
  Wire.beginTransmission(DS1307_RTC_ADDRESS);//Begins a transmission to the I2C slave device with the given address
  Wire.write(2);//This sets the adress to 02h spot in the registry for setting the hours
  Wire.write(decToBcd(Hours));//Queues byte of hours in decimal, converted to binary coded decimal
  Wire.endTransmission();//Transmits the queued bytes
}

