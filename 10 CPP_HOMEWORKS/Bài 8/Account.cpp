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
 * Function: MACRO DOWHILE_METHODMENU
 * Description: Macro sử dụng chức năng của từng method
 * Input:
 *   content - Nội dung chức năng của từng method
 */
#define DOWHILE_METHODMENU(content)                            \
    do                                                         \
    {                                                          \
        content                                                \
        printf("\n- Nhan phim '1' => DE TIEP TUC CHUC NANG\n");  \
        printf("\n- Nhan phim '0' => DE THOAT CHUC NANG\n");     \
        scanf("%d", &condistion);                              \
    } while (condistion == 1)

/*
 * Function: MACRO PRINT_INFORMATION
 * Description: Macro phần hiển thị thông tin
 * Input:
 *   object - đối tượng cần hiển thị
 */

#define PRINT_INFORMATION(object)                  \
    printf("\n%s\t", object.getName());            \
    printf("%u    ", object.getNumbers());         \
    printf("   %u  ", object.getRemainder())                    

/*
 * Function: Class Human
 * Description: Quản lý thông tin của con người
 */
/*
/*--------------------------------------CLASS CON NGƯỜI----------------------------------*/
class Human
{
private:
    char name[20];  

    unsigned int numberOfAccounts;

    unsigned int remainder;
public:
    Human(const char nameOfCustomer[], unsigned int numberOfAccounts, unsigned int remainder);

    void setName(const char name[]);

    void setNumbers(unsigned int numberOfAccounts);

    void setRemainder(unsigned int remainder);

    char* getName();

    unsigned int getNumbers();

    unsigned int getRemainder();
};

/*
 * Function: Method setName
 * Description: Set name cho đối tượng
 * Input:
 *  nameOfCustomer - char*
 */
/*-------------------------------------ĐẶT TÊN CHO CON NGƯỜI -------------------------------*/
void Human::setName(const char nameOfCustomer[]){
    strcpy(Human::name, nameOfCustomer);
}

/*
 * Function: Method setNumbers
 * Description: Set số tài khoản cho đối tượng
 * Input:
 *  numberOfAccounts - unsigned int
 */
/*-------------------------------------ĐẶT SỐ TÀI KHOẢN CHO CON NGƯỜI -------------------------------*/
void Human::setNumbers(unsigned int numberOfAccounts){
    Human::numberOfAccounts = numberOfAccounts;
}

/*
 * Function: Method setRemainder
 * Description: Set số dư cho đối tượng
 * Input:
 *  remainder - unsigned int
 */
/*-------------------------------------ĐẶT SỐ DƯ TÀI KHOẢN CHO CON NGƯỜI -------------------------------*/
void Human::setRemainder(unsigned int remainder){
    Human::remainder = remainder;
}

/*
 * Function: Constructor Human
 * Description: Khởi tạo dữ liệu cho đối tượng
 * Input:
 *  name - char*
 *  numberOfAccounts - unsigned int
 *  remainder - unsigned int
 */
/*-------------------------------------CONTRUSTION CỦA CON NGƯỜI -------------------------------*/
Human::Human(const char nameOfCustomer[], unsigned int numberOfAccounts, unsigned int remainder){

    strcpy(Human::name, nameOfCustomer);

    Human::numberOfAccounts = numberOfAccounts;

    Human::remainder = remainder;
}

/*
 * Function: Method getName
 * Description: Lấy tên được nhập vào từ bàn phím
 * Output:
 *  name - char*
 */
/*-------------------------------------LẤY TÊN CỦA KHÁCH HÀNG -------------------------------*/
char* Human::getName(){
    return Human::name;
}

/*
 * Function: Method getNumbers
 * Description: Lấy thông tin về số tài khoản của khách hàng được nhập vào từ bàn phím
 * Output:
 *  numberOfAccounts - unsigned int
 */
/*-------------------------------------LẤY THÔNG TIN SỐ TÀI KHOẢN CỦA KHÁCH HÀNG -------------------------------*/
unsigned int Human::getNumbers(){
    return Human::numberOfAccounts;
}

/*
 * Function: Method getRemainder
 * Description: Lấy thông tin về số dư tài khoản của khách hàng được nhập vào từ bàn phím
 * Output:
 *  remainder - unsigned int
 */
