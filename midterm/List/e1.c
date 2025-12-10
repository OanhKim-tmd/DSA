/*Tạo struct ArrayList có:
arr[100]
size
Viết hàm:
    init()
    addLast()
    printList()*/

#include<stdio.h>
struct List{
    int arr[100];
    int size;

};
void init(struct List *l){
    l->size=0;
}
void addLast(struct List*l,int x){
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
    struct List list ;
    init(&list);
    addLast(&list, 10);
    addLast(&list, 20);
    addLast(&list, 30);

    Print(list);
    return 0;
}