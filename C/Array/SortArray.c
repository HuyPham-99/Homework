
/*
* File: Sort_Array.c
* Author: Hung Huy
* Date: 28/03/2023
* Description: Xử lý mảng.
* Requires:
// Câu 1: Tạo mảng bất kỳ. Ví dụ: arr[] = {1, 7, 8, 2, 3, 8, 3, 7, 6, 7, 8, 8, 2}
// Câu 2: Sắp xếp mảng theo thứ tự tăng dần.
// Câu 3: Liệt kê số lần xuất hiện của từng phần tử trong mảng. Ví dụ: số 1 xuất hiện 1 lần
//                                                                  số 7 xuất hiện 2 lần
//                                                                  số 8 xuất hiện 2 lần
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

/*
 * Description: Tạo cấu trúc cơ bản của mảng
 * Input:
 *   size: kích thước của mảng
 *   *firstAdd: con trỏ tới vị trí đầu tiên được nhập của mảng
 */
/*---------------------------------------CẤU TRÚC CỦA MẢNG-------------------------------------*/
typedef struct{
    uint8_t size;       // Kích thước của mảng
    uint8_t *firstAdd;  // Vị trí đầu tiên của mảng 
}typeArray;             


/*---------------------------------------CÔNG THỨC TẠO MẢNG BẤT KỲ (RANDOM ARRAY)-------------------------------------*/
int randomA(int minN, int maxN){
 return minN + rand() % (maxN + 1 - minN);
}

/*
 * Function: RANDOM_ARRAY
 * Description: Dùng để tạo ra mảng bất kỳ
 * Input:
 *   lenght: chiều dài của mảng
 */
/*---------------------------------------HÀM TẠO MẢNG BẤT KỲ-------------------------------------*/
void randomArray(typeArray *value, uint8_t length){ // Tạo con trỏ giá trị: value và biến kích thước: length
    
    srand((int)time(0));                            // Hàm void srand cung cấp seed cho bộ sinh số ngẫu nhiên được sử dụng bởi hàm rand.
    
    value->size = length; 
    
    printf("Size of array: ");                      // Nhập kích thước mảng mong muốn
    
    scanf("%d", &length);
    
    value->firstAdd = (uint8_t *)malloc(sizeof(uint8_t)*value->size); // Cấp phát động cho biến kích thước
    
    for(int i = 0; i < value->size; ++i)
    {
        value->firstAdd[i] = randomA(0,length);
    }    
}

/*
 * Function: SORT_ARRAY
 * Description: Sắp xếp mảng theo giá trị tăng dần của phần tử
 * Input:
 *      i: vị trí của phần tử thứ 1.
 *      j: vị trí của phần tử thứ 2.
 * intermeDiaries: biến đếm tăng dần của mảng.
 */
/*---------------------------------------HÀM SẮP XẾP MẢNG TĂNG DẦN-------------------------------------*/
void sortArray(typeArray*arr){

    printf("Incrementally sorted array: "); 

    uint8_t intermeDiaries;                 // Biến đếm tăng dần của mảng
    
    for (int i = 0; i < arr->size; i++)
    {
        for (int j = i + 1; j < arr->size; j++)
        {
            if (arr->firstAdd[j] < arr->firstAdd[i]) //Nếu giá trị của biến tạm bé hơn giá trị của biến thực tại vị trí tương ứng thì
            {
                uint8_t intermeDiaries = arr->firstAdd[j];  // Gán biến tạm 
                
                arr->firstAdd[j] = arr->firstAdd[i];        // So sánh hai số liền kề nhau trong một mảng bất kỳ.
                
                arr->firstAdd[i] = intermeDiaries;          // Trong hai số được so sánh thì số nào lớn hơn thì đổi vị trí với số nhỏ hơn
            }
            
        }
        printf("%d ",arr->firstAdd[i],i); 
    }
}

/*
 * Function: COUNT_ARRAY
 * Description: Đếm số lần xuất hiện của từng phần tử trong mảng bất kỳ
 * Input:
 *     i: vị trí của từng phần tử.
 * count: biến đếm của mảng.
 */
/*---------------------------------------HÀM ĐẾM SỐ LẦN XUẤT HIỆN CỦA TỪNG PHẦN TỬ TRONG MẢNG BẤT KỲ-------------------------------------*/
void countArray(typeArray *arr){
    
    printf("\nNumbers  Number of appearances\n"); // In ra giá trị của phần tử trong mảng và số lần xuất hiện của từng phần tử
    
    int count = 0; // Khởi tạo biến đếm 
    
    int i; // khởi tạo biến vị trí
    
    for (i = 0; i < arr->size; i++)
    {
        if(arr->firstAdd[i] == arr->firstAdd[i + 1]) { // Nếu tại vị trí đang xét bằng với vị trí khởi tạo cộng cho 1 thì
            
            count++; // Tăng biến đếm lên 1
        }
        else { // Trường hợp vị trí cần xét không bằng với vị trí khởi tạo thì cho số lần xuất hiện của phần tử đó là 1
            
            printf("%d \t %d\n", arr->firstAdd[i], count); 
            
            count = 1;
        }
    }
    
}


/*
 * Function: SHOW_RESULTS
 * Description: Hiển thị kết quả của mảng sau khi được xử lý theo yêu cầu
 * Input:
 * i: vị trí của từng phần tử.
 */
/*---------------------------------------HÀM HIỂN THỊ KẾT QUẢ-------------------------------------*/
void showResults(typeArray *arr){
    printf("\n++++++ KQ ++++++\n");

    int i;

    for (int i = 0; i < arr->size; i++)
    {
        printf("\narr[%d] = %d\n",i, arr->firstAdd[i]);
    }
    
}


int main(int argc, char const *argv[])
{
    typeArray arr;

    randomArray(&arr, 10); // Hàm tạo mảng bất kỳ 

    showResults(&arr); // Hàm hiển thị kết quả

    sortArray(&arr); // Hàm sắp xếp mảng tăng dần

    countArray(&arr); // Hàm đếm số lần xuất hiện của từng phần tử

    free(arr.firstAdd); //Giải phóng con trỏ để tiết kiệm bộ nhớ

    return 0;
}