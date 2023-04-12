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
#define PRINT_INFORMATION(object)                   \
    printf("\n%s\t", object.getName());             \
    printf("%d\t", object.getAge());                \
    printf("%.2f\t  ", object.getKlogam());         \
    printf("  %.2f\t", object.getHight());          \
    printf("%.2f\n", object.getBmi())


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
        scanf("%d", &key);                                     \
    } while (key == 1)


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

      float klogam;

      float hight;

      float bmi;
    public:
        humans(const char name[], unsigned int ageOfHuman, float kgam, float high);

        void setName(const char name[]);

        void setAge(unsigned int ageOfHuman);

        void setKlogam(float kgam);

        void setHight(float high);

        char* getName();

        unsigned int getAge();

        float getKlogam();

        float getHight();

        float getBmi();
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
 * Function: Method setAge
 * Description: Set tuổi cho đối tượng
 * Input:
 *  ageOfHuman - usingned int  
 */
/*-------------------------------------ĐẶT TUỔI CHO ĐỐI TƯỢNG -------------------------------*/
void humans::setAge(unsigned int ageOfHuman){

    humans::age = ageOfHuman;

}

/*
 * Function: Method setKlogam
 * Description: Set cân nặng cho đối tượng
 * Input:
 *  kgam - float
 */
/*-------------------------------------ĐẶT CÂN NẶNG CHO ĐỐI TƯỢNG -------------------------------*/
void humans::setKlogam(float kgam){

    humans::klogam = kgam;

}

/*
 * Function: Method setHight
 * Description: Set chiều cao cho đối tượng
 * Input:
 *  high - float
 */
/*-------------------------------------ĐẶT CHIỀU CAO CHO ĐỐI TƯỢNG -------------------------------*/
void humans::setHight(float high){

    humans::hight = high;

}


/*
 * Function: Constructor humans
 * Description: Khởi tạo dữ liệu cho đối tượng
 * Input:
 *  name - char*
 * ageOfHuman - unsigned int
 * kgam - float
 * high - float
 */
