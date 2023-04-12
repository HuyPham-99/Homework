/*
* File: Resaurant.cpp
* Author: Hung Huy
* Date: 28/03/2023
* Description: This is a file for restaurant menu.
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <vector>
#include <iostream>

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
 * Description: Macro phần hiển thị thông tin món ăn 
 * Input:
 *   object - đối tượng cần hiển thị
 *   orderNumOfFood - số thứ tự của món ăn
 */
#define PRINT_INFORMATION(orderNumOfFood, object)                                                     \
    printf(" %d\t| %d\t| %s\t\t|  %.f\t\n",orderNumOfFood, object.getId(),                            \
                                    object.getName(), object.getPrices());                             
       

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


/*--------------------------------------CLASS CỦA NHÀ HÀNG----------------------------------*/
class Restaurant{
private:

    unsigned int  idOfFood;

    float priceOfFood;

    char nameOfFood[20];

    unsigned int numberOfTable;

    

public:
    Restaurant(const char name[],  float prices);
    
    void setNameOfFood(const char name[]);
    
    void setPriceOfFood(float prices);

    
    
    unsigned int getId();
    
    char* getName();
        
    float getPrices();
    
   

};

/*-------------------------------------ĐẶT THÔNG TIN CHO MÓN ĂN CÓ TRONG NHÀ HÀNG-------------------------------*/

/*-------------------------------------ĐẶT TÊN CHO MÓN ĂN -------------------------------*/
void Restaurant::setNameOfFood(const char name[]){

    strcpy(Restaurant::nameOfFood,name);

}


/*-------------------------------------ĐẶT GIÁ CHO MÓN ĂN -------------------------------*/
void Restaurant::setPriceOfFood(float prices){

    Restaurant::priceOfFood = prices;
}



/*------------------------------------CONSTRUCTOR NHÀ HÀNG----------------------------------*/
Restaurant::Restaurant(const char name[], float prices){
    //Tự động tạo ID cho món ăn
    static unsigned int r_Id = 100;
    Restaurant::idOfFood = r_Id;
    r_Id++;

    strcpy(Restaurant::nameOfFood,name);

    Restaurant::priceOfFood = prices;

}

/*-------------------------------------ID CỦA MÓN ĂN------------------------------------*/

unsigned int Restaurant::getId()
{
    return Restaurant::idOfFood;
}

/*-------------------------------------TÊN CỦA MÓN ĂN------------------------------------*/
char* Restaurant::getName(){

    return Restaurant::nameOfFood;
}

/*-------------------------------------GIÁ CỦA MÓN ĂN------------------------------------*/
float Restaurant::getPrices()
{
    return Restaurant::priceOfFood;
}

/*--------------------------------------CLASS CỦA QUẢN LÝ NHÀ HÀNG----------------------------------*/
class menuOfManeger
{
    private:

        vector<Restaurant> missonOfManeger; 

        unsigned int numberOfTable = 0;//Trạng thái của bàn

    public:

        void setNumberOfTable(unsigned int numberOfTable);

        unsigned int getNumberOfTableInRestaurant();

        vector<Restaurant> getMissonOfManeger();
        
        void addOfDishes();

        void newOfDishes();

        void earesOfDishes();

        void displayOfDishes();


};

void menuOfManeger::setNumberOfTable(unsigned int numbersOfTables){

    menuOfManeger::numberOfTable = numbersOfTables;
}

unsigned int menuOfManeger::getNumberOfTableInRestaurant(){

    return menuOfManeger::numberOfTable;
}


/*
 * Function: Method getMissonOfManeger
 * Description: Lấy data danh sách món ăn đã quản lý nhập vào để làm database cho hệ thống
 * Output:
 *   missonOfManeger - vector<Restaurant>
 */
vector<Restaurant> menuOfManeger::getMissonOfManeger(){
    return menuOfManeger::missonOfManeger;
}


/*
 * Function: Method addFood
 * Description: Thêm món ăn mới 
 */
void menuOfManeger::addOfDishes()
{
    char name[20];

    float price;

    int key;

    printf("/* THEM MON AN MOI */\n");

    ENTER_DATA("Nhap ten mon: ", "%s", &name, 0);

    ENTER_DATA("Nhap gia (nghin dong): ", "%.f", &price, price < 0);

    Restaurant Restaurant(name, price);

    missonOfManeger.push_back(Restaurant);
}




