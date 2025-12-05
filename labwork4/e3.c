/*We want to implement a program in C/C++ to calculate approximately the number
Pi, a real constant, π = 3.14159265358979323846. One of the Pi formulas is as
follows:
π = 4/1 - 4/3 + 4/5 -4/7 + ... + 4/(4n+1) - 4/(4n+3) 

where n is a natural number.
When n = 10, pi 3.0962410; When n = 100, pi 3.13659310; When n = 1000, pi
3.14109110; When n = 10000, pi 3.14138410;
Write a function using Recursion with the input n to calculate pi. Another
parameters can be used in the function input. Write a main function to test
implemented functions.
 Calculate the complexity of your algorithm. Justify the answer.*/


#include<stdio.h>

double Recursion(int k,int n, double pi){
    if(k>n){
        return pi;
    }
    pi = pi + (4.0f/(4*k+1))- (4.0f/(4*k+3));
    return Recursion(k+1,n,pi);
    
}
int main(){
    int n;
    printf("Enter the number n: ");
    scanf("%d",&n);
    printf("Pi = :%.7f",Recursion(0,n,0.0));
    return 0;
}
//Calculate the complexity of your algorithm : O(n)
