/*
 * File: I2C_Slave.ino
 * Author: Hung Huy
 * Date: 4/12/2023
 * Description: Program slave I2C Arduino
 */
/***********Slave**************/
#include <Wire.h>

#define LED2 13 //Led of slave

#define slaveAddress 9 //Address of slave

int buttonState = LOW; //Set up status of button is LOW

//Function set up 
void setup()
{
  // Start the I2C Bus as Slave on address 9
  Wire.begin(slaveAddress);
  
  Wire.onReceive(receiveEvent); 

  // Define the LED pin as Output
  pinMode(LED2, OUTPUT);
}

/*
 * Function: receiveEvent
 * Description: Attach a function to trigger when something is received.
 * - Read status of button and light up LED2.
 * Input:
 *   buttonState - int
 * Output:  
 *   LED2 - int
 */
void receiveEvent(int buttonState)
{
  buttonState = Wire.read();

  if (buttonState == LOW){
  
        digitalWrite(LED2,HIGH);
  }
  else{
        digitalWrite(LED2,LOW);
  }
}

//Function main of program
void loop()
{
  delay(100);
}

