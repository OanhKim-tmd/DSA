/*Question 1 (16 pts)
A Harshad number is an integer that is divisible by the sum of its digits.
Example:
- 18/(1+8) = 18/9 = 2, 18 is divisible by 2 → Harshad number.
- 21/(2+1) = 21/3 = 7, divisible → Harshad number.
- 19/(1+9) = 19/10 = 1.919, not divisible → not a Harshad number.
- 274/(2+7+4) = 274/13 = 21.07, not divisible → not a Harshad number.
▪ Implement a program in C/C++ using Iteration to find all Harshad numbers from 1 to n (n is
a natural number). (7pts)
▪ Implement another function using Recursion to complete the above question. (7pts)
▪ Calculate the complexity of your functions or algorithms. Justify the answer (comment
directly in your source files). (2pts) */


// Interation
#include<stdio.h>
int Sum(int n){
    int sum=0;
    while(n>0){
        sum=sum+n%10;       
        n=n/10;
    }
    return sum;

}
void Check(int n,int sum){
    if(sum!=0&&n%sum==0){
        printf("%d\n",n);
    }

}
int main(){
    int n;
    printf("Enter the number n:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int sum = Sum(i);
        Check(i,sum);
    }
    return 0;
}
// O(n)=n.log(n)

//Recursion
#include<stdio.h>
int Sum(int n){
    int sum=0;
    while(n>0){
        sum =sum +n%10;
        n=n/10;
    }
    return sum;
}
int Check(int n){
    int sum=Sum(n);
    if (n==0){
        return 0;
    }
    if(sum!=0 && n%sum==0){
        printf("%d\n",n);
    }
    Check(n-1);
}
int main(){
    int n;
    printf("Enter the number n:");
    scanf("%d",&n);
    Check(n);
    return 0;
}
//O(n)=n.log(n)