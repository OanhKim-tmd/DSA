/*/* Exercise 1 (9 pts): Convert Decimal to Octal Using a Stack
Problem Description
In this problem, we want to convert a decimal number into octal (base 😎.
We repeatedly divide the number by 8 and store the remainders.
Example
125 / 8 = 15, remainder 5
15  / 8 = 1,  remainder 7
1   / 8 = 0,  remainder 1
The result is 175.
Your tasks:
Implement a program in C/C++ to solve the problem using a Stack data structure.
(7 pts)
You must implement the functions:
init(), isEmpty(), push(), pop(), and display().
Analyze the complexity of your functions and justify your answer.
(2 pts)*/

#include<stdio.h>
#define MAX 100
typedef struct{
    int arr[MAX];
    int top;
}Stack;
void init(Stack *s){
    s->top=-1;
}
int isEmpty(Stack *s){
    return s->top==-1;
}
void push (Stack *s,int val){
    if(s->top==MAX-1){
        printf("Stack overflow\n");
        return;
    }
    s->arr[++(s->top)]=val;
}
int pop(Stack *s){
    if(isEmpty(s)){
        printf("Stack underflow\n");
        return;
    }
    return s->arr[(s->top)--];
}
int display(Stack *s){
    for(int i=s->top;i>=0;i--){
        printf("%d",s->arr[i]);
    }
    printf("\n");
}
int Cal(int n){
    Stack s;
    init(&s);
    if(n==0){
        return 0;
    }
    while(n>0){
        push(&s,n%8);
        n=n/8;
    }
    display(&s);
}
int main(){
    int n=125;
    Cal(n);
    return 0;
}