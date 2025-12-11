/*Problem 1 (11 pts): Recursively Reverse a Singly Linked List

Cho một danh sách liên kết đơn (singly linked list) chứa các số nguyên.

Tasks:

Cài đặt struct Node cho linked list với các trường data và next.

Viết hàm initList() để tạo danh sách rỗng.

Viết hàm đệ quy reverseList() để đảo ngược danh sách liên kết.

Viết hàm displayList() để in danh sách liên kết.

Viết hàm insertLast() để thêm phần tử vào cuối danh sách.

Viết hàm main() để:

khởi tạo danh sách,

thêm 5 số nguyên tùy ý,

in danh sách,

đảo ngược danh sách bằng đệ quy,

in lại danh sách đã đảo ngược.*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* initList() {
    return NULL;
}
Node* insertLast(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        return newNode;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}
Node* reverseList(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* rest = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}
void displayList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
int main() {
    Node* head = initList();
    head = insertLast(head, 10);
    head = insertLast(head, 20);
    head = insertLast(head, 30);
    head = insertLast(head, 40);
    head = insertLast(head, 50);
    printf("Original List:\n");
    displayList(head);
    head = reverseList(head);
    printf("Reversed List:\n");
    displayList(head);
    return 0;
}
/*
Time Complexity:
- insertLast(): O(n) — traverses the list to find the end.
- reverseList(): O(n) — each node is visited once during the recursion.
- displayList(): O(n) — traverses the list to print each element.
Overall, the main operations are linear in relation to the number of nodes in the list.