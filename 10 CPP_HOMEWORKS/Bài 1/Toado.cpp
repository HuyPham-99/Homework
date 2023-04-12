#include<stdio.h>
#include<math.h>
#include <iostream>
#include <vector>
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
#define PRINT_INFORMATION1(numberOfPoint, object)   \
    printf("\n%u\t|", numberOfPoint);                \
    printf("%u\t|", object.getX1());               \
    printf("  %u\t|    ", object.getY1());             \
    printf("%u\t|", object.getX2());                 \
    printf("  %u\t|", object.getY2());             \
    printf(" %.2f        |    \n", object.getDistanceAB())    

        
/*
 * Function: MACRO PRINT_INFORMATION
 * Description: Macro phần hiển thị thông tin
 * Input:
 *   object - đối tượng cần hiển thị
 */
#define PRINT_INFORMATION2(numberOfPoint, object)       \
    printf("  %u\t|", numberOfPoint);                   \
    printf("%u\t|", object.getX2());                    \
    printf("  %u\t|    ", object.getY2());              \
    printf("%u\t|", object.getX3());                    \
    printf("  %u\t|    ", object.getY3());        \
    printf(" %.2f        |    \n", object.getDistanceBC())  

/*
 * Function: MACRO PRINT_INFORMATION
 * Description: Macro phần hiển thị thông tin
 * Input:
 *   object - đối tượng cần hiển thị
 */
#define PRINT_INFORMATION3(numberOfPoint, object)       \
    printf("  %u\t|", numberOfPoint);                   \
    printf("%u\t|", object.getX1());                    \
    printf("  %u\t|    ", object.getY1());              \
    printf("%u\t|", object.getX3());                    \
    printf("  %u\t|    ", object.getY3());        \
    printf(" %.2f        |    \n", object.getDistanceAC())  

    
/*--------------------------------------CLASS CỦA TỌA ĐỘ MẶT PHẲNG----------------------------------*/
class Point
{
    private:
        unsigned int x1, x2, x3;
        unsigned int y1, y2, y3;


        float distanceAB;
        float distanceBC;
        float distancAC;

        float area;
    public:
        Point(unsigned int X1, unsigned int Y1, unsigned int X2, unsigned int Y2, unsigned int X3, unsigned int Y3);

        void setPointX1(unsigned int X1);
        
        void setPointY1(unsigned int Y1);

        void setPointX2(unsigned int X2);
        
        void setPointY2(unsigned int Y2);

        void setPointX3(unsigned int X3);
        
        void setPointY3(unsigned int Y3);


        unsigned int getX1();

        unsigned int getY1();

        unsigned int getX2();

        unsigned int getY2();

        unsigned int getX3();

        unsigned int getY3();

        float getArea();

        float getDistanceAB();

        float getDistanceBC();

        float getDistanceAC();
};

/*--------------------------------------ĐẶT TUNG ĐỘ CHO ĐIỂM 1---------------------------------*/
void Point::setPointX1(unsigned int X1){
    Point::x1 = X1;
}
/*--------------------------------------ĐẶT HOÀNH ĐỘ CHO ĐIỂM 1---------------------------------*/
void Point::setPointY1(unsigned int Y1){
    Point::y1 = Y1;
}

/*--------------------------------------ĐẶT TUNG ĐỘ CHO ĐIỂM 2---------------------------------*/
void Point::setPointX2(unsigned int X2){
    Point::x2 = X2;
}
/*--------------------------------------ĐẶT HOÀNH ĐỘ CHO ĐIỂM 2---------------------------------*/
void Point::setPointY2(unsigned int Y2){
    Point::y2 = Y2;
}


/*--------------------------------------ĐẶT TUNG ĐỘ CHO ĐIỂM 3---------------------------------*/
void Point::setPointX3(unsigned int X3){
    Point::x3 = X3;
}
/*--------------------------------------ĐẶT HOÀNH ĐỘ CHO ĐIỂM 3---------------------------------*/
void Point::setPointY3(unsigned int Y3){
    Point::y3 = Y3;
}

