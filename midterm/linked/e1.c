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
    newNode->next = Head;
    Head=newNode;
}
void printList(){
    struct Node *cur =Head;
    while(cur !=NULL){
        printf("%d ",cur->data);
        cur=cur->next;
    }
    printf("\n");
}
int main(){
    Head = NULL;    
    pushFront(10);
    pushFront(20);
    pushFront(30);
    printList(); 
    return 0;
}

