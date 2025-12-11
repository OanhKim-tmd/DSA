// /*Question 1 (12 pts)
// ▪ Write a pseudo-code to convert a natural number into binary using Iteration. (2pts)
// ▪ Implement your proposed algorithm in C/C++. (8pts)
// ▪ Calculate the complexity of your algorithm. Justify the answer (comment directly in your
// source files). (2pts)
// Question 2 (8 pts)
// ▪ Propose another algorithm using recursive functions and implement in C/C++ to perform the
// above problem. (4pts)
// ▪ Calculate the complexity of your algorithm. Justify the answer (comment directly in your
// source files). (2pts)*/
#include<stdio.h>
double iPart(float n){
    int arr[10];
    int i=0;
    int temp = (int)n;
    while(temp > 0){
        arr[i]=temp%2;
        temp=temp/2;
        i++;
    }
    for(int j=i-1;j>=0;j--){
        printf("%d",arr[j]);
    }
}
void yPart(float n,int k,int j){
    if(j>k){
        return ;
    }
    n=n-(int)n;
    n=n*2;
    printf("%d",(int)n);
    yPart(n,k,j+1);
}
int main(){
    float n=4.47f;
    iPart(n);
    printf(".");
    int k=(int)n;
    yPart(n,k,1);
    return 0;
}

