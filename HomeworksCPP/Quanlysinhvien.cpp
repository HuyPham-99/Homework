/*
* File: Quan_ly_sinh_vien.cpp
* Author: Hung Huy
* Date: 25/03/2023
* Description: This is a file for student management menu.
*/
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;


/*--------------------------------------MACRO NHẬP DỮ LIỆU----------------------------------*/
#define ENTER_DATA(content, format, variable, condition) \
    do                                                          \
    {                                                           \
        printf(content);                                        \
        scanf(format, variable);                                \
    } while (condition)
/*------------------------------------MACRO HIỂN THỊ THÔNG TIN-------------------------------*/
#define PRINT_INFORMATION(object)                                                               \
    printf(" %d\t| %s\t| %d\t|   %s\t\t|", object.getStudentId(), object.getName(),             \
           object.getAge(), object.getGender());                                                \
    printf(" %.2f\t| %.2f\t| %.2f\t|", object.getMathScores(), object.getPhysicScores(),        \
           object.getChemistryScores());                                                        \
    printf("   %.2f\t|   %s\n", object.getGpa(), object.getStudentRank())

/*---------------------------------------CLASS STUDENT-------------------------------------*/
class Student
{
private:
    uint8_t studentId;//Id của sinh viên
    char studentName[20];//Tên sinh viên
    char studentGender[4];//Giới tính sinh viên
    uint8_t studentAge;//Tuổi sinh viên
    float mathScores;//Điểm môn toán
    float physicsScores;//Điểm môn lý
    float chemistryScores;//Điểm môn hóa
    float GPA;//GPA là điểm trung bình
    char studentRank[11];//Học lực sinh viên

public:
    //Constructor of Student
    Student(const char Name[], const char Gender[], const uint8_t Age, float Math, float Physics, float Chemistry);
    
    //Insert data of constructor
    void setNameOfStudent(const char Name[]);
    void setGenderOfStudent(const char Gender[]);
    void setAgeOfStudent(uint8_t Age);
    void setmathScores(float Math);
    void setphysicsScores(float Physics);
    void setchemistryScores(float Chemistry);

    //Get data of constructor
    uint8_t getStudentId();
    char *getName();
    char *getGender();
    uint8_t getAge();
    float getMathScores();
    float getPhysicScores();
    float getChemistryScores();
    float getGpa();
    char *getStudentRank();
};


/*---------------------------------------ĐĂT TÊN SINH VIÊN-----------------------------------*/
void Student::setNameOfStudent(const char Name[])
{
    strcpy(Student::studentName, Name);
}


/*-------------------------------------ĐẶT GIỚI TÍNH SINH VIÊN-------------------------------*/
void Student::setGenderOfStudent(const char Gender[])
{
    if (strcmp((char *)"Nam", Gender) != 0 && strcmp((char *)"Nu", Gender) != 0)
    {
        printf("ERROR! Gioi tinh khong hop le");
    }
    else
    {
        strcpy(Student::studentGender, Gender);
    }
}


/*-------------------------------------ĐẶT TUỔI SINH VIÊN------------------------------------*/
void Student::setAgeOfStudent(uint8_t Age)
{
    Student::studentAge = Age;
}


/*-------------------------------------ĐẶT ĐIỂM TOÁN SINH VIÊN-------------------------------*/
void Student::setmathScores(float Math)
{
   
    if (Student::mathScores < 0 ||  Student::mathScores > 10)
    {
        printf("ERROR! Diem toan khong hop le");
        Student::mathScores = Math;
    }
    else{
        Student::mathScores = Math;
    }
}


/*-------------------------------------ĐẶT ĐIỂM LÝ SINH VIÊN---------------------------------*/
 void Student::setphysicsScores(float Physics)
{   
    
    if (Student::physicsScores < 0 || Student::physicsScores > 10)
    {
        printf("ERROR! Diem Ly khong hop le");
        Student::physicsScores = 0;
    }
    else
    {
        Student::physicsScores = Physics;
    }
}

/*-------------------------------------ĐẶT ĐIỂM HÓA SINH VIÊN---------------------------------*/
void Student::setchemistryScores(float Chemistry)
{
    
    if (Student::chemistryScores < 0 || Student::chemistryScores > 10)
    {
        printf("ERROR! Diem Ly khong hop le");
        Student::chemistryScores = 0;
    }
    else
    {
        Student::chemistryScores = Chemistry;
    }
}

