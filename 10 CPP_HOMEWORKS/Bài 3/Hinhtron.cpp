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
 * Function: MACRO PRINT_INFORMATION
 * Description: Macro phần hiển thị thông tin
 * Input:
 *   object - đối tượng cần hiển thị
 */
#define PRINT_INFORMATION(object)                       \
    printf("  \n%.2f\t", object.getCircumFerence());    \
    printf("  %.2f\t", object.getArea())             

/*
 * Function: Class circle
 * Description: Quản lý thông tin của hình tròn như bán kính
 */
/*
/*--------------------------------------CLASS CỦA HÌNH TRÒN----------------------------------*/
class circle{
    private:
        float radius;

        float circumference;

        float area;
    public:

        circle(float r);

        void setRadius(float r);

        float getRadius();

        float getCircumFerence();

        float getArea();
};

/*
 * Function: Method setRadius
 * Description: Set bán kính hình tròn
 * Input:
 *  radius - float
 */
/*-------------------------------------ĐẶT BÁN KÍNH CHO BÀI TOÁN -------------------------------*/
void circle::setRadius(float r){

    circle::radius = r;

}

/*
 * Function: Constructor circle
 * Description: Khởi tạo dữ liệu cho hình tròn
 * Input:
 *  radius - float
 */
/*-------------------------------------CONTRUSTION CỦA HÌNH TRÒN -------------------------------*/
circle::circle(float r){

    circle::radius = r;

}

/*
 * Function: Method getLeght
 * Description: Lấy bán kính hình tròn
 * Output:
 *  radius - float
 */
/*-------------------------------------LẤY GIÁ TRỊ BÁN KÍNH CHO HÌNH TRÒN -------------------------------*/
float circle::getRadius(){

    return circle::radius;

}

/*
 * Function: Method getcircumference
 * Description: Lấy chu vi hình tròn
 * Output:
 *  circumference - float
 */
/*-------------------------------------LẤY GIÁ TRỊ CHU VI CHO HÌNH TRÒN -------------------------------*/
float circle::getCircumFerence(){

    float circumferenceOfCircle;

    circumferenceOfCircle = circle::radius * 2 * 3.14;

    circle::circumference = circumferenceOfCircle;

    return circle::circumference;
}

/*
 * Function: Method getarea
 * Description: Lấy diện tích của hình tròn
 * Output:
 *  area - float
 */
/*-------------------------------------LẤY GIÁ TRỊ DIỆN TÍCH CHO HÌNH TRÒN -------------------------------*/
float circle::getArea(){

    float areaOfCircle;

    areaOfCircle = pow(circle::radius,2) * 3.14;

    circle::area = areaOfCircle;

    return circle::area;
}

/*
 * Function: Class caculator
 * Description: Quản lý thông tin bài toán về hình học đang xét
 */
/*
/*-------------------------------------CLASS TÍNH TOÁN -------------------------------*/
class caculator
{
    private:
        vector<circle> cir;
    public:

        void caculatorOfCircle();
        
        void display();
};

/*
 * Function: Function caculatorOfCircle
 * Description: Nhập giá trị tính toán cho hình tròn
 * Input:
 *  radius - float (bán kính hình tròn)
 */
/*-------------------------------------HÀM NHẬP GIÁ TRỊ -------------------------------*/
void caculator::caculatorOfCircle(){
    float radius;

    printf("Nhap ban kinh cua hinh tron: ");

    scanf("%f", &radius);

    circle circle(radius);

    cir.push_back(circle);
}

/*-------------------------------------HÀM HIỂN THỊ GIÁ TRỊ  -------------------------------*/
void caculator::display(){
    printf("\nGIA TRI SAU KHI TINH TOAN");
    printf("\nChu vi | Dien tich ");
    for (circle circle : cir)
    {
        PRINT_INFORMATION(circle);
    }
}

/*
 * Function: Function runOfMath
 * Description: Chạy bài toán
 * Input:
 *  cir.caculatorOfCircle() - Gọi hàm tính toán
 *  cir.display() - Gọi hàm hiển thị
 */
/*-------------------------------------HÀM CHẠY BÀI TOÁN-------------------------------*/
void runOfMath(){

    caculator cir;

    cir.caculatorOfCircle();

    cir.display();

}

int main(int argc, char* argv[]){

    runOfMath();

    return 0;
}