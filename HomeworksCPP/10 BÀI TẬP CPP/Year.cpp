#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

/*--------------------------------------MACRO NHẬP DỮ LIỆU----------------------------------*/
/*
 * Function: MACRO ENTER_DATA
 * Description: Macro phần nhập thông tin 
 * Input:
 *   content - Nội dung cần nhập
 *   format - định dạng kiểu dữ liệu
 *   variable - biến cần nhập vào
 *   condition - điều kiện để nhập
 */

#define ENTER_DATA(content, format, variable,condition)         \
    do                                                          \
    {                                                           \
        printf(content);                                        \
        scanf(format, variable);                                \
    } while (condition)        

/*
 * Function: MACRO DOWHILE_METHODMENU
 * Description: Macro sử dụng chức năng của từng method
 * Input:
 *   content - Nội dung chức năng của từng method
 */
#define DOWHILE_METHODMENU(content)                            \
    do                                                         \
    {                                                          \
        content                                                \
        printf("- Nhan phim '1' => DE TIEP TUC CHUC NANG\n");  \
        printf("- Nhan phim '0' => DE THOAT CHUC NANG\n");     \
        scanf("%d", &condistion);                              \
    } while (condistion == 1)

/*
 * Function: MACRO PRINT_INFORMATION
 * Description: Macro phần hiển thị thông tin
 * Input:
 *   object - đối tượng cần hiển thị
 */
#define PRINT_INFORMATION(object)                  \
    printf("\n%u\t", object.getDay());             \
    printf("%u    ", object.getMonth());           \
    printf("   %u  ", object.getYear());           \
    printf(" %u\t", object.getAge())            


/*
 * Function: Class YearHoliday
 * Description: Quản lý thông tin về ngày tháng năm
 * intput: 
 *  days - unsigned int 
 *  months - unsigned int 
 *  years - unsigned int 
 */ 
/*--------------------------------------CLASS CỦA NĂM----------------------------------*/
class YearHoliday
{
private:
    unsigned int days;

    unsigned int months;

    unsigned int years;

    unsigned int age;
public:
    YearHoliday(unsigned int day, unsigned int month, unsigned int year);

    void setDays(unsigned int day);

    void setMonths(unsigned int month);

    void setYears(unsigned int year);

    unsigned int getDay();

    unsigned int getMonth();

    unsigned int getYear();

    unsigned int getAge();
};

/*
 * Function: Method setDays
 * Description: Set ngày
 * Input:
 *  day - unsigned int
 */
/*-------------------------------------ĐẶT NGÀY CHO HỆ THỐNG -------------------------------*/
void YearHoliday::setDays(unsigned int day){

    YearHoliday::days = day;
}

/*
 * Function: Method setMonths
 * Description: Set tháng
 * Input:
 *  month - unsigned int
 */
/*-------------------------------------ĐẶT THÁNG CHO HỆ THỐNG -------------------------------*/
void YearHoliday::setMonths(unsigned int month){

    YearHoliday::months = month;
}

/*
 * Function: Method setYears
 * Description: Set năm
 * Input:
 *  year - unsigned int
 */
/*-------------------------------------ĐẶT NĂM CHO HỆ THỐNG -------------------------------*/
void YearHoliday::setYears(unsigned int year){

    YearHoliday::years = year;
}


/*
 * Function: CONTRUSTION YearHoliday
 * Description: Quản lý thông tin về ngày tháng năm
 * intput: 
 *  days - unsigned int 
 *  months - unsigned int 
 *  years - unsigned int 
 */ 
/*-------------------------------------CONTRUSTION CỦA YearHoliday -------------------------------*/

YearHoliday::YearHoliday(unsigned int day, unsigned int month, unsigned int year){

    YearHoliday::days = day;
    
    YearHoliday::months = month;

    YearHoliday::years = year;
}


/*
 * Function: Method getDay
 * Description: Lấy giá trị ngày được nhập vào từ bàn phím
 * Output:
 *  days - unsigned int
 */
/*-------------------------------------LẤY GIÁ TRỊ NGÀY -------------------------------*/
unsigned int YearHoliday::getDay(){

    return YearHoliday::days;
}

