
/*
 * File: SPI_MASTER.ino
 * Author: Hung Huy
 * Date: 4/11/2023
 * Description: Chương trình master SPI Arduino
 */

/***********Master**************/
#include <Arduino.h>
#include <SPI.h>

//Gán macro cho các chân Arduno để code được tường minh
#define push 5 

#define LED 4

//Gán macro cho các chân Arduno để code được tường minh
#define SCK_PIN 13

#define MISO_PIN 12

#define MOSI_PIN 11

#define SS_PIN 10

int x;

int value;

void setup() {

  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(push, INPUT);

  pinMode(LED, OUTPUT);

  SPI.begin();

  SPI.setClockDivider(SPI_CLOCK_DIV8);
  
  digitalWrite(SS_PIN, HIGH);

}

void loop() {
  
  // put your main code here, to run repeatedly:
  byte m_send, m_receive;

  value = digitalRead(push);

  if(value == HIGH){

    x = 1;
    
  }
  else{

    x = 0;

  }

  digitalWrite(SS_PIN, LOW);

  m_send = x;

  m_receive = SPI.transfer(m_send);

  if (m_receive == 1){

    digitalWrite(LED,HIGH);

  }
  else{

    digitalWrite(LED,LOW);

  }
  delay(500);
}
