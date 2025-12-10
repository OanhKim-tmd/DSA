#include<stdio.h>
int Prime(int n){
    if(n<=1){
        return 0;
    }else if(n==2){
        return 1;
    }else {
        for(int i=2;i<n;i++){
            if(n%i==0){
                return 0;
            }
        }
        return 1;
    }
}
void Check(int a,int b){
    if((Prime(a)&&Prime(b))&&(a-b==2||a-b==-2)){
        printf("(%d, %d)",a,b);
    }

}
void checkRecursion(int arr[],int n,int i ,int j){
    if(j>=n){
        return;
    }
    Check(arr[i],arr[j]);
    checkRecursion(arr,n,i,j+1);
}
int main(){
    int arr[]={2,5,11,13,17,19,7,21};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n-1;i++){
        checkRecursion(arr,n,i,i+1);
    }
    return 0;
}
// T(n)=O(n^3)