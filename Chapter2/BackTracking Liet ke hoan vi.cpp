#include<stdio.h>

int x[100], n = 3, j = 5;

void solution(){
	for (int i = 1; i <= n; i++){
		printf("%d",x[i]);
	}
	printf("\n");
}

int checkUCV(int v, int k){
	if (x[k-1] < v)
	return 1;
	return 0;
}

void Try(int k){
	for (int v = 1; v <= j; v++){
		if (checkUCV(v,k)){
			x[k] = v;
			if (k == n) solution();
			else Try(k+1);
		}
	}
}

int main(){
	Try(1);
}
