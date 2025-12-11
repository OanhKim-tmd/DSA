/*  
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
// Inplement a main function to test all above position */
#include<stdio.h>
typedef struct FibPair{
    int fn_1; //f(n-1)
    int fn_2; //f(n-2)
}FibPair;
FibPair init(){
    FibPair fp;
    fp.fn_1=1;
    fp.fn_2=0;
    return fp;
}
FibPair calculate(int n){
    if(n==0){
        FibPair base ={0,0};
        return base;
    }
    if(n==1){
        return init();
    }
    FibPair prev =calculate(n-1);
    FibPair current;
    current.fn_1=prev.fn_1+prev.fn_2;
    current.fn_2=prev.fn_1;
    return current;
}
void display(int n){
    FibPair result = calculate(n);
    printf("%d",result.fn_1);
}

int main(){
    int n=5;
    display(n);
    return 0;


}