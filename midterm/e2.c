/*Problem 1: (10 pts)
 Write a program to enter a natural number n and find all sphenic numbers from 1 to n using
Recursion (combined with iteration if necessary).
Note: A sphenic number is a product of p*q*r where p, q, and r are three distinct prime numbers.
Example: 30 = 2 * 3* 5; 42 = 2*3*7; 66 = 2*3*11.
30, 42, 66, 70, 78, 102, 105, 110, 114, 130, 138, 154, 165, … are sphenic numbers.
 Calculate the complexity of your program (Best scenario, Worst scenario, Average). Justify your
answer. (2pts)*/


#include <stdio.h>
int Prime(int n){
    if(n<2){
        return 0;               // 1
    }
    for(int i=2;i*i<=n;i++){
        if(n%i==0){             // căn n
            return 0;
        };
    }
    return 1;
}
int Sphenic(int n){
    int count=0;
    for(int i=2;i<=n;i++){
        if(n%i==0&&Prime(i)&&(n/i)%i!=0){ 
            count++;
        }
    }
    return count ==3 ;
}
void Sphenicrecursion(int n,int j){
    if(j>n){
        return;
    }
    if(Sphenic(j)){
        printf("%d\n",j);       // n^2 . căn n
    }
    Sphenicrecursion(n,j+1);
}
int main(){
    int n;
    printf("Enter the number n: ");
    scanf("%d",&n);
    Sphenicrecursion(n,1);
    
}