enum typeOfUpdateData{
    nameOfData = 1,
    priceOfData = 2,
    exitFunction = 3,
};
/*
 * Function: Method newOfDishes
 * Description: Cập nhật thông tin món ăn cho nhà hàng 
 */
void menuOfManeger::newOfDishes(){
    
    int key;

    unsigned int id;

    char name[20];
    
    float priceOfFood;

    unsigned int choice;

    bool haveDishes = false;

    vector<Restaurant> *ptr = &missonOfManeger;

    missonOfManeger.empty();//Kiểm tra xem vector có rỗng hay không để xử lý yêu cầu
    if (missonOfManeger.empty())
    {
        printf("\nYEU CAU CUA BAN KHONG CO THONG TIN DE XU LY\n");

        printf("VUI LONG NHAP THONG TIN MON AN CHO NHA HANG\n");
    }
    else{

        printf("\n-----------------------DANH SACH MON AN--------------------------\n");
        printf("STT\t|  ID\t| Ten mon\t| Gia(Nghin dong)\n");
        int orderNumOfFood  = 1;

        for (Restaurant Restaurant : missonOfManeger) 
            {
                PRINT_INFORMATION(orderNumOfFood, Restaurant);
                orderNumOfFood++;
            }

        for (int index = 0; index < ptr->size(); index++)
        {

            ENTER_DATA("Nhap id cua mon an: ", "%u", &id, 0);

            if ((ptr->at(index)).getId() == id)
            {
                printf("------CHON THONG TIN CAN CAP NHAT------\n");
                printf("1. TEN\n");
                printf("2. GIA\n");
                printf("3. Thoat\n");
                printf("-------------------------------------------\n");
                ENTER_DATA("- Nhan phim : ", "%u", &choice, 0);

                switch (choice)
                {
                    case nameOfData:
                        ENTER_DATA("Nhap ten: ", "%s", &name, 0);

                        (ptr->at(index)).setNameOfFood(name);

                        haveDishes = true;
                        break;

                    case priceOfData:
                        ENTER_DATA("Nhap gia: ", "%f", &priceOfFood, 0);

                        (ptr->at(index)).setPriceOfFood(priceOfFood);

                        haveDishes = true;
                        break;

                    case exitFunction:
                        break;
                    default:
                        printf("KHONG DUNG LUA CHON, VUI LONG NHAP LAI\n");
                        break;
                }
                break;
            }
            if(haveDishes != true)
                {
                    printf("KHONG TIM THAY MON AN CAN SUA\n");
                    printf("VUI LONG KIEM TRA LAI THONG TIN MON AN CAN SUA\n");
                }
        }
    }
 
}

/*
 * Function: Method earesOfDishes
 * Description: Xóa thông tin món ăn cho nhà hàng 
 */
void menuOfManeger::earesOfDishes(){
    unsigned int id;

    unsigned int key;

    bool haveDishes = false;

    vector<Restaurant> *ptr = &missonOfManeger;

    missonOfManeger.empty();//Kiểm tra xem vector có rỗng hay không để xử lý yêu cầu

    if (missonOfManeger.empty())
    {
        printf("\nYEU CAU CUA BAN KHONG CO THONG TIN DE XU LY\n");

        printf("VUI LONG NHAP THONG TIN MON AN\n");
    }
    else{

        printf("\n-----------------------DANH SACH MON AN--------------------------\n");
        printf("STT\t|  ID\t| Ten mon\t| Gia(Nghin dong)\n");
        int orderNumOfFood  = 1;

        for (Restaurant Restaurant : missonOfManeger) 
            {
                PRINT_INFORMATION(orderNumOfFood, Restaurant);
                orderNumOfFood++;
            }

        ENTER_DATA("\nNhap ID cua mon an can xoa: ", "%u", &id, 0);

        for (int index = 0; index < ptr->size(); index++)
        {    
            if ((ptr->at(index)).getId() == id)
                {
                    ptr->erase(ptr->begin() + index);
                    haveDishes = true;
                    printf("*DA XOA MON AN*\n");
                    break;
                }
                if (haveDishes != true)
                {
                    printf("KHONG TIM THAY MON AN\n");
                }
        }
            
    }
    
}

