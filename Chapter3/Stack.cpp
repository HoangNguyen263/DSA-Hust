#include<stdio.h>
#include<stdlib.h>

struct Stack{
	int data;
	struct Stack *next;
};
typedef struct Stack Stack;
Stack *top = NULL;

Stack *makenewnode(int x){
	Stack *t = (Stack*)malloc(sizeof(Stack));
	if (t == NULL) {
	printf("Error");
	exit(0);
}
	t->data = x;
	t->next = NULL;
	return t;
}

void push(int x){
	Stack *t = makenewnode(x);
	if (t == NULL) printf("Stack is full");
	else{
		t->next = top;
		top = t;
	}
}

void pop(){
	Stack *t = (Stack*)malloc(sizeof(Stack));
	if (top == NULL){
		printf("Stack is empty");
		exit(0);
	} else{
		t = top;
		top = top->next;
		free(t);
	}
}

void display(Stack *s){
	Stack *t = s;
	printf("Top-->");
	while (t != NULL){
		printf("|%d|-->",t->data);
		t = t->next;
	}
	
}

void stackDestroy(){
	Stack *t = top;
	while(t != NULL){
		top = t->next;
		free(t);
		t = top;
	}
}

int main(){
	for (int i = 1; i <= 5; i++){
		push(i);
	}
	//pop();
	//display(top);
	stackDestroy();
	display(top);
}
