/*Tạo danh sách gồm các phần tử:
5, 15, 25*/
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
void Print(struct List l){
    for(int i=0;i<l.size;i++){
        printf("%d ",l.arr[i]);
    }
    printf("\n");
}
int main(){
    struct List list;
    init(&list);
    add(&list,5);
    add(&list,15);
    add(&list,25);
    Print(list);
    return 0;
}