/*
 * Function: Method getMonth
 * Description: Lấy giá trị tháng được nhập vào từ bàn phím
 * Output:
 *  months - unsigned int
 */
/*-------------------------------------LẤY GIÁ TRỊ THÁNG -------------------------------*/
unsigned int YearHoliday::getMonth(){

    return YearHoliday::months;
}

/*
 * Function: Method getYear
 * Description: Lấy giá trị năm được nhập vào từ bàn phím
 * Output:
 *  years - unsigned int
 */
/*-------------------------------------LẤY GIÁ TRỊ NĂM -------------------------------*/
unsigned int YearHoliday::getYear(){

    return YearHoliday::years;
}


/*
 * Function: Method getAge
 * Description: Lấy giá trị tuổi bằng năm hiện tại trừ đi năm sinh
 * Output:
 *  age - unsigned int
 */
/*-------------------------------------LẤY GIÁ TRỊ TUỔI -------------------------------*/
unsigned int YearHoliday::getAge(){

    unsigned int age;

    age = 2023 - YearHoliday::years;

    YearHoliday::age = age;

    return YearHoliday::age;
}

/*
 * Function: Class yearHoliday
 * Description: Quản lý thông tin của yearHoliday
 */
/*
/*--------------------------------------CLASS THÔNG TIN YEARHOLIDAY----------------------------------*/
class yearHoliday{
    private:
        vector<YearHoliday> holiday;
    public:
        void addData();

        void displayOfData();
};

/*
 * Function: Function addData
 * Description: thêm dữ liệu cho hệ thống
 */
/*-----------------------------HÀM THÊM THÔNG TIN CHO HỆ THỐNG-----------------------------*/
void yearHoliday::addData(){

    unsigned int day;

    unsigned int month;

    unsigned int year;

    ENTER_DATA("Nhap ngay sinh: ", "%u", &day, day < 1 || day > 31);

    ENTER_DATA("Nhap thang sinh: ", "%u", &month, month < 1 || month > 12);

    ENTER_DATA("Nhap nam sinh: ", "%u", &year, year < 0);

    YearHoliday YearHoliday(day,month,year);

    holiday.push_back(YearHoliday);
}

/*
 * Function: Function displayOfData
 * Description: Hiển thị dữ liệu cho hệ thống
 */
/*-----------------------------HÀM THÊM HIỂN THỊ HỆ THỐNG-----------------------------*/
void yearHoliday::displayOfData(){

    printf("\nTHONG TIN DOI TUONG");
    printf("\nNgay  | Thang | Nam  | Tuoi");
   
    for(YearHoliday YearHoliday : holiday){
        PRINT_INFORMATION(YearHoliday);
    }
}


/*
 * Function: enum typeOfHumans
 * Description: Gán tên và chức năng cho từng hàm để dễ đọc và bảo trì
 */
enum typeOfHumans{
    addHumans = 1,
    display = 2,
    exitMenu = 0,
};
/*-------------------------------------HÀM CHẠY CHƯƠNG TRÌNH -------------------------------*/
void runOfProgram(){

    yearHoliday data;

    unsigned int choice;

    unsigned int condistion;

    do
    {
    system("cls");
    printf("\n              CHUONG TRINH THONG TIN                  \n");
    printf("************************MENU***************************\n");
    printf("**  1. Them data                                      **\n");
    printf("**  2. Hien thi danh sach                             **\n");
    printf("**  0. Thoat menu                                     **\n");
    printf("*******************************************************\n");
    printf("Vui long nhap su lua chon: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case addHumans:
        if (addHumans == 1)
        {
            DOWHILE_METHODMENU
            (
                system("cls");
                data.addData();
                printf("THEM DU LIEU CHO HE THONG THANH CONG\n");

            );
        }
        break;
    case display:
        if (display == 2)
        {
            DOWHILE_METHODMENU
            (
                data.displayOfData();
                printf("\n");
            );
        }
        break;
    case exitMenu:
        break;
    default:
        printf("Yeu cau khong ton tai\n");
        printf("Vui long nhap yeu cau\n");
        system("\nPause");
    }
    } while (choice != 0);
}

int main(int argc, char* argv[]){

    runOfProgram();

    return 0;
}