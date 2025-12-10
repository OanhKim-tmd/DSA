/*Nhập 5 số nguyên từ bàn phím lưu vào ArrayList, sau đó in ra.
Gợi ý:
dùng addLast()
dùng scanf()*/


#include<stdio.h>

struct List{
    int arr[100];
    int size;
};

void init(struct List *l){
    l->size = 0;
}

void add(struct List *l, int x){
    l->arr[l->size] = x;
    l->size++;
}

void Print(struct List l){
    for(int i = 0; i < l.size; i++){
        printf("%d ", l.arr[i]);
    }
    printf("\n");
}

int main(){
    int n;
    printf("how many numbers? Enter: ");
    scanf("%d", &n);

    struct List list;
    init(&list);

    for(int i = 0; i < n; i++){
        int x;
        printf("Enter number %d: ", i + 1);
        scanf("%d", &x);
        add(&list, x);
    }
    
    printf("List: ");
    Print(list);

    return 0;
}
