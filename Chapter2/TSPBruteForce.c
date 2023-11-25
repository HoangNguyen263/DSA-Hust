#include"stdio.h"
#define N 30
#define INF 1000000
//Dùng duyệt toàn bộ sẽ có (n-1)! phương án tất cả
int n,m;
int c[N][N]; //chi phí
int x[N]; //phương án
int mark[N]; //mảng đánh dấu cho hoán vị
int f; // độ dài hành trình đã đi được và sẽ được update liên tục
int f_min; //độ dài hành trình ngắn nhất tìm thấy

void readData(){
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n;j ++){
            c[i][j] = INF; // không có đường đi trực tiếp từ i đến j
        }
    }

    for (int k = 1; k <= m; k++){
        int i,j,d;
        scanf("%d%d%d",&i,&j,&d);
        c[i][j] = d;
}

}

void updateBest(){
    if (f + c[x[n]][x[1]] < f_min){
        f_min = f + c[x[n]][x[1]];
    }
}

void Try(int k){
    for(int v = 1; v <= n; v++){
        if (mark[v] == 0){
            x[k] = v;
            f = f + c[x[k-1]][x[k]];
            mark[v] = 1; //đánh dấu
            if (k == n) updateBest();
            else Try(k+1);
            //khôi phục trạng thái
            f = f - c[x[k-1]][x[k]];
            mark[v] = 0;
        }
    }
}

int main(){
    readData();
    f = 0;
    for(int v = 1; v <= n; v++) mark[v] = 0;
    x[1] = 1; mark[1]=1;
    f_min = INF;
    Try(2);
    printf("%d",f_min);
}
