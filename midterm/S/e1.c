


    
// }
// The fibonacci sequence is defined as: 0, 1, 1, 2, 3
// Using the conventional recersive definision: f(n) = f(n - 1) + f(n - 2),
//  the complexity is O(2^n) due to the binary recursive calls. 
// In this problem, we aim to improve the computing the fibonacci number at
//  position n by using the following structure
// struct FibPair{
//      int fn_1; //f(n-1)
//      int fn_2; //f(n-2)
// };
//Your tasks are to
//Implement the necessary function in C/C++
// +) init() initialize the first two fibo value
// +) calculate() recursively computes the fibonacci number at position n 
// using the fibpair structure and only one recursive call
// +) display() prints the fibonacci number at a at a given _POSIX_CLOCK_SELECTION
// Inplement a main function to test all above position

#include <stdio.h>

typedef struct {
    int fn_1; //f(n-1)
    int fn_2; //f(n-2)
} FirPair;

FirPair init() {
    FirPair n = {1, 0};
    return n;
}

int calculate(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    FirPair pair = init();
    int current = 0;
    for (int i = 2; i <= n; i++) {
        current = pair.fn_1 + pair.fn_2;
        pair.fn_2 = pair.fn_1;
        pair.fn_1 = current;
    }
    return pair.fn_1;
}
/* 
 calculate():
 Time complexity: O(n) — the loop runs from 2 to n performing O(1) work per iteration.
 Space complexity: O(1) — uses a constant amount of extra space.
*/

void display(int n) {
    printf("Fibonacci at f(%d): %d\n", n, calculate(n));
}

int main() {
    int n = 5;
    display(n);
    return 0;
}