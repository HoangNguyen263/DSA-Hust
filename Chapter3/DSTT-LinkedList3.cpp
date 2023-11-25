#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};

typedef struct Node Node;

Node *head = NULL;

Node *makeNode(int x){
	Node *t = (Node*)malloc(sizeof(Node));
	if (t == NULL){
		printf("Heap is full");
		exit(0);
	}
	t->data = x;
	t->next = NULL;
	return t;
}

void printList(Node *h){
	Node *p = h;
	while (p != NULL){
		printf("%d ",p->data);
		p = p->next;
	}
}

//sum
int sum(Node *h){
	int sum = 0;
	Node *p = h;
	while (p != NULL){
		sum += p->data;
		p = p->next;
	}
	return sum;
}

int sumRecur(Node *h){
	if (h == NULL) return 0;
	else return h->data + sumRecur(h->next);
}

//Reverse using slide pointers r,p,q
void reverse(){
	Node *p,*q,*r;
	p = head;
	q = r = NULL;
	while (p != NULL){
		//slide
		r = q;
		q = p;
		p = p->next;
		//reverse
		q->next = r;
	}
	head = q;
	
}

int main(){
	Node *p,*temp;
	for (int i = 1; i <= 5; i++){
		Node *t = makeNode(i);
		if (i == 1){
			head = t;
			p = head;
		} else {
			p->next = t;
			p = t;
		}
	}
	
	printList(head);
	printf("\n%d\n",sum(head));
	reverse();
	printList(head);
	
}

