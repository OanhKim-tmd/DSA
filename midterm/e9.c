// buble sort
#include<stdio.h>
int main(){
    int arr[10]={3,5,7,8,9,83,42,15,75,43};
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
    // for(int i=0;i<9;i++){
    //     for(int j= i+1;j<10;j++){
    //         if(arr[i]>arr[j]){
    //             int temp=arr[i];
    //             arr[i]=arr[j];
    //             arr[j]=temp;
    //         }
    //     }
    // }
    for(int i=0;i<9;i++){
        for(int j=0;j<9-i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j]=temp;
            }
        }
    }
    printf("\n");
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}