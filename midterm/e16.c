/*Problem:
In this problem, we would like to perform a prime factorization of a given natural number N:
N = 120 = 2 * 2 * 2 * 3 * 5;
N = 84 = 2 * 2 * 3 * 7
Question 1: (12 pts)
▪ Write a pseudo-code to implement the factorization using Recursion (combined with
iteration if necessary). (3 pts)
▪ Implement the proposed pseudo-code using C/C++. (7 pts)
▪ Calculate the complexity of your program (Best scenario, Worst scenario, Average). Justify
your answer. (2 pts)*/
#include<stdio.h>
void Prime(int n){
    if(n<=1){
        return ;
    }else{
        for(int i=2;i<=n;i++){
            if(n%i==0){
                printf("%d ",i);
                Prime(n/i);
                return ;
            }
        }
    }
}
int main(){
   
    Prime(84);
    return 0;
}