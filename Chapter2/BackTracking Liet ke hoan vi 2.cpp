#include<stdio.h>

#define MAX 100

int x[MAX], n = 8;

void solution(){
	for (int i = 1; i <= n; i++){
		printf("%d",x[i]);
	}
	printf("\n");
}

//mang de danh dau xem v da xuat hien truoc do chua
int m[] = {0};

int Try(int k){
	for (int v = 1; v <= n; v++){
		if (!m[v]){
			x[k] = v;
			m[v] = 1;//danh dau
			if (k == n) solution();
			else Try(k+1);
			m[v] = 0;//khoi phuc
		}
	}
}

int main(){
	Try(1);
}
