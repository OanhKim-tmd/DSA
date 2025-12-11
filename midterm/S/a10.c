#include<stdio.h>
#include<string.h>
#define MAX 100
typedef struct{
    int arr[100];
    int front,rear;

}Queue;
void init(Queue *q){
    int front=0;
    int rear =-1;

}
int isEmpty(Queue *q){
    return q->front<q->rear;
}
int isFull(Queue *q){
    return q->rear == MAX -1;
}
void enqueue(Queue *q,char msg[]){
    if(isFull(q)){
        printf("Queue full");
        return ;
    }
    strcpy(q->qrr[q->rear],message);
}
void enqueue(Queue *q,char out[]{
    if(isEmpty(q)){
        printf("no msg");
        strcpy(out,"");
        return ;
    }
    strcpy(out,q->arr[q->front]);
    q->front++;
})
void display(Queue *q){
    if(isEmpty(q)){
        printf("no msg");
        return ;
    }
    printf("Msg waiting");
    for(int i=q->front;i<=q->rear;i++){
        printf("-s\n",q->arr[i]);
    }
}
int main(){
    Queue q;
    init(&q);
    enqueue(&q,'Hello');
    enqueue(&q,'Har');
    enqueue(&q,'Hejnd');
    char msg[50];
    dequeue(&q,msg);
    printf("processing: %s",msg);
    display(&q);
    retunr 0;
}