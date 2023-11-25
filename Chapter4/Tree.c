#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
    char data;
    struct TreeNode *lmostchild; //trỏ đến nút con trái nhất
    struct TreeNode *rsibling;//trỏ đến nút anh em bên phải
} TreeNode;

TreeNode *root;

TreeNode *makenewnode(char x){
    TreeNode *p = (TreeNode*)malloc(sizeof(TreeNode));
    if (p == NULL){
        printf("Error");
        exit(0);
    }
    p->data = x;
    p->lmostchild = NULL;
    p->rsibling = NULL;
    return p;
}

TreeNode *find(TreeNode *r, char id){
    if (r == NULL) return NULL;
    if (r->data == id) return r;
    //không tìm thấy ở gốc thì ta sẽ tìm ở nút còn lại, bắt đầu từ nút con trái nhất
    TreeNode *p = r->lmostchild;
    while (p != NULL){
        TreeNode *q = find(p,id);
        if (q != NULL) return q; //q khác null tức là đã tìm thấy q
        p = p->rsibling;
    }
    return NULL; //trả lại NULL nếu ko tìm thấy
}


//preOrder: visit(node),preOrder(left subtree),preOrder(right subtree)
void preOrder(TreeNode *r){
    if (r == NULL) return;
    printf("%c ",r->data);
    TreeNode *p = r->lmostchild;
    while (p != NULL){
        preOrder(p);
        p = p->rsibling;
    }
}

//postOrder: post(left subtree),post(right subtree),visit(root)
void postOrder(TreeNode *r){
    if (r == NULL) return;
    TreeNode *p = r->lmostchild;
    while (p != NULL){
        postOrder(p);
        p = p->rsibling;
    }
    printf("%c ",r->data);
}

//inOrder:in(left subtree), visit(root), in(right subtree)
void inOrder(TreeNode *r){
    if (r == NULL) return;
    TreeNode *p = r->lmostchild;
    inOrder(p);
    printf("%c ",r->data);

    if (p != NULL) p = p->rsibling;
    while (p != NULL){
        inOrder(p);
        p = p->rsibling;
    }
}

//hàm đếm số nút trên cây
int count(TreeNode *r){
    if (r == NULL) return 0;
    
    int c = 1;
    TreeNode *p = r->lmostchild;
    while (p != NULL){
        c += count(p);
        p=p->rsibling;
    }
    return c;
}

//hàm đếm số lá của cây
int countleaves(TreeNode *r){
    if (r == NULL) return 0;

    TreeNode *p = r->lmostchild;
    if (p == NULL) return 1; //nếu cây chỉ có 1 nút, gốc ko có nút con

    int c = 0;
    while (p != NULL){
        c += countleaves(p);
        p = p->rsibling;
    }
    return c;
}

//độ cao của 1 nút = độ dài đường đi lớn nhât từ nút đó đến nút lá + 1
int heightNode(TreeNode *r){
    if (r == NULL) return 0;
    int maxh = 0;

    for(TreeNode *p = r->lmostchild; p != NULL; p = p->rsibling){
        int h = heightNode(p);
        if (h > maxh) maxh = h;
    }
    return maxh + 1;
}

int height(char v){
    //trả lại độ cao của nút có giá trị v
    TreeNode *t = find(root,v);
    return heightNode(t);
}

//độ sâu của 1 nút = độ dài đường đi từ gốc đến nút đó + 1
int depthNode(char v,TreeNode *r,int d){
    //d là độ sâu của r trên cây gốc root
    if (r == NULL) return -1; //v không tồn tại trên cây gốc r
    if (r->data == v) return d;
    for (TreeNode *p = r->lmostchild; p!= NULL; p = p->rsibling){
        if (p->data ==v) return d+1;
        int rs = depthNode(v,p,d+1);//độ sâu root->r = d thì từ root->p = d+1
        if (rs>-1) return rs;
    }
    return -1;
}

int depth(int v){
    return depthNode(v,root,1);
}

//tìm cha của 1 nút
TreeNode *parent(TreeNode *p, TreeNode *r){
    if (r == NULL) return NULL;
    TreeNode *child = r->lmostchild;
    if (child == p) return r;

    while (child != NULL){
        TreeNode *t = parent(p,child);
        if (t != NULL) return t;
        child = child->rsibling;
    }
    return NULL;
}

int main(){
    TreeNode *root=NULL;
	TreeNode *nutA, *nutB, *nutC, *nutD, *nutE, *nutF, *nutG, *nutH, *nutI, *nutJ, *nutK;
	nutA = makenewnode('A');
	nutB = makenewnode('B');
	nutC = makenewnode('C');
	nutD = makenewnode('D');
	nutE = makenewnode('E');
	nutF = makenewnode('F');
	nutG = makenewnode('G');
	nutH = makenewnode('H');
	nutI = makenewnode('I');
	nutJ = makenewnode('J');
	nutK = makenewnode('K');

    nutA->lmostchild= nutB;
	
	nutB->lmostchild = nutE;
	nutB->rsibling = nutC;
	
	nutC->lmostchild = nutG;
	nutC->rsibling = nutD;
	
	nutE->rsibling = nutF;
	
	nutG->lmostchild= nutH;
	
	nutH->rsibling = nutI;
	nutI->rsibling = nutJ;
	nutJ->rsibling = nutK;
	
	root = nutA;

    preOrder(root);
}