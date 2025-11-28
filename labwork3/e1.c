/*Exercise 1:
Suppose we would like to implement a queue system for a commercial website.
Given that the website offers a list of items, each item has a limited quantity in
stock. Implement a queue of customers, and each customer can buy only a few
products among the available items.
 Determine the item name, quantity, and price in stock.
 Specify a queue of n customers; each customer can buy k products from one
item (k is different for each customer).
 Customers take turns to enter (enqueue) and leave (dequeue) the queue according to the FIFO order to purchase wanted products.
 If a customer successfully purchases products, display a message and reduce
the number of products in stock. Otherwise, display a warning message if the
item has been run out.
Implement the above problems in C/C++ using a Queue data structure. Write
a main function for testing all written functions (init(), display(), enqueue(), dequeue(),...).*/

#include <stdio.h>
#include <string.h>
#define MAX 100
typedef struct {
    char name[50];
    float price;
    int quantity;
}Item;
typedef struct {
    char Name[50];
    char item[50];
    int buyAmount;
}Customer;
typedef struct {
    int front,behind,size;
    Customer data[100];
}Queue;
void initQueue(Queue* q){
    q-> front = q-> behind = -1;
}
int isEmpty(Queue* q){
    return q->front==-1;
}
int isFull(Queue* q){
    return q->behind== MAX-1;
    
}
void enqueue(Queue *q,Customer c){
    if (isFull(q)){
        printf("Queue full\n");
        return;
    }
    if (isEmpty(q)){
        q->front = 0;
        q->behind = 0;
        q->data[q->behind] = c;
    } else {
        q->data[++q->behind] = c;
    }
} 
Customer dequeue(Queue *q) {
    Customer empty = {"","", 0};
    if (isEmpty(q)) return empty;

    Customer c = q->data[q->front];
    if (q->front == q->behind)
        initQueue(q);
    else
        q->front++;

    return c;
}
void displayStock(Item items[], int n){
    printf("\nCurrent stock:\n");
    printf("Name       | Price    | Quantity\n");
    printf("---------------------------------\n");
    for(int i = 0; i < n; i++){
        printf("%-10s | %-8.2f | %d\n", items[i].name, items[i].price, items[i].quantity);
    }
    printf("\n");
}
int findItemIndex(Item items[], int n, char *name){
    for(int i = 0; i < n; i++){
        if(strcmp(items[i].name, name) == 0) return i;
    }
    return -1; 
}
int main(){
    int n;
    Queue q;
    initQueue(&q);
    Item items[] = {
        {"car", 20000, 2},
        {"moto", 1200, 5},
        {"bicycle", 80, 10},
        {"truck", 36000, 3}
    };
    int itemCount = sizeof(items)/sizeof(items[0]);
    printf("==========LIST OF ITEMS=========\n");
    printf("   Name    |  Price  | Quantity \n");
    printf("--------------------------------\n");
    for(int i=0;i<itemCount;i++){
        printf("%-10s | %-7.0f | %d\n", items[i].name ,items[i].price, items[i].quantity);
    }
    

    printf("Enter the number custumers: ");
    scanf("%d",&n);
    for(int i=0 ; i < n ; i++){
        Customer c;
        printf("\nCustomer %d:\n", i+1);
        printf("Enter name: ");
        scanf("%s", c.Name);
        printf("Enter item: ");
        scanf("%s", c.item);
        printf("Enter quantity: ");
        scanf("%d", &c.buyAmount);
        enqueue(&q, c);
    }
    printf("\n--- Processing Queue ---\n");
    while(!isEmpty(&q)){
        Customer c = dequeue(&q);
        int idx = findItemIndex(items, itemCount, c.item);
        if(idx == -1){
            printf("Customer %s: Item '%s' not found.\n", c.Name, c.item);
        } else if(items[idx].quantity >= c.buyAmount){
            items[idx].quantity -= c.buyAmount;
            printf("Customer %s successfully purchased %d %s(s).\n", c.Name, c.buyAmount, c.item);
        } else {
            printf("Customer %s: Item '%s' is out of stock or insufficient quantity.\n", c.Name, c.item);
        }
        displayStock(items, itemCount);
    }
    return 0;
}


