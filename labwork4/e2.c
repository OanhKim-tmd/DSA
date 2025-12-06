/*Exercise 2 :
Write a program in C/C++ to enter a natural number n and find all sphenic numbers
from 1 to n using Recursion. Calculate the complexity of the proposed algorithm.
Note: A sphenic number is a product of p*q*r where p, q, and r are three distinct
prime numbers. Example: 30 = 2 * 3* 5; 42 = 2*3*7; 66 = 2*3*11
*/

#include <stdio.h>
int Prime(int n){
    if(n<2){
        return 0;
    }
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return 0;
        };
    }
    return 1;
}
int Sphenic(int n){
    int count=0;
    for(int i=2;i<n;i++){
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
        printf("%d\n",j);
    }
    Sphenicrecursion(n,j+1);
}
int main(){
    int n;
    printf("Enter the number n: ");
    scanf("%d",&n);
    Sphenicrecursion(n,1);
    
}




