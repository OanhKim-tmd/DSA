/*Bài 7: Xóa node cuối cùng

Viết hàm DeleteLast()

Kiểm tra danh sách còn 1 phần tử thì head=NULL*/
#incl
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
