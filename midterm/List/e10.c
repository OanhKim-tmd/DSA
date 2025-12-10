/*Bài 1.10
Cho người dùng nhập số n, sau đó nhập n phần tử vào list rồi in ra tổng.
Ví dụ:
Input:
5
1 2 3 4 5
Output:
15*/

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
int Sum(struct List l){
    int sum =0;
    for(int i=0;i<l.size;i++){
        sum=sum+l.arr[i];
    }
    return sum;
}
int main(){
    struct List list;
    init(&list);
    add(&list,1);
    add(&list,2);
    add(&list,3);
    add(&list,4);
    add(&list,5);
    printf("%d",Sum(list));
    return 0;
}