/*
 * Function: Method displayOfDishes
 * Description: Hiển thị thông tin món ăn
 */
void menuOfManeger::displayOfDishes(){
    unsigned int key;

    printf("\n-----------------------DANH SACH MON AN--------------------------\n");
    printf("STT\t|  ID\t| Ten mon\t| Gia(Nghin dong)\n");
    int orderNumOfFood  = 1;
    for (Restaurant Restaurant : missonOfManeger) 
    {
        PRINT_INFORMATION(orderNumOfFood, Restaurant);
        orderNumOfFood++;
    }
}





/*---------------------------------------------------CLASS ORDERED FOOD--------------------------------------------------------*/
/*
 * Function: Class orDeredFood
 * Description: Quản lý thông tin những món đã được gọi bởi nhân viên
 */
class orDeredFood  
{
protected:
    unsigned int numberOfFood;

    char nameFood[20];

    float priceFood;

    unsigned int idFood;

public:
    
    orDeredFood(unsigned int id, const char nameFood[], const float priceFood, unsigned int numberOfFood);

    void setnumberOfFood(unsigned int numberOfFood);

    unsigned int  getIDFood();

    unsigned int  getnumberOfFood();

    char* getNameFood();

    float getPriceFood();

    

};


/*
 * Function: Constructor orDeredFood
 * Description: Khởi tạo dữ liệu cho mỗi món ăn đã gọi
 * Input:
 *   id - unsigned int 
 *   nameFood - char*
 *   priceFood - float
 *   numberOfFood - unsigned int
 */
orDeredFood::orDeredFood(const unsigned int id, const char nameFood[], const float priceFood, unsigned int numberOfFood)
{
    orDeredFood::idFood = id;

    strcpy(orDeredFood::nameFood, nameFood);

    orDeredFood::priceFood = priceFood;

    orDeredFood::numberOfFood = numberOfFood;
}

/*
 * Function: Method setnumberOfFood
 * Description: Set số lượng của mỗi món ăn
 * Input:
 *  numberOfFood - unsigned int
 */
void orDeredFood::setnumberOfFood(unsigned int numberOfFood)
{
    orDeredFood::numberOfFood = numberOfFood;
}

/*
 * Function: Method getnumberOfFood
 * Description: Lấy số lượng của mỗi món ăn
 * Output:
 *  numberOfFood - unsigned int 
 */
unsigned int orDeredFood::getnumberOfFood()
{
    return orDeredFood::numberOfFood;
}

/*
 * Function: Method getIDFood
 * Description: Lấy ID của món ăn đã gọi
 * Output:
 *  idFood - unsigned int
 */
unsigned int orDeredFood::getIDFood()
{
    return orDeredFood::idFood;
}

/*
 * Function: Method getNameFood
 * Description: Lấy tên của món ăn đã gọi
 * Output:
 *  nameFood - char*
 */
char* orDeredFood::getNameFood()
{
    return orDeredFood::nameFood;
}

/*
 * Function: Method getPriceFood
 * Description: Lấy giá của món ăn đã gọi
 * Output:
 *  priceFood - float
 */
float orDeredFood::getPriceFood()
{
    return orDeredFood::priceFood;
}

/*---------------------------------------------------CLASS TABLE--------------------------------------------------------*/
/*
 * Function: Class Table
 * Description: Chứa Property và Method để sử dụng cho class nhân viên.
 */
class Table
{
private:
    bool stateTable = 0; // Trạng thái bàn ăn

    float totalMoney = 0; //Tổng tiền sau khi được tính

    vector<orDeredFood> listOrderedFood;//Tạo vector để lưu thông tin sau khi nhân viên gọi món tránh việc dữ liệu bị overlording

    vector<Restaurant> copyListFood; //Lấy dữ liệu từ class Restaurant(dữ liệu tổng) để làm dữ kiện giải quyết bài toán của nhân viên

public:

    Table(menuOfManeger manager);

    void orderFood();

    void displayOrderedFood();

    void getTotalMoney();

    bool getStateTable();

    void updateListFood(menuOfManeger manager);
};

/*
 * Function: Constructor Table
 * Description: Khởi tạo dữ liệu cho bàn ăn, copy data danh sách món ăn của quản lý đã tạo để gọi món
 * Input:
 *   manager - Manager
 */
