/*Bài 1.9
Cho array [5, 4, 3, 2, 1] đưa toàn bộ vào ArrayList và in ra.
Gợi ý:
int a[5] = {5,4,3,2,1};
for i=0->4 addLast(a[i])*/

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
    for (int i=0;i<l.size;i++){
        printf("%d",l.arr[i]);
    }
}
int main(){
    struct List list;
    init (&list);
    int a[5] = {5,4,3,2,1};
    for(int i=0;i<5;i++){
        int x=a[i];
        add(&list,x);
    }
    Print(list);

    
    return 0;
}