#include<stdio.h>
typedef struct{
    int ln_1;
    int ln_2;
}LucasPair;

LucasPair init(){
    LucasPair fp;
    fp.ln_1=1;
    fp.ln_2=2;
    return fp;
}
LucasPair calculate(int n){
    if(n==0){
        LucasPair base ={2,0};
        return base;
    }
    if(n==1){
        return init();
    }
    LucasPair current;
    LucasPair prev = calculate(n-1);
    current.ln_1 = prev.ln_1 + prev.ln_2;
    current.ln_2 = prev.ln_1;
    return current;

}
void display(int n){
    LucasPair result = calculate(n);
    printf("%d",result.ln_1);
    
}
int main(){
    int n=0;
    display(n);
    return 0;
}