/*------------------------------------CONSTRUCTOR TỌA ĐỘ CÁC ĐIỂM TRONG MẶT PHẲNG----------------------------------*/
Point::Point(unsigned int X1, unsigned int Y1, unsigned int X2, unsigned int Y2, unsigned int X3, unsigned int Y3)
{
    Point::x1 = X1;
    Point::y1= Y1;

    Point::x2 = X2;
    Point::y2= Y2;

    Point::x3 = X3;
    Point::y3= Y3;

}


/*--------------------------------------LẤY DATA TUNG ĐỘ CHO ĐIỂM 1---------------------------------*/
unsigned int Point::getX1(){

    return Point::x1;
}
/*--------------------------------------LẤY DATA HOÀNH ĐỘ CHO ĐIỂM 1---------------------------------*/
unsigned int Point::getY1(){

    return Point::y1;
}

/*--------------------------------------LẤY DATA TUNG ĐỘ CHO ĐIỂM 2---------------------------------*/
unsigned int Point::getX2(){

    return Point::x2;
}
/*--------------------------------------LẤY DATA HOÀNH ĐỘ CHO ĐIỂM 2---------------------------------*/
unsigned int Point::getY2(){

    return Point::y2;
}
/*--------------------------------------LẤY DATA TUNG ĐỘ CHO ĐIỂM 3---------------------------------*/
unsigned int Point::getX3(){

    return Point::x3;
}
/*--------------------------------------LẤY DATA HOÀNH ĐỘ CHO ĐIỂM 3---------------------------------*/
unsigned int Point::getY3(){

    return Point::y3;
}

/*--------------------------------------LẤY DATA KHOẢNG CÁCH GIỮA ĐIỂM 1 VÀ ĐIỂM 2 ---------------------------------*/
float Point::getDistanceAB(){
    unsigned int dis;

    dis = sqrt(pow(Point::x2 - Point::x1,2) + pow(Point::y2 - Point::y1,2));

    Point::distanceAB = dis;

    return Point::distanceAB;
}

/*--------------------------------------LẤY DATA KHOẢNG CÁCH GIỮA ĐIỂM 2 VÀ ĐIỂM 3 ---------------------------------*/
float Point::getDistanceBC(){
    unsigned int dis;

    dis = sqrt(pow(Point::x3 - Point::x2,2) + pow(Point::y3 - Point::y2,2));

    Point::distanceBC = dis;

    return Point::distanceBC;
}

/*--------------------------------------LẤY DATA KHOẢNG CÁCH GIỮA ĐIỂM 1 VÀ ĐIỂM 3 ---------------------------------*/
float Point::getDistanceAC(){
    unsigned int dis;

    dis = sqrt(pow(Point::x3 - Point::x1,2) + pow(Point::y3 - Point::y1,2));

    Point::distancAC = dis;

    return Point::distancAC;
}

/*--------------------------------------LẤY DATA DIỆN TÍCH CỦA TAM GIÁC TƯƠNG ỨNG ---------------------------------*/
float Point::getArea(){
    return Point::area;
}

/*--------------------------------------CLASS CỦA BÀI TOÁN----------------------------------*/
class Math
{
    private:
        vector<Point> coorDinates;

    public:

        void setData();

        void displayData1();

        void displayData2();

        void displayData3();

        void checkAndMathTriangleType();
};

