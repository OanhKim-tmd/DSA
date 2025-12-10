/*/*Question 1 (10 pts)
In this problem, a natural number is given. The objective is to find a digit and swap its position
in the number to obtain the smallest possible value.
Note: The smallest value must have the same number of digits as in the original value; thus,
0 cannot be used.
 Example: 51029 -> the possible smallest value is 15029 after one swap.
 Propose an algorithm using iteration and implement it in C/C++ to complete the task. (3
pts)
 Propose and implement an alternative algorithm using recursion for this task. (6 pts)
 Calculate the complexity of the two approaches. Justify your answer by making comments
on the code. (1 pt)
Hint: You can use an array to store all digits. The problem becomes sorting and searching on
an array.*/

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