/*------------------------------------CONSTRUCTOR SINH VIÊN----------------------------------*/
Student::Student(const char Name[], const char Gender[], const uint8_t Age, float Math, float Physics, float Chemistry)
{
    //Tự động tạo ID cho Sinh viên
    static uint8_t s_Id = 100;
    Student::studentId = s_Id;
    s_Id++;

    strcpy(Student::studentName, Name);

    strcpy(Student::studentGender, Gender);

    Student::studentAge = Age;

    Student::mathScores = Math;

    Student::physicsScores = Physics;

    Student::chemistryScores = Chemistry;
}

/*-------------------------------------ID CỦA SINH VIÊN------------------------------------*/
uint8_t Student::getStudentId()
{
    return Student::studentId;
}

/*-------------------------------------TÊN CỦA SINH VIÊN-----------------------------------*/
char *Student::getName()
{
    return Student::studentName;
}

/*----------------------------------GIỚI TÍNH CỦA SINH VIÊN--------------------------------*/
char *Student::getGender()
{
    return Student::studentGender;
}

/*-------------------------------------TUỔI CỦA SINH VIÊN----------------------------------*/
uint8_t Student::getAge()
{

    return Student::studentAge;
}
/*----------------------------------ĐIỂM TOÁN CỦA SINH VIÊN--------------------------------*/
float Student::getMathScores()
{
    return Student::mathScores;
    
}

/*----------------------------------ĐIỂM LÝ CỦA SINH VIÊN----------------------------------*/
float Student::getPhysicScores()
{
    return Student::physicsScores;
}

/*----------------------------------ĐIỂM HÓA CỦA SINH VIÊN---------------------------------*/
float Student::getChemistryScores()
{
    return Student::chemistryScores;
}

/*-----------------------------ĐIỂM TRUNG BÌNH CỦA SINH VIÊN------------------------------*/
float Student::getGpa()
{
    Student::GPA = (Student::mathScores + Student::physicsScores + Student::chemistryScores) / 3;
    return Student::GPA;
}

/*-----------------------------------HỌC LỰC CỦA SINH VIÊN--------------------------------*/
char *Student::getStudentRank()
{
    float score = Student::getGpa();

    if (score >= 8.00)
    {
        strcpy(Student::studentRank, "Gioi");
    }
    else if (score >= 6.50)
    {
        strcpy(Student::studentRank, "Kha");
    }
    else if (score >= 5.00)
    {
        strcpy(Student::studentRank, "Trung Binh");
    }
    else
    {
        strcpy(Student::studentRank, "Yeu");
    }

    return Student::studentRank;
}

/*---------------------------------------CLASS MENU-------------------------------------*/
class Menu
{
private:
    vector<Student> list;

public:
    void addStudent();
    void updateInformationOfStudent();
    void eraseStudent();
    void searchStudent();
    void softOfByGPA();
    void softOfByName();
    void displayInformationOfStudent();
};

/*-------------------------------------CHỨC NĂNG THÊM SINH VIÊN-----------------------------------*/
void Menu::addStudent()
{
    char name[20];
    char gender[4];
    uint8_t age;
    float math;
    float physic;
    float chemistry;
 
    ENTER_DATA("Nhap ten: ", "%s", &name, 0);

    ENTER_DATA("Nhap tuoi: ", "%d", &age, age > 100 || age < 1);

    ENTER_DATA("Nhap gioi tinh: ", "%s", &gender, 0);

    ENTER_DATA("Nhap diem toan: ", "%f", &math, math > 10 || math < 0);

    ENTER_DATA("Nhap diem ly: ", "%f", &physic, physic > 10 || physic < 0);

    ENTER_DATA("Nhap diem hoa: ", "%f", &chemistry, chemistry > 10 || chemistry < 0);

    Student student(name, gender, age, math, physic, chemistry);

    list.push_back(student);
    
    printf("\nTHEM SINH VIEN THANH CONG!\n");

}

