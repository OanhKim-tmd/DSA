/*Suppose that we use a List data structure to represent unbounded
integers.
 - the first element refers to the sign: 1 is positive and -1 is negative.
 - each element in the list represents one digit of these integers.
Implement and test the program in C/C++ using an Array-based List (Static or
Dynamic) to manage this unbounded integers:
 - add new digits at any place in an integer.
 - remove a digit at a specfic position in an integer.
 - calculate the sum of all digits from an unbounded integer.
 - display the whole number on the screen.*/


#include <stdio.h>
#include <stdlib.h>

#define CAP 100

typedef struct {
    int size;
    int data[CAP];
} List;

List* init(List *number) {
    number = (List*)malloc(sizeof(List));
    if (number == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    for (int i = 0; i < CAP; i++) {
        number->data[i] = -1;
    }

    number->size = 0;
    return number;
}

// cập nhật size = số phần tử khác -1, tính luôn cả phần tử 0 (sign)
int getLength(List* number) {
    int l = -1;
    for (int i = 0; i < CAP; i++) {
        if (number->data[i] != -1) {
            l = i;
        }
    }
    number->size = l;
    return l;
}

int sum(List* number) {
    int s = 0;
    for (int i = 1; i <= number->size; i++) {
        if (number->data[i] != -1)
            s += number->data[i];
    }
    printf("The sum is %d\n", s);
    return s;
}

void display(List *number) {
    if (number->data[0] == -1)
        printf("-");
    else
        printf("+");

    for (int i = 1; i <= number->size; i++) {
        if (number->data[i] != -1)
            printf("%d", number->data[i]);
        else
            printf("_");
    }
    printf("\n");
}

void add(List *number, int target, int value) {
    if (target < 0 || target >= CAP) {
        printf("Invalid target index!\n");
        return;
    }

    if (target == 0) { 
        // phần sign
        if (value != 1 && value != -1) {
            printf("Invalid sign! Must be 1 or -1.\n");
            return;
        }
    } else {
        if (value < 0 || value > 9) {
            printf("Invalid digit! Must be 0..9.\n");
            return;
        }
    }

    number->data[target] = value;
    getLength(number);
}

void removeDigit(List *number, int target) {
    if (target < 0 || target >= CAP) {
        printf("Invalid index!\n");
        return;
    }
    number->data[target] = -1;
    getLength(number);
}

int main() {
    List* number = init(NULL);

    // Ví dụ thêm số 2467
    add(number, 0, 1);  // sign +
    add(number, 1, 2);
    add(number, 2, 4);
    add(number, 3, 6);
    add(number, 4, 7);

    // Lỗi: digit 11 không hợp lệ
    add(number, 5, 11);

    display(number);
    sum(number);

    // Ví dụ xóa
    removeDigit(number, 3);
    display(number);

    free(number);
    return 0;
}
