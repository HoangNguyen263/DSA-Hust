#include<stdio.h>
#include<stdlib.h>

struct Polynom{
	int coeff;
	int exp;
	struct Polynom *next;
};

typedef struct Polynom poly;

poly *poly1 = NULL,*poly2 = NULL;

poly *makenewnode(int coeff, int exp){
	poly *p = (poly*)malloc(sizeof(poly));
	if (p==NULL){
		printf("Error");
		exit(0);
	}
	p->coeff = coeff;
	p->exp = exp;
	p->next = NULL;
}

void display(poly *ptr){
	poly *p = ptr;
	printf("\nCoeff|Exp\n");
	while (p != NULL){
		printf("|%d|%d|-->",p->coeff,p->exp);
		p=p->next;
	}
}

poly *polysum(poly *p1, poly *p2){
	if((p1==NULL)&&(p2==NULL)) return NULL;
    if(p1==NULL) return p2;
    if(p2==NULL) return p1;
	//ptr1, ptr2, ptr la 3 con tro de duyet bieu thuc 1,2 
	//va bieu thuc thu ba bieu thuc 1 + bieu thuc 2
	//polysum la con tro tro vao phan tu dau tien cua bieu thuc tong
	poly *polysum, *ptr, *ptr1, *ptr2;
	polysum = NULL;
	//node la con tro de tao node moi
	poly *node = (poly*)malloc(sizeof(poly));//node dau tien
	node->next = NULL;
	//cho polysum tro vao node dau tien
	polysum = node;
	ptr1 = p1;
	ptr2 = p2;
	while (ptr1 != NULL && ptr2 != NULL){
		//chuyen ptr vao node moi vua tao o vong while
		//truoc
		ptr = node;
		if (ptr1->exp > ptr2->exp){
			node->coeff = ptr2->coeff;
			node->exp = ptr2->exp;
			ptr2 = ptr2->next; //update ptr2
		}
		else if (ptr1->exp < ptr2->exp){
			node->coeff = ptr1->coeff;
			node->exp = ptr1->exp;
			ptr1 = ptr1->next; //upadate ptr1;
		} else {
			node->coeff = ptr1->coeff + ptr2->coeff;
			node->exp = ptr1->exp;
			ptr2 = ptr2->next; //update ptr2
			ptr1 = ptr1->next; //upadate ptr1;
		}
		if((ptr1==NULL)&&(ptr2==NULL)) return polysum;
		//tao node moi va cho node vua tao o tren
		//tro vao node moi
		node = (poly*)malloc(sizeof(poly));
		node->next = NULL;
		ptr->next = node;
	}//end of while
	
	if (ptr1 == NULL){
		//copy nhung thu con o poly2 vao polysum
		while (ptr2 != NULL){
			ptr = node;
			node->coeff = ptr2->coeff;
			node->exp = ptr2->exp;
			ptr2 = ptr2->next;
			if(ptr2==NULL) return polysum;
			node = (poly*)malloc(sizeof(poly));
		    node->next = NULL;
		    ptr->next = node;
		}
	}
	
	if (ptr2 == NULL){
		//copy nhung thu con o poly1 vao polysum
		while (ptr1 != NULL){
			ptr = node;
			node->coeff = ptr1->coeff;
			node->exp = ptr1->exp;
			ptr1 = ptr1->next;
			if(ptr1==NULL) return polysum;
			node = (poly*)malloc(sizeof(poly));
		    node->next = NULL;
		    ptr->next = node;
		}
	}
		
}

int main(){
	poly1 = makenewnode(1,0);
    poly1->next = makenewnode(2,1);
    //poly1->next->next = makenewnode(5,3);
    
    display(poly1);
    
    poly2 = makenewnode(-1,0);
    poly2->next = makenewnode(4,2);
    poly2->next->next = makenewnode(1,3);
    poly2->next->next->next = makenewnode(-6,4);
    
    display(poly2);
    
    poly *psum = polysum(poly1,poly2);
    
    display(psum);
}
