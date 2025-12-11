#include<stdio.h>
typedef struct{
    int pn_1;
    int pn_2;
}Pell;
Pell init(){
    Pell fp;
    fp.pn_1=1;
    fp.pn_2=0;
    return fp;
}
Pell calculate(int n){
    if(n==0){
        Pell base = {0,0};
        return base;
    }
    if(n==1){
        return init();
    }
    Pell current;
    Pell prev = calculate(n-1);
    current.pn_1=2*prev.pn_1+prev.pn_2;
    current.pn_2=prev.pn_1;
    return current;
}
void Display(int n){
    Pell result = calculate(n);
    printf("%d",result.pn_1);
}
int main(){
    int n =5;
    Display(n);
    return 0;
}