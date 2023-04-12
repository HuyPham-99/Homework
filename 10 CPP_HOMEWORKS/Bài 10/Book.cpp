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

#define PRINT_INFORMATION(object)                   \
    printf("\n%s\t", object.getNameOfBook());       \
    printf("  %s    ", object.getNameOfAuthor());     \
    printf(" %u  ", object.getYear());            \
    printf("   \t %u\t\n", object.getNumberOfBook())            
/*
 * Function: Class book
 * Description: Quản lý thông tin của sách
 */
/*
/*--------------------------------------CLASS BOOK----------------------------------*/
class book{
    private:
        char nameOfBook[20];

        char nameOfAuthor[20];

        unsigned int year;

        unsigned int numberOfBook;
    public:
        book(const char nameOfBook[20], const char nameOfAuthor[20], unsigned int year, unsigned int numberOfBook);

        void setNameOfBook(const char nameOfBook[20]);

        void setNameOfAuthor(const char nameOfAuthor[20]);

        void setYear(unsigned int year);

        void setNumberOfBook(unsigned int numberOfBook);


        char* getNameOfBook();

        char* getNameOfAuthor();

        unsigned int getYear();

        unsigned int getNumberOfBook();
};

/*
 * Function: Method setNameOfBook
 * Description: Set tên cho sách
 * Input:
 *   nameOfBook - char*
 */
/*-------------------------------------ĐẶT TÊN CHO SÁCH -------------------------------*/
void book::setNameOfBook(const char nameOfBook[]){

    strcpy(book::nameOfBook, nameOfBook);
}

/*
 * Function: Method setNameOfBook
 * Description: Set tên cho tác giả
 * Input:
 *   nameOfAuthor - char*
 */
/*-------------------------------------ĐẶT TÊN CHO TÁC GIẢ -------------------------------*/
void book::setNameOfAuthor(const char nameOfAuthor[]){

    strcpy(book::nameOfAuthor, nameOfAuthor);
}

/*
 * Function: Method setYear
 * Description: Set năm xuất bản
 * Input:
 *   year - usinged int 
 */
/*-------------------------------------ĐẶT NĂM XUẤT BẢN -------------------------------*/
void book::setYear(unsigned int year){

    book::year = year;
}

/*
 * Function: Method setNumberOfBook
 * Description: Set số lượng sách
 * Input:
 *   numberOfBook - usinged int 
 */
/*-------------------------------------ĐẶT SỐ LƯỢNG SÁCH -------------------------------*/
void book::setNumberOfBook(unsigned int numberOfBook){

    book::numberOfBook = numberOfBook;
}


/*
 * Function: Constructor car
 * Description: Khởi tạo dữ liệu cho đối tượng
 * Input:
 *  nameOfBook - char*
 *  nameOfAuthor - char*
 *  year - unsigned int
 *  numberOfBook - unsigned int
 */
/*-------------------------------------CONTRUSTION CỦA SÁCH -------------------------------*/
book::book(const char nameOfBook[20], const char nameOfAuthor[20], unsigned int year, unsigned int numberOfBook){
    
    strcpy(book::nameOfBook, nameOfBook);

    strcpy(book::nameOfAuthor, nameOfAuthor);

    book::year = year;

    book::numberOfBook = numberOfBook;
}


/*
 * Function: Method getNameOfBook
 * Description: Lấy tên sách được nhập vào từ bàn phím
 * Output:
 *  nameOfBook - char*
 */
/*-------------------------------------LẤY TÊN CỦA SÁCH -------------------------------*/
char* book::getNameOfBook(){

    return book::nameOfBook;
}

/*
 * Function: Method getNameOfAuthor
 * Description: Lấy tên tác giả được nhập vào từ bàn phím
 * Output:
 *  nameOfBook - char*
 */
/*-------------------------------------LẤY TÊN CỦA TÁC GIẢ -------------------------------*/
char* book::getNameOfAuthor(){

    return book::nameOfAuthor;
}

