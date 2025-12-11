#include<stdio.h>
#include<math.h>
double Cal(int k,int n){
    if(k>n){
        return 0;
    }
    return Cal(k+1,n) + (pow(-1,k+1) /((k)*(k+1)))  ;
}
int main(){
    int n=100;
    double ln = 0.5 + (Cal(1,n)*0.5);
    printf("%.10f",ln);
    return 0;
}

