/*
 * File: I2C_MASTER.cpp
 * Author: Hung Huy
 * Date: 4/13/2023
 * Description: Chương trình master I2C Arduino
 */

/***********Master**************/
#include <Arduino.h>

/*
 * Function: MACRO TFull
 * Description: TFull: chu kỳ clock 
 */
#define TFull 50


//Xác lập địa chỉ cho Slave
#define SLAVE_ADDRESS 0x55

/*
 * Function: MACRO SCL_PIN, MACRO SDA_PIN
 * Description: Định dạng các port theo I2C Arduino
 */
#define SCL_PIN A5
#define SDA_PIN A4

/*
 * Function: MACRO SCL_OUTPUT, MACRO SDA_OUTPUT, MACRO SDA_INPUT
 * Description: Set up của các chân SCL và SDA trạng thái nhận hay xuất data
 */
#define SCL_OUTPUT pinMode(SCL_PIN, OUTPUT)
#define SCL_INPUT pinMode(SCL_PIN, INPUT)
#define SDA_OUTPUT pinMode(SDA_PIN, OUTPUT)
#define SDA_INPUT pinMode(SDA_PIN, INPUT)

/*
 * Function: MACRO SCL_HIGH, MACRO SCL_LOW
 * Description: Set up trạng thái cho SCL là HIGH hoặc LOW
 */
#define SCL_HIGH digitalWrite(SCL_PIN, HIGH)
#define SCL_LOW digitalWrite(SCL_PIN, LOW)

/*
 * Function: MACRO SDA_HIGH, MACRO SDA_LOW
 * Description: Set up trạng thái cho SDA là HIGH hoặc LOW
 */
#define SDA_HIGH digitalWrite(SDA_PIN, HIGH)
#define SDA_LOW digitalWrite(SDA_PIN, LOW)

/*
 * Function: MACRO SDA_READ, MACRO SCL_READ
 * Description: Đọc data tại SDA và SCL
 */
#define SDA_READ digitalRead(SDA_PIN)
#define SCL_READ digitalRead(SCL_PIN)


/*
* Function: setup
* Description: Hàm chỉ chạy 1 lần duy nhất khi Arduino hoạt động
* Input:
*   void
* Output:
*   return: None
*/
void setup()
{
  delay(100);

  Serial.begin(9600);
}

/*
* Function: loop
* Description: Hàm chạy lặp đi lặp lại khi Arduino hoạt động
* - Đọc data từ Slave và truyền data ngược lại cho Slave
*/
void loop()
{
    byte res[10] = {0};

    int8_t data;

    Serial.println("Started write data");

    char c_Data[10] = "1234";

    Serial.println(String((char*) c_Data));

    data = I2C_Writedata(SLAVE_ADDRESS, c_Data);

    Serial.println("Started write data successfully");

    delay(200);

    data = I2C_ReadData(SLAVE_ADDRESS, res, 4);

    Serial.println("Started reading");
    
    if (data == 1)
    {
      Serial.println("Read data from Slave is ok: ");

      Serial.println(String((char*) res));
    }
    else 
    {
      Serial.println("Fail to read");
    }
    
    delay(200);
}

/*
* Function: I2C_Start
* Description: Hàm bắt đầu giao tiếp I2C
* Input:
*   void
* Output:
*   return: None
*/
void I2C_Start(void)
{
  SDA_HIGH;

  SCL_HIGH;
	
  SDA_OUTPUT;

  SCL_OUTPUT;
  delayMicroseconds(TFull/2);//Delay 1 chu kỳ 

  SDA_LOW;  
  delayMicroseconds(TFull/2);//Delay 1 chu kỳ 

  SCL_LOW;	
}

/*
* Function: I2C_Stop
* Description: Hàm kết thúc giao tiếp I2C
* Input:
*   void
* Output:
*   return: None
*/
void I2C_Stop(void){	
	SDA_LOW;
    delayMicroseconds(TFull/2);//Delay 1 chu kỳ 

    SCL_HIGH;
	delayMicroseconds(TFull/2);//Delay 1 chu kỳ 	

    SDA_HIGH;
}


/*
* Function: I2C_ReadAck
* Description: Hàm đọc tín hiệu ACK hoặc NACK từ Slave để quyết định READ or WRITE
* Input:
*   void
* Output:
*   return: ACK - uint8_t
*/
//Hàm check ACK or NACK
uint8_t I2C_ReadAck(void){

  uint8_t ACK;

  //READ ACK OR NACK 
  SDA_INPUT; 
  delayMicroseconds(TFull/2);

  SCL_HIGH;
  delayMicroseconds(TFull/2);

  //Đọc giá trị sau đó lưu vào uint8_t ACK
  ACK = SDA_READ; //Trả về 0 hoặc 1

  SCL_LOW;

  SDA_OUTPUT;

  delayMicroseconds(TFull/2);

  return ACK;  //ACK = 0 hoặc NACK = 1;
}