Table::Table(menuOfManeger manager)
{
    for (auto data : manager.getMissonOfManeger())
    {
        copyListFood.push_back(data);
    }
}


/*
 * Function: orderFood
 * Description: Gọi món ăn
 */
void Table::orderFood(){

    int key;
    unsigned int id;
    unsigned int numberOfFood;

    vector<Restaurant> *ptr = &copyListFood;

    bool haveFood = false;

    copyListFood.empty();

    if (copyListFood.empty())
    {
        printf("\nYEU CAU CUA BAN KHONG CO THONG TIN DE XU LY\n");

        printf("VUI LONG QUAN LY NHAP THONG TIN MON AN\n");
    }
    else{
        printf("\n-----------------------DANH SACH MON AN--------------------------\n");
        printf("STT\t|  ID\t| Ten mon\t| Gia mon an(Nghin dong)\n");
        int orderNumOfFood  = 1;
        for (Restaurant Restaurant : copyListFood) 
        {
            PRINT_INFORMATION(orderNumOfFood, Restaurant);
            orderNumOfFood++;
        }

        printf("/* GOI MON AN */\n");

        ENTER_DATA("Nhap ID mon an: ", "%u", &id, 0);

        for (int index = 0; index < ptr->size(); index++)
        {
            
            if ((ptr->at(index)).getId() == id)
            {
                        
                ENTER_DATA("Nhap so luong: ", "%u", &numberOfFood, numberOfFood < 0);

                orDeredFood foodHasOder((ptr->at(index)).getId(), (ptr->at(index)).getName(), (ptr->at(index)).getPrices(), numberOfFood);

                listOrderedFood.push_back(foodHasOder);
                        
                stateTable = 1;
                haveFood = 1;

                break;
            }
        }

        if(haveFood != 1)
        {
            printf("KHONG TIM THAY MON AN CAN GOI\n");
        }
        printf("- Nhan phim '1' => De tiep tuc goi mon an\n");
    }

}


/*
 * Function: displayOrderedFood
 * Description: Hiển thị món ăn đã gọi
 */
void Table::displayOrderedFood()
{
    int key;

    copyListFood.empty();

    if (copyListFood.empty())
    {
        printf("\nYEU CAU CUA BAN KHONG CO THONG TIN DE XU LY\n");

        printf("VUI LONG NHAP THONG TIN MON AN\n");
    }
    else{
        printf("\n-----------------------DANH SACH MON AN--------------------------\n");
                printf("STT\t|  ID\t| Ten mon\t| Soluong\t| Gia mon an(Nghin dong)\n");
                int orderNum  = 1;
                for (orDeredFood food : listOrderedFood) 
                {
                    printf(" %u\t| %u\t| %s\t\t|  %u\t\n",orderNum, food.getIDFood(), food.getNameFood(), food.getnumberOfFood());       

                    orderNum++;
                }

                printf("- Nhan phim '1' => De Hien thi Danh sach Mon an da goi\n");
    }
}



/*
 * Function: getTotalMoney
 * Description: Tính tổng tiền món ăn đã gọi.
 */
void Table::getTotalMoney()
{
    int key;
 
    copyListFood.empty();

    if (copyListFood.empty())
    {
        printf("\nYEU CAU CUA BAN KHONG CO THONG TIN DE XU LY\n");

        printf("KHONG THE TINH TIEN\n");
    }
    else{
        printf("\n-----------------------DANH SACH MON AN--------------------------\n");
        printf("STT\t|  ID\t| Ten mon\t| Soluong\t| Gia mon an(Nghin dong)\n");

        int orderNum  = 1;

        for (orDeredFood food : listOrderedFood) 
        {
            printf(" %u\t| %u\t| %s\t\t|  %u\t\t|  %.f\t\n",orderNum, food.getIDFood(),food.getNameFood(), food.getnumberOfFood(), food.getPriceFood());                         
            orderNum++;
        }

        for (orDeredFood food : listOrderedFood) 
        {
            Table::totalMoney = Table::totalMoney + food.getPriceFood() * food.getnumberOfFood();
        }

        printf("=> Tong tien: %.1f (nghin dong)\n", Table::totalMoney);

        listOrderedFood.clear();
        stateTable = 0;
    }
   
}

/*
 * Function: Method getStateTable
 * Description: Lấy trạng thái của mỗi bàn, xem bàn đó đã có người ăn chưa.
 * Output:
 *   stateTable - bool 
 */