/*
 * Function: Method getYear
 * Description: Lấy năm xuất bản được nhập vào từ bàn phím
 * Output:
 *  year - unsigned int
 */
/*-------------------------------------LẤY NĂM XUẤT BẢN CỦA SÁCH -------------------------------*/
unsigned int book::getYear(){

    return book::year;
}

/*
 * Function: Method getNumberOfBook
 * Description: Lấy số lượng sách được nhập vào từ bàn phím
 * Output:
 *  book - unsigned int
 */
/*-------------------------------------LẤY SỐ LƯỢNG SÁCH -------------------------------*/
unsigned int book::getNumberOfBook(){

    return book::numberOfBook;
}

/*
 * Function: Class information
 * Description: Quản lý thông tin của sách
 */
/*
/*--------------------------------------CLASS BOOK----------------------------------*/
class information
{
    private:
        vector<book> check;
    public:
        void addData();

        void borrowBooks();

        void bookReturn();

        void displayOfData();
};

/*
 * Function: Function setData
 * Description: thêm dữ liệu cho hệ thống
 */
/*-----------------------------HÀM THÊM THÔNG TIN CHO HỆ THỐNG-----------------------------*/

void information::addData(){
    char name[20];

    char author[20];

    unsigned int yearOfBook;

    unsigned int numbers;

    ENTER_DATA("Nhap ten cua sach: ", "%s", &name,0);

    ENTER_DATA("Nhap ten cua tac gia: ", "%s", &author,0);

    ENTER_DATA("Nhap nam xuat ban: ", "%u", &yearOfBook,0);
    
    ENTER_DATA("Nhap so luong cua sach: ", "%u", &numbers,0);


    book book(name, author, yearOfBook, numbers);

    check.push_back(book);
}

/*
 * Function: Function borrowBooks
 * Description: Thực hiện chức năng mượn sách
 */
/*-----------------------------HÀM MƯỢN SÁCH-----------------------------*/
void information::borrowBooks(){

    char name[20];

    char author[20];

    unsigned int numberOfBooks;

    unsigned int numbers;

    vector<book> *ptr = &check;

    check.empty();//Kiểm tra xem vector có rỗng hay không để xử lý yêu cầu
    if (check.empty())
    {
        printf("\nYEU CAU CUA BAN KHONG CO THONG TIN DE XU LY\n");

        printf("VUI LONG NHAP THONG TIN KHACH HANG\n");
    }
    else{
        ENTER_DATA("Nhap ten sach: ", "%s", &name, 0);

        ENTER_DATA("Nhap tac gia: ", "%s", &author, 0);

        for (int index = 0; index < ptr->size(); index++)//Sử dụng hàm size trong thư viện vector để lấy được độ dài của vector.
                                                        //Vì vector tự ghi nhớ độ dài chính bản thân nó.
        {
            for (book book : check)
            {
            if (strcmp(ptr->at(index).getNameOfBook(), name) || strcmp(ptr->at(index).getNameOfAuthor(), author) == 0)//Sử dụng hàm at để lấy vị trí của phần tử trong vector
            {
                printf("\nTHONG TIN SACH");
                printf("\nTen   \t| Tac gia | Nam xuat ban|So luong\n");

                PRINT_INFORMATION(ptr->at(index));//Sử dụng marco in thông tin

                printf("\nNhap so luong sach can muon:  ");
                scanf("%u", &numbers);

                numberOfBooks = ptr->at(index).getNumberOfBook() - numbers;

                ptr->at(index).setNumberOfBook(numberOfBooks);

                break;
            }
            else{
                printf("THONG TIN KHONG DUNG VOI DANH SACH.");

                printf("\n/*TIM KIEM THONG TIN KHONG THANH CONG*/\n");

                break;
            }
            }
            
        }
    }
}


/*
 * Function: Function bookReturn
 * Description: Thực hiện chức năng trả sách
 */