/*
* Function: I2C_Write8bit
* Description: Hàm truyền 8 bit data từ Master sang Slave
* Input:
*   data - byte
* Output:
*   No return
*/
//Hàm gửi 8 data
void I2C_Write8bit(byte data){ //Only send 8bit with 8 clock no start/stop/ack

    uint8_t i;

    for (int i = 0; i < 8; i++)
    {
        if ((data & 0x80) != 0) //data & 1000.0000 = 1
        {
          SDA_HIGH; //Gửi bit cao nhất 1
        }
        else
        {
          SDA_LOW; //Gửi bit thấp nhất 0
        }

        data = data << 1;   
        
        delayMicroseconds(TFull/2);
        SCL_HIGH;
        delayMicroseconds(TFull/2);
        SCL_LOW;
    }
}

/*
* Function: I2C_Writedata
* Description: Hàm truyền n data từ Master sang Slave
* Input:
*   address - byte
*   data - char*
* Output:
*   No return 1 or -1 (Success or Failure)
*/
//Hàm gửi n data
uint8_t I2C_Writedata(byte address, char* data){

    uint8_t ack;

    //(1) Start
    I2C_Start();
    
    //(2) Start sending data
    address = address << 1; //7 bit + 0 => write data

    I2C_Write8bit(address);

    //(3) READ ACK OR NACK 
    ack = I2C_ReadAck();

    if (ack == 1) //ACK == NACK
    {
      I2C_Stop();

      return -1;
    }
    //(4) Send data until data == 0 
    else{
      while (*data != '\0')
      {
        I2C_Write8bit(*data);
          
        ack = I2C_ReadAck(); //Check ACK

        if (ack == 1) //ACK == NACK
        {
          I2C_Stop();

          return -1;
        }
        data++;
      }
    }
    //(5) Stop sending
    I2C_Stop(); 

    return 1;
}

/*
* Function: I2C_Read8bit
* Description: Hàm đọc 8 bit data từ Slave gửi về Master
* Input:
*   void
* Output:
*   data - uint8_t
*/
//Hàm đọc 8 bit data
byte I2C_Read8bit(void)
{
    uint8_t data; 

    int i;

    SDA_INPUT;

    SCL_OUTPUT;

    SCL_LOW;

    //READ 8BIT DATA-----------------------
    for (int i = 0; i < 8; i++)
    {
        delayMicroseconds(TFull/2);
        
        SCL_HIGH;

        data = (data << 1) | SDA_READ;

        delayMicroseconds(TFull/2);

        SCL_LOW;
    }

    return data;
}

/*
* Function: I2C_SendAck
* Description: Hàm gửi tín hiệu ACK hoặc NACK tới Slave
* Input:
*   void 
* Output:
*   ACK or NACK
*/
void I2C_SendAck(void)
{
    SCL_LOW;

    SDA_OUTPUT;

    SDA_LOW;//Send ACK
    delayMicroseconds(TFull/2);

    SCL_HIGH;
    delayMicroseconds(TFull/2);

    SCL_LOW;
    
    SDA_INPUT;
    delayMicroseconds(TFull/2);
}

/*
* Function: I2C_ReadData
* Description: Hàm đọc n data từ Slave gửi về Master
* Input:
*   address - byte
*   data - byte*
*   count - byte
* Output:
*   No return 1 or -1 (Success or Failure)
*/
//Hàm đọc n data
int8_t I2C_ReadData(byte address, byte* data, byte count){

    int8_t ack;
    //(1) START --------------------------------
    I2C_Start();

    //(2) SEND ADDRESS (7bit) + (1 bit READ) --------------------------------
    address = (address << 1) + 1; //7 bit + 1 => READ data

    I2C_Write8bit(address);

    //(3) Check ACK------------------------------
    ack = I2C_ReadAck();

    if (ack == 1) //ACK == NACK
    {
      I2C_Stop();

      return -1; //FAIL (-1)
    }
    //(4) Đọc n data
    else{
      for (int i = 0; i < count; i++)
      {
        *data = I2C_Read8bit();

        data++; 

        I2C_SendAck();
      }
    }
    //(5) STOP-------------------
    I2C_Stop();
    
    return 1;
}