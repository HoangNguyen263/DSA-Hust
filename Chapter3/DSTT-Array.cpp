#include<stdio.h>

struct Array{
	int size;
	int length;
	int a[10];
};

typedef struct Array Array;

void Display(Array arr){
	printf("Size of array: %d\nLength of array: %d",arr.size,arr.length);
	printf("\nAll elements of array: \n");
	for (int i = 0; i < arr.length; i++){
		printf("%d ",arr.a[i]);
	}
}

void Insert(Array *arr,int x, int p){
	if (p >= 0 && p <= arr->length){
		for (int i = arr->length; i >= (p+1); i--){
			arr->a[i] = arr->a[i-1];
		}
		arr->a[p] = x;
		arr->length++;
	}
}

void makeNull(Array *arr){
	arr->length = 0;
}


void Delete(Array *arr, int p){
	if (p >= 0 && p < arr->length){
		for (int i = p; i < arr->length; i++){
			arr->a[i] = arr->a[i+1];
		}
		arr->length--;
	}
}

int Retrieve(Array arr, int p){
	if (p >= 0 && p < arr.length){
		return arr.a[p];
	}
}

int Locate(Array arr, int x){
	for (int i = 0; i < arr.length; i++){
		if (arr.a[i] == x) return i;
	}
	return -1;
}

void Reverse(Array *arr){
	int i,j;
	for (i  = 0, j = arr->length - 1; i < j; i++,j--){
		int temp;
		temp = arr->a[i];
		arr->a[i] = arr->a[j];
		arr->a[j] = temp;
	}
}

int main(){
	struct Array arr = {10,5,{2,3,4,5,6}};
	printf("\n*********Insert*********\n");
	Insert(&arr,10,2);
	Display(arr);
	
	/*printf("\n*********Delete*********\n");
	Delete(&arr,2);
	Display(arr);
	
	printf("\n*********Retrieve*********\n");
	printf("%d",Retrieve(arr,2));
	
	printf("\n*********Locate*********\n");
	printf("%d",Locate(arr,4));
	
	//printf("\n*********MakeNULL*********\n");
	//makeNull(&arr);
	//Display(arr);
	
	printf("\n*********Reverse*********\n");
	Reverse(&arr);
	Display(arr);*/
	
}