/*-------------------------------------CHỨC NĂNG CẬP NHẬT THÔNG TIN SINH VIÊN THEO ID-----------------------------------*/
/*-------------------------------------CHỨC NĂNG CẬP NHẬT THÔNG TIN SINH VIÊN THEO ID CHƯA HOÀN THIỆN CHỈ CÓ THỂ LẤY VỊ TRÍ ID ĐẦU TIÊN ĐỂ XỬ LÝ-----------------------------------*/
void Menu::updateInformationOfStudent(){
    
    uint8_t id;
    char name[20];
    char gender[4];
    uint8_t age;
    float math;
    float physic;
    float chemistry;
    
    vector<Student> *poniter = &list;
    
    
    list.empty();//Kiểm tra xem vector có rỗng hay không để xử lý yêu cầu

    if (list.empty())
    {
        printf("\nYEU CAU CUA BAN KHONG CO THONG TIN DE XU LY\n");

        printf("VUI LONG NHAP THONG TIN SINH VIEN\n");
    }
    else{

        Menu::displayInformationOfStudent();//Hien thi thong tin de nguoi dung de dang xu ly thong tin
        
        ENTER_DATA("Nhap ID cua sinh vien can cap nhat thong tin: ", "%u", &id, 0);
        
        for (int index = 0; index < poniter->size(); index++)//Sử dụng hàm size trong thư viện vector để lấy được độ dài của vector.
                                                            //Vì vector tự ghi nhớ độ dài chính bản thân nó.
        {
            if (poniter->at(index).getStudentId() == id)//Sử dụng hàm at để lấy vị trí của phần tử trong vector
            {
                
                if (strcpy(poniter->at(index).getName(),name) != name)//Sử dụng hàm at để lấy vị trí của phần tử trong vector
                {
                    ENTER_DATA("Nhap ten: ", "%s", &name, 0);
                    strcpy(poniter->at(index).getName(),name);
                }
                
                if (poniter->at(index).getAge() != age)
                {
                    ENTER_DATA("Nhap tuoi: ", "%d", &age, age > 100 || age < 1);
                    poniter->at(index).setAgeOfStudent(age);
                }

                if (strcpy(poniter->at(index).getGender(),gender) != gender)
                {
                    ENTER_DATA("Nhap gioi tinh: ", "%s", &gender, 0);
                    strcpy(poniter->at(index).getGender(),gender);
                }

                if (poniter->at(index).getMathScores() != math)
                {
                    ENTER_DATA("Nhap diem toan: ", "%f", &math, math > 10 || math < 0);
                    poniter->at(index).setAgeOfStudent(math);

                }

                if (poniter->at(index).getPhysicScores() != physic)
                {
                    ENTER_DATA("Nhap diem ly: ", "%f", &physic, physic > 10 || physic < 0);
                    poniter->at(index).setAgeOfStudent(physic);

                }

                if(poniter->at(index).getChemistryScores() != chemistry)
                {
                    ENTER_DATA("Nhap diem hoa: ", "%f", &chemistry, chemistry > 10 || chemistry < 0);
                    poniter->at(index).setAgeOfStudent(chemistry);
                }
               
                Student student(name, gender, age, math, physic, chemistry);

                list.push_back(student);

                if (poniter->at(index).getStudentId() == id)//Sử dụng hàm at để lấy vị trí của phần tử trong vector
                {
                    poniter->erase(poniter->begin() + index);//Dùng poniter trỏ tới vị trí bắt đầu cộng với index và sau đó dùng hàm erase để xóa vị trí tương ứng
                }

                printf("\n------------------------------------DANH SACH SINH VIEN SAU KHI CAP NHAT-----------------------------------\n");
                printf("__________________________________________________________________________________________\n");
                printf("  ID\t| Ten\t| Tuoi\t|   Gioi Tinh\t| Toan\t|  Ly\t|  Hoa\t|   DiemTB\t|   HocLuc\n");
                for (Student student : list)
                {
                    PRINT_INFORMATION(student);//Sử dụng marco in thông tin
                }
                printf("\nCAP NHAT THONG TIN SINH VIEN THANH CONG*/\n");
                break;
            }
            else{
                printf("\nID cua sinh vien khong ton tai.\n");

                printf("\nCAP NHAT THONG TIN SINH VIEN KHONG THANH CONG*/\n");
                break;
            }
        }
    }
}

