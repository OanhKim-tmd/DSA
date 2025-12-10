/*Bài 1.7
Viết hàm isEmpty(), trả về:
1 nếu list trống
0 nếu có phần tử*/

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
int isEmpty(struct List *l){
    return l->size==0;

}
int main(){
    struct List list;
    init (&list);
    add(&list,5);
    add(&list,7);
    add(&list,6);
    add(&list,9);
    add(&list,1);
    printf("%d",isEmpty(&list));
    return 0;
}