/*--------------------------------------CHỨC NĂNG THÊM DATA CHO BÀI TOÁN----------------------------------*/
void Math::setData(){

    unsigned int pointX1;

    unsigned int pointY1;

 
    unsigned int pointX2;

    unsigned int pointY2;


    unsigned int pointX3;

    unsigned int pointY3;

    unsigned int condistion;

    system("cls");
    printf("YEU CAU BAI TOAN\n");
    printf("1.TINH KHOANG CACH GIUA HAI DIEM TRONG TOA DO PHANG\n");
    printf("2.TINH DIEN TICH TAM GIAC KHI CO BA DIEM DUOC XAC DINH TRONG TOA DO PHANG\n");

    ENTER_DATA("Nhap yeu cau can tinh toan: ", "%u", &condistion, condistion > 2 || condistion < 0);

    if (condistion == 1)
    {
        ENTER_DATA("Nhap toa do diem x1: ", "%u", &pointX1, 0);

        ENTER_DATA("Nhap toa do diem y1: ", "%u", &pointY1, 0);

        ENTER_DATA("Nhap toa do diem x2: ", "%u", &pointX2, 0);

        ENTER_DATA("Nhap toa do diem y2: ", "%u", &pointY2, 0);
    }

 
    if (condistion == 2)
    {
        ENTER_DATA("Nhap toa do diem x1: ", "%u", &pointX1, 0);

        ENTER_DATA("Nhap toa do diem y1: ", "%u", &pointY1, 0);

        ENTER_DATA("Nhap toa do diem x2: ", "%u", &pointX2, 0);

        ENTER_DATA("Nhap toa do diem y2: ", "%u", &pointY2, 0);

        ENTER_DATA("Nhap toa do diem x3: ", "%u", &pointX3, 0);

        ENTER_DATA("Nhap toa do diem y3: ", "%u", &pointY3, 0);
    }
    

    Point Point(pointX1, pointY1, pointX2, pointY2, pointX3, pointY3);

    coorDinates.push_back(Point);
}

/*--------------------------------------CHỨC NĂNG KIỂM TRA LOẠI TAM GIÁC TƯƠNG ỨNG VÀ TÍNH DIỆN TÍCH TAM GIÁC----------------------------------*/
/*--------------------------------------CHỨC NĂNG NÀY CHƯA HOÀN THIỆN DO DỮ LIỆU ĐỂ KIỂM TRA BÀI TOÁN TỪ 3 ĐIỂM BẤT KỲ TRONG TỌA ĐỘ PHẲNG LÀ VÔ CÙNG NHIỀU----------------------------------*/
void Math::checkAndMathTriangleType(){
    Point *AB;

    Point *BC;

    Point *AC;

    float heightOfTriangle;

    float areaOfTriangle;
    vector<Point> *ptr = &coorDinates;

    coorDinates.empty();

    if (coorDinates.empty())
    {
        printf("\nYEU CAU CUA BAN KHONG CO THONG TIN DE XU LY\n");

        printf("KHONG THE TINH DIEN TICH TAM GIAC\n");
    }
    else{
        for (int index = 0; index < ptr->size(); index++)
        {
            Point *AB = &coorDinates.at(index);

            Point *BC = &coorDinates.at(index);

            Point *AC = &coorDinates.at(index);


            printf("Tu 3 diem trong toa do phang ta duoc cac canh cua tam giac tuong ung\n");
            printf("Gia tri cua canh AB: %.2f\n", ptr->at(index).getDistanceAB());
            printf("Gia tri cua canh BC: %.2f\n", ptr->at(index).getDistanceBC());
            printf("Gia tri cua canh AC: %.2f\n", ptr->at(index).getDistanceAC());

            printf("Nhap chieu cao cua tam giac tuong unng: ");
            scanf("%f", &heightOfTriangle);

            areaOfTriangle = (ptr->at(index).getDistanceAC() * heightOfTriangle) * 0.5;

            printf("Dien tich cua tam giac tuong ung: %.2f\n", areaOfTriangle);
        }
        
    }
}

/*--------------------------------------HIỂN THỊ TỌA ĐỘ GIỮA HAI ĐIỂM 1 VÀ ĐIỂM 2----------------------------------*/
void Math::displayData1(){
    coorDinates.empty();

    if (coorDinates.empty())
    {
        printf("\nYEU CAU CUA BAN KHONG CO THONG TIN DE XU LY\n");

        printf("KHONG CO THONG TIN DE HIEN THI\n");
    }
    else{
        printf("\n-----------------------TOA DO--------------------------\n");
        printf("STT\t|  X1\t| Y1\t| X2\t| Y2\t| KHOANG CACH\t|\n");
        unsigned int  numberOfPoint  = 1;

        for (Point Point : coorDinates){
            PRINT_INFORMATION1(numberOfPoint, Point);

            numberOfPoint++;
        }
    }
    
}

