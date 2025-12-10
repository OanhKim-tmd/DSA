/*Bài 1.5
Viết hàm getSize() trả về số phần tử hiện có.
Test:
thêm 4 phần tử
in size → 4*/
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
void getSize(struct List l){
    printf("%d ",l.size);
}
int main(){
    struct List list;
    init(&list);

    add(&list,5);
    add(&list,7);
    add(&list,6);
    add(&list,9);
    add(&list,1);

    getSize(list);


    return 0;
}