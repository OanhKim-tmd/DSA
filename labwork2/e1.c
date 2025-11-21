/*Suppose that we use a List data structure to represent unbounded
integers.
 - the first element refers to the sign: 1 is positive and -1 is negative.
 - each element in the list represents one digit of these integers.
Implement and test the program in C/C++ using an Array-based List (Static or
Dynamic) to manage this unbounded integers:
 - add new digits at any place in an integer.
 - remove a digit at a specfic position in an integer.
 - calculate the sum of all digits from an unbounded integer.
 - display the whole number on the screen.

}*/

#include <stdio.h>
#define MAX 100
typedef struct {
    int size;
    int element[MAX];
}List;
void init(List *l,int n){
    l->size=0;
    l->element[0] = (n>0)?1:-1; // the first element refers to the sign: 1 is positive and -1 is negative.
    l->size = 1;
}

//each element in the list represents one digit of these integers
int length(List *l,int n){
    int digit[1000];
    int k=1;
    if(n==0){
        digit[k++]=0;
    }else{
        while (n!=0){
            if(n<0){
                n=-n;
            }
            digit[k++]=n%10;
            n=n/10;
        }
    }
    for(int i=k;i>0;i--){
        l->element[l->size++]=digit[i];
    }   
}
// add new digits at any place in an integer.
int insert(List *l,int pos,int val){
    if(l->size==MAX){
        printf("List is full\n:");
        
    }
    if(pos<0||pos>l->size){
        printf("Invalid position\n");
    }
    for(int i = l->size;i>pos+1;i--){
        l->element[i]=l->element[i-1];
    }
    l->element[pos+1]=val;
    l->size++;
}
// remove 1 digits at any place in an integer
int delete(List *l,int pos){
    if(pos<1||pos >=(l->size-1)){
        printf("Invalid position\n");
    }
    for(int i=pos+1;i<l->size-1;i++){
        l->element[i]=l->element[i+1];
    }
    l->size--;
}

// sum of digits in an integer expect sign
int Sum(List *l){
    int sum=0;
    for(int i=1;i<l->size;i++){
        sum += l->element[i];
    }
    return sum;
}
// display integer 
void display(List *l){
    if(l->element[0]==-1){
        printf("-");
    }else if(l->element[0]==1){
        printf("+");
    }
    for(int i=2;i<l->size;i++){
        printf("%d",l->element[i]);
    }
    printf("\n");
}
int main(){
    int n,choice,pos,val;
    List l;
    printf("Enter the number: ");
    scanf("%d",&n);
    init(&l,n);
    length(&l,n);
    while(1){
        printf("\n\n----MANAGING LARGE INTEGER NUMBERS----\n");
        printf("1.Display number\n");
        printf("2.Add digit into 1 position\n");
        printf("3.Delete digit\n");
        printf("4.Sum digit\n");
        printf("0.Exit\n\n");
        printf("Your choice( Enter 0 to 4, please):");
        scanf("%d",&choice);        
        if(choice==1){
            printf("Your number is: ");
            display(&l);
        }else if(choice==2){
            printf("the position which you want to add:");
            scanf("%d",&pos);
            printf("the digit which you want to add :");
            scanf("%d",&val);
            insert(&l,pos,val);
        }else if(choice==3){
            printf("the position which you want to delete:");
            scanf("%d",&pos);
            delete(&l,pos);
        }else if(choice==4){
            printf("Sum of your number is:%d ",Sum(&l));
        }else if(choice==0){
            break;
        }else{
            printf("Please, choice from 0 to 4.");
        }  
    }
    return 0;
}