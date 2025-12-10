/*Bài 6 (Khá)
Viết hàm
void insertAt(int index, int x);
Ví dụ:
Input:
[10 20 30]
insertAt(1, 99)
Output:
10 99 20 30*/
#include<stdio.h>
struct List{
    int arr[100];
    int size;
};
void init(struct List *l){
    l->size=0;
}
void add(struct List *l,int x){
    l->arr[l->size]=x;
    l->size++;
}
void insertAt(struct List *l,int x,int y){
    l->size=l->size+1;
    for(int i=l->size;i>y;i--){
        l->arr[i]=l->arr[i-1];
    }
    l->arr[y]=x;
}
void Print(struct List l){
    for(int i=0;i<l.size;i++){
        printf("%d ",l.arr[i]);
    }
}
int main(){
    struct List list;
    init(&list);
    add(&list,10);
    add(&list,20);
    add(&list,30);
    insertAt(&list,90,1);
    Print(list);


    return 0;
}