bool Table::getStateTable()
{
    return Table::stateTable;
}

/*
 * Function: Method updateListFood
 * Description: Cập nhật danh sách món ăn khi người quản Lý thay đổi.  
 */
void Table::updateListFood(menuOfManeger manager)
{
    copyListFood.clear();//Xóa database món ăn sau khi người quản lý thay đổi database món ăn.
    for (auto data : manager.getMissonOfManeger())
    {
        copyListFood.push_back(data);//Cập nhật database mà quản lý đã thay đổi.
    }
}


/*--------------------------------------CLASS CỦA NHÂN VIÊN NHÀ HÀNG----------------------------------*/
/*
 * Function: Class Nhân viên.
 * Description: Chứa Property và Method sử dụng cho chương trình của nhân viên.
 */
class menuOfstaff
{
private:

    vector<Table> missonOfStaff;//Gán giá trị của quản lý đã nhập cho nhân viên.
    
    unsigned int numberTable = 0;

public:

    void displayStateTable();

    void selectTable( unsigned int numTable);

    unsigned int  getNumberOfTable();

    void getDataFromManager(menuOfManeger *manager);

    void updateDataFromManager(menuOfManeger *manager);

};

/*
 * Function: Method getDataFromManager.
 * Description: Lấy data danh sách món ăn và số bàn mà Quản lý đã nhập vào.
 * Input:
 *  manager: Manager*
 */
void menuOfstaff::getDataFromManager(menuOfManeger *manager)
{
    menuOfstaff::numberTable = manager->getNumberOfTableInRestaurant();
    for(int i = 0; i < menuOfstaff::numberTable; i++)
    {
        Table table(*manager);

        missonOfStaff.push_back(table);
    }
}

/*
 * Function: Method updateDataFromManager
 * Description: Cập nhât data danh sách món ăn và số bàn mà quản lý đã nhập vào.
 * Input:
 *  manager: Manager*
 */
void menuOfstaff::updateDataFromManager(menuOfManeger *manager)
{
    int lastQuantityTable = menuOfstaff::numberTable;

    menuOfstaff::numberTable = manager->getNumberOfTableInRestaurant();

    for(int i = 0; i < lastQuantityTable; i++) //Cập nhật thông tin danh sách món.
    {
        Table table(*manager);

        missonOfStaff.at(i).updateListFood(*manager);
    }

    for(int i = lastQuantityTable; i < menuOfstaff::numberTable; i++) //Cập nhật thêm số lượng bàn nếu Manager có nhập thêm.
    {
        Table table(*manager);

        missonOfStaff.push_back(table);
    }
}

/*
 * Function: Method getQuantityTable
 * Description: Lấy số bàn quản lý đã nhập.
 * Output:
 *  numberTable - unsigned int 
 */
unsigned int menuOfstaff::getNumberOfTable()
{
    return menuOfstaff::numberTable;
}


/*
 * Function: Method displayStateTable
 * Description: Hiển thị trạng thái bàn 
 */
void menuOfstaff::displayStateTable()
{
    missonOfStaff.empty();

    if (missonOfStaff.empty())
    {
        printf("\nYEU CAU CUA BAN KHONG CO THONG TIN DE XU LY\n");

        printf("TRANG THAI KHONG XAC DINH\n");

        printf("NHAN PHIM '0' DE THOAT\n");
    }
    else{
        printf("------------------------Trang thai ban------------------------\n");
        printf("Ban:      |");
        for(int i = 1; i <= menuOfstaff::numberTable; i++)
        {
            printf(" %u  |", i);
        }
        printf("\nT.Thai:   |");
        for(int i = 0; i < menuOfstaff::numberTable; i++)
        {
            if(missonOfStaff.at(i).getStateTable() == 1){
                printf(" x  |");
            }
            else
            {
                printf("    |");
            }
        }
    }
}


enum typeChoiceOfStaff{
    orderFood = 1,
    displayOfFood = 2,
    coutOfMoney = 3, 
    returnOfMenu = 0,
};
/*
 * Function: Method selectTable
 * Description: Lựa chọn bàn ăn
 * Input:
 *  numTable - unsigned int
 */
