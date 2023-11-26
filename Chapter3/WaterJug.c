#include<stdio.h>
#include<stdlib.h>

typedef struct QueueNode{
    int x,y;
    struct QueueNode *next;//con trỏ đến phần tử tiếp theo trong queue
    struct QueueNode *parent; //con trỏ trỏ đến trạng thái sinh ra trạng thái hiện tại
}Node;

Node *head,*tail;
Node *start; //trạng thái ban đầu
Node *target;//trạng thái kết thúc thoả mãn yêu cầu
int visited[1000][1000];
int a,b,c;


Node *makenode(int x, int y, Node *par){
    Node *p =(Node*)malloc(sizeof(Node));
    p->x = x;
    p->y = y;
    p->next = NULL;
    p->parent = par;
    return p;
}

void enqueue(Node *s){
    if (head == NULL && tail == NULL){
        head = s;
        tail = s;
        return;
    }
    tail->next = s;
    tail = s;

}

Node* dequeue(){
    Node *r = head;
    head = head->next;
    if (head = NULL) tail = NULL; //Khi hàng đợi còn duy nhất 1 phần tử
    return r;

}

int isEmpty(){
    if (head == NULL && tail == NULL) return 1;
    return 0;

}

int checkFinal(Node *s){
    if (s->x == c || s->y == c || s->x + s->y == c){
        return 1;
    } else return 0;
}

void solve(){
    for (int i = 0; i < 1000; i++){
        for (int j = 0; j < 1000; j++){
            visited[i][j] = 0;
        }
    }
    head = NULL;
    tail = NULL;
    start = makenode(0,0,NULL);
    enqueue(start);
    visited[0][0] = 1;
    target = NULL;
    while(!isEmpty()){
        Node *s = dequeue(); //trạng thái hiện tại s->,s->y
        Node *ns = NULL; //trạng thái tiếp theo

        //đổ đầy bình 1 (a,s->y)
        if (visited[a][s->y] == 0){
            ns = makenode(a,s->y,s);
            if (checkFinal(ns)) {target = ns; break;}
            enqueue(ns); //đưa trạng thái mới vào hàng đợi
            visited[ns->x][ns->y] = 1; //đánh dấu trạng thái được sinh ra
        }

        //đổ đầy bình 2 (s->x,b)
        if (visited[s->x][b] == 0){
            ns = makenode(s->x,b,s);
            if (checkFinal(ns)) {target = ns; break;}
            enqueue(ns); //đưa trạng thái mới vào hàng đợi
            visited[ns->x][ns->y] = 1; //đánh dấu trạng thái được sinh ra
        }

        //đổ hết bình 1 ra ngoài (0,y)
        if (visited[0][s->y] == 0){
            ns = makenode(0,s->y,s);
            if (checkFinal(ns)) {target = ns; break;}
            enqueue(ns); //đưa trạng thái mới vào hàng đợi
            visited[ns->x][ns->y] = 1; //đánh dấu trạng thái được sinh ra
        }

        //đổ hết bình 2 ra ngoài (x,0)
        if (visited[s->x][0] == 0){
            ns = makenode(s->x,0,s);
            if (checkFinal(ns)) {target = ns; break;}
            enqueue(ns); //đưa trạng thái mới vào hàng đợi
            visited[ns->x][ns->y] = 1; //đánh dấu trạng thái được sinh ra
        }

        //đổ nước từ bình 1 sang 2 
        int nx,ny;
        if (s->x + s-> y >= b){
                nx = s->x + s->y - b;
                ny = b;
        }
        else if (s->x + s->y <= b){
                nx = 0; 
                ny = s->x + s->y;
        }
        if (visited[nx][ny] == 0){
            ns = makenode(nx,ny,s);
            if (checkFinal(ns)) {target = ns; break;}
            enqueue(ns); //đưa trạng thái mới vào hàng đợi
            visited[ns->x][ns->y] = 1; //đánh dấu trạng thái được sinh ra
        }

        //đổ nước từ bình 2 sang 1 
        if (s->x + s-> y >= a){
                ny = s->x + s->y - a;
                nx = a;
        }
        else if (s->x + s->y <= a){
                ny = 0; 
                nx = s->x + s->y;
            }
        if (visited[nx][ny] == 0){
            ns = makenode(nx,ny,s);
            if (checkFinal(ns)) {target = ns; break;}
            enqueue(ns); //đưa trạng thái mới vào hàng đợi
            visited[ns->x][ns->y] = 1; //đánh dấu trạng thái được sinh ra
        }
        
        if (target == NULL) printf("Not found");
        else{
            Node *s = target;
            while (s != NULL){
                printf("(%d,%d)",s->x,s->y);
                s = s->parent;
            }
        }
    }
}

int main(){
    a=6;
    b=8;
    c=4;
    solve();

}
