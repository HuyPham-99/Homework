
/*
 * File: SPI_MASTER.ino
 * Author: Hung Huy
 * Date: 4/13/2023
 * Description: Chương trình master SPI Arduino
 */
/***********Master**************/
#include <Arduino.h>

/*
 * Function: MACRO TFull
 * Description: TFull: chu kỳ clock 
 */
#define TFull 50

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
//Đọc trạng thái của button pin
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
 * Function: MACRO SCK_OUPUT, MACRO MISO_INPUT, MACRO MOSI_OUPUT, MACRO SS_OUTPUT
 * Description: Set up của các chân Arduino trạng thái nhận hay xuất data
 */
#define SCK_OUPUT pinMode(SCK_PIN, OUTPUT)
#define MISO_INPUT pinMode(MISO_PIN, INPUT)
#define MOSI_OUPUT pinMode(MOSI_PIN, OUTPUT)
#define SS_OUTPUT pinMode(SS_PIN, OUTPUT)

/*
 * Function: MACRO MOSI_HIGH, MACRO MOSI_LOW
 * Description: Set up trạng thái cho MOSI là HIGH hoặc LOW
 */
#define MOSI_HIGH digitalWrite(MOSI_PIN, HIGH)
#define MOSI_LOW digitalWrite(MOSI_PIN, LOW)

/*
 * Function: MACRO SS_HIGH, MACRO SS_LOW
 * Description: Set up trạng thái cho SS là HIGH hoặc LOW
 */
#define SS_HIGH digitalWrite(SS_PIN, HIGH)
#define SS_LOW  digitalWrite(SS_PIN, LOW)

/*
 * Function: MACRO SCK_HIGH, MACRO SCK_LOW
 * Description: Set up trạng thái cho SCK là HIGH hoặc LOW
 */
#define SCK_HIGH digitalWrite(SCK_PIN, HIGH)
#define SCK_LOW digitalWrite(SCK_PIN, LOW)

/*
 * Function: MACRO READ_MISO
 * Description: Đọc data từ chân MISO
 */
//Đọc trạng thái của MISO pin
#define READ_MISO digitalRead(MISO_PIN)


/*
* Function: SPI_setup
* Description: Hàm set up SPI cho master
* Input:
*   void
* Output:
*   return: None
*/
//Set up SPI cho Master
void SPI_setup(void)
{
    MOSI_OUPUT;

    MISO_INPUT;

    SCK_LOW;

    SCK_OUPUT;

    SS_HIGH;

    SS_OUTPUT;

    BUTTON_INPUT;

    LED_OUTPUT;

    delay(1);
}

/*
* Function: SPI_begin
* Description: Hàm bắt đầu giao tiếp SPI
* Input:
*   void
* Output:
*   return: None
*/
void SPI_begin(void)
{
    SS_LOW; //1 Master - 1 Slave
}

/*
* Function: SPI_end
* Description: Hàm kết thúc giao tiếp SPI
* Input:
*   void
* Output:
*   return: None
*/
void SPI_end(void)
{
    SCK_LOW;
    SS_HIGH;
}

/*
* Function: SPI_transfer
* Description: Hàm truyền và nhận đồng thời 1 byte data của master
* Input:
*   No input
* Output:
*   return: byte_in - uint8_t
*/
uint8_t SPI_transfer(uint8_t byte_out)
{
    uint8_t byte_in = 0; //0000.0000

    uint8_t ibit;   //ibit: intergerBit

    uint8_t result; 

    for (ibit = 0x80; ibit > 0; ibit = ibit >> 1) //Dịch từng bit của ibit qua phải từng đơn vị cho đến khi ->0000.0000(stop condistion)
    {
        result = byte_out & ibit; //(#0 = true) , (=0 = false)

        if (result != 0)
        {
            MOSI_HIGH;
        }
        else if (result == 0)
        {
            MOSI_LOW;
        }
        delayMicroseconds(TFull/2); //Đợi nữa chu kỳ lấy data mẫu
        SCK_HIGH; 

        //Đọc data MISO
        if (READ_MISO == HIGH)
        {
            byte_in = byte_in | ibit; //0000.0000(byte_in) | 1000.0000(ibit) = 1000.0000
        }
        delayMicroseconds(TFull/2); //Đợi nữa chu kỳ lấy data mẫu
        SCK_LOW; //Kết thức 1 chu kỳ clock
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
* - Đọc data khi BUTTON = 1 tương ứng nút bấm được nhấn và truyền data qua slave, 
* sau đó dựa trên data mà slave gửi về để quyết định LED sáng hay không.
*/
void loop(){

    uint8_t vallue;

    byte m_send, m_receive;//Data truyền và data nhận

    SPI_begin();

    vallue = READ_BUTTON;

    SS_LOW;

    m_send = vallue;
    m_receive = SPI_transfer(m_send);

    if (m_receive == 1){
        LED_LOW;
    }
    else{
        LED_HIGH;
    }

    SPI_end();  

    delay(200);
}