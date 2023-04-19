
#define CHANGE_STATUS 1

#define BUTTON_PIN 2 

const byte ledPin[] = {3,4,5,6,7,8,9,10};

byte countLed;

volatile byte status = LOW; // khai báo biến kiểu volatile, tránh sai số trong quá trình thực hiện ngắt.

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
  countLed = sizeof(ledPin);  

  for (int i=0 ; i < countLed ; i++) 
  {
    pinMode(ledPin[i],OUTPUT);  //Các chân LED là OUTPUT

    digitalWrite(ledPin[i],LOW); //Mặc định các đèn LED sẽ tắt
    
    digitalWrite(BUTTON_PIN, HIGH);    // Treo chân ngắt 0, chân số 2 lên mức cao.
  }

  attachInterrupt(0, switchStatus, CHANGE_STATUS); // khai báo ngắt 0, chương trình con switchStatus, chế độ có sự thay đổi là sinh ngắt

}

/*
* Function: loop
* Description: Hàm chạy lặp đi lặp lại khi Arduino hoạt động
* - Bật tất cả các đèn LED và tắt tất cả LED thông qua ngắt ngoài là button
*/
void loop() {
  /*
    Bật tất cả các đèn LED
  */
  for (int i=0; i < countLed; i++)
  {
    digitalWrite(ledPin[i],status); //Bật đèn
  }
}

void switchStatus()   // chương trình con ngắt, khi có ngắt xảy ra sẽ thực hiện chương trình này.
{ 
  status = !status;   // đảo trang thái.
}
