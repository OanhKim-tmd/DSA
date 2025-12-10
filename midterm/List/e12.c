/*Bài 4 (Vừa)
Viết hàm:
void removeLast();*/

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
void removeLast(struct List *l){
    l->size = l->size -1 ;
}
void Print(struct List l){
    for(int i=0;i<l.size;i++){
        printf("%d ",l.arr[i]);
    }
}
int main(){
    struct List list;
    init(&list);
    add(&list,1);
    add(&list,2);
    add(&list,3);
    add(&list,4);
    add(&list,5);
    removeLast(&list);
    Print(list);
    return 0;
}