#include<stdio.h>
#include<stdlib.h>

struct Stack{
	char data;
	struct Stack *next;
};
typedef struct Stack Stack;
Stack *top = NULL;

Stack *makenewnode(char x){
	Stack *t = (Stack*)malloc(sizeof(Stack));
	if (t == NULL) {
	printf("Error");
	exit(0);
}
	t->data = x;
	t->next = NULL;
	return t;
}

void push(char x){
	Stack *t = makenewnode(x);
	if (t == NULL) printf("Stack is full");
	else{
		t->next = top;
		top = t;
	}
}
char pop(){
	Stack *t = (Stack*)malloc(sizeof(Stack));
	if (top == NULL){
		printf("Stack is empty");
		exit(0);
	} else{
		t = top;
		char x = t->data;
		top = top->next;
		free(t);
		return x;
	}
}

void display(Stack *s){
	Stack *t = s;
	printf("Top-->");
	while (t != NULL){
		printf("%c",t->data);
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

int match(char a, char b){
	if (a == '(' && b == ')') return 1;
	if (a == '[' && b == ']') return 1;
	if (a == '{' && b == '}') return 1;
	return 0;
}

int solve(char *x, int n){
	for (int i = 0; i < n; i++){
		if (x[i] == '(' || x[i] == '[' || x[i] == '{'){
			push(x[i]);
		} else{
			if (top == NULL) return 0;
			else {
				char c = pop();
				if (match(c,x[i]) == 0)
				return 0;
			}
		}
	}
	if (top != NULL) return 0;
	return 1;
}

int main(){
	
	//char x[6]={'[','{','(',')','}',']'};
	//printf("%d\n",solve(x,7));
	
	char x[4]={'k','h','o','a'};
	for (int i = 0; i < 4; i++){
		push(x[i]);
	}
	display(top);
}
