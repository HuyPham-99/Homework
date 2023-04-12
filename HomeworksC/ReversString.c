
/*
* File: Revers_String.c
* Author: Hung Huy
* Date: 28/03/2023
* Description: Xử lý chuỗi.
* Requires:
// Chỉ sử dụng thư viện stdio.
// Viết một chuổi đảo ngược.
// In hoa chữ cái đầu sau dấm chấm.
// Chuyển tất cả đoạn văn được in hoa thành chữ thường.
// Chuyển tất cả đoạn văn được in thường thành in hoa.
*/

#include <stdio.h>


/*---------------------------------------ĐỀ BÀI-------------------------------------*/
char s1[] = "The Grammy award-winning singer. who has been less active on digital platforms in recent weeks. explained her decision to distance herself from social media platforms during an appearance on the Conan OBrien Needs a Friend podcast, alongside her brother Finneas";


/*
 * Main function
 * Description: 
    // Viết một chuổi đảo ngược.
    // In hoa chữ cái đầu sau dấm chấm.
    // Chuyển tất cả đoạn văn được in hoa thành chữ thường.
    // Chuyển tất cả đoạn văn được in thường thành in hoa.
 * Input:
 * length: chiều dài của chuỗi
 *     s1: chuỗi lúc ban đầu chưa được xử lý (chuỗi 1)
 *     s2: chuỗi sau khi được xử lý theo yêu cầu bài toán (chuỗi 2)
 *    tmp: mảng tạm thời để gán trị của chuỗi 1 để làm data xử lý
 *      i: vị trí của các phần tử trong chuỗi 1.
 *      j: vị trí của các phần tử trong chuỗi 2.
 *  count: biến đếm của chương trình.
 * thepreiod: dấu chấm.
 */

int main() {
   
   int length = 0; // chiều dài của chuỗi lúc đầu

/*---------------------------------------IN RA CHUỖI BAN ĐẦU-------------------------------------*/
   printf("\n\nOriginal: ");
   printf("%s", s1);


/*---------------------------------------TÍNH CHIỀU DÀI CỦA CHUỖI-------------------------------------*/
   while(s1[length] != '\0') // '\0' là ký tự NULL kết thúc cho chuỗi
   {
      length++; 
   }

   char tmp[length];// Tạo mảng tạm thời gán giá trị cho chuỗi


/*---------------------------------------IN CHUỖI THEO CHIỀU ĐẢO NGƯỢC-------------------------------------*/
   int j = 0;//j: vị trí của các phần tử trong chuỗi 2.

   int count = 0;// count: biến đếm của chương trình.

    for(int i = length; i >= 0; i--){ // Duyệt từng ký tự bắt đầu từ cuối chuỗi

      if (i == length || i == length - 1) //Xử lý ký tự '\0' bằng cách bỏ qua

      continue;

      // Đếm số lượng ký tự mà chương trình duyệt
      count++; 
      
      // Khi gặp khoảng trắng, thực hiện sao chép từ chuỗi qua mảng tạm thời
      if (s1[i] == ' '){ 

         for(int k = i; k < i + count; k++){

            tmp[j] = s1[k + 1];

            j++;
         }
            tmp[j-1] = ' ';

            count = 0;
      }
      
      // Xử lý từ ở đầu câu của chuỗi
        if (i == 0){ 

            for(int k = i; k < i + count; k++){

                tmp[j] = s1[k];

                j++;
            }
        }

   }

   tmp[length - 1] = '\0';

   printf("\n\nReverse: %s", tmp);

 


/*---------------------------------------ĐỔI CÁC CHỮ IN THƯỜNG THÀNH IN HOA-------------------------------------*/
   for(int i = 0; i < length ; i++)
    {
      if (i == length || i == length - 1) //Xử lý ký tự '\0' bằng cách bỏ qua

      continue;

      if (s1[i] >= 97 && s1[i] <= 122)// VD: 'a' cách 'A' 32 đơn vị theo bảng mã ASCII
      {
         tmp[i] = (s1[i] - 32);//Chuyển đổi từng vị trí theo bảng mã ASCII 
      }
      else tmp[i] = s1[i]; //Trường hợp các ký tự không nằm trong vùng từ 97 đến 122 theo bảng mã ASCII
	}
	printf("\n\nUperCases: %s", tmp);


/*---------------------------------------ĐỔI CÁC CHỮ IN HOA THÀNH IN THƯỜNG-------------------------------------*/
   for(int i = 0; i < length ; i++)
   {
      if (i == length || i == length - 1) //Xử lý ký tự '\0' bằng cách bỏ qua

      continue;

      if (s1[i] >= 65 && s1[i] <= 90)// TVD: 'A' cách 'a' 32 đơn vị theo bảng mã ASCII
      {
         tmp[i] = (s1[i] + 32); //Chuyển đổi từng vị trí theo bảng mã ASCII 
      }
      else tmp[i] = s1[i]; //Trường hợp các ký tự không nằm trong vùng từ 65 đến 90 theo bảng mã ASCII
	}
   printf("\n\nLowerCases: %s", tmp);

   

/*---------------------------------------IN HOA CHỮ CÁI SAU DẤU CHẤM-------------------------------------*/
   int thePeriod; // thepreiod: dấu chấm
   
   for(int i=0; i <= length; i++)
   {  
      if (i == length || i == length - 1) //Xử lý ký tự '\0' bằng cách bỏ qua

      continue;

      if (thePeriod == 1) // Nếu có xuất hiện dấu chấm
      {
         if((s1[i] >= 97 && s1[i] <= 122)) // Kiểm tra có các chữ cái in hoa không
         {
         tmp[i] = (s1[i] - 32); //Chuyển cả chuỗi ký tự về trạng thái in hoa

         thePeriod = 0; // Sau đó gán cho theperiod = 0 <-> không xuất hiện dấu chấm

         continue;// Dùng câu lệnh continue để tiếp tục chương trình
         }
      }
      tmp[i] = s1[i]; // Cho chuỗi tạm thời bằng với chuỗi ban đầu

      if(s1[i] == '.') //kiểm tra chuỗi có xuất hiện dấu chấm không
      {
         tmp[i] = s1[i]; // Cho chuỗi tạm thời bằng với chuỗi ban đầu

         thePeriod = 1; // Cho dấu chấm = 1 <-> dấu chấm được hiển thị trong chuỗi
      }
   }

   printf("\n\nUperAfterPeriod: %s", tmp);

   return 0;

 }
   




