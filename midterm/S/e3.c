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
