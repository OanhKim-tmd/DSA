/*
Exercise 1 : In this problem, we would like to implement the algorithm to calculate the digit sum of a given natural number that can be used in detecting errors
in message transmission or data storage.
For example:
N = 103509, the digit sum = 1 + 0 + 3 + 5 + 0 + 9 = 18.
N = 9512, the digit sum = 9 + 5 + 1 + 2 = 17
 Write a pseudo-code to solve the above problem using Iteration.
 Write a program from the pseudo-code and solve the Problem using Iteration.
 Calculate the complexity. Justify your answer.
 Write a program to solve the Problem using Recursion (with Iteration if
necessary).
 Calculate the complexity. Justify your answer.
*/


// Pesudo-code to solve the above problem using Interation.

/*
Step 1: Enter n and sum = 0
Step 2: int m=n%10
Step 3: sum=sum+m
Step 4: n=n/10
Step 5: if n>0 , go to the step 2 
Step 6: printf sum
*/

// Using Iteration
#include <stdio.h>
int main(){
    int n,sum = 0 ;
    printf("Enter the number n: ");
    scanf("%d",&n);
    while(n>0){
        int m = n % 10;
        sum=sum+m;
        n=n/10;
    }
    printf("The digit sum is: %d \n ",sum);
}
// Calculate the complexity : O(Log n)

// Using Recusion
#include <stdio.h>
int Sum(int n){
    if(n==0){
        return 0;
    }
    return (n%10)+Sum(n/10);
}
int main(){
    int n,sum=0;
    printf("enter the number n:");
    scanf("%d",&n);
    printf("The digit sum is: %d\n", Sum(n));
}
//Caculate the complexity : O(Log n)

