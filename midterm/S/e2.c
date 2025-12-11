/*in this problem, we want to convert a decimal number to binary:
// 13/2=6 (r = 1)
// 6/2 = 3 (r = 0)
// 3/2 = 1 (r = 1)
// 1/2 = 0 (r = 1)
// The result is 1101
// Write C++ program using a Stack data structure 
// (use init(), display(), push(), pop()). Analyze the complexity*/

#include <stdio.h>
#define MAX 100
typedef struct {
    int arr[MAX];
    int top;
} Stack;
void init(Stack *s) {
    s->top = -1;
} 
void push(Stack *s, int x) {
    s->arr[++s->top] = x;
}
int pop(Stack *s) {
    return s->arr[s->top--];            
}
void display(Stack s) {
    while (s.top != -1) {
        printf("%d", pop(&s));
    }
}
int main() {
    int n = 13;
    Stack s;
    init(&s);   
    while (n > 0) {
        push(&s, n % 2);
        n /= 2;
    }
    printf("Binary: ");
    display(s);
    return 0;
}




