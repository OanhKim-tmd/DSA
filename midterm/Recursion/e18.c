#include<stdio.h>
#include<math.h>
int Power(int a,int b){
    if(b==0){
        return 1;
    }
    return a*Power(a,b-1);
}
int main(){
    int n=153;
    int temp=n;
    int check =n;
    int count=0;
    while(n>0){
        n=n/10;
        count ++;
    }
    int Sum=0;
    for(int i=0;i<count;i++){
        int a=temp%10;
        temp=temp/10;
        Sum=Sum+Power(a,count);
    }
    if(Sum==check){
        printf("okeee");
    }
    return 0;
}
