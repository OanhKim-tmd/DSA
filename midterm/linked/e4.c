/*Bài 3: Đếm số node trong Linked List
Viết hàm CountNodes() trả về số lượng node hiện có.*/
#include<stdio.h>
typedef struct Node{
    int data;
    struct Node* pnext;
}node;
typedef struct List{
    int size;
    struct Node* pHead;
}List;
void init(List *l){
    l->size=0;
    l->pHead=NULL;
}
int main(){
    
    return 0;
}