/*-----------------------------HÀM TRẢ SÁCH-----------------------------*/
void information::bookReturn(){
    char name[20];

    char author[20];

    unsigned int numberOfBooks;

    unsigned int numbers;

    vector<book> *ptr = &check;

    check.empty();//Kiểm tra xem vector có rỗng hay không để xử lý yêu cầu
    if (check.empty())
    {
        printf("\nYEU CAU CUA BAN KHONG CO THONG TIN DE XU LY\n");

        printf("VUI LONG NHAP THONG TIN KHACH HANG\n");
    }
    else{
        
        ENTER_DATA("Nhap ten sach: ", "%s", &name, 0);

        ENTER_DATA("Nhap tac gia: ", "%s", &author, 0);

        for (int index = 0; index < ptr->size(); index++)//Sử dụng hàm size trong thư viện vector để lấy được độ dài của vector.
                                                        //Vì vector tự ghi nhớ độ dài chính bản thân nó.
        {
            for (book book : check)
            {
            if (strcmp(ptr->at(index).getNameOfBook(), name) || strcmp(ptr->at(index).getNameOfAuthor(), author) == 0)//Sử dụng hàm at để lấy vị trí của phần tử trong vector
            {
                printf("\nTHONG TIN SACH");
                printf("\nTen   \t| Tac gia | Nam xuat ban|So luong\n");

                PRINT_INFORMATION(ptr->at(index));//Sử dụng marco in thông tin

                printf("\nNhap so luong sach can tra:  ");
                scanf("%u", &numbers);

                numberOfBooks = ptr->at(index).getNumberOfBook() + numbers;

                ptr->at(index).setNumberOfBook(numberOfBooks);

                break;
            }
            else{
                printf("THONG TIN KHONG DUNG VOI DANH SACH.");

                printf("\n/*TIM KIEM THONG TIN KHONG THANH CONG*/\n");

                break;
            }
            }
            
        }
    }
}

/*
 * Function: Function displayOfData
 * Description: Thực hiện chức năng hiển thị thông tin
 */
/*-----------------------------HÀM HIỂN THỊ THÔNG TIN-----------------------------*/
void information::displayOfData(){
    printf("\nTHONG TIN SACH");
    printf("\nTen   \t| Tac gia | Nam xuat ban|So luong\n");
    for (book book : check){
        PRINT_INFORMATION(book);
    }
}

/*
 * Function: enum typeOfHumans
 * Description: Gán tên và chức năng cho từng hàm để dễ đọc và bảo trì
 */
enum typeOfBook{
    adData = 1,
    borrow = 2,
    returnBook = 3,
    displayOfResult = 4,
    exitMenu = 0,
};

/*
 * Function: Function runOfProgram
 * Description: Thực hiện chức năng chạy chương trình tổng
 */
/*-----------------------------HÀM CHẠY CHƯƠNG TRÌNH-----------------------------*/
void runOfProgram(){
    information results;

    unsigned int choice;

    unsigned int condistion;
    do
    {
    system("cls");
    printf("\n              CHUONG TRINH THONG TIN                 \n");
    printf("************************MENU***************************\n");
    printf("**  1. Them data                                      **\n");
    printf("**  2. Muon sach                                      **\n");
    printf("**  3. Tra sach                                       **\n");
    printf("**  4. Hien thi data                                  **\n");
    printf("**  0. Thoat menu                                     **\n");
    printf("*******************************************************\n");
    printf("Vui long nhap su lua chon: ");
    scanf("%u", &choice);
    switch (choice)
    {
    case adData:
        if (adData == 1)
        {
            DOWHILE_METHODMENU
            (
                results.addData();
            );
        }
        break;
    case borrow:
        if (borrow == 2)
        {
            DOWHILE_METHODMENU
            (
                results.displayOfData();
                results.borrowBooks();
            );
        }
        break;
    case returnBook:
        if (returnBook == 3)
        {
            DOWHILE_METHODMENU
            (
                results.displayOfData();
                results.bookReturn();

            );
        }
        break;
    case displayOfResult:
        if (displayOfResult == 4)
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
