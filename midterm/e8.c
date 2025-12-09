/*Initialize a random array of your choice. The current goal is to verify whether an array number is
pentagonal,
Note: a pentagonal number is calculated by the following formula:
f(n)=(3n^2-n)/2
Write pseudo-code using Recursion (if necessary, Iteration) to check all values in the given
array are pentagonal or not. (2pts)
Write a program in C/C++ to complete your proposed algorithm in the pseudo-code. (8pts).
Note: The program must include a recursive function and the main function.
Calculate the complexity of your algorithm. Justify the answer. (2pts) |
*/
#include<stdio.h>
int Oanh(int j,int flag,int arr[]){
    if(j>=6){
        return 0;
    }
    for(int n=0;n<=arr[j];n++){
        int temp = (n*(3*n-1))/2;
        if(temp==arr[j]){
            printf("%d is Yes\n",arr[j]);
            flag ++;
        } 
    }
    if(flag==0){
        printf("%d is No\n",arr[j]);
    }
    flag=0;
    Oanh(j+1,flag,arr);
}
int main(){
    int flag =0;
    int arr[6]={1, 7, 12, 22, 35, 51};
    Oanh(0,flag,arr);
}
// O(n)=n^2