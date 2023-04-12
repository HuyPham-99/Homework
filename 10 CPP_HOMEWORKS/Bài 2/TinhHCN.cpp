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
#define PRINT_INFORMATION(object)                     \
    printf("  \n%d\t", object.getCircumFerence());    \
    printf("  %d\t\t", object.getArea());             \
    printf(" %d", object.getDiagonal())

/*
 * Function: Class rectangle
 * Description: Quản lý thông tin của hình chữ nhật như chiều dài, chiều rộng, chu vi, diện tích và đường chéo
 */
/*
/*--------------------------------------CLASS CỦA HÌNH CHỮ NHẬT----------------------------------*/
class rectangle{
    private:
        unsigned int  leght;

        unsigned int width;

        unsigned int circumference;

        unsigned int area;
        
        unsigned int diagonal;

    public:
        rectangle(unsigned int leght, unsigned int width);

        void setLeght(unsigned int leght);

        void setWidth(unsigned int width);

        unsigned int getLeght();

        unsigned int getWidth();

        unsigned int getCircumFerence();

        unsigned int getArea();

        unsigned int getDiagonal();
};

/*
 * Function: Method setLeght
 * Description: Set chiều dài hình chữ nhật
 * Input:
 *  leght - unsigned int 
 */
/*-------------------------------------ĐẶT CHIỀU DÀI CHO BÀI TOÁN -------------------------------*/
void rectangle::setLeght(unsigned int leght){
    rectangle::leght = leght;
}

/*
 * Function: Method setWidth
 * Description: Set chiều rộng hình chữ nhật
 * Input:
 *  width - unsigned int
 */
/*-------------------------------------ĐẶT CHIỀU RỘNG CHO BÀI TOÁN -------------------------------*/
void rectangle::setWidth(unsigned int width){
    rectangle::width = width;
}


/*
 * Function: Constructor rectangle
 * Description: Khởi tạo dữ liệu cho hình chữ nhật
 * Input:
 *  leght - unsigned int 
 *  width - unsigned int
 */
/*-------------------------------------CONTRUSTION CỦA HÌNH CHỮ NHẬT -------------------------------*/
rectangle::rectangle(unsigned int leght, unsigned int width){
    rectangle::leght = leght;
    rectangle::width = width;
}

/*
 * Function: Method getLeght
 * Description: Lấy chiều dài hình chữ nhật
 * Output:
 *  leght - unsigned int 
 */
/*-------------------------------------LẤY GIÁ TRỊ CHIỀU DÀI CỦA HÌNH CHỮ NHẬT -------------------------------*/
unsigned int rectangle::getLeght(){

    return rectangle::leght;
}

/*
 * Function: Method getWidth
 * Description: Lấy chiều rộng hình chữ nhật
 * Output:
 *  width - unsigned int
 */
/*-------------------------------------LẤY GIÁ TRỊ CHIỀU RỘNG CỦA HÌNH CHỮ NHẬT -------------------------------*/
unsigned int rectangle::getWidth(){
    return rectangle::width;
}

/*
 * Function: Method getCircumFerence
 * Description: Lấy chu vi hình chữ nhật
 * Output:
 *  circumFerence - unsigned int
 */
/*-------------------------------------LẤY GIÁ TRỊ CHU VI HÌNH CHỮ NHẬT -------------------------------*/
unsigned int rectangle::getCircumFerence(){

    unsigned int circumferenceOfRectangle;

    if (rectangle::leght != rectangle::width)
    {
        circumferenceOfRectangle = 2*(rectangle::leght + rectangle::width);//Công thức tính chu vi hình chữ nhật

        rectangle::circumference = circumferenceOfRectangle;

        return rectangle::circumference;
    }
    else{
        circumferenceOfRectangle = rectangle::leght*4;//Nếu chiều dài bằng chiều rộng thì tính chu vi theo công thức của hình vuông

        rectangle::circumference = circumferenceOfRectangle;

        return rectangle::circumference;
    }
}

/*
 * Function: Method getArea
 * Description: Lấy diện tích hình chữ nhật
 * Output:
 *  area - unsigned int
 */
