/*Bài 1.6
Viết hàm clearList() làm list rỗng trở lại.
Test:*/

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
int clearList(struct List *l){
    l->size =0;//chỉ cần set array lít về 0 là nó tự óa hết hàm 
}
void Print(struct List l){
    for(int i=0;i<l.size;i++){
        printf("%d",l.arr[i]);
    }
}
int main(){
    struct List list;
    init(&list);

    add(&list,5);
    add(&list,7);
    add(&list,6);
    add(&list,9);
    add(&list,1);

    clearList(&list);
    Print(list);

    
   
    return 0;
}