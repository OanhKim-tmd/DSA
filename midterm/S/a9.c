/*
Đề bài
Một ứng dụng nhắn tin cần lưu các tin nhắn mới vào hàng chờ (queue).
Mỗi tin nhắn đến sẽ được đưa vào queue, và hệ thống xử lý tin nhắn theo thứ tự FIFO.
Bạn cần viết chương trình C để:
Cài đặt Queue dùng mảng gồm chuỗi ký tự (string).
Cài đặt các hàm:
init() – khởi tạo queue
isEmpty()
isFull()
enqueue() – thêm tin nhắn mới vào queue
dequeue() – lấy tin nhắn cũ nhất ra để “xử lý”
display() – in toàn bộ tin nhắn đang chờ
Yêu cầu chạy chương trình:
Thêm các tin nhắn:
"Hello"
"How are you?"
"I am Oanh!"
Lấy ra 1 tin nhắn và in:
*/

#include<stdio.h>
#include<string.h>
#define MAX 100
typedef struct{
    char arr[MAX][10];
    int front,rear;
}Queue;

void init(Queue *q){
    q->front=0;
    q->rear=-1;
}
int isEmpty(Queue *q){
    return q->front>q->rear;
}
int isFull(Queue *q){
    return q->rear == MAX -1;
}
void enqueue(Queue *q,char msg[]){
    if(isFull(q)){
        printf("Fulll!");
        return ;
    }
    strcpy(q->arr[++(q->rear)],msg);
}
void dequeue(Queue *q,char out[]){
    if(isEmpty(q)){
        printf("Empty!!!!");
        return;
    }
    strcpy(out,q->arr[q->front]);
    q->front++;
}
void Display(Queue *q){
    for(int i = q->front;i<=q->rear;i++){
        printf("%s",q->arr[i]);
    }
    printf("\n");
}

int main(){
    Queue q;
    init(&q);
    enqueue(&q,"Oanh");
    enqueue(&q,"Duong");
    enqueue(&q,"cute");
    enqueue(&q,"qua");
    char msg[50];
    Display(&q);
    return 0;
}
