/*Bài 1 (11 điểm): Đệ quy tính tổng các phần tử trong linked list

Cho danh sách liên kết đơn (singly linked list) lưu các số nguyên.

Yêu cầu:

Cài đặt struct Node với trường data và next.

Viết hàm insertLast() để thêm phần tử vào cuối danh sách.

Viết hàm đệ quy sumList() tính tổng tất cả các phần tử trong danh sách.

Viết hàm main() để:

tạo danh sách,

thêm 5 số nguyên tùy ý,

gọi sumList() và in ra tổng.*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
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
int sumList(Node* head) {
    if (head == NULL) {
        return 0;
    }
    return head->data + sumList(head->next);
}
int main() {
    Node* head = NULL;
    head = insertLast(head, 5);
    head = insertLast(head, 10);
    head = insertLast(head, 15);
    head = insertLast(head, 20);
    head = insertLast(head, 25);
    int total = sumList(head);
    printf("Sum of list elements: %d\n", total);
    return 0;
}   
/*
Time complexity of sumList(): O(n) — where n is the number of nodes in the list, as we visit each node exactly once.
Space complexity of sumList(): O(n) — due to the recursion stack, which can go as deep as the number of nodes in the list.
*/