/*Bài 2 (9 điểm): Kiểm tra chuỗi có cân bằng dấu ngoặc dùng stack

Cho một chuỗi chỉ gồm các ký tự '(' và ')'.

Yêu cầu:

Cài đặt stack dùng mảng hoặc linked list với các hàm init(), push(), pop(), isEmpty().

Viết hàm isBalanced() sử dụng stack để kiểm tra chuỗi dấu ngoặc có cân bằng hay không.

Viết hàm main() để nhập chuỗi từ người dùng, gọi hàm kiểm tra và in "YES" nếu cân bằng, "NO" nếu không.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct {
    char arr[MAX];
    int top;
} Stack;
void init(Stack *s) {
    s->top = -1;
}
int isEmpty(Stack *s) {
    return s->top == -1;
}
void push(Stack *s, char x) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    s->arr[++s->top] = x;
}
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return '\0';
    }
    return s->arr[s->top--];
}
int isBalanced(const char* str) {
    Stack s;
    init(&s);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == '(') {
            push(&s, str[i]);
        } else if (str[i] == ')') {
            if (isEmpty(&s)) {
                return 0; // Not balanced
            }
            pop(&s);
        }
    }
    return isEmpty(&s); // Balanced if stack is empty
}
int main() {
    char str[MAX];
    printf("Enter a string of parentheses: ");
    scanf("%s", str);
    if (isBalanced(str)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
/*
Time complexity of isBalanced(): O(n) — where n is the length of the string,
as we traverse the string once.
Space complexity of isBalanced(): O(n) — in the worst case, all opening parentheses
are pushed onto the stack.
*/
