/*Bài toán tháp Hà Nội
• Có n đĩa với kích thước khác nhau và 3 cọc A, B, C
• Ban đầu n đĩa nằm ở cọc A theo thứ tự đĩa nhỏ nằm
trên và đĩa lớn nằm dưới
• Tìm cách chuyển n đĩa này từ cọc A sang cọc C, sử
dụng cọc B làm trung gian Lời giải theo nguyên tắc 
    • Mỗi lần chỉ được chuyển 1 đĩa trên cùng từ 1 cọc sang 
      cọc khác 
    • Không được phép để xảy ra tình trạng đĩa to nằm bên
      trên đĩa nhỏ
*/
#include<stdio.h>
void TOH(int n, char A, char B, char C){
    if (n == 1){
        printf("Move 1 disk from %c to %c\n",A,C);
    } else {
        TOH(n-1,A,C,B);
        TOH(1,A,B,C);
        TOH(n-1,B,A,C);
    }
}

int main(){
    TOH(3,'A','B','C');
}