/*-------------------------------------LẤY GIÁ TRỊ DIỆN TÍCH HÌNH CHỮ NHẬT -------------------------------*/
unsigned int rectangle::getArea(){

    unsigned int areaOfRectangle;

     if (rectangle::leght != rectangle::width)
    {
        areaOfRectangle = (rectangle::leght * rectangle::width);//Công thức tính diện tích hình chữ nhật

        rectangle::area = areaOfRectangle;

        return rectangle::area;
    }
    else{
        areaOfRectangle = (rectangle::leght * rectangle::width);//Khi chiều dài bằng chiều rộng thì diện tích của hình vuông được tính như hình chữ nhật

        rectangle::area = areaOfRectangle;

        return rectangle::area;
    }
   
}


/*
 * Function: Method getDiagonal
 * Description: Lấy diện tích hình chữ nhật
 * Output:
 *  diagonal - unsigned int
 */
/*-------------------------------------LẤY GIÁ TRỊ DƯỜNG CHÉO HÌNH CHỮ NHẬT -------------------------------*/
unsigned int rectangle::getDiagonal(){
    unsigned int diagonalOfRectangle;

    if (rectangle::leght != rectangle::width)
    {
        diagonalOfRectangle = sqrt(pow(rectangle::leght, 2) + pow(rectangle::width, 2));//Công thức tính đường chéo trong hình chữ nhật 

        rectangle::diagonal = diagonalOfRectangle;

        return rectangle::diagonal;
    }
    else{
        diagonalOfRectangle = sqrt(pow(rectangle::leght, 2) + pow(rectangle::width, 2));//Công thức tính đường chéo trong hình vuông

        rectangle::diagonal = diagonalOfRectangle;

        return rectangle::diagonal;
    }
   
}


/*
 * Function: Class caculator
 * Description: Quản lý thông tin bài toán về hình học đang xét
 */
/*
/*-------------------------------------CLASS TÍNH TOÁN -------------------------------*/
class caculator{
    private:
        vector<rectangle> math;
        
    public:
        void caculatorOfRectangle();

        void geomeTryTest();

        void display();
};

/*
 * Function: Function caculatorOfRectangle
 * Description: Nhập giá trị tính toán cho hình chữ nhật
 * Input:
 *  leght - unsigned int (chiều dài hình chữ nhật)
 *  width - unsigned int (chiều rộng hình chữ nhật)
 */
/*-------------------------------------HÀM NHẬP GIÁ TRỊ -------------------------------*/
void caculator::caculatorOfRectangle(){

    unsigned int leght;

    unsigned int width;
    
    ENTER_DATA("Nhap chieu dai cua hinh: ", "%u", &leght, leght < 0);//Nhập số âm thì sẽ bị hàm pow làm cho giá trị về số dương

    ENTER_DATA("Nhap chieu rong cua hinh: ", "%u", &width, width < 0);//Nhập số âm thì sẽ bị hàm pow làm cho giá trị về số dương

    rectangle rectangle(leght, width);

    math.push_back(rectangle);

}

/*-------------------------------------HÀM HIỂN THỊ GIÁ TRỊ  -------------------------------*/
void caculator::display(){

    printf("\nGIA TRI SAU KHI TINH TOAN");
    printf("\nChu vi | Dien tich | Duong cheo");
   
    for(rectangle rectangle : math){

        PRINT_INFORMATION(rectangle);
        
    }
    
}

/*
 * Function: Function geomeTryTest
 * Description: Xét hình học đã tính toán là hình chữ nhật hay hình vuông
 * Input:
 *  rectangle.getLeght() - lấy giá trị chiều dài hình chữ nhật
 *  rectangle.getWidth() - lấy giá trị chiều rộng hình chữ nhật
 */
/*-------------------------------------HÀM SO SÁNH GIÁ TRỊ ĐỂ XÉT YÊU CẦU CỦA BÀI TOÁN-------------------------------*/
void caculator::geomeTryTest(){
    for(rectangle rectangle : math){
        if (rectangle.getLeght() == rectangle.getWidth())
        {
            printf("Hinh hoc dang xet la hinh vuong");
        }
        else{
            printf("Hinh hoc dang xet khong phai la hinh vuong");
        }
    }
}

/*
 * Function: Function runOfMath
 * Description: Chạy bài toán
 * Input:
 *  math.caculatorOfRectangle() - Gọi hàm tính toán
 *  math.geomeTryTest() - Gọi hàm so sánh
 *  math.display() - Gọi hàm hiển thị
 */
/*-------------------------------------HÀM CHẠY BÀI TOÁN-------------------------------*/
void runOfMath(){

    caculator math;

    math.caculatorOfRectangle();

    math.geomeTryTest();

    math.display();
}

int main(int argc, char* argv[]){

    runOfMath();

    return 0;
}