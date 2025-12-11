/*Đề bài:
Viết chương trình C để cài đặt Queue bằng Linked List và thực hiện:
Thêm 2 số vào queue: 10, 20
Lấy ra 1 số từ queue
In ra số vừa lấy được*/
#include <stdio.h>
#include <stdlib.h> 
typedef struct Node {
    int data;
    struct Node* next;
} Node;
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;
void init(Queue* q) {
    q->front = q->rear = NULL;
}
int isEmpty(Queue* q) {
    return q->front == NULL;
}
void enqueue(Queue* q, int data) {
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
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}
int main() {
    Queue q;
    init(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    int value = dequeue(&q);
    printf("Dequeued: %d\n", value);
    return 0;}
/*
Time complexity:
- Enqueue: O(1) — adding an element to the rear of the queue takes constant time.
- Dequeue: O(1) — removing an element from the front of the queue also takes constant time.
Space complexity:
- O(n) — where n is the number of elements in the queue, as each element is stored in a node of the linked list.
*/