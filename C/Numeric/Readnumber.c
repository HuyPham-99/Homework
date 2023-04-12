/*
* File: Read_Number.c
* Author: Hung Huy
* Date: 28/03/2023
* Description: Đọc giá trị của số được nhập từ bàn phím.
*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <conio.h>



/*
 * Function: ENUM_OF_VALUE_OF_NUMBERS
 * Description: Dùng enum để người dùng hiểu được ý nghĩa của các số được xét trong chương trình
 * Input:
 *   numbers: (zero,one,two,three,four,five,six,seven,eight,nine)
 *   values: (0,1,2,3,4,5,6,7,8,9)
 */
/*---------------------------------------GIÁ TRỊ CỦA SỐ-------------------------------------*/
enum theValueOfTheNumber{//Sử dụng enum để code được tường minh và người kế thừa sẽ hiểu được chức năng của chương trình một cách khách quan nhất
   
    zero = 0,

    one= 1,

    two = 2,

    three = 3,

    four = 4,

    five = 5,

    six = 6,

    seven = 7,

    eight = 8,

    nine = 9,
};


/*
 * Function: THE_VALUE_OF_THE_NUMBERS
 * Description: Dùng đọc giá trị của từng số theo từng vị trí trong mảng
 * Input:
 *   numbers: (zero,one,two,three,four,five,six,seven,eight,nine)
 *   values: (0,1,2,3,4,5,6,7,8,9)
 */
/*--------------------------------------VỊ TRÍ GIÁ TRỊ TƯƠNG ỨNG CỦA SỐ----------------------------------*/
void theValueOfTheNumber(uint8_t num) 
{
    switch (num) 
    {
        case zero:

            printf("khong ");

            break;

        case one:

            printf("mot ");

            break;

        case two:

            printf("hai ");

            break;

        case three:

            printf("ba ");

            break;

        case four:

            printf("bon ");

            break;

        case five:

            printf("nam ");

            break;

        case six:

            printf("sau ");

            break;

        case seven:
            printf("bay ");

            break;

        case eight:

            printf("tam ");

            break;

        case nine:

            printf("chin ");

            break;
        default:

            printf("");

            break;
        
    }
}


/*
 * Function: ENUM_OF_DECIMAL_VALUE_OF_NUMBERS
 * Description: Dùng enum để người dùng hiểu được ý nghĩa thập phận của các số theo từng vị trí
 * Input:
 *   numbers: (zero,one,two,three,four,five)
 *   values: (0,1,2,3,4,5)
 */
/*---------------------------------------GÍA TRỊ THẬP PHÂN CỦA SỐ-------------------------------------*/
enum decimalValueOfNumbers{//Sử dụng enum để code được tường minh và người kế thừa sẽ hiểu được chức năng của chương trình một cách khách quan nhất
    
    millions = 0,// hàng triệu
    
    Hundreds= 1,// hàng trăm
    
    rowTens = 2,// hàng mười
    
    thousands = 3,//hàng nghìn
    
    Hundred = 4,// hàng trăm
    
    rowTen = 5,// hàng mười
};



/*
 * Function: DECIMAL_VALUE_OF_NUMBER
 * Description: Dùng đọc giá trị thập phân của từng số theo từng vị trí trong mảng
 * Input:
 *   numbers: (zero,one,two,three,four,five)
 *   values: (0,1,2,3,4,5)
 */
/*--------------------------------------GIÁ TRỊ THẬP PHÂN TƯƠNG ỨNG CỦA SỐ----------------------------------*/
void decimalValueOfNumbers(uint8_t num) 
{
    switch (num) 
    {
        case millions:

            printf("trieu ");

            break;

        case Hundreds:
        case Hundred:

            printf("tram ");
            
            break;
            
        case rowTens:
        case rowTen:
            
            printf("muoi ");
            
            break;
        
        case thousands:
            
            printf("nghin ");
           
            break;
    }
}


/*
 * Function: READ_THE_POSITION_OF_NUMBER
 * Description: Dùng đọc và lấy vị trí của từng số có trong mảng 
 * Input:
 *   i: thứ tự của các số ở trong mảng
 */
/*--------------------------------------HÀM ĐỌC VỊ TRÍ CỦA SỐ----------------------------------*/
void readThePositionOfTheNumber(uint8_t Arr[]) {
    //Chỉ giải quyết được khi nhập số có bảy chữ số và chưa giải quyết triệt để khi arr[i] có số 0
    for (int i = 0; i < 7; i++) 
    { 
        if (Arr[i] != 0) //Trường hợp khác 0 thì đọc vị trí rồi đọc giá trị thập phân tương ứng với vị trí đó
        {
            theValueOfTheNumber(Arr[i]); // Trường hợp khi dãy số là 1111111 thì chưa giải quyết được triệt để
            
            decimalValueOfNumbers(i);
        }
        if (Arr[2] == 0 && Arr[3] == 0 && Arr[4] == 0 && Arr[5] == 0)
        {
            continue;
        }
        else if ((i == 1 || i == 4) && (Arr[i] == 0)) // Nếu tại vị trí arr[1] và arr[4] thì giá trị được đọc là không trăm
        {
            printf("khong tram ");
        }
        else if ((i == 2 || i == 5) && (Arr[i] == 0)) // Nếu tại giá trị arr[2] và arr[5] thì đọc là linh
        {
            printf("linh ");
        } 
    }
}



/*
 * Main
 * Description: Nhập số cần đọc và in ra giá trị tương ứng
 * Input:
 *   i: thứ tự của các số ở trong mảng
 *   num: dãy số cần đọc
 *   Max: giá trị lớn nhất có thể đọc
 */
int main(int argc, char const *argv[])
{
    //Nhap dãy số n cần đọc
    //Sử dụng do..while để yêu cầu người dùng nhập dữ liệu vào 
    //Nếu nhập khác với điều kiện bài toán (n > 1000000) thì yêu cầu nhập lại

    uint32_t num;
    uint32_t Max = 10000000;
    uint8_t Arr[7];

    do
    {
        printf("Nhap gia tri cua n: ");

        scanf("%u", &num);
    } while (num < 0 || num >= Max);
    
    for (int i = 6; 0 <= i; i--) 
    {
        Arr[i] = num % 10;//Tách các số lần lượt ở hàng triệu, trăm nghìn, chục nghìn, hàng nghìn, hàng trăm, hàng chục, hàng đơn vị
                            
        num = num / 10;
    }
    printf("Cach doc cua day so la: ");

    readThePositionOfTheNumber(Arr);
    

    getch();
    return 0;
    
}