/*-------------------------------------CHỨC NĂNG XÓA THÔNG TIN SINH VIÊN THEO ID-----------------------------------*/
void Menu::eraseStudent(){
    
    uint8_t id;
    char name[20];
    char gender[4];
    uint8_t age;
    float math;
    float physic;
    float chemistry;
    bool haveStudent = false;

    vector<Student> *poniter = &list;

    list.empty();//Kiểm tra xem vector có rỗng hay không để xử lý yêu cầu

    if (list.empty())
    {
        printf("\nYEU CAU CUA BAN KHONG CO THONG TIN DE XU LY\n");

        printf("VUI LONG NHAP THONG TIN SINH VIEN\n");
    }
    else{
        Menu::displayInformationOfStudent();//Hien thi thong tin de nguoi dung de dang xu ly thong tin

        ENTER_DATA("\nNhap ID cua sinh vien can xoa: ", "%u", &id, 0);

        for (int index = 0; index < poniter->size(); index++)//Sử dụng hàm size trong thư viện vector để lấy được độ dài của vector.
                                                        //Vì vector tự ghi nhớ độ dài chính bản thân nó.
        {
            if (poniter->at(index).getStudentId() == id)//Sử dụng hàm at để lấy vị trí của phần tử trong vector
            {
                poniter->erase(poniter->begin() + index);//Dùng poniter trỏ tới vị trí bắt đầu cộng với index và sau đó dùng hàm erase để xóa vị trí tương ứng
                haveStudent = true;
                printf("\nXOA THONG TIN SINH VIEN THANH CONG*/\n");
                break;
            }
        }
        if (haveStudent != true)
        {
            printf("ID CUA SINH VIEN KHONG DUNG VOI DANH SACH SINH VIEN.");

            printf("\nXOA THONG TIN SINH VIEN KHONG THANH CONG*/\n");
        }
    }
}

/*-----------------------------CHỨC NĂNG TÌM KIẾM SINH VIÊN THEO TÊN-----------------------------*/
void Menu::searchStudent(){

    char name[20];

    vector<Student> *poniter = &list;

    list.empty();//Kiểm tra xem vector có rỗng hay không để xử lý yêu cầu
    if (list.empty())
    {
        printf("\nYEU CAU CUA BAN KHONG CO THONG TIN DE XU LY\n");

        printf("VUI LONG NHAP THONG TIN SINH VIEN\n");
    }
    else{
        
        Menu::displayInformationOfStudent();//Hien thi thong tin de nguoi dung de dang xu ly thong tin

        ENTER_DATA("\nNhap ten cua sinh vien can tim kiem: ", "%s", &name, 0);
        
        for (int index = 0; index < poniter->size(); index++)//Sử dụng hàm size trong thư viện vector để lấy được độ dài của vector.
                                                        //Vì vector tự ghi nhớ độ dài chính bản thân nó.
        {
            for (Student student : list)
            {
            if (strcmp(poniter->at(index).getName(), name) == 0)//Sử dụng hàm at để lấy vị trí của phần tử trong vector
            {
                printf("\n------------------------------------THONG TIN CUA SINH VIEN-----------------------------------\n");
                printf("__________________________________________________________________________________________\n");
                printf("  ID\t| Ten\t| Tuoi\t|   Gioi Tinh\t| Toan\t|  Ly\t|  Hoa\t|   DiemTB\t|   HocLuc\n");  

                PRINT_INFORMATION(poniter->at(index));//Sử dụng marco in thông tin

                printf("\nTIM KIEM THONG TIN SINH VIEN THANH CONG*/\n");
                break;
            }
            else{
                printf("TEN CUA SINH VIEN KHONG DUNG VOI DANH SACH SINH VIEN.");

                printf("\n/*TIM KIEM THONG TIN SINH VIEN KHONG THANH CONG*/\n");

                break;
            }
            }
            
        }
    }
}

/*-----------------------------CHỨC NĂNG SẮP XẾP SINH VIÊN THEO GPA-----------------------------*/
void Menu::softOfByGPA(){

    Student *student1;//Tạo con trỏ cho học sinh 1

    Student student = *student1;//Tạo con trỏ trung gian để hoán đổi các sinh viên trong danh sách

    Student *student2;//Tạo con trỏ cho học sinh 2

    vector<Student> *poniter = &list;

    list.empty();//Kiểm tra xem vector có rỗng hay không để xử lý yêu cầu

    if (list.empty())
    {
        printf("\nYEU CAU CUA BAN KHONG CO THONG TIN DE XU LY\n");
        printf("VUI LONG NHAP THONG TIN SINH VIEN\n");
    }
    else{
        for (int indexStudent1 = 0; indexStudent1 < list.size() - 1; indexStudent1++)
        {
            Student *student1 = &list.at(indexStudent1);//Lấy địa chỉ của sinh viên 1 tại vị trí của sinh viên đang được xét trong danh sách sinh viên

            for (int  indexStudent2 = 1; indexStudent2 < list.size(); indexStudent2++)
            {
                Student *student2 = &list.at(indexStudent2);//Lấy địa chỉ của sinh viên 2 tại vị trí của sinh viên đang được xét trong danh sách sinh viên

                if (poniter->at(indexStudent1).getGpa() > poniter->at(indexStudent2).getGpa()){

                    student = *student1;

                    *student1 = *student2;

                    *student2 = student;
                }
                
            }
        }
        Menu::displayInformationOfStudent();//Hien thi thong tin de nguoi dung de dang xu ly thong tin

        printf("\nSAP XEP THONG TIN SINH VIEN THEO GPA THANH CONG*/\n");
    }
}


