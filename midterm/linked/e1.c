#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *Head =NULL;
void pushFront(int x){
    struct Node *newNode =(struct Node*)malloc(sizeof(struct Node));
    newNode->data =x ;
    newNode->next = head;
    head=newNode;
}