void menuOfstaff::selectTable(unsigned int numTable)
{
    int key;

    missonOfStaff.empty();

    if (missonOfStaff.empty())
    {
        printf("\nYEU CAU CUA BAN KHONG CO THONG TIN DE XU LY\n");

        printf("BAN HIEN TAI KHONG CO THONG TIN\n");

        printf("NHAN PHIM '0' DE THOAT\n");
    }
    else{

        system("cls");
        printf("------BAN %d------\n",numTable + 1);
        printf("1. Goi mon\n");
        printf("2. Danh sach mon da goi\n");
        printf("3. Tinh tien\n");
        printf("0. Thoat\n");

        ENTER_DATA("- VUI LONG NHAP LUA CHON : ", "%d", &key, key > 3 || key < 0);

        switch (key)
        {

        case orderFood:

            missonOfStaff.at(numTable).orderFood();

            break;
        case displayOfFood:

            missonOfStaff.at(numTable).displayOrderedFood();

            system("\nPause\n");

            break;
        case coutOfMoney:
            system("cls");

            missonOfStaff.at(numTable).getTotalMoney();

            system("\nPause\n");

            break;
        case returnOfMenu:

            return;
        default:

            break;
        }
    }
}

/*
 * Function: runStaffProgram
 * Description: Chương trình dành cho Nhân Viên
 * Input:
 *  staff - *staff
 */
void runStaffProgram(menuOfstaff *staff)
{

    int key;

    do
    {
        system("cls");
        printf("--------------------------NHAN VIEN---------------------------\n");
        staff->displayStateTable();
        printf("\n--------------------------------------------------------------\n");
        ENTER_DATA("- Nhap lua chon cua ban (nhan phim 0 khi khong co thong tin) : ", "%d", &key, key > staff->getNumberOfTable() || key < 0);

        switch (key)
        {
        case 0:
            return;
        default:
            staff->selectTable(key-1);
            break;
        }
    } while (1);
}



/*---------------------------------------KEY OF RETAURANT-------------------------------------*/
enum typeFunctionOfRestaurant{//Sử dụng enum để code được tường minh và người kế thừa sẽ hiểu được chức năng của chương trình một cách khách quan nhất
    Management = 1,
    Staff = 2,
    exitMenu = 3,
};

/*---------------------------------------KEY OF MANAGEMENT-------------------------------------*/
enum typeManagementOfRestaurant{//Sử dụng enum để code được tường minh và người kế thừa sẽ hiểu được chức năng của chương trình một cách khách quan nhất
    addDishes = 1,
    editorDeredFood = 2,
    deleteOrderedDishes = 3,
    listOfDishes = 4,
    insertOfTables = 5,
    returnMenu = 6,
};

/*---------------------------------------KEY OF STAFF-------------------------------------*/
enum typeStaffOfRestaurant{//Sử dụng enum để code được tường minh và người kế thừa sẽ hiểu được chức năng của chương trình một cách khách quan nhất
    selectTable = 1,
    returnToMenu = 2,
};

