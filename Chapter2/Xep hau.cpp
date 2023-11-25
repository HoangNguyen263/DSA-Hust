#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define MAX 100

int x[MAX], n;//x[i] là cột của quân hậu xếp trên hàng i

void solution(){
	for(int i = 1; i <= n; i++){
		printf("%d ",x[i]);
	}
	printf("\n");
}

int check(int v, int k){
	for (int i = 1; i < k; i++){
		//kiem tra xem 2 cot co trung nhau ko x[i] != x[j] 
		if (v==x[i]) return 0;
		//kiem tra duong cheo co trung nhau ko |x[i] - x[j]| != |i-j|
		if (abs(v-x[i])==abs(k-i)) return 0; // x[k] = v => |x[i] - v| != |i-k|
	}
	return 1;
}

void Try(int k){
	for (int v = 1; v <= n; v++){
		if (check(v,k)){
			x[k] = v;
			if (k==n) solution();
			else Try(k+1);
		}
	}
}

int main(){
	n=8;
	Try(1);
	return 1;
}