/*-------------------------------------CONTRUSTION CỦA CON NGƯỜI -------------------------------*/
humans::humans(const char name[], unsigned int ageOfHuman, float kgam, float high){

    strcpy(humans::name, name);
    
    humans::age = ageOfHuman;

    humans::klogam = kgam;

    humans::hight = high;
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
 * Function: Method getAge
 * Description: Lấy tuổi đã nhập từ bàn phím vào hệ thống
 * Output:
 *  age - float
 */
/*-------------------------------------LẤY GIÁ TRỊ TUỔI CỦA ĐỐI TƯỢNG -------------------------------*/
unsigned int humans::getAge(){

    return humans::age;

}

/*
 * Function: Method getKlogam
 * Description: Lấy cân nặng đã nhập từ bàn phím vào hệ thống
 * Output:
 *  klogam - float
 */
/*-------------------------------------LẤY GIÁ TRỊ CÂN NẶNG CỦA ĐỐI TƯỢNG -------------------------------*/
float humans::getKlogam(){

    return humans::klogam;

}

/*
 * Function: Method getHight
 * Description: Lấy chiều cao đã nhập từ bàn phím vào hệ thống
 * Output:
 *  hight - float
 */
/*-------------------------------------LẤY GIÁ TRỊ CHIỀU CAO CỦA ĐỐI TƯỢNG -------------------------------*/
float humans::getHight(){

    return humans::hight;

}

/*
 * Function: Method getBmi
 * Description: Lấy chỉ số BMI sau khi các giá trị về đối tượng đẵ được thiết lập 
 * Output:
 *  hight - float
 */
/*-------------------------------------LẤY GIÁ TRỊ BMI CỦA ĐỐI TƯỢNG -------------------------------*/
float humans::getBmi(){

    float chiso;

    chiso = humans::klogam / pow(humans::hight,2);

    humans::hight = chiso;

    return humans::hight;
}

/*
 * Function: Class BIM
 * Description: Quản lý thông tin về các dữ liệu liên quan đến đối tượng và từ đó tính được chỉ số BMI
 */
/*
/*-------------------------------------CLASS BMI -------------------------------*/
class BIM
{
private:
    vector<humans> bmi;
public:
    void addHumans();

    void compare();

    void display();
};

/*
 * Function: Function addHumans
 * Description: Nhập dữ liệu về tên, tuổi, cân nặng, chiều cao của đối tượng
 * Input:
 *  ageOfHumans - int
 *  nameOfHumans - char
 *  kgOfHumans - float
 *  hightOfHumans - float
 */
/*-------------------------------------HÀM NHẬP GIÁ TRỊ -------------------------------*/
void BIM::addHumans(){

    int ageOfHumans;

    char nameOfHumans[20];

    float kgOfHumans;

    float hightOfHumans;

    ENTER_DATA("Nhap ten: ", "%s", &nameOfHumans, 0);

    ENTER_DATA("Nhap tuoi: ", "%d", &ageOfHumans, 0);

    ENTER_DATA("Nhap can nang: ", "%f", &kgOfHumans, 0);
    
    ENTER_DATA("Nhap chieu cao: ", "%f", &hightOfHumans, 0);

    humans humans(nameOfHumans, ageOfHumans, kgOfHumans, hightOfHumans);
    bmi.push_back(humans);
}


/*
 * Function: Function swap
 * Description: So sánh và đổi chỗ đối tượng theo điều kiện về tuổi và cân nặng
 * Input:
 *  humans *preson1
 *  humans *preson2
 */
/*-------------------------------------HÀM ĐỔI CHỖ-------------------------------*/
void swap(humans *preson1, humans *preson2)
{
    humans humans = *preson1;
    *preson1 = *preson2;
    *preson2 = humans;
}

/*
 * Function: Function compare
 * Description: So sánh và đổi chỗ đối tượng theo điều kiện về tuổi và cân nặng
 */
/*-----------------------------HÀM SẮP XẾP SINH VIÊN THEO TUỔI VÀ CÂN NẶNG-----------------------------*/
void BIM::compare(){

    bmi.empty();//Kiểm tra xem vector có rỗng hay không để xử lý yêu cầu

    if (bmi.empty())
    {
        printf("\nYEU CAU CUA BAN KHONG CO THONG TIN DE XU LY\n");

        printf("VUI LONG NHAP THONG TIN\n");
    }
    else{
        for (int indexA = 0; indexA < bmi.size() - 1; indexA++)
        {
            humans *preson1 = &bmi.at(indexA);
            for (int indexB = 1; indexB < bmi.size(); indexB++)
            {
                humans *preson2 = &bmi.at(indexB);
                if (preson1->getAge() > preson2->getAge() || preson1->getKlogam() > preson2->getKlogam())
                {
                    swap(preson1, preson2);
                }
                }
        }
        
    }
}

/*-----------------------------HÀM HIỂN THỊ DỮ LIỆU ĐỐI TƯỢNG-----------------------------*/
void BIM::display(){

    printf("\nTHONG TIN DOI TUONG");
    printf("\nTen  | Tuoi | Trong luong| Chieu cao| Chi so BMI");
   
    for(humans humans : bmi){
        PRINT_INFORMATION(humans);
    }
    
}

/*
 * Function: enum typeOfHumans
 * Description: Gán tên và chức năng cho từng hàm để dễ đọc và bảo trì
 */
enum typeOfHumans{
    addHumans = 1,
    compareHumans = 2,
    display = 3,
    exitMenu = 0,
};
/*-------------------------------------HÀM CHẠY CHƯƠNG TRÌNH -------------------------------*/
void displayOfData(){

    BIM bim;

    int choice;

    int condistion;

    int key;
    do
    {
    system("cls");
    printf("\n              CHUONG TRINH TINH BIM                  \n");
    printf("************************MENU***************************\n");
    printf("**  1. Them data                                      **\n");
    printf("**  2. So sanh                                        **\n");
    printf("**  3. Hien thi danh sach                             **\n");
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
                bim.addHumans();

                printf("*Them thong tin doi tuong thanh cong*\n");
            );
        }
        break;

    case compareHumans:
        if (compareHumans == 2)
        {
            DOWHILE_METHODMENU
            (
                bim.compare();
                
                printf("*Da sap xep danh sach theo tuoi va can nang*\n");
            );
        }
        break;

    case display:
        if (display == 3)
        {
            DOWHILE_METHODMENU
            (
                bim.display();
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

    displayOfData();

    return 0;
}