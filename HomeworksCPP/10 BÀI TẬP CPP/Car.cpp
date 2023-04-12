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
    printf("\n%s\t", object.getColor());           \
    printf("  %s    ", object.getEngine());        \
    printf("\t%u\n  ", object.getKm())                    

/*
 * Function: Class car
 * Description: Quản lý thông tin của xe
 */
/*
/*--------------------------------------CLASS CAR----------------------------------*/
class car{
    private:
        char color[20];

        char engine[20];

        unsigned int km;

        unsigned int costs;
    public:
        car(const char color[20], const char engine[20], unsigned int km);

        void setColor(const char color[]);

        void setEngine(const char engine[]);

        void setKm(unsigned int km);

        char* getColor();

        char* getEngine();

        unsigned int getKm();

        unsigned int getCosts();
};

/*
 * Function: Method setColor
 * Description: Set màu sắc cho xe
 * Input:
 *  color - char*
 */
/*-------------------------------------ĐẶT MÀU SẮC CHO XE -------------------------------*/
void car::setColor(const char color[])
{
    strcpy(car::color, color);
}

/*
 * Function: Method setEngine
 * Description: Set kiểu động cơ cho xe
 * Input:
 *  engine - char*
 */
/*-------------------------------------ĐẶT THÔNG TIN ĐỘNG CƠ CHO XE -------------------------------*/
void car::setEngine(const char engine[])
{
    strcpy(car::engine, engine);
}

/*
 * Function: Method setKm
 * Description: Set KM mà xe đã đi
 * Input:
 *  km - unsigned int
 */
/*-------------------------------------ĐẶT THÔNG TIN VỀ SỐ KM MÀ XE ĐÃ ĐI-------------------------------*/
void car::setKm(unsigned int km){
    car::km = km;
}


/*
 * Function: Constructor car
 * Description: Khởi tạo dữ liệu cho đối tượng
 * Input:
 *  color - char*
 *  engine - char*
 *  km - unsigned int
 */
/*-------------------------------------CONTRUSTION CỦA XE -------------------------------*/
car::car(const char color[20], const char engine[20], unsigned int km){
    strcpy(car::color, color);
    strcpy(car::engine, engine);
    car::km = km;
}

/*
 * Function: Method getColor
 * Description: Lấy màu sắc được nhập vào từ bàn phím
 * Output:
 *  color - char*
 */
/*-------------------------------------LẤY MÀU SẮC CỦA XE -------------------------------*/
char* car::getColor(){
    return car::color;
}

/*
 * Function: Method getEngine
 * Description: Lấy thông tin động cơ được nhập vào từ bàn phím
 * Output:
 *  engine - char*
 */
/*-------------------------------------LẤY THÔNG TIN ĐỘNG CƠ CỦA XE -------------------------------*/
char* car::getEngine(){
    return car::engine;
}

/*
 * Function: Method getKm
 * Description: Lấy thông tin số km được nhập vào từ bàn phím
 * Output:
 *  engine - char*
 */
/*-------------------------------------LẤY THÔNG TIN SỐ KM MÀ XE ĐÃ ĐI  -------------------------------*/
unsigned int car::getKm(){
    return car::km;
}


/*
 * Function: Method getCosts
 * Description: Dựa vào dữ liệu về số KM đã đi, thông qua getCosts ta được số tiền cần bảo trì
 * Output:
 *  costs - unsigned int
 */
/*-------------------------------------LẤY THÔNG TIN SỐ TIỀN MÀ XE CẦN BẢO TRÌ -------------------------------*/
unsigned int car::getCosts(){
    unsigned int cost;
    cost = (car::getKm()/20000)*700000;
    car::costs = cost;
    return car::costs;
}


/*
 * Function: Class maintenanceCosts
 * Description: Quản lý thông tin về chi phí bảo trì cũng như thông tin về xe
 */
/*
/*--------------------------------------CLASS THÔNG TIN CỦA XE VÀ CHI PHÍ BẢO TRÌ----------------------------------*/
class maintenanceCosts{
    private:
        vector<car> check;
    public:
        void setData();

        void costs();

        void displayOfData();
};

/*
 * Function: Function setData
 * Description: thêm dữ liệu cho hệ thống
 */
