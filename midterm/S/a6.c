#include<stdio.h>
#define MAX 100
typedef struct{
    int arr[MAX];
    int top;

}Stack;
void init(Stack *s){
    s->top= -1;
}
void push(Stack *s,int val){
    s->arr[++(s->top)]=val;
}
int pop(Stack *s){
    return s->arr[(s->top)--];
}
void display(Stack *s){
    for(int i=0;i<=s->top;i++){
        printf("%d",s->arr[i]);
    }
    printf("\n");
}
void reverseNumber(int n){
    Stack s;
    init(&s);
    if(n==0)return ;
    while(n>0){
        push(&s,n%10);
        n=n/10;
    }
    display(&s);

}
int main(){
    int n=12345;
    reverseNumber(n);
    return 0;
}