/*Problem 2 (9 pts): Queue Implementation Using Linked List for Parentheses Checking

Cho một chuỗi chứa các ký tự '(' và ')'.

Tasks:

Cài đặt một queue bằng linked list, với các hàm:

initQueue()

enqueue()

dequeue()

isEmpty()

displayQueue()

Viết hàm isBalanced() sử dụng queue đã cài để kiểm tra xem chuỗi có dấu ngoặc đơn cân bằng hay không (có thể dùng queue để lưu các dấu ngoặc mở, khi gặp dấu đóng sẽ dequeue).

Viết hàm main() để nhập chuỗi, dùng hàm trên kiểm tra và in kết quả "Balanced" hoặc "Not Balanced".*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    char data;
    struct Node* next;
} Node;
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;
void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}
int isEmpty(Queue* q) {
    return q->front == NULL;
}
void enqueue(Queue* q, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }   
    q->rear->next = newNode;
    q->rear = newNode;
}
char dequeue(Queue* q) {
    if (isEmpty(q)) {
        return '\0';
    }
    Node* temp = q->front;
    char data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}
int isBalanced(const char* str) {
    Queue q;
    initQueue(&q);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            enqueue(&q, '(');
        } else if (str[i] == ')') {
            if (isEmpty(&q)) {
                return 0; // Not balanced
            }
            dequeue(&q);
        }
    }
    return isEmpty(&q); // Balanced if queue is empty
}
int main() {
    const char* str = "(()())";
    if (isBalanced(str)) {  
        printf("Balanced\n");
    } else {
        printf("Not Balanced\n");
    }
    return 0;
}
/*
Time complexity:
- enqueue(): O(1) — adding an element to the rear of the queue takes constant time.
- dequeue(): O(1) — removing an element from the front of the queue also takes constant time.
- isBalanced(): O(n) — where n is the length of the input
    */