/*---------------------------------------MENU OF RETAURANT-------------------------------------*/
void runMenuOfResTaurant()
{
    menuOfManeger Maneger;

    menuOfstaff staff;

    //Menu quản lý 
    unsigned int choice;
  
    do
    {
        system("cls");
        printf("\n           CHUONG TRINH QUAN LY NHA HANG             \n");
        printf("************************MENU******************************\n");
        printf("**  1. Quan ly nha hang                                 **\n");
        printf("**  2. Nhan vien nha hang                               **\n");
        printf("**  3. Thoat menu                                       **\n");
        printf("**********************************************************\n");
        ENTER_DATA("Vui long nhap su lua chon theo chuc vu cua ban (1 - 3): ", "%u", &choice, choice > 3 || choice < 0);
        switch (choice)
        {
        unsigned int key;
        case Management://Quản lý nhà hàng
    
            unsigned int missonM;
            int conditionsOfRunProgram;

            do
            {
            system("cls");
            printf("\n                 QUAN LY NHA HANG                    \n");
            printf("************************MENU******************************\n");
            printf("**  1. Them mon                                         **\n");
            printf("**  2. Sua mon                                          **\n");
            printf("**  3. Xoa mon                                          **\n");
            printf("**  4. Danh sach mon                                    **\n");
            printf("**  5. Dat so luong ban                                 **\n");
            printf("**  6. Quay lai menu                                    **\n");
            printf("**********************************************************\n");
            ENTER_DATA("Vui long nhap su lua chon theo nhiem vu cua ban (1 - 6): ", "%u", &missonM, missonM > 6 || missonM < 0);
            switch (missonM)
            {
                case addDishes:
                    system("cls");
                    printf("\n/* NHIEM VU CUA QUAN LY NHA HANG */\n");

                    DOWHILE_METHODMENU
                    (
                        
                        Maneger.addOfDishes();

                        printf("\nTHEM THONG TIN CHO MON AN THANH CONG!\n"); 

                        printf("\n- Nhan phim '1' => De tiep tuc chuc nang\n");
                    );        
                break;

                case editorDeredFood:
                    system("cls");
                    printf("\n/* NHIEM VU CUA QUAN LY NHA HANG */\n");

                    DOWHILE_METHODMENU
                    (
                        
                        Maneger.newOfDishes();

                        printf("\nCAP NHAT THONG TIN CHO MON AN THANH CONG!\n"); 

                        printf("\n- Nhan phim '1' => De tiep tuc chuc nang\n");
                    );        
                break;

                case deleteOrderedDishes:
                    system("cls");
                    printf("\n/* NHIEM VU CUA QUAN LY NHA HANG */\n");

                    DOWHILE_METHODMENU
                    (
                        
                        Maneger.earesOfDishes();

                        printf("\nXOA MON AN THANH CONG!\n"); 

                        printf("\n- Nhan phim '1' => De tiep tuc chuc nang\n");
                    );  
                break;

                case listOfDishes:
                    printf("/* NHIEM VU CUA QUAN LY NHA HANG */\n");

                    DOWHILE_METHODMENU
                    (
                        
                        Maneger.displayOfDishes();

                        printf("\n- Nhan phim '1' => De tiep tuc chuc nang\n");
                    );        
                break;    

                case insertOfTables:
                    system("cls");
                    printf("/* NHIEM VU CUA QUAN LY NHA HANG */\n");

                    DOWHILE_METHODMENU
                    (
                        
                        unsigned int numberOfTables;

                        printf("Nhap so luong ban can dat: ");
                        scanf("%u", &numberOfTables);

                        Maneger.setNumberOfTable(numberOfTables);

                        printf("\nDAT SO LUONG BAN THANH CONG!\n"); 

                    );  
                break;
                staff.getDataFromManager(&Maneger); //Lấy data của Manager copy sang staff

                default:
                printf("Yeu cau khong ton tai\n");
                printf("Vui long nhap yeu cau tu (1 - 6)\n");
                system("\nPause");
            }       
            }while(missonM != 6);
        break;

        case Staff://Nhân viên nhà hàng
    
            unsigned int missonS;
            int conditionsOfStaff;
            do
            {
            system("cls");
            printf("\n                 NHAN VIEN NHA HANG                  \n");
            printf("************************MENU***************************\n");
            printf("**  1. Chon ban                                      **\n");
            printf("**  2. Quay lai menu                                 **\n");
            printf("*******************************************************\n");
            ENTER_DATA("Vui long nhap su lua chon theo nhiem vu cua ban: ", "%u", &missonS, missonS > 2 || missonS < 0);
            switch (missonS)
            {
            case selectTable:
                printf("\n/* NHIEM VU CUA NHAN VIEN NHA HANG */\n");

                system("cls");
                staff.updateDataFromManager(&Maneger); //Cập nhật dữ liệu từ Manager -> staff

                runStaffProgram(&staff);
  
            break;

            case returnToMenu:
            break;
            
            default:
                printf("Yeu cau khong ton tai\n");
                printf("Vui long nhap yeu cau tu (1 - 2)\n");
                system("\nPause");
            } 

            }while(missonS != 2);
        break;

        case exitMenu:
            system("cls");
            printf("\n-----CAM ON BAN DA SU DUNG MENU-----\n");
            printf("------------HEN GAP LAI-------------\n");
        break;

        default:
            printf("Yeu cau khong ton tai\n");
            printf("Vui long nhap yeu cau tu (1 - 3)\n");
            system("\nPause");
        }  
    }while(choice != 3);
}

int main(int argc, char const *argv[])
{

    runMenuOfResTaurant();

    return EXIT_SUCCESS;
}