/*
Exercise 2: Assume that a railway train has N railroad cars attached together
such as car1, car2, car3, ..., carN . A train can be considered as a list and each car
corresponds to a node in this list.
1
   - Each car carries a maximum capacity of passengers (int type) and has an id
(char type). Both variables are user-defined values.
   - Each car is reserved by a number of passengers (int type) (which should be
less than its capacity). If there are any cars that don’t have any passengers,
they should be removed from the train.
   - It is possible to add new cars to the train.
   - A function is available to display all cars’ information or the length of the
train.
Implement a program in C/C++ using Linked List to manage the train and test all
functions.*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Car{
    int capacity;
    int passenger;
    char id[50];
    struct Car *next;
} Car;

// Create a new car
Car *init(int capacity, int passenger, char* id){
    Car* newCar = (Car*)malloc(sizeof(Car));
    if(newCar==NULL){
        printf("Memory is not available!\n");
        return NULL;
    }
    newCar->capacity= capacity;
    newCar->passenger=passenger;
    strcpy(newCar->id,id);
    newCar->next=NULL;
    return newCar;
}
// add a new car
void addCar(Car **head,int capacity,int passenger, char* id){
    Car* newCar=init(capacity,passenger,id);
    if(*head ==NULL){
        *head =newCar;
        return;
    }
    Car *temp =*head;
    while(temp->next =NULL){
        temp=temp->next;
    }
    temp->next =newCar;
}
void resever(Car *head,char *id, int num){
    Car *temp =head;
    while (temp !=NULL){
        if(strcmp(temp->id,id)==0){
            if(temp->passenger +num >temp->capacity){
                
            }
        }

    }
}


void displayCar(int car){
    for(int i=1;i<=car;i++){
            if (i==car){
                printf("  _________________  \n");}
            else{
                printf("  _________________  ");
            }
        }
    for(int i=1;i<=car;i++){
        if (i==car){
            printf(" |                 | \n");}
        else{
            printf(" |                 | ");
        }
    }
    for(int i=1;i<=car;i++){
        if (i==car){
            printf(" |                 | \n");}
        else{
            printf(" |                 | ");
        }
    }
    for(int i=1;i<=car;i++){
        if (i==car){
            printf("  -0-------------0-  \n");}
        else{
            printf("  -0-------------0-  ");
        }
    }    
               
                
}

int main(){
    int pas,choice,car;
    char id[50];
    printf("Enter the number cars :");
    scanf("%d",&car);
    getchar();
    int i=0;
    while(i<car){
        printf("Enter the id of car: ");
        fgets(id,sizeof(id),stdin);
        size_t len = strlen(id);
        if (len > 0 && id[len - 1] == '\n') {
            id[len - 1] = '\0';
        }
        printf("Enter the number maximum passengers of car(id: %s):",id);
        scanf("%d",&pas);
        getchar();
        i++;
        
    }
    
    while(1){
        printf("\n\n======= Managing the railway train =======\n");
        printf("1.Display all car'information.\n");
        printf("2.Add 1 car in any place.\n");
        printf("3.Book a seat for passengers(auto remove empty cars).\n");
        printf("4.length of the train.\n");
        printf("5.Exit.\n");
        printf("\n Your choice( from 1 to 5): ");
        scanf("%d",&choice);
        if(choice==1){
            
        }else if(choice==2){

        }else if(choice==3){

        }else if(choice==5){
            break;
        }else if(choice==4){

        }else{
            printf("Please enter number from 1 to 4.");
        }
    }
    return 0;
}