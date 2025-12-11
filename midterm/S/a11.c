/*BÀI TẬP QUEUE — MÔ PHỎNG NGƯỜI XẾP HÀNG MUA VÉ

Đề bài:
Một quầy bán vé chỉ phục vụ tối đa MAX = 5 khách trong hàng chờ (Queue).
Mỗi khách được gán một ID kiểu số nguyên.
Yêu cầu:
Cài đặt Queue dạng mảng vòng gồm các hàm:
init()
isEmpty()
isFull()
enqueue()
dequeue()
display()
Trong hàm main:
5 khách đầu tiên đến: 11, 22, 33, 44, 55
Quầy phục vụ 2 khách (dequeue)
Sau đó có 3 khách mới đến: 66, 77, 88
In hàng chờ hiện tại*/
#include<stdio.h>

#define MAX 5
typedef struct{
    int arr[MAX];
    int front;
    int rear;
}Queue;
void init(Queue *q){
    q->front=0;
    q->rear=-1;
}
int isEmpty(Queue *q){
    return q->front>q->rear;
}
int isFull(Queue *q){
    return q->rear==MAX-1;
}
void enqueue(Queue *q,int val){
    if(isFull(q)){
        printf("Queue full!");
        return;
    }
    strcpy(q->arr[++(q->rear)],val);
}
void dequeue(Queue *q,int val){
    if(isEmpty(q)){
        printf("no msg");
        return ;
    }
    strcpy(out,q->arr[q->front]);
    q->front++;
}
void display(Queue *q){
    for(int i = q->front;i<=q->rear;i++){
        printf("%d",q->arr[i]);
    }
}
int main(){
    Queue q;
    init(&q);
    enqueue(&q,11);
    enqueue(&q,12);
    enqueue(&q,13);
    enqueue(&q,14);
    display(&q);
    return 0;
}