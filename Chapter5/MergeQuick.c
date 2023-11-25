#include<stdio.h>

void display(int a[],int size){
    for (int i = 0; i < size; i++){
        printf("%d ",a[i]);
    }
}

/*Merge Sort: Dựa trên Divde and Conquer
TRộn 2 dãy đã được sắp xếp thành 1 dãy đã được sắp xếp
*/
void merge(int a[],int L,int M, int R){
    int i = L, j = M+1; //i dùng để duyệt dãy bên trái, j để duyệt dãy bên phải
    int temp[1000];
    for (int k = L; k <= R; k++){
        if (j > R){
            temp[k] = a[i]; i++; //nếu j vượt quá R thì copy các thành phần còn lại của dãy i vào temp[]
        } 
        else if (i > M){
            temp[k] = a[j]; j++;// nếu i vượt quá M thì copy các thành phần còn lại của dãy j vào temp[]
        } 
        else{
            if (a[i] < a[j]){
                temp[k] = a[i]; i++;
            } else {
                temp[k] = a[j]; j++;
            }
        }
    }
    for (int k = L; k <= R; k++) a[k] = temp[k];
}

void mergeSort(int a[], int L, int R){
    if (L < R){
        int M = (L + R) / 2;
        mergeSort(a,L,M);//T(n/2)
        mergeSort(a,M+1,R);//T(n/2)
        merge(a,L,M,R);//O(n)
    }
} //T(n) = 2T(n/2) + O(n) => Theo định lý thợ O(nlogn)

/*Quick Sort*/
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[],int L, int R){
    int i = L, j = R + 1;
    int pivot = a[L];
    while (i < j){
        //from left to right,find the first element that >= pivot
        i =  i + 1;
        while (i <= R && a[i] < pivot) i++;
        //from right to left, find the first element that <= pivot
        j = j - 1;
        while (j >= L && a[j] > pivot) j--;
        if (i >= j) break;
        swap(&a[i],&a[j]);
    }
    
    swap(&a[j],&a[L]); //pivot is sorted at index j
    return j; // trả lại j là vị trí để chia mảng thành 2 phần: phần bên trái <= pivot, bên phải >= pivot
}

void quickSort(int a[],int L, int R){
    int index_pivot;
    if (L < R){
        index_pivot = partition(a,L,R);
        quickSort(a,L,index_pivot - 1);
        quickSort(a,index_pivot+1,R);
    }
}

int main(){
    int a[10] = {3,4,9,12,20,1,2,8,10,15};
    printf("Before sort: ");
    display(a,10);
    printf("\n");
    //mergeSort(a,0,9);
    //printf("After Merge Sort: ");
    quickSort(a,0,9);
    printf("After Quick Sort: ");
    display(a,10);
}