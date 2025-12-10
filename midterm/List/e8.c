/*/*Bài 1.8

Viết hàm printReverse() in list theo thứ tự ngược.

Ví dụ:

10 20 30 -> 30 20 10*/

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
void printReverse(struct List l){
    for(int i=l.size-1;i>=0;i--){
        printf("%d",l.arr[i]);
    }
}
int main(){
    struct List list;
    init (&list);
    add(&list,5);
    add(&list,7);
    add(&list,6);
    add(&list,9);
    add(&list,1);
    printReverse(list);
    return 0;
}