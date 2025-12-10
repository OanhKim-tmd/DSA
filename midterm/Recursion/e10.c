#include<stdio.h>
#include<math.h>
double Cal(int k,int n){
    if(k>n){
        return 0;
    }
    return Cal(k+1,n) - (pow(-1,k) /(k))  ;
}
int main(){
    int n=1000;
    printf("%.10f",Cal(1,n));
    return 0;
}

