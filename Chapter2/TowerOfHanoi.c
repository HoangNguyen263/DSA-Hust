#include<stdio.h>
void TOH(int n, char A, char B, char C){
    if (n == 1){
        printf("Move 1 disk from %c to %c\n",A,C);
    } else {
        TOH(n-1,A,C,B);
        TOH(1,A,B,C);
        TOH(n-1,B,A,C);
    }
}

int main(){
    TOH(3,'A','B','C');
}