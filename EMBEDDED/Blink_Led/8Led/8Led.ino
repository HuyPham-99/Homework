
const byte ledPin[] = {3,4,5,6,7,8,9,10};

byte countLed;

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
  }
}

/*
* Function: loop
* Description: Hàm chạy lặp đi lặp lại khi Arduino hoạt động
* - Bật tuần tự các đèn LED
* - Tắt tuần tự các đèn LED
*/
void loop() {
  /*
    Bật tuần tự các đèn LED
  */
  for (int i=0; i < countLed; i++) 
  {
    digitalWrite(ledPin[i],HIGH); //Bật đèn

    delay(200); // Dừng để các đèn LED sáng dần
  }
  
  /*
    Tắt tuần tự các đèn LED
  */
  for (int i = 0;i < countLed; i += 1) 
  {
    digitalWrite(ledPin[i],LOW); // Tắt đèn

    delay(200); // Dừng để các đèn LED tắt dần
  }
}
