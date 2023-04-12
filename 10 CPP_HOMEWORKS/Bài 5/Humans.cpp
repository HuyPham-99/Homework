#include <stdio.h>
#include <stdint.h>
#include <string.h>
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
 * Function: MACRO PRINT_INFORMATION
 * Description: Macro phần hiển thị thông tin 
 * Input:
 *   object - đối tượng cần hiển thị
 */
#define PRINT_INFORMATION(object)                  \
    printf("\n%s\t", object.getName());            \
    printf("%d    ", object.getAge());             \
    printf("%s  ", object.getAddres());            \
    printf(" %d\t\n", object.getYear())            

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
 * Function: Class humans
 * Description: Quản lý thông tin của con người
 */
/*
/*--------------------------------------CLASS CỦA CON NGƯỜI----------------------------------*/
class humans{
    private:
      char name[20];

      unsigned int age;

      unsigned int years;

      char address[20];
    public:
        humans(const char name[], unsigned int year, const char addres[]);

        void setName(const char name[]);

        void setYear(unsigned int year);
        
        void setAddress(const char addres[]);

        char* getName();

        unsigned int getYear();
        
        unsigned int getAge();

        char* getAddres();

};

/*
 * Function: Method setName
 * Description: Set tên cho đối tượng
 * Input:
 *  name - char* 
 */
/*-------------------------------------ĐẶT TÊN CHO ĐỐI TƯỢNG -------------------------------*/
void humans::setName(const char name[]){

    strcpy(humans::name,name);
}


/*
 * Function: Method setAddress
 * Description: Set năm sinh cho đối tượng
 * Input:
 *  year - unsigned int
 */
/*-------------------------------------ĐẶT NĂM SINH CHO ĐỐI TƯỢNG -------------------------------*/
void humans::setYear(unsigned int year){
    humans::years = year;
}

/*
 * Function: Method setAddress
 * Description: Set địa chỉ cho đối tượng
 * Input:
 *  addres - addres* 
 */
/*-------------------------------------ĐẶT ĐỊA CHỈ CHO ĐỐI TƯỢNG -------------------------------*/
void humans::setAddress(const char addres[]){
    strcpy(humans::address, addres);
}

/*
 * Function: Constructor humans
 * Description: Khởi tạo dữ liệu cho đối tượng
 * Input:
 *  name - char*
 *  address - char*
 *  year - unsigned int
 */
/*-------------------------------------CONTRUSTION CỦA CON NGƯỜI -------------------------------*/
humans::humans(const char name[], unsigned int year, const char addres[]){
    strcpy(humans::name, name);
    humans::years = year;
    strcpy(humans::address, addres);
}


/*
 * Function: Method getName
 * Description: Lấy tên đã nhập từ bàn phím vào hệ thống
 * Output:
 *  name - char*
 */
/*-------------------------------------LẤY GIÁ TRỊ TÊN CỦA ĐỐI TƯỢNG -------------------------------*/
char* humans::getName(){
    return humans::name;
}

/*
 * Function: Method getYear
 * Description: Lấy năm sinh đã nhập từ bàn phím vào hệ thống
 * Output:
 *  year - unsigned int
 */
/*-------------------------------------LẤY GIÁ TRỊ NĂM SINH CỦA ĐỐI TƯỢNG -------------------------------*/
unsigned int humans::getYear(){
    return humans::years;
}

/*
 * Function: Method getAddres
 * Description: Lấy địa chỉ đã nhập từ bàn phím vào hệ thống
 * Output:
 *  address - char*
 */
/*-------------------------------------LẤY GIÁ TRỊ ĐỊA CHỈ CỦA ĐỐI TƯỢNG -------------------------------*/
char* humans::getAddres(){
    return humans::address;
}

/*
 * Function: Method getAge
 * Description: Lấy giá trị tuổi của đối tượng từ năm sinh (dùng năm hiện tại trừ đi năm sinh)
 * Output:
 *  age - unsigned int
 */
/*-------------------------------------LẤY GIÁ TRỊ TUỔI CỦA ĐỐI TƯỢNG -------------------------------*/
unsigned int humans::getAge(){
    unsigned int Age;
    Age = 2023 - humans::years;
    humans::age = Age;
    return humans::age;
}

/*
 * Function: Class Information
 * Description: Quản lý thông tin của con người
 */
/*
/*--------------------------------------CLASS THÔNG TIN CỦA CON NGƯỜI----------------------------------*/
class Information{
    private:
        vector<humans> information;

    public:
        void addDataOfHuman();

        void displayOfDataOfHuman();
};

/*
 * Function: Function addDataOfHuman
 * Description: Thêm thông tin của đối tượng như tên, năm sinh và địa chỉ
 */
/*-----------------------------HÀM THÊM THÔNG TIN CỦA ĐỐI TƯỢNG-----------------------------*/
void Information::addDataOfHuman(){

    unsigned int yearOfHumans;

    char nameOfHumans[20];

    char addresOfHumans[20];

    ENTER_DATA("Nhap ten: ", "%s", &nameOfHumans, 0);

    ENTER_DATA("Nhap nam sinh: ", "%u", &yearOfHumans, 0);

    ENTER_DATA("Nhap dia chi: ", "%s", &addresOfHumans, 0);

    humans humans(nameOfHumans, yearOfHumans, addresOfHumans);
    information.push_back(humans);
}

/*-----------------------------HÀM HIỂN THỊ THÔNG TIN CỦA ĐỐI TƯỢNG-----------------------------*/
void Information::displayOfDataOfHuman(){
    printf("\nTHONG TIN DOI TUONG");
    printf("\nTen  | Tuoi | Dia chi\t  | Nam sinh\n");
   
    for(humans humans : information){
        PRINT_INFORMATION(humans);
    }
}


/*
 * Function: enum typeOfHumansg
 * Description: Gán tên và chức năng cho từng hàm để dễ đọc và bảo trì
 */
enum typeOfHumans{
    addHumans = 1,
    display = 2,
    exitMenu = 0,
};
/*-------------------------------------HÀM CHẠY CHƯƠNG TRÌNH -------------------------------*/
void runOfProgram(){
    
    Information infor;

    unsigned int  choice;

    unsigned int  condistion;

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
    scanf("%u", &choice);
    switch (choice)
    {
    case addHumans:
        if (addHumans == 1)
        {
            DOWHILE_METHODMENU
            (
                infor.addDataOfHuman();

                printf("*Them thong tin doi tuong thanh cong*\n");
            );
        }
        break;

    case display:
        if (display == 2)
        {
            DOWHILE_METHODMENU
            (
                infor.displayOfDataOfHuman();
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