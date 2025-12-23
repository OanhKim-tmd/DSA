/*
Exercise 1 – Linear Search
Requirements
Read an integer n
Read an array a[n]
Read an integer x
Implement Linear Search
Print the index of the first occurrence of x
Print -1 if x is not found
Notes
No sorting required
Use iterative approach
*/
#include<stdio.h>
int Search (int arr[],int m, int i){
    for(int j=0;j<i;j++){
        if(arr[j]==m){
            return j;
        }
    }
    return -1;
}
int main(){
    int n,m;
    int i=0;
    printf("Enter the number n:");
    scanf("%d",&n);
    int arr[n   ];
    while(n>0){
        arr[i]=n%10;
        n=n/10;
        i++;
    }
    printf("Enter the number which you want to find:");
    scanf("%d",&m);
    if(Search(arr,m,i)==-1){
        printf("No");
    }else{
        printf("yess");
    }

    return 0;
}