/*
 * File: SPI_SLAVE.ino
 * Author: Hung Huy
 * Date: 4/13/2023
 * Description: Chương trình slave SPI Arduino
 */
/***********Slave**************/
#include <Arduino.h>

/*
 * Function: MACRO BUTTON_PIN, MACRO LED_PIN
 * Description: Định dạng port cho các thiết bị ngoại vi
 */
#define BUTTON_PIN 5
#define LED_PIN 4

/*
 * Function: MACRO BUTTON_INPUT, MACRO BUTTON_OUTPUT
 * Description: Set up cho button trạng thái nhận hay xuất data
 */
#define BUTTON_INPUT pinMode(BUTTON_PIN, INPUT);
#define BUTTON_OUTPUT pinMode(BUTTON_PIN, OUTPUT);

/*
 * Function: MACRO READ_BUTTON
 * Description: Đọc data từ button
 */
#define READ_BUTTON digitalRead(BUTTON_PIN)
#define READ_BUTTON digitalRead(BUTTON_PIN)

/*
 * Function: MACRO LED_INPUT, MACRO LED_OUTPUT
 * Description: Set up cho led trạng thái nhận hay xuất data
 */
#define LED_INPUT pinMode(LED_PIN, INPUT);
#define LED_OUTPUT pinMode(LED_PIN, OUTPUT);

/*
 * Function: MACRO LED_HIGH, MACRO LED_LOW
 * Description: Set up trạng thái cho LED là HIGH hoặc LOW
 */
#define LED_HIGH digitalWrite(LED_PIN, HIGH)
#define LED_LOW digitalWrite(LED_PIN, LOW)

/*
 * Function: MACRO SCK_PIN, MACRO MISO_PIN, MACRO MOSI_PIN, MACRO SS_PIN
 * Description: Định dạng các port theo SPI Arduino
 */
#define SCK_PIN 13
#define MISO_PIN 12
#define MOSI_PIN 11
#define SS_PIN 10

/*
 * Function: MACRO SCK_INPUT, MACRO MISO_OUTPUT, MACRO MOSI_INTPUT, MACRO SS_INPUT
 * Description: Set up của các chân Arduino trạng thái nhận hay xuất data
 */
#define SCK_INPUT pinMode(SCK_PIN, INPUT)
#define MISO_OUTPUT pinMode(MISO_PIN, OUTPUT)
#define MOSI_INTPUT pinMode(MOSI_PIN, INPUT)
#define SS_INPUT pinMode(SS_PIN, INPUT)


/*
 * Function: MACRO READ_SCK
 * Description: Đọc trạng thái của SCK 
 */
#define READ_SCK digitalRead(SCK_PIN)

/*
 * Function: MACRO READ_MOSI
 * Description: Đọc trạng thái của MOSI 
 */
#define READ_MOSI digitalRead(MOSI_PIN)

/*
 * Function: MACRO READ_SS
 * Description: Đọc trạng thái của SS
 */
#define READ_SS digitalRead(SS_PIN)

/*
 * Function: MACRO MISO_HIGH, MACRO MISO_LOW
 * Description: Ghi trạng thái của MISO
 */
#define MISO_HIGH digitalWrite(MISO_PIN, HIGH)
#define MISO_LOW digitalWrite(MISO_PIN, LOW)

/*
* Function: SPI_setup
* Description: Hàm set up SPI cho Slave
* Input:
*   void
* Output:
*   return: None
*/
void SPI_setup(void)
{
    SCK_INPUT;

    MISO_OUTPUT;

    MOSI_INTPUT;

    SS_INPUT;

    BUTTON_INPUT;

    LED_OUTPUT;
}


/*
* Function: SPI_transfer
* Description: Hàm truyền và nhận đồng thời 1 byte data của slave
* Input:
*   No input
* Output:
*   return: byte_in - uint8_t
*/
uint8_t SPI_transfer(uint8_t byte_out)//Transfer byte from slave
{
    uint8_t byte_in = 0; //0000.0000

    uint8_t ibit;   //ibit: intergerBit

    uint8_t result; 

    while (READ_SS == HIGH); //Đợi SS == 0 (xuống mức thấp): start condistion

    for (ibit = 0x80; ibit > 0; ibit = ibit >> 1)
    {
        result = byte_out & ibit; //(#0 = true) , (=0 = false) 

        if (result != 0)
        {
            MISO_HIGH;
        }
        else if (result == 0)
        {
            MISO_LOW;
        }

        while (READ_SCK == LOW); //Đợi SCK lên 1

        if (READ_MOSI == HIGH) //Đọc data đầu vào của MOSI nếu data đọc được là 1 thì set data vào tại vị trí tương ứng là 1
        {
            byte_in = byte_in | ibit; ///0000.0000(byte_in) | 1000.0000(ibit) = 1000.0000
        }

        while (READ_SCK == HIGH); //Đợi SCK về 0
        //Kết thúc 1 chu kỳ clock
       
    }
    return byte_in;
}

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
    
    SPI_setup();
}

/*
* Function: loop
* Description: Hàm chạy lặp đi lặp lại khi Arduino hoạt động
* - Đọc data khi BUTTON = 1 tương ứng nút bấm được nhấn và truyền data qua master, 
* sau đó dựa trên data mà master đã gửi để quyết định LED sáng hay không.
*/
void loop(){

    uint8_t vallue;

    byte m_send, m_receive;//Data truyền và data nhận

    vallue = READ_BUTTON;

    m_send = vallue;

    m_receive = SPI_transfer(m_send);

    if (m_receive == 1){
        LED_HIGH;
    }
    else{
        LED_LOW;
    }
    delay(200);
}