/*-------------------------------------LẤY THÔNG TIN SỐ DƯ TÀI KHOẢN CỦA KHÁCH HÀNG -------------------------------*/
unsigned int Human::getRemainder(){
    return Human::remainder;
}


/*
 * Function: Class Bank
 * Description: Quản lý thông tin của Bank
 */
/*
/*--------------------------------------CLASS HÀM XỬ LÝ BÀI TOÁN ĐỐI VỚI DỮ LIỆU ĐƯỢC NHẬP VÀO THÔNG TIN TRONG NGÂN HÀNG----------------------------------*/
class Bank{
    private:
        vector<Human> check;
    public:
        void setData();

        void withDrawals();

        void depoSit();

        void checkBalance();

        void displayOfData();
};

/*
 * Function: Function addData
 * Description: thêm dữ liệu cho hệ thống
 */
/*-----------------------------HÀM THÊM THÔNG TIN CHO HỆ THỐNG-----------------------------*/
void Bank::setData(){
    
    char name[20];

    unsigned int numbers;

    unsigned int remain;

    ENTER_DATA("Nhap ten cua khach hang: ", "%s", &name, 0);

    ENTER_DATA("Nhap so tai khoan cua khach hang: ", "%u", &numbers, 0);

    ENTER_DATA("Nhap so du tai khoan cua khach hang: ", "%u", &remain, 0);

    Human Human(name, numbers, remain);
    check.push_back(Human);
}

/*
 * Function: Function withDrawals
 * Description: Rút tiền của người dùng ra khỏi hệ thống
 */
/*-----------------------------HÀM RÚT TIỀN RA KHỎI HỆ THỐNG-----------------------------*/
void Bank::withDrawals(){
    char name[20];
    unsigned int money;
    unsigned int amount;

    vector<Human> *ptr = &check;

    check.empty();//Kiểm tra xem vector có rỗng hay không để xử lý yêu cầu
    if (check.empty())
    {
        printf("\nYEU CAU CUA BAN KHONG CO THONG TIN DE XU LY\n");

        printf("VUI LONG NHAP THONG TIN KHACH HANG\n");
    }
    else{
        ENTER_DATA("Nhap ten khach hang can tim kiem: ", "%s", name, 0);

        for (int index = 0; index < ptr->size(); index++)//Sử dụng hàm size trong thư viện vector để lấy được độ dài của vector.
                                                        //Vì vector tự ghi nhớ độ dài chính bản thân nó.
        {
            for (Human Human : check)
            {
            if (strcmp(ptr->at(index).getName(), name) == 0)//Sử dụng hàm at để lấy vị trí của phần tử trong vector
            {
                printf("\nTHONG TIN KHACH HANG");
                printf("\nTen  | So tai khoan | So du");
                
                PRINT_INFORMATION(ptr->at(index));//Sử dụng marco in thông tin

                printf("\nNhap so tien can rut: ");
                scanf("%u", &money);

                amount = ptr->at(index).getRemainder() - money;

                ptr->at(index).setRemainder(amount);
                
                printf("\nTHONG TIN SAU KHI CAP NHAT.\n");

                break;
            }
            else{
                printf("TEN CUA KHACH HANG KHONG DUNG VOI DANH SACH.\n");

                printf("\n/*TIM KIEM THONG TIN KHONG THANH CONG*/\n");

                break;
            }
            }
            
        }
    }
}

/*
 * Function: Function depoSit
 * Description: Nộp tiền của người dùng cho hệ thống
 */
