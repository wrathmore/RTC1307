//Header file: class declaration
#include <Arduino.h> // This include is for all the arduino specific defines
#include <Wire.h>//Library that handles I2C protocol
#define BAUD_RATE 115200 //setting of the baudrate
#define DS1307_RTC_ADDRESS 104 // defines the adress of the slave RTC module for the I2C protocol

#ifndef RTC1307_h // This is to make sure we do not load the library more then once
#define RTC1307_h // and declares the library in this scope

  class RTC1307{
   
    private://Acces specifier
    
    //Member functions
    byte bcdToDec(byte);
      //converts binary coded decimal to decimal
    byte decToBcd(byte);
      //converts decimal to binary coded decimal
    
    public:// Acces specifier
    
    //default constructor
    RTC1307();
    
    //Overload constructor
    RTC1307(int,int,int);
    
    //Destructor
    ~RTC1307();
    
    //Accesor funnctions
    byte getHours();
      //Returns the hours from the RTC module
      
    byte getMinutes();
      //Returns the minutes from the RTC module

    byte getSeconds();
      //Returns the seconds from the RTC module
     
    //Mutator functions
    void setHours(int);
      //Sets the hours on the RTC module

    void setMinutes(int);
      //Sets the minutes on the RTC module

    void setSeconds(int);
      //Sets the seconds on the RTC module
  };

#endif

