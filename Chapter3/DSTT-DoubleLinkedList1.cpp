#include<stdio.h>
#include<stdlib.h>

struct dnode{
	int data;
	struct dnode *prev;
	struct dnode *next;
};

typedef struct dnode dnode;

dnode *head = NULL, *tail = NULL;

dnode *makeNode(int x){
	dnode *p = (dnode*)malloc(sizeof(dnode));
	//check if heap is full
	if (p == NULL) exit(0);
	p->data = x;
	p->prev = NULL;
	p->next = NULL;
	
	return p;
}

dnode* locate(int x){
	dnode *p = head;
	while(p != NULL){
		if (p->data == x) return p;
		p = p->next;
	}
}

void printList(){
	dnode *p = head;
	while (p != NULL){
		printf("%d ",p->data);
		p = p->next;
	}
}

void removeNode(dnode *p){
	if (head == NULL) exit(0);
	else{
		if (p == head){
			head = head->next;
			free(p);
		} 
		//delete head node
		else if (p == head){
			head = head->next;
			head->prev = NULL;
			free(p);
		}
		//delete last node
		else if (p == tail){
			p->prev->next = NULL;
			tail = tail->prev;
			free(p);
		}
		//if double linked listed has only 1 node
		else if (head == tail && p == head){
			head == NULL;
			tail == NULL;
			free(p);
		}
		else{
			p->prev->next = p->next;
			p->next->prev = p->prev;
		} 
		}
	}
	
void insertLast(int x){
	dnode *t = makeNode(x);
	if (head == NULL && tail == NULL){
		head = t;
		tail = t;
	} else{
		t->prev = tail;
		tail->next = t;
		tail = t;
	}
}

void insertAfter(dnode *q, int x){
	dnode *t = makeNode(x);
	if (head == NULL && q == head){
		head == t;
		tail == t;
	} else if (q == tail){
		insertLast(x);
	}
	else{
		t->next = q->next;
		q->next->prev = t;
		q->next = t;
	}
}

int sum(dnode *h){
	int sum = 0;
	if (h == NULL) return sum;
	dnode *p = h;
	while (p != NULL){
		printf("\n%d\n",p->data);
		sum += p->data;
		p = p->next;
	}
	return sum;
}

int main(){
	dnode *p;
	for (int i = 1; i <= 10; i++){
		dnode *t = makeNode(i);
		if (i == 1){
			head = t;
			tail = t;
			p = t;
		} else {
			p->next = t;
			t->prev = p;
			p = t;
			tail = t;
		}
	}
	dnode *temp;
	temp = locate(5);
	//removeNode(temp);
	//insertAfter(temp,100);
	printf("\n%d\n",sum(head));
	printList();
}