/*-----------------------------HÀM NỘP TIỀN VÀO HỆ THỐNG-----------------------------*/
void Bank::depoSit(){

    char name[20];

    unsigned int money;

    unsigned int amount;

    vector<Human> *ptr = &check;

    check.empty();//Kiểm tra xem vector có rỗng hay không để xử lý yêu cầu
    if (check.empty())
    {
        printf("\nYEU CAU CUA BAN KHONG CO THONG TIN DE XU LY\n");

        printf("VUI LONG NHAP THONG TIN KHACH HANG\n");
    }
    else{
        ENTER_DATA("Nhap ten khach hang can tim kiem: ", "%s", name, 0);

        for (int index = 0; index < ptr->size(); index++)//Sử dụng hàm size trong thư viện vector để lấy được độ dài của vector.
                                                        //Vì vector tự ghi nhớ độ dài chính bản thân nó.
        {
            for (Human Human : check)
            {
            if (strcmp(ptr->at(index).getName(), name) == 0)//Sử dụng hàm at để lấy vị trí của phần tử trong vector
            {
                printf("\nTHONG TIN KHACH HANG");
                printf("\nTen  | So tai khoan | So du");
                
                PRINT_INFORMATION(ptr->at(index));//Sử dụng marco in thông tin

                printf("\nNhap so tien can nop: ");
                scanf("%u", &money);

                amount = ptr->at(index).getRemainder() + money;

                ptr->at(index).setRemainder(amount);
                
                printf("\nTHONG TIN SAU KHI CAP NHAT.\n");

                break;
            }
            else{
                printf("TEN CUA KHACH HANG KHONG DUNG VOI DANH SACH.\n");

                printf("\n/*TIM KIEM THONG TIN KHONG THANH CONG*/\n");

                break;
            }
            }
            
        }
    }
}

/*
 * Function: Function displayOfData
 * Description: Hiển thị dữ liệu cho hệ thống
 */
/*-----------------------------HÀM THÊM HIỂN THỊ HỆ THỐNG-----------------------------*/
void Bank::displayOfData(){
    char name[20];
    unsigned int money;
    unsigned int amount;

    vector<Human> *ptr = &check;

    check.empty();//Kiểm tra xem vector có rỗng hay không để xử lý yêu cầu
    if (check.empty())
    {
        printf("\nYEU CAU CUA BAN KHONG CO THONG TIN DE XU LY\n");

        printf("VUI LONG NHAP THONG TIN KHACH HANG\n");
    }
    else{
        ENTER_DATA("Nhap ten khach hang can tim kiem: ", "%s", name, 0);

        for (int index = 0; index < ptr->size(); index++)//Sử dụng hàm size trong thư viện vector để lấy được độ dài của vector.
                                                        //Vì vector tự ghi nhớ độ dài chính bản thân nó.
        {
            for (Human Human : check)
            {
            if (strcmp(ptr->at(index).getName(), name) == 0)//Sử dụng hàm at để lấy vị trí của phần tử trong vector
            {
                printf("\nTHONG TIN KHACH HANG");
                printf("\nTen  | So tai khoan | So du");
                
                PRINT_INFORMATION(ptr->at(index));//Sử dụng marco in thông tin
                break;
            }
            else{
                printf("TEN CUA KHACH HANG KHONG DUNG VOI DANH SACH.\n");

                printf("\n/*TIM KIEM THONG TIN KHONG THANH CONG*/\n");

                break;
            }
            }
            
        }
    }
}


/*
 * Function: enum typeOfHumans
 * Description: Gán tên và chức năng cho từng hàm để dễ đọc và bảo trì
 */
enum typeOfFunctions{
    addHumans = 1,
    withDrawals = 2,
    depoSit = 3,
    displayOfAcount = 4,
    exitMenu = 0,
};

/*-------------------------------------HÀM CHẠY CHƯƠNG TRÌNH -------------------------------*/
void runOfProgram(){
    Bank infor;

    int choice;

    int condistion;
    do
    {
    system("cls");
    printf("\n              CHUONG TRINH THONG TIN                  \n");
    printf("************************MENU***************************\n");
    printf("**  1. Them data                                      **\n");
    printf("**  2. Rut tien                                       **\n");
    printf("**  3. Nop tien                                       **\n");
    printf("**  4. Kiem tra so du                                 **\n");
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
                infor.setData();
                printf("\nTHEM DATA NGUOI DUNG THANH CONG\n");

            );
        }
        break;
    case withDrawals:
        if (withDrawals == 2)
        {
            DOWHILE_METHODMENU
            (

                infor.withDrawals();
                system("cls");
                infor.displayOfData();
                
                printf("\nYEU CAU RUT TIEN THANH CONG\n");
            );
        }
        break;
    case depoSit:
        if (depoSit == 3)
        {
            DOWHILE_METHODMENU
            (
                infor.depoSit();

                system("cls");

                infor.displayOfData();

                printf("\nYEU CAU NOP TIEN THANH CONG\n");

            );
        }
        break;
    case displayOfAcount:
        if (displayOfAcount == 4)
        {
            DOWHILE_METHODMENU
            (
                infor.displayOfData();

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
