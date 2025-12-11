/*Bài 1: Tạo một danh sách liên kết rỗng
Viết chương trình khai báo node, khai báo head = NULL, sau đó in ra thông báo “List is empty”.*/
#include<stdio.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* Head=NULL;

int main(){
    if(Head==NULL){
        printf("List is empty\n");
    }else{
        printf("List is not empty\n");
    }
    return 0;
}