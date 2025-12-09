/*Problem:
In this problem, we would like to re-implement a selection sort to sort an array of numbers with
some improvements.
Selection Sort divides the input list into two parts: the sublist of elements already sorted and the
unsorted sublist of elements remaining to be sorted.
- find the smallest element in the unsorted sublist
- swap this element with the leftmost unsorted element, it equivalents to move this element
from the unsorted sublist to the sorted one,
- continue to proceed all elements in the unsorted sublist.
Question 1: (12 pts)
▪ Propose a recursive algorithm (pseudo-code) for the above Selection Sort (combined with
iteration if necessary). (3pts)
▪ Implement the proposed pseudo-code using C/C++ (7pts)
▪ Calculate the complexity of your program (Best scenario, Worst scenario, Average). Justify
your answer. (2pts)*/
#include<stdio.h>
int Run(int arr[],int i,int j, int length){
    if(j>=length){
        return 0;
    }
    if(arr[i]>arr[j]){
        int temp =arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    Run(arr,i,j+1,length);
}

int main(){
    int arr[]={5,83,9,74,62,96,3};
    int length=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<length-1;i++){
        Run(arr,i,i+1,length);
    }
    for(int i=0;i<length;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}