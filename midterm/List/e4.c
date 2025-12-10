/*Bài 1.3
Viết hàm getAt(index), trả về giá trị tại index.
Test trong main:
thêm 3 phần tử
gọi getAt(0), getAt(2)*/

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
int getAt(struct List l,int index){
    return l.arr[index];
}


int main(){
    struct List list;
    init(&list);

    add(&list,5);
    add(&list,8);
    add(&list,9);

    printf("%d ",getAt(list,0));
    printf("%d ",getAt(list,2));
    return 0;
}