/*--------------------------------------HIỂN THỊ TỌA ĐỘ GIỮA HAI ĐIỂM 2 VÀ ĐIỂM 3----------------------------------*/
void Math::displayData2(){
    coorDinates.empty();

    if (coorDinates.empty())
    {
        printf("\nYEU CAU CUA BAN KHONG CO THONG TIN DE XU LY\n");

        printf("KHONG CO THONG TIN DE HIEN THI\n");
    }
    else{
        printf("\n-----------------------TOA DO--------------------------\n");
        printf("STT\t|  X2\t| Y2\t| X3\t| Y3\t| KHOANG CACH\t|\n");
        unsigned int  numberOfPoint  = 1;

        for (Point Point : coorDinates){
            PRINT_INFORMATION2(numberOfPoint, Point);
            numberOfPoint++;
        }
    }
   
}

/*--------------------------------------HIỂN THỊ TỌA ĐỘ GIỮA HAI ĐIỂM 1 VÀ ĐIỂM 3----------------------------------*/
void Math::displayData3(){
    coorDinates.empty();

    if (coorDinates.empty())
    {
        printf("\nYEU CAU CUA BAN KHONG CO THONG TIN DE XU LY\n");

        printf("KHONG CO THONG TIN DE HIEN THI\n");
    }
    else{
        printf("\n-----------------------TOA DO--------------------------\n");
        printf("STT\t|  X1\t| Y1\t| X3\t| Y3\t| KHOANG CACH\t|\n");
        unsigned int  numberOfPoint  = 1;

        for (Point Point : coorDinates){
            PRINT_INFORMATION3(numberOfPoint, Point);
            numberOfPoint++;
        }
    }
}


/*
 * Function: enum typeOfFunctions
 * Description: Gán tên và chức năng cho từng hàm để dễ đọc và bảo trì
 */
enum typeOfFunctions{
    adData = 1,
    displayOfResult1 = 2,
    displayOfResult2 = 3,
    displayOfResult3 = 4,
    mathTriangle = 5,
    exitMenu = 0,
}; 
    
/*--------------------------------------HÀM CHẠY CHƯƠNG TRÌNH TỔNG----------------------------------*/
void runProgram(){

    Math program;

    unsigned int requested;

    unsigned int condistion;
    do
    {
    system("cls");
    printf("\n              CHUONG TRINH THONG TIN                 \n");
    printf("************************MENU***************************\n");
    printf("**  1. Them data                                      **\n");
    printf("**  2. Hien thi toa do 2 diem X1,Y1 VA X2,Y2          **\n");
    printf("**  3. Hien thi toa do 2 diem X2,Y2 VA X3,Y3          **\n");
    printf("**  4. Hien thi toa do 2 diem X1,Y1 VA X3,Y3          **\n");
    printf("**  5. Tinh dien tich cua tam giac                    **\n");
    printf("**  0. Thoat menu                                     **\n");
    printf("*******************************************************\n");
    ENTER_DATA("Nhap yeu cua tinh toan cua ban: ", "%u", &requested, requested < 0);
    switch (requested)
    {
    case adData:
        if (adData == 1)
        {
            program.setData();
            system("Pause");
        }
        break;
    case displayOfResult1:
        if (displayOfResult1 == 2)
        {
            program.displayData1();

            system("Pause");

        }
        break;
    case displayOfResult2:
        if (displayOfResult2 == 3)
        {
            program.displayData2();

            system("Pause");
        }
        break;
    case displayOfResult3:
        if (displayOfResult3 == 4)
        {
            program.displayData3();

            system("Pause");
        }
        break;
    case mathTriangle:
        if (mathTriangle == 5)
        {
            program.checkAndMathTriangleType();

            system("Pause");
        }
        break;
    case exitMenu:
        break;
    default:
        printf("Yeu cau khong ton tai\n");
        printf("Vui long nhap yeu cau\n");
        system("\nPause");
    }
    } while (requested != 0);
}


int main(int argc, char* argv[]){

    runProgram();

    return 0;
}
