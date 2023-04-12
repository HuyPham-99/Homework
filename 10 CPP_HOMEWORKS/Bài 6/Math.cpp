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
#define PRINT_INFORMATION(object)                                                                                   \
    printf("\nPhan so: %.f/%.f\t\nKet qua sau khi rut gon: %.2f\n", object.getNumerator(),                          \
                                                                    object.getDenominator(), object.getFraction());           

/*
 * Function: Class element
 * Description: Quản lý THÔNG DỮ LIỆU LIÊN QUAN ĐẾN SỐ NGUYÊN TỐ
 * intput: 
 *  numerator - float (tu so)
 *  denominator - float (mau so)
 *  fraction - float (phan so)
 */ 
/*--------------------------------------CLASS CỦA SỐ NGUYÊN TỐ----------------------------------*/
class element{

    private:

        float numerator; 

        float denominator;

        float fraction;

    public:
        element(float numerAtor, float denominAtor);

        void setNumerator(float numerAtor);

        void setDenominator(float denominAtor);

        float getNumerator() const { return numerator;};

        float getDenominator() const { return denominator;};

        float getFraction();

};

/*
 * Function: Method setNumerator
 * Description: Set tử số
 * Input:
 *  numerAtor - float
 */
/*-------------------------------------ĐẶT MẪU SỐ CHO PHÂN SỐ -------------------------------*/
void element::setNumerator(float numerAtor){
    element::numerator = numerAtor;
}

/*
 * Function: Method setDenominator
 * Description: Set mẫu số
 * Input:
 *  denominAtor - float
 */
/*-------------------------------------ĐẶT TỬ SỐ CHO PHÂN SỐ -------------------------------*/
void element::setDenominator(float denominAtor){
    element::denominator = denominAtor;
}

/*
 * Function: Constructor element
 * Description: Khởi tạo dữ liệu cho phân số
 * Input:
 *  numerAtor - float
 *  denominAtor - float
 */
/*-------------------------------------CONTRUSTION CỦA PHÂN SỐ -------------------------------*/
element::element(float numerAtor, float denominAtor){
    element::numerator = numerAtor;

    element::denominator = denominAtor;
}

/*
 * Function: Method getFraction
 * Description: Lấy giá trị của phân số từ dữ liệu của tử số và mẫu số đã nhập từ bàn phím vào hệ thống
 * Output:
 *  name - char*
 */
/*-------------------------------------LẤY GIÁ TRỊ CỦA PHÂN SỐ -------------------------------*/
float element::getFraction(){
    float result;

    result = element::numerator / element::denominator;

    element::fraction = result;

    return element::fraction;
}

/*
 * Function: Class Math
 * Description: Quản lý bài toán như cộng trừ nhân chia
 */
/*
/*--------------------------------------CLASS THÔNG TIN CỦA BÀI TOÁN----------------------------------*/
class Math
{
private:
    vector<element> fraction;
public:
    
    void setDataOfFraction();

    void additionOfFraction();

    void subtractionOfFraction();

    void multiplicationOfFraction();

    void divisionOfFraction();

    void displayOfData();
};


/*
 * Function: Function setDataOfFraction
 * Description: thêm dữ liệu cho phân số như tử số và mẫu số
 */
/*-----------------------------HÀM THÊM THÔNG TIN CHO PHÂN SỐ-----------------------------*/
void Math::setDataOfFraction(){

    float numer;

    float denomin;
    
    ENTER_DATA("Nhap tu so:", "%f", &numer, 0);

    ENTER_DATA("Nhap mau so:", "%f", &denomin, 0);


    element element(numer, denomin);

    fraction.push_back(element);

}

/*
 * Function: Function additionOfFraction
 * Description: Hàm thực hiện chức năng cộng hai phân số 
 */
/*-----------------------------HÀM CỘNG HAI PHÂN SỐ-----------------------------*/
void Math::additionOfFraction(){
    float addition;

    element *fraction1;

    element *fraction2;

    vector<element> *ptr = &fraction;

    for (int indexA = 0; indexA < fraction.size() - 1 ; indexA++)
    {
        element *fraction1 = &fraction[indexA];
        for (int indexB = 1; indexB < fraction.size(); indexB++)
        {
            element *fraction2 = &fraction[indexB];
            if (fraction1->getFraction()!=0 || fraction2->getFraction()!=0)
            {
                addition = (ptr->at(indexA).getFraction() + ptr->at(indexB).getFraction()); 
                // addition = (((ptr->at(indexA).getNumerator()*ptr->at(indexB).getDenominator())+(ptr->at(indexA).getDenominator()*ptr->at(indexB).getNumerator()))/(ptr->at(indexA).getDenominator()*ptr->at(indexB).getDenominator()));
            }
        }
    }
    printf("\nGia tri khi cong hai phan so: %.2f\n", addition);
}


/*
 * Function: Function subtractionOfFraction
 * Description: Hàm thực hiện chức năng trừ hai phân số 
 */
