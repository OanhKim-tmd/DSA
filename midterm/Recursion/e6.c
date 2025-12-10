#include<stdio.h>
int main(){
    int n =5185;
    int arr[10];
    int count=0;
    for(int i=0;i<10;i++){
        if(n==0){
            break;
        }
        arr[i]=n%10;
        n=n/10;
        count ++;
    }
    for(int i=count-1;i>=0;i--){
        printf("%d",arr[i]);
        

    }
    int found=0;
    if(arr[count-2]==0){
        for(int i=count-3;i>0;i--){
            for(int j=i-1;j>=0;j--){
                if(arr[i]>arr[j]){
                    int temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                    break;
                }
            }
        }
    }else{
        for(int i=count-1;i>0;i--){
            for(int j=i-1;j>=0;j--){
                if(arr[i]>arr[j]){
                    int temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                    found++;
                }
            }
            if(found==1){
                break;
            }
        }
    }
 
    printf("\n");
    for(int i=count-1;i>=0;i--){
        printf("%d",arr[i]);
    }
    
    return 0;
}