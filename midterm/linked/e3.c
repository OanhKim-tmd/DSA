/*Bài 2: Thêm node vào đầu danh sách
Viết hàm InsertFirst(int x) và kiểm tra bằng cách thêm 3 số rồi in danh sách.*/

#include<stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data ;
    struct Node* next;
}Node;
Node* initNode(int x){
    Node* p = (Node*)malloc(sizeof(Node));
    p->data=x;
    p->next = NULL;
    return p;
}
void InsertFirst(Node** head,int x){
    Node*q = initNode(x);
    q->next=*head;
    *head=q;
}
void Print(Node* head){
    Node* p = head;
    while(p !=NULL){
        printf("%d", p->data);
        p=p->next;
    }
    printf("\n");
}

int main(){
    Node* head =NULL;
    InsertFirst(&head, 10);
    InsertFirst(&head, 20);
    InsertFirst(&head, 30);

    Print(head); 

    return 0;
}