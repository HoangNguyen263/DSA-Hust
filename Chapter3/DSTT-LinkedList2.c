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
	printf("\n");
}

Node *locate(Node *h, int x){
	Node *p = h;
	while (p != NULL){
		if (p->data == x) return p;
		p = p->next;
	}
	return NULL;
}

//Delete
void deleteHead(){
	Node *t = head;
	head = t->next;
	free(t);
}

void deleteLast(Node *h){
	Node *p = h;
	while (p->next->next != NULL) {
		p = p->next;
	}
	Node *t = p->next;
	p->next = NULL;
	free(t);
}

void deleteAt(Node *h, Node *p){
	if (p == h) deleteHead();
	else {
		Node *t = h;
		while (t->next != p){
			t = t->next;
		}
		t->next = p->next;
		free(p);

	}
}

int isEmpty(Node *h){
	if (h == NULL) return 1;
	else return 0;
}

void deleteList(){
	if (isEmpty(head)) exit(1);
	else {
		Node *p = head;
		while(p != NULL){
			head = head->next;
			free(p);
			p = head;

		}
		printf("\nComplete\n");
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
	
	printf("\n ***DeleteHead*** \n");
	deleteHead();
	printList(head);
	printf("\n ***DeleteLast*** \n");
	deleteLast(head);
	printList(head);
	printf("\n ***DeleteAt*** \n");
	temp = locate(head,51);
	deleteAt(head,temp);
	printList(head);
	printf("\n ***DeleteList*** \n");
	deleteList();
	printList(head);
}