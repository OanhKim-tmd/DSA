/*Bài 3 (Vừa)
Viết hàm:
int search(int x);
→ trả về index tìm thấy, nếu không có trả về -1.*/

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
int search(struct List l,int y){
    for(int i=0;i<l.size;i++){
        int x=l.arr[i];
        if(y==x){
            return i;
        }
    }
    return -1;
}

int main(){
    struct List list;
    init(&list);
    add(&list,1);
    add(&list,2);
    add(&list,3);
    add(&list,4);
    add(&list,5);
    printf("%d",search(list,5));
    return 0;
}