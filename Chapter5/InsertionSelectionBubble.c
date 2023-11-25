#include<stdio.h>

void display(int a[],int size){
    for (int i = 0; i < size; i++){
        printf("%d ",a[i]);
    }
}

/*Insertion Sort: chia mảng kích thước n ban đầu thành 2 phần sorted và unsorted
- Tại mỗi bước lặp sẽ chuyển từ phần đầu tiên của unsorted sang sorted và chèn
- Ở bước lặp k(k = 1,2,...n-1): liên tục đổi chỗ phần tử k với phần tử ngay trước chừng nảo
phần tử k còn nhỏ hơn phần tử đó
- Dùng k để duyệt mảng ban đầu, pos để duyệt phần sorted của mảng
*/
void insertionSort(int a[], int size){
    for (int k = 1; k < size; k++){
        int temp = a[k];
        int pos = k;
        while (pos > 0 && a[pos-1] > temp){
            a[pos] = a[pos-1];
            pos--;
        }
        a[pos] = temp; //chèn temp (=a[k) vào đúng vị trí
    }
}

/*Selection Sort: chia mảng kích thước n thành 2 phần sorted và unsorted
- Tại mỗi bước lặp, tìm phần tử nhỏ nhất của unsorted và đổi chỗ với phần tử đầu tiên của 
unsorted
- Bước lặp i (i = 0,1,...n-2): tìm phần tử đầu tiên của unsorted trong dãy a[i] đến a[n-1] rồi
chuyển lên vị trí i
*/
void swap(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(int a[], int size){
    for(int i = 0; i < size - 1; i++){
        int index_min = i;
        for (int j = i+1; j < size; j++){
            if(a[j] < a[index_min]) index_min = j;
        }
        swap(&a[i],&a[index_min]);
    }
}

/*Bubble Sort: cho mảng kích thước n
- Tối đa n-1 bước lặp
- Bước i (i=1,2,...n-1) bubble phần tử có giá trị lớn nhất trong a[0] đến a[n-i] về vị trí n-i
- Thuật toán kết thúc khi nó nhận ra mảng đã sắp xếp xong(không còn phép hoán đổi nào được 
thực hiện
*/
void bubbleSort(int a[], int n){
    int sorted = 0; //ghi nhận không có phép hoán đổi nào được thực hiện
    for (int i = 1; i <= n - 1; i++){
        printf("\n%d %d\n",i,sorted);
        if (sorted == 0){
            sorted = 1;
            for (int j = 0; j <= n - i; j++){
            if (a[j] > a[j+1]){
                swap(&a[j],&a[j+1]);
                sorted = 0; //đã thực hiện hoán đổi
                printf("\n");
                display(a,n);
                printf("%d\n",sorted);
            }
        }
        }
        
    }
}

int main(){
    int a[6] = {23,78,45,8,32,56};
    printf("/************************/");
    printf("\nBefore Sort: ");
    display(a,6);
    printf("\n");


    //insertionSort(a,6);
    //printf("/************************/");
    //printf("\nAfter Insertion Sort: ");
    //display(a,6);

    //selectionSort(a,6);
    //printf("/************************/");
    //printf("\nAfter Selection Sort: ");
    //display(a,6);

    int b[8] = {9,6,2,12,11,9,3,7};
    bubbleSort(b,8);
    printf("/************************/");
    printf("\nAfter Bubble Sort: ");
    display(b,8);
}