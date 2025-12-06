/*Question 2: (6 pts)
In this context, we try to find co-prime numbers using at least a recursive function.
 Implement the recursive function (2 pts).
 Write a program to solve the above Problem using the recursive function (4 pts)
*/

#include<stdio.h>
int Num2(int i,int j){
    if(j>=10){
        return 0;
    }
    Check(arr[i],arr[j],2);
    Num2(i,j+1);
}

int Check(int i,int j,int k){
    if(k>i){
        return 0;
    }
    if(i>j){
        int temp =i;
        i=j;
        j=temp;
    }
    if(j%k==0&&i%k==0){  
        Check(int i;int j;k+1);
    }
    printf("(%d, %d)",i,j);
    Check(int i;int j;k+1);
}
int main(){
    int arr[10]={2,10,27,13,90,45,5,26,49,50};
    for(int i=0;i<9;i++){
        Num2(arr[i],arr[i+1];)
    }
    return 0;
}