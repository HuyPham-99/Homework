/*
 * File: I2C_Master.ino
 * Author: Hung Huy
 * Date: 4/12/2023
 * Description: Program master I2C Arduino
 */
/***********Master**************/
#include <Wire.h>

//Assign macros to Arduno pins to make the code explicit
#define push 5 //Button
#define LED1  4 //Led of master
#define slaveAddress 9 //Address of slave

int buttonState = 0; // variable for reading the pushbutton status

//Function set up 
void setup()
{
  Serial.begin( 9600 ); // start serial for output

  pinMode(push, INPUT);

  Wire.begin(); // join i2c bus (address optional for master) 
}

//Function main of program
/*
 * Function: loop
 * Description: Read status of button and light up LED1 after that transmit data to device #9.
 * Input:
 *   slaveAddress - int
 *   buttonState - int
 * Output:  
 *   LED1 - int
 */
void loop()
{
  Wire.beginTransmission(slaveAddress);// TRANSMIT TO DEVICE #9

  buttonState = digitalRead(push); //Read status of button

  if (buttonState == HIGH){
  
        digitalWrite(LED1,HIGH);
  }
  else{
        digitalWrite(LED1,LOW);
  }

  Wire.write(buttonState);//Write status or vallue of buttonState

  Wire.endTransmission();//End of transmission

  delay(100);
}