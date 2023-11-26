#include<stdio.h>
#define N 100
//Sử dụng tham lam 3
typedef struct Segment{
    int a,b;
}Segment;

Segment s[N];
int n;
int res;//số đoạn tìm được

void input(){
    scanf("%d",&n);
    for (int i = 1; i <= n; i++){
        scanf("%d%d",&s[i].a,&s[i].b);
    }
}

void solve(){
    //sắp xếp các đoạn theo thứ tự không giảm của s[i].b
    for (int i = 1; i <= n-1; i++){
        for (int j = i+1; j <= n; j++){
            if(s[i].b > s[j].b){
                Segment temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    int last = -1000000; //toạ độ b của đoạn cuối cùng được lựa chọn
    res = 0;
    for (int i = 1; i <= n; i++){
        //check đoạn s[i] được lựa chọn có giao với đoạn được chọn ở bước trước không
        //s[i].a > last => KHông giao
        if (s[i].a > last){
            res += 1;
            last = s[i].b;
            printf("Select segment %d: %d, %d\n",i,s[i].a,s[i].b);
        }
        
    }
    printf("%d",res);

}

int main(){
    input();
    solve();
    return 0;
}