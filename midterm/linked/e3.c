/*Bài 2: Thêm node vào đầu danh sách
Viết hàm InsertFirst(int x) và kiểm tra bằng cách thêm 3 số rồi in danh sách.*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *pnext;
} Node;
typedef struct List{
    int size;
    Node *pHead;
} List;
void init(List *l){
    l->size = 0;
    l->pHead = NULL;
}
Node* initNode(int val){
    Node *node = (Node*)malloc(sizeof *node);
    node->data = val;
    node->pnext = NULL;
    return node;
}
int isEmpty(List* l){
    return (l->size == 0);
}
void InsertFirst(List *l, int x){
    Node *p = initNode(x);
    p->pnext = l->pHead;
    l->pHead = p;
    l->size++;
}
void Print(List *l){
    Node *p = l->pHead;
    while(p != NULL){
        printf("%d ", p->data);
        p = p->pnext;
    }
    printf("\n");
}
int main(){
    List L;
    init(&L);

    InsertFirst(&L, 10);
    InsertFirst(&L, 20);
    InsertFirst(&L, 30);

    Print(&L);

    return 0;
}
