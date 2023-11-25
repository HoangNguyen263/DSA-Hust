#include<stdio.h>
#define MAX 1000000
int a[MAX];

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void display(int a[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}


//Hàm vun lại đống để thoả mãn tính chất max heap: chọn nút con lớn nhất, đổi chỗ nút con này 
//và a[i] nếu nút con này lớn hơn a[i] và vun lại đống từ nút con này
void heapify(int a[], int i, int N){
    int L = 2 * i;
    int R = 2 * i + 1;
    int max = i;
    if (L <= N && a[L] > a[max]) max = L;
    if (R <= N && a[R] > a[max]) max = R;
    if (max != i){
        swap(&a[i],&a[max]);
        heapify(a,max,N-1);
    }
}

/*Hàm sắp xếp vun đống:
- Xây dựng max heap (hàm buildHeap)
- Đổi chỗ a[0] ch0 a[n-1]
- Vun lại đống từ a[0] tới a[n-2]
- Đổi chỗ a[0] cho a[n-2]
- Vun lại đống từ a[0] tới a[n-3]
.......
*/
void buildHeap(int a[],int N){
    //vun các nút từ dưới lên
    for (int i = N/2; i >= 0; i--)
    heapify(a,i,N-1);
}

void heapSort(int a[],int N){
    buildHeap(a,N-1);
    for (int i = N-1; i > 0; i--){
        swap(&a[0],&a[i]);
        heapify(a,0,i-1);
    }
}

int main(){
    int a[9] = {8,4,2,7,6,9,11,19,5};
    display(a,9);
    heapSort(a,9);
    display(a,9);

}