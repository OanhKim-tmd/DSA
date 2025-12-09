/*Problem:
Given an array of nautral numbers as following: 4, 15, 45, 9, 40, 27, 3, 5, 10.
In this problem, we try to find all triplets (a, b, c) where a number is the product of two other
numbers in the array i.e. a = b*c; or b = a*c; or c = a*b.
The expect outcome of the above array is: {(15, 3, 5}, (45, 9, 5), (4, 40, 10), (9, 27, 3), (15, 45,
3)}
Question 1: (13 pts)
▪ Propose a pseudo-code to solve the above problem using Iteration. (2 pts)
▪ Implement the proposed algorithms in C/C++. (9pts)
▪ Calculate the complexity of your program (Best scenario, Worst scenario, Average). Justify
your answer. (2 pts)*/

#include<stdio.h>
int Product(int i,int j,int arr[],int k ,int length){
    if(k>length){
        return 0;
    }
    if(i*j==arr[k]&&i!=j){
        printf("(%d,%d,%d)",i,j,arr[k]);
    }
    Product(i,j,arr,k+1,length);
}
int main(){
    int arr[]={4,15,45,9,40,27,3,5,10};
    int length=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<length-1;i++){
        for(int j=i;j<length;j++){
            Product(arr[i],arr[j],arr,0,length);
        }
    }
    return 0;
}