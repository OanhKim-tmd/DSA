#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char url[100];
    char title[100];
} Website;

typedef struct {
    Website data[MAX];
    int top;
} Stack;

void init(Stack *s) { s->top = -1; }

int isEmpty(Stack *s) { return s->top == -1; }
int isFull(Stack *s) { return s->top == MAX - 1; }

void push(Stack *s, Website w) {
    if (!isFull(s)) s->data[++(s->top)] = w;
}

Website pop(Stack *s) {
    Website empty = {"", ""};
    if (isEmpty(s)) return empty;
    return s->data[(s->top)--];
}

void display(Stack *s) {
    if (isEmpty(s)) { printf("Empty\n"); return; }
    for (int i = s->top; i >= 0; i--)
        printf("Title: %s, URL: %s\n", s->data[i].title, s->data[i].url);
}

int main() {
    Stack Backward, Forward;
    init(&Backward);
    init(&Forward);

    // Giả sử đã truy cập 3 website
    push(&Backward, (Website){"https://google.com", "Google"});
    push(&Backward, (Website){"https://stackoverflow.com", "StackOverflow"});
    push(&Backward, (Website){"https://github.com", "GitHub"});

    printf("Backward stack:\n");
    display(&Backward);
    printf("\nForward stack:\n");
    display(&Forward);

    // Back action: pop Backward -> push Forward
    if (!isEmpty(&Backward)) {
        Website w = pop(&Backward);
        push(&Forward, w);
        printf("\nAfter Back:\nBackward stack:\n");
        display(&Backward);
        printf("Forward stack:\n");
        display(&Forward);
    }

    // Forward action: pop Forward -> push Backward
    if (!isEmpty(&Forward)) {
        Website w = pop(&Forward);
        push(&Backward, w);
        printf("\nAfter Forward:\nBackward stack:\n");
        display(&Backward);
        printf("Forward stack:\n");
        display(&Forward);
    }

    return 0;
}