/*-----------------------------CHỨC NĂNG SẮP XẾP SINH VIÊN THEO TÊN-----------------------------*/
void Menu::softOfByName(){

    Student *student1;//Tạo con trỏ cho học sinh 1

    Student student = *student1;//Tạo con trỏ trung gian để hoán đổi các sinh viên trong danh sách

    Student *student2;//Tạo con trỏ cho học sinh 2

    vector<Student> *poniter = &list;

    list.empty();//Kiểm tra xem vector có rỗng hay không để xử lý yêu cầu

    if (list.empty())
    {
        printf("\nYEU CAU CUA BAN KHONG CO THONG TIN DE XU LY\n");
        printf("VUI LONG NHAP THONG TIN SINH VIEN\n");
    }
    else{
        for (int indexStudent1 = 0; indexStudent1 < list.size() - 1; indexStudent1++)
        {
            Student *student1 = &list.at(indexStudent1);//Lấy địa chỉ của sinh viên 1 tại vị trí của sinh viên đang được xét trong danh sách sinh viên
            for (int  indexStudent2 = 1; indexStudent2 < list.size(); indexStudent2++)
            {
                Student *student2 = &list.at(indexStudent2);//Lấy địa chỉ của sinh viên 2 tại vị trí của sinh viên đang được xét trong danh sách sinh viên
                if (strcmp(strupr(poniter->at(indexStudent1).getName()), strupr(poniter->at(indexStudent2).getName())) > 0){

                    student = *student1;

                    *student1 = *student2;

                    *student2 = student;
                }
                
            }
        }
        Menu::displayInformationOfStudent();//Hien thi thong tin de nguoi dung de dang xu ly thong tin

        printf("\nSAP XEP THONG TIN SINH VIEN THEO TEN THANH CONG*/\n");
    }
}



/*-----------------------------CHỨC NĂNG HIỂN THỊ DANH SÁCH SINH VIÊN-----------------------------*/
void Menu::displayInformationOfStudent()
{
    printf("\n------------------------------------DANH SACH SINH VIÊN-----------------------------------\n");
    printf("__________________________________________________________________________________________\n");
    printf("  ID\t| Ten\t| Tuoi\t|   Gioi Tinh\t| Toan\t|  Ly\t|  Hoa\t|   DiemTB\t|   HocLuc\n");
    for (Student student : list)
    {
        PRINT_INFORMATION(student);//Sử dụng marco in thông tin
    }
}

/*---------------------------------------KEY OF MENU-------------------------------------*/
enum typeMenu{//Sử dụng enum để code được tường minh và người kế thừa sẽ hiểu được chức năng của chương trình một cách khách quan nhất
    addStudent = 1,
    updateInformationOfStudent = 2,
    eraseStudent = 3,
    searchStudent = 4,
    softOfByGPA = 5,
    softOfByName = 6,
    displayInformationOfStudent = 7,
    exitMenu = 8,
};

