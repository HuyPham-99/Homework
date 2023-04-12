/*
 * File: SPI_SLAVE.ino
 * Author: Hung Huy
 * Date: 4/11/2023
 * Description: Chương trình slave SPI Arduino
 */
/***********Slave**************/
#include<Arduino.h>
#include<SPI.h>

//Gán macro cho các chân Arduno để code được tường minh
#define inputbutton 5
#define outputLED 4


volatile boolean received;
volatile byte Slavereceived,Slavesend;

int buttonvalue;
int x;

void setup()
{
  // put your setup code here, to run once:

  Serial.begin(115200); 
  
  pinMode(inputbutton,INPUT); 

  pinMode(outputLED,OUTPUT);   

  pinMode(MISO,OUTPUT);  // Đặt MISO làm OUTPUT                

  SPCR |= _BV(SPE);//Bật SPI ở chế độ Slave Mode trên thanh ghi SPCR (SPE: SPI ENABLE)        
  received = false;

  SPI.attachInterrupt();  //Kích hoạt ngắt SPI                
  
}

//Trình ngắt SPI
ISR (SPI_STC_vect)  //Tiến trình con xử lý ngắt (Interrupt Service Routine - ISR)                      
{
  Slavereceived = SPDR; // Lấy dữ liệu nhận được từ thanh ghi SPDR        
  received = true;                        
}

void loop()
{  
  // put your main code here, to run repeatedly:
  if(received)                           
  {
    if (Slavereceived == 1) 
    {
      digitalWrite(outputLED,HIGH);       
    }
    else
    {
      digitalWrite(outputLED,LOW);          
    }
      
    buttonvalue = digitalRead(inputbutton);  
      
    if (buttonvalue == HIGH)           
    {
      x=1;
       
    }
    else
    {
      x=0;
    }
  Slavesend=x;                

  SPDR = Slavesend;          
               
  delay(500);
  }
}