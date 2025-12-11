/*/*
🟩 Exercise 2 (9 pts): Convert a String into Reverse Order Using a Stack
Problem Description
A message needs to be reversed for a simple encoding system.
You must reverse a string using a Stack, where each character 
is pushed into the stack and then popped out in reverse order.
Example
Input: " Hello ""
Stack operations:
push(H)
push(e)
push(l)
push(l)
push(o)
pop → o
pop → l
pop → l
pop → e
pop → H
Output:
olleH
Your tasks:
Implement a program in C/C++ that reverses an input string using a stack.
(7 pts)
Required functions:
init(), push(), pop(), isEmpty(), display()
Analyze the time complexity of your operations.
(2 pts)*/
#include<stdio.h>
#define MAX 100
typedef struct{
    char arr[MAX];
    int top;
}Stack;
void init(Stack *s){
    s->top =-1;
}
int isEmpty(Stack *s){
    return s->top==-1;
}
void push (Stack *s,char val){
    if(s->top == MAX-1){
        printf("Stack overflow\n");
        return ;
    }
    s->arr[++(s->top)]=val;
}
int pop (Stack *s){
    if(isEmpty(s)){
        printf("Stack underfloe\n");
        return 0;
    }
    return s->arr[(s->top)--];
}
void display(Stack *s){
    for (int i=s->top;i>=0;i--){
        printf("%c",s->arr[i]);
    }
    printf("\n");
}


int main(){
    Stack s;
    init(&s);
    push(&s,'H');
    push(&s,'e');
    push(&s,'l');
    push(&s,'l');
    push(&s,'o');
    display(&s);
    return 0;
}