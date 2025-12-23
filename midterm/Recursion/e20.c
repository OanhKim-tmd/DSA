#include<stdio.h>
int div (int *q, int *r, int a,int b){
    if(a<b){
        *r = a;
        return 0;
    }
    *q=*q+1;
    return div(q,r,a-b,b);
}
int main(){
    int a=10,b=3,q=0,r=0;
    div(&q,&r,a,b);
    printf("Quotient: %d ,Remainder : %d \n",q,r);
    return 0;
}