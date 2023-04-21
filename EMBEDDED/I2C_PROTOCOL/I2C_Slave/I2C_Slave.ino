/*
 * File: I2C_SLAVE.cpp
 * Author: Hung Huy
 * Date: 4/13/2023
 * Description: Chương trình slave I2C Arduino
 */

/***********SLAVE**************/
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
void setup(){

    Serial.begin(9600);
    delay(100);
}

/*
* Function: loop
* Description: Hàm chạy lặp đi lặp lại khi Arduino hoạt động
* - Đọc data từ Master và truyền data ngược lại cho Master
*/
/*USE THIS FUNCTION
- I2C BEGIN(): CHECK START CONDISTIONS , CHECK ADDRESS 
- I2C WRITE(): SENE CHAR *DATA
- I2C READ():  READ DATA[] FROM MASTER
*/
void loop(){
    
    int8_t data;//Condistion data from master

    int8_t dataFromS;//data from Slave to master

    byte dataFromMaster[10] = {0};

    char dataFromSlave[10] = "1234";

    data = I2C_Begin(SLAVE_ADDRESS);//Đợi tín hiệu từ Master

    if (data == 0)
    {   
       I2C_ReadData(dataFromMaster, 4);

       Serial.println("Data from Master is:");

       Serial.println(String((char*) dataFromMaster));
    }
    else if(data == 1) //Truyền data cho Master
    {   
        
        dataFromS = I2C_WriteData(dataFromSlave);

        Serial.println("Master want to read data");

        Serial.println(dataFromSlave);

        if (dataFromS == 1)
        {
            Serial.println("Write data successful");
        }
        else if(dataFromS == -1)
        {
            Serial.println("Write data failed");
        }
        else{
            Serial.println("SOMETHING ERROR");
        }
    }
    //Wrong address
    else if(data == -1){
        Serial.println("Wrong address");
    }
    //Data is uncontroll
    else{
        Serial.println("Other number return uncontrol");
    }
    delay(200);
}


/*
* Function: I2C_Begin
* Description: Hàm bắt đầu giao tiếp I2C
* Input:
*   address - byte
* Output:
*   return:  
*   (1) Right address
*           Write: 0
*           Read: 1
*   (2) Wrong address: return 2
*   (3) Not start condistion : loop again
*/
uint8_t I2C_Begin(byte address){
   
    uint8_t Ack_Read_Write = 0;

    uint8_t data = 0;

    uint8_t i;

    while (true)
    {
        SDA_INPUT;

        SCL_INPUT;

        while ((SDA_READ != 1 || SCL_READ != 1)); //Đợi tín hiệu từ Master (start condition)

        while (SDA_READ == 1); //Đợi tín hiệu từ SDA_READ về 0 chuẩn bị bắt đầu quá trình đọc dữ liệu từ Master 

        delayMicroseconds(1); //Delay nữa chu kỳ

        if (SCL_READ == 1)// Start condition
        {
            while (SCL_READ == 1); //Đợi tín hiệu SCL về 0

            for (int i = 0; i < 8; i++)
            {
                while (SCL_READ == 0); //Đợi tín hiệu SCL về 1
            
                data = (data << 1) | SDA_READ; 

                while (SCL_READ == 1); //Đợi tín hiệu SCL về 0
            }
            
            //Gía trị của ACK or NACK
            Ack_Read_Write =  data & 1;

            data = data >> 1;

            if (data == address)
            {
                I2C_SendAck();

                return Ack_Read_Write;
            }
            else{
                return -1;
            }
        }
        else
        {
            //Do nothing if address is not true
        }
    }
    
}

/*
* Function: I2C_Read8bit
* Description: Hàm đọc 8 bit data từ Master gửi về Slave
* Input:
*   void
* Output:
*   data - uint8_t
*/
uint8_t I2C_Read8bit(void){

    uint8_t i;

    uint8_t data;

    SDA_INPUT;

    SCL_INPUT;

    for (int i = 0; i < 8; i++)
    {
        while (SCL_READ == 0); //Đợi tín hiệu SCL về 1
            
        data = (data << 1) | SDA_READ; 

        while (SCL_READ == 1); //Đợi tín hiệu SCL về 0
    }
    //Đọc 1 byte data thành công

    return data;
}

/*
* Function: I2C_ReadData
* Description: Hàm đọc n data từ Slave gửi về Master
* Input:
*   dataFromMaster - byte*
*   count - uint8_t
* Output:
*   data - byte
*/
int8_t I2C_ReadData(byte* dataFromMaster, uint8_t count){

    for (int i = 0; i < count; i++)
    {
        *dataFromMaster = I2C_Read8bit();

        dataFromMaster++;   

        I2C_SendAck();
    }
}

/*
* Function: I2C_Write8bit
* Description: Hàm truyền 8 bit data từ Slave sang Master
* Input:
*   data - byte
* Output:
*   No return
*/
//Send 8 bit (1 byte data) to Master
void I2C_Write8Data(byte data){

    SDA_OUTPUT;

    uint8_t i;

    for (int i = 0; i < 8; i++)
    {
        if((data & 0x80) != 0)
        {
            SDA_HIGH;
        }
        else
        {
            SDA_LOW;
        }

        data = data << 1;

        while (SCL_READ == 0);//Đợi tín hiệu SCL từ master

        while (SCL_READ == 1);//Đợi tín hiệu SCL từ master  

    }
    SDA_INPUT;
}

/*
* Function: I2C_ReadAck
* Description: Hàm đọc tín hiệu ACK hoặc NACK từ Master để quyết định READ or WRITE
* Input:
*   void
* Output:
*   return: ACK - uint8_t
*/
//Hàm check ACK or NACK của Slave
uint8_t I2C_ReadAck(void){

  uint8_t ACK;

  //READ ACK OR NACK 
  SDA_INPUT; 
  delayMicroseconds(TFull/2);
   
  while (SCL_READ == 0);//Đợi tín hiệu SCL từ master

  //Đọc giá trị sau đó lưu vào uint8_t ACK
  ACK = SDA_READ; //Trả về 0 hoặc 1

  while (SCL_READ == 1);//Đợi tín hiệu SCL từ master

  return ACK;  //ACK = 0 hoặc NACK = 1;
}

/*
* Function: I2C_SendAck
* Description: Hàm gửi tín hiệu ACK hoặc NACK tới Master
* Input:
*   void 
* Output:
*   ACK or NACK
*/
void I2C_SendAck(void)
{
    SDA_OUTPUT;

    SDA_LOW; //Send ACK to Master

    while (SCL_READ == 0); //Đợi tín hiệu SCL về 1

    while (SCL_READ == 1); //Đợi tín hiệu SCL về 0

    SDA_INPUT;  
}


/*
* Function: I2C_WriteData
* Description: Hàm gửi n data từ Slave gửi về Master
* Input:
*   data - char*
* Output:
*   No return 1 or -1 (Success or Failure)
*/
//Send n data from Slave to master
uint8_t I2C_WriteData(char *data)
{
    uint8_t ack;

    while (*data != '\0')
    {
        I2C_Write8Data(*data);

        ack = I2C_ReadAck();
        if (ack == 1)
        {
            SDA_INPUT;

            return ack;
        }
        data++;  
    }

    SDA_INPUT;
    return 1;
}

