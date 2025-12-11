/*Question 1 — (16 pts)

A Happy number is defined as follows:
Take any positive integer, replace the number by the sum of the squares of its digits, and repeat.
If the process eventually reaches 1, the number is happy; otherwise, it loops endlessly and is not happy.

Examples:
19 → 1²+9² = 82 → 8²+2² = 68 → 6²+8² = 100 → 1 → Happy
4 → 4² = 16 → 1²+6² = 37 → 3²+7² = 58 → 5²+8² = 89 → … loops → Not happy
Tasks:
▪ Write a C/C++ program using Iteration to determine whether a number is a Happy number. (7 pts)
▪ Write another version using Recursion. (7 pts)
▪ Analyze and justify the time complexity of both algorithms (comment in code). (2 pts)*/

#include<stdio.h>

int Double(int n){
    if(n==1){
        return 1;
    }
    if(n==4){
        return 0;
    }
    int sum=0;
    while(n>0){
        int k = n%10;
        sum = sum + k * k;
        n=n/10;
    }
    return Double(sum);
}
int main(){
    int n=7;
    if(Double(n)){
        printf("Happy");
    }else{
        printf("not Happy");
    }
    return 0;
}