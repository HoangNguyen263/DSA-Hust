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

//Search
Node *findLast(Node *h){
	Node *p  = h;
	if (p == NULL) printf("List Empty");
	while (p->next != NULL){
		p = p->next;
	}
	return p;
}

Node *locate(Node *h, int x){
	Node *p = h;
	while (p != NULL){
		if (p->data == x) return p;
		p = p->next;
	}
	return NULL;
}

Node *prev(Node *h, Node *p){
	Node *t = h;
	while (t->next != p){
		t = t->next;
	}
	return t;
}

//Insert
void insertHead1(Node **h, int x){
	Node *t = makeNode(x);
	t->next = *h;
	*h = t;
}

void insertHead2(int x){
	Node *t = makeNode(x);
	t->next = head;
	head = t;
}

void insertLast(Node *p,int x){
	Node *t = makeNode(x);
	if (t == NULL) printf("full");
	while (p->next != NULL){
		p = p->next;
	}
	p->next = t;
}

void insertPrev(Node *h,Node *q, int x){
	Node *t = makeNode(x);
	Node * p = h;
	if (q == head) insertHead1(&head,x);
	else {
		while (p->next != q){
		p = p->next;
	}
	t->next = p->next;
	p->next = t;
	}
}

void insertAfter(Node *q, int x){
	Node *t = makeNode(x);
	Node * p = head;
	if (head == NULL) {
		head = t;
	} else {
		while (p != q){
		p = p->next;
	}
	t->next = q->next;
	q->next = t;
	}
	
}

int main(){
	Node *p,*temp;
	for (int i = 1; i <= 100; i++){
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
	
	printf("\n");
	printf("%d ",findLast(head)->data);
	
	printf("\n");
	temp = locate(head,98);
	printf("%d ",prev(head,temp)->data);
	
	printf("\n***Insert***\n");
	printf("\nAfter InsertHead ");
	insertHead1(&head,1001);
	//insertHead2(1001);
	printList(head);
	printf("\nAfter InsertLast ");
	insertLast(head,10);
	printList(head);
	printf("\nAfter InsertPrev ");
	temp = locate(head,10);
	insertPrev(head,temp,5);
	printList(head);
	printf("\nAfter InsertAfter ");
	temp = locate(head,1);
	insertAfter(temp,5);
	printList(head);
	
	
}


