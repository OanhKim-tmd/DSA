#include<stdio.h>
typedef struct{
    int tn_1;
    int tn_2;
    int tn_3;
}Tribo;
Tribo init(){
    Tribo fp;
    fp.tn_1=1;
    fp.tn_2=1;
    fp.tn_3=0;
    return fp;
}
Tribo calculate(int n){
    if(n==0){
        Tribo base ={0,0,0};
        return base;
    }
    if(n==1){
        Tribo base ={1,0,0};
        return base;
    }
    if(n==2){
        return init();
    }
    Tribo prev = calculate(n-1);
    Tribo current;
    current.tn_1=prev.tn_1+prev.tn_2+prev.tn_3;
    current.tn_2=prev.tn_1;
    current.tn_3=prev.tn_2;
    return current;
}
void Display(int n){
    Tribo result =calculate(n);
    printf("%d",result.tn_1);
}
int main(){
    int n=5;
    Display(n);
    return 0;
}