/*---------------------------------------MENU-------------------------------------*/
void runMenu(){

    //Menu quản lý sinh viên
    Menu menu;
    int solution;
    int conditionsOfRunProgram;
    do
    {
    system("cls");
    printf("\n           CHUONG TRINH QUAN LY SINH VIEN            \n");
    printf("************************MENU***************************\n");
    printf("**  1. Them sinh vien.                               **\n");
    printf("**  2. Cap nhat thong tin sinh vien boi ID.          **\n");
    printf("**  3. Xoa sinh vien theo ID.                        **\n");
    printf("**  4. Tim kiem sinh vien theo ten.                  **\n");
    printf("**  5. Sap xep sinh vien theo diem trung binh(GPA).  **\n");
    printf("**  6. Sap xep sinh vien theo ten.                   **\n");
    printf("**  7. Hien thi danh sach sinh vien.                 **\n");
    printf("**  8. Thoat menu                                    **\n");
    printf("*******************************************************\n");
    printf("Vui long nhap su lua chon cua ban: ");
    scanf("%d", &solution);
    
    switch (solution)
        {
       
        case addStudent://Thêm sinh viên
            printf("\n/* KHAI BAO THONG TIN SINH VIEN */\n");
            do
            {
                menu.addStudent();

                printf("- Nhan phim '1' => De tiep tuc Them sinh vien\n");
                printf("- Nhan phim '0' => De Thoat chuc nang\n");
                scanf("%d", &conditionsOfRunProgram);

            } while (conditionsOfRunProgram == 1);

            system("\nPause");
            break;
            
        case updateInformationOfStudent://Cập nhật thông tin sinh viên
            printf("/* CAP NHAT THONG TIN SINH VIEN */\n");
            do
            {
                menu.updateInformationOfStudent();

                printf("- Nhan phim '1' => De tiep tuc cap nhat thong tin sinh vien\n");
                printf("- Nhan phim '0' => De Thoat chuc nang\n");
                scanf("%d", &conditionsOfRunProgram);
                
            } while (conditionsOfRunProgram == 1);

            system("\nPause");
            break;
        
        case eraseStudent:
            printf("/* XOA THONG TIN SINH VIEN THEO ID */\n");
            do
            {
                menu.eraseStudent();

                printf("- Nhan phim '1' => De tiep tuc xoa thong tin sinh vien\n");
                printf("- Nhan phim '0' => De Thoat chuc nang\n");
                scanf("%d", &conditionsOfRunProgram);
                
            } while (conditionsOfRunProgram == 1);

            system("\nPause");
            break;

        case searchStudent://Tìm kiếm sinh viên
            printf("/* TIM KIEM THONG TIN SINH VIEN THEO TEN */\n");

            do
            {
                menu.searchStudent();

                printf("- Nhan phim '1' => De tiep tuc tim thong tin sinh vien\n");
                printf("- Nhan phim '0' => De Thoat chuc nang\n");
                scanf("%d", &conditionsOfRunProgram);
                
            } while (conditionsOfRunProgram == 1);
            
            system("\nPause");
            break;

        case softOfByGPA://sapXep
            printf("/* SAP XEP THONG TIN SINH VIEN THEO GPA */\n");
            do
            {
                menu.softOfByGPA();

                printf("- Nhan phim '1' => De tiep tuc tim thong tin sinh vien\n");
                printf("- Nhan phim '0' => De Thoat chuc nang\n");
                scanf("%d", &conditionsOfRunProgram);
                
            } while (conditionsOfRunProgram == 1);
            system("\nPause");
            break;

        case softOfByName://sapXep
            printf("/* SAP XEP THONG TIN SINH VIEN THEO GPA */\n");
            do
            {
                menu.softOfByName();

                printf("- Nhan phim '1' => De tiep tuc tim thong tin sinh vien\n");
                printf("- Nhan phim '0' => De Thoat chuc nang\n");
                scanf("%d", &conditionsOfRunProgram);
                
            } while (conditionsOfRunProgram == 1);
            system("\nPause");
            break;

        case displayInformationOfStudent://hienThi
            do
            {
                menu.displayInformationOfStudent();

                printf("- Nhan phim '1' => De tiep tuc hien thi danh sach sinh vien\n");
                printf("- Nhan phim '0' => De Thoat chuc nang\n");
                scanf("%d", &conditionsOfRunProgram);
                
            } while (conditionsOfRunProgram == 1);
            
            system("\nPause");
            break;

        case exitMenu://Nhấn phím 0 để thoát chương trình
            printf("-----CAM ON BAN DA SU DUNG MENU-----\n");
            printf("------------HEN GAP LAI-------------\n");
            break;

        default:
            printf("Yeu cau khong ton tai\n");
            printf("Vui long nhap yeu cau tu (1 - 8)\n");
            system("\nPause");
        }

    }while(solution != 8);
}

int main(int argc, char const *argv[])
{
    runMenu();

    return 0;
}