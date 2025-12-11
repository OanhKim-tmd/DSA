
/*Bài 4: Tìm một giá trị trong danh sách

Viết hàm Search(int x) trả về:

1 nếu tồn tại

0 nếu không*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Hàm tìm kiếm giá trị trong danh sách liên kết
int Search(Node* head, int x) {
    Node* current = head;
    
    while (current != NULL) {
        if (current->data == x) {
            return 1;  // Found
        }
        current = current->next;
    }
    
    return 0;  // Not found
}

// Hàm thêm node vào cuối danh sách
void Push(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Hàm giải phóng bộ nhớ
void FreeList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    Push(&head, 10);
    Push(&head, 20);
    Push(&head, 30);
    Push(&head, 40);
    Push(&head, 50);
    printf("Tìm 30: %s\n", Search(head, 30) ? "Tồn tại" : "Không tồn tại");
    printf("Tìm 25: %s\n", Search(head, 25) ? "Tồn tại" : "Không tồn tại");
    printf("Tìm 10: %s\n", Search(head, 10) ? "Tồn tại" : "Không tồn tại");
    FreeList(head);
    
    return 0;
}