/*-----------------------------HÀM CỘNG HAI PHÂN SỐ-----------------------------*/
void Math::subtractionOfFraction(){
    float subtraction;

    element *fraction1;

    element *fraction2;

    vector<element> *ptr = &fraction;

    for (int indexA = 0; indexA < fraction.size() - 1; indexA++)
    {
        element *fraction1 = &fraction[indexA];
        for (int indexB = 1; indexB < fraction.size(); indexB++)
        {
            element *fraction2 = &fraction[indexB];
            if (fraction1->getFraction()!=0 || fraction2->getFraction()!=0)
            {
                subtraction = (ptr->at(indexA).getFraction() - ptr->at(indexB).getFraction()); 
                // subtraction = (((ptr->at(indexA).getNumerator()*ptr->at(indexB).getDenominator()) - (ptr->at(indexA).getDenominator()*ptr->at(indexB).getNumerator())) / (ptr->at(indexA).getDenominator()*ptr->at(indexB).getDenominator()));
               
            }
        }
    }
    printf("\nGia tri khi tru hai phan so: %.2f\n", subtraction);
}

/*
 * Function: Function multiplicationOfFraction
 * Description: Hàm thực hiện chức năng nhân hai phân số 
 */
/*-----------------------------HÀM NHAN HAI PHÂN SỐ-----------------------------*/
void Math::multiplicationOfFraction(){
    float multiplication;

    element *fraction1;

    element *fraction2;

    vector<element> *ptr = &fraction;

    for (int indexA = 0; indexA < fraction.size() - 1; indexA++)
    {
        element *fraction1 = &fraction[indexA];
        for (int indexB = 1; indexB < fraction.size(); indexB++)
        {
            element *fraction2 = &fraction[indexB];
            if (fraction1->getFraction()!=0 || fraction2->getFraction()!=0)
            {
                multiplication = (ptr->at(indexA).getFraction() * ptr->at(indexB).getFraction()); 
               
            }
        }
    }
    printf("\nGia tri khi nhan hai phan so: %.2f\n", multiplication);
}

/*
 * Function: Function divisionOfFraction
 * Description: Hàm thực hiện chức năng chia hai phân số 
 */
/*-----------------------------HÀM CHIA HAI PHÂN SỐ-----------------------------*/
void Math::divisionOfFraction(){
    float division;

    element *fraction1;

    element *fraction2;

    vector<element> *ptr = &fraction;

    for (int indexA = 0; indexA < fraction.size() - 1; indexA++)
    {
        element *fraction1 = &fraction[indexA];
        for (int indexB = 1; indexB < fraction.size(); indexB++)
        {
            element *fraction2 = &fraction[indexB];
     
            if (fraction1->getFraction()!=0 || fraction2->getFraction()!=0)
            {
                division = (ptr->at(indexA).getFraction() / ptr->at(indexB).getFraction()); 
            }
        }
    }
    printf("\nGia tri khi chia hai phan so: %.3f\n", division);
}



/*
 * Function: Function divisionOfFraction
 * Description: Hàm hiển thị thông tin bài toán
 */
/*-----------------------------HÀM HIỂN THỊ DATA-----------------------------*/
void Math::displayOfData(){
    for (element element : fraction)
    {
        PRINT_INFORMATION(element);
    }   
}


/*
 * Function: enum typeOfHumansg
 * Description: Gán tên và chức năng cho từng hàm để dễ đọc và bảo trì
 */
enum typeOfMath{
    adData = 1,
    additionOfData = 2,
    subtractionOfData = 3,
    multiplication = 4,
    division = 5,
    displayOfResult = 6,
    exitMenu = 0,
};
/*-------------------------------------HÀM CHẠY CHƯƠNG TRÌNH -------------------------------*/
void runOfProgram(){
    Math result;
    int choice;
    int condistion;
    do
    {
    system("cls");
    printf("\n              CHUONG TRINH THONG TIN                 \n");
    printf("************************MENU***************************\n");
    printf("**  1. Them data                                      **\n");
    printf("**  2. Phep cong                                      **\n");
    printf("**  3. Phep tru                                       **\n");
    printf("**  4. Phep nhan                                      **\n");
    printf("**  5. Phep chia                                      **\n");
    printf("**  6. Hien thi data                                  **\n");
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
                result.setDataOfFraction();
                printf("THEM DATA CHO PHAN SO THANH CONG\n");

            );

        }
        break;
        
    case additionOfData:
        if (additionOfData == 2)
        {
            DOWHILE_METHODMENU
            (
                result.displayOfData();
                result.additionOfFraction();
                printf("THUC HIEN PHEP CONG HAI PHAN SO THANH CONG\n");

            );
        }
        break;

    case subtractionOfData:
        if (subtractionOfData == 3)
        {
            DOWHILE_METHODMENU
            (
                result.displayOfData();
                result.subtractionOfFraction();
                printf("THUC HIEN PHEP TRU HAI PHAN SO THANH CONG\n");
            );
        }
        break;
        
    case multiplication:
        if (multiplication == 4)
        {
            DOWHILE_METHODMENU
            (
                result.displayOfData();
                result.multiplicationOfFraction();
                printf("THUC HIEN PHEP NHAN HAI PHAN SO THANH CONG\n");
            );  
        }
        break;

    case division:
        if (division == 5)
        {
            DOWHILE_METHODMENU
            (
                result.displayOfData();
                result.divisionOfFraction(); 
                printf("THUC HIEN PHEP CHIA HAI PHAN SO THANH CONG\n");
            );
        }
        break;

    case displayOfResult:

        if (displayOfResult == 6)
        {
            DOWHILE_METHODMENU
            (
                result.displayOfData();
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
