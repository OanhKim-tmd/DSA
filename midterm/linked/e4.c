/*
Đề bài:
Viết chương trình C dùng Linked List đơn để:
Thêm phần tử vào cuối danh sách (InsertLast).
Sau khi thêm ba số: 5, 15, 25, hãy in danh sách ra màn hình.
Cuối cùng, tính và in giá trị tổng các phần tử có trong danh sách.
Yêu cầu:
Không dùng struct List, chỉ dùng Node* head.
Phải có các hàm sau:
Node* initNode(int x)
void InsertLast(Node** head, int x)
void Print(Node* head)
int Sum(Node* head)*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* initNode(int x) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = x;
    p->next = NULL;
    return p;
}

// Thêm vào cuối danh sách
void InsertLast(Node** head, int x) {
    Node* p = initNode(x);
    if (*head == NULL) {       
        *head = p;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = p;
}
// dau danh sach
void InsertFirst(Node** head,int x){
    Node*q = initNode(x);
    q->next=*head;
    *head=q;
}
void Print(Node* head) {
    Node* p = head;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int Sum(Node* head) {
    int s = 0;
    Node* p = head;
    while (p != NULL) {
        s += p->data;
        p = p->next;
    }
    return s;
}
int main() {
    Node* head = NULL;

    InsertLast(&head, 5);
    InsertLast(&head, 15);
    InsertLast(&head, 25);

    Print(head);

    printf("Sum = %d\n", Sum(head));

    return 0;
}
