/*in this problem, we want to convert a decimal number to binary:
// 13/2=6 (r = 1)
// 6/2 = 3 (r = 0)
// 3/2 = 1 (r = 1)
// 1/2 = 0 (r = 1)
// The result is 1101
// Write C program using a Stack data structure 
// (use init(), display(), push(), pop()). Analyze the complexity*/
#include<stdio.h>
#define MAX 100
typedef struct{
    int arr[MAX];
    int top;
}Stack;
void init(Stack *s){
    s->top=-1;
}
void push(Stack *s, int val){
    s->arr[++(s->top)]=val;
}
int pop(Stack *s){
    return s->arr[(s->top)--];
}
void display(Stack *s){
    for(int i =s->top;i>=0;i--){
        printf("%d",s->arr[i]);
    }
    printf("\n");
}
int calculate(int n){
    Stack s;
    init(&s);
    if(n==0){
        return 0;
    }
    while(n>0){
        push(&s,n%2);
        n=n/2;
    }
    display(&s);
}
int main(){
    calculate(13);

    return 0;
}