/*-----------------------------HÀM THÊM THÔNG TIN CHO HỆ THỐNG-----------------------------*/
void maintenanceCosts::setData(){
    char colorOfCar[20];

    char engineOfCar[20];

    unsigned int kmOfCheck;

    ENTER_DATA("Nhap mau cua xe: ", "%s", &colorOfCar, 0);

    ENTER_DATA("Nhap kieu dong co cua xe: ", "%s", &engineOfCar, 0);

    ENTER_DATA("Nhap KM ma xe da di: ", "%u", &kmOfCheck, 0);

    car car(colorOfCar, engineOfCar, kmOfCheck);

    check.push_back(car);

}

/*
 * Function: Function costs
 * Description: Hiển thị dữ liệu cho hệ thống
 */
/*-----------------------------HÀM TÍNH CHI PHÍ BẢO TRÌ DỰA VÀO SỐ KM ĐÃ ĐI-----------------------------*/
void maintenanceCosts::costs(){//Chi phí sửa chữa

    char color[20];

    char type[20];

    unsigned int money;

    unsigned int cost;

    vector<car> *ptr = &check;

    check.empty();//Kiểm tra xem vector có rỗng hay không để xử lý yêu cầu
    if (check.empty())
    {
        printf("\nYEU CAU CUA BAN KHONG CO THONG TIN DE XU LY\n");

        printf("VUI LONG NHAP THONG TIN KHACH HANG\n");
    }
    else{
        ENTER_DATA("Nhap mau xe: ", "%s", &color, 0);

        ENTER_DATA("Nhap kieu dong co: ", "%s", &type, 0);

        for (int index = 0; index < ptr->size(); index++)//Sử dụng hàm size trong thư viện vector để lấy được độ dài của vector.
                                                        //Vì vector tự ghi nhớ độ dài chính bản thân nó.
        {
            for (car car : check)
            {
            if (strcmp(ptr->at(index).getColor(), color) || strcmp(ptr->at(index).getEngine(), type) == 0)//Sử dụng hàm at để lấy vị trí của phần tử trong vector
            {
                printf("\nTHONG TIN KHACH HANG");
                printf("\nMau xe  | Kieu dong co | So km");

                PRINT_INFORMATION(ptr->at(index));//Sử dụng marco in thông tin

                printf("\nChi phi bao tri la: %u", ptr->at(index).getCosts());  

                ptr->erase(ptr->begin() + index);
                
                break;
            }
            else{
                printf("TEN CUA KHACH HANG KHONG DUNG VOI DANH SACH.");

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
void maintenanceCosts::displayOfData(){
    printf("\nTHONG TIN KHACH HANG");
    printf("\nMau xe  | Kieu dong co | So km");
    for (car car : check){
        PRINT_INFORMATION(car);
    }
}

/*
 * Function: enum typeOfHumans
 * Description: Gán tên và chức năng cho từng hàm để dễ đọc và bảo trì
 */
enum typeOfCar{
    adData = 1,
    costsOfMaintenance = 2,
    displayOfResult = 3,
    exitMenu = 0,
};

/*-------------------------------------HÀM CHẠY CHƯƠNG TRÌNH -------------------------------*/
void runOfProgram(){
    maintenanceCosts results;

    int choice;

    int condistion;
    do
    {
    system("cls");
    printf("\n              CHUONG TRINH THONG TIN                 \n");
    printf("************************MENU***************************\n");
    printf("**  1. Them data                                      **\n");
    printf("**  2. Chi phi bao tri                                **\n");
    printf("**  3. Hien thi data                                  **\n");
    printf("**  0. Thoat menu                                     **\n");
    printf("*******************************************************\n");
    printf("Vui long nhap su lua chon: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case adData:
        if (adData == 1)
        {
            DOWHILE_METHODMENU
            (
                results.setData();
                printf("\nTHEM DU LIEU XE THANH CONG\n");

            );
            
        }
        break;
    case costsOfMaintenance:
        if (costsOfMaintenance == 2)
        {
            results.displayOfData();
            DOWHILE_METHODMENU
            (
                printf("\nTINH TOAN CHI PHI BAO TRI THANH CONG\n");
                results.costs();
            );
        }
        break;

    case displayOfResult:
        if (displayOfResult == 3)
        {
            DOWHILE_METHODMENU
            (
                results.displayOfData();
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
