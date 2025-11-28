#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    char name[50];
    float price;
    int quantity;
} Item;

typedef struct {
    char Name[50];
    char itemName[50];
    int buyAmount;
} Customer;

typedef struct {
    int front, behind;
    Customer data[MAX];
} Queue;

void initQueue(Queue* q){
    q->front = q->behind = -1;
}

int isEmpty(Queue* q){
    return q->front == -1;
}

int isFull(Queue* q){
    return q->behind == MAX - 1;
}

void enqueue(Queue *q, Customer c){
    if(isFull(q)){
        printf("Queue full\n");
        return;
    }
    if(isEmpty(q)){
        q->front = 0;
        q->behind = 0;
        q->data[q->behind] = c;
    } else {
        q->data[++q->behind] = c;
    }
    printf("[ENQUEUE] Customer '%s' joined the queue (Product: '%s', Qty: %d)\n", c.Name, c.itemName, c.buyAmount);
}

Customer dequeue(Queue *q) {
    Customer empty = {"", "", 0};
    if(isEmpty(q)) return empty;

    Customer c = q->data[q->front];
    if(q->front == q->behind) {
        initQueue(q);
    } else {
        q->front++;
    }
    return c;
}

int findItemIndexByName(Item items[], int n, char* name){
    for(int i = 0; i < n; i++){
        if(strcmp(items[i].name, name) == 0) return i;
    }
    return -1;
}

void displayItems(Item items[], int n){
    printf("\n=== LIST OF ITEMS ===\n");
    printf("%-10s | %-10s | %-10s\n", "Name", "Price", "Quantity");
    printf("-----------------------------------\n");
    for(int i = 0; i < n; i++){
        printf("%-10s | $%-9.2f | %-10d\n", items[i].name, items[i].price, items[i].quantity);
    }
    printf("\n");
}

void displayWaitingCustomers(Queue* q) {
    if(isEmpty(q)){
        printf("No customers waiting in the queue.\n");
        return;
    }
    printf("\n\n\n\n\n--- CUSTOMERS WAITING IN QUEUE ---\n");
    for(int i = q->front; i <= q->behind; i++){
        Customer c = q->data[i];
        printf("%d. %s (Product: %s | Qty: %d)\n", i - q->front + 1, c.Name, c.itemName, c.buyAmount);
    }
    printf("----------------------------------\n\n");
}

int main() {
    Item items[] = {
        {"car", 20000.0, 2},
        {"moto", 1200.0, 5},
        {"bicycle", 80.0, 10},
        {"truck", 36000.0, 3}
    };
    int itemCount = sizeof(items)/sizeof(items[0]);

    Queue q;
    initQueue(&q);

    printf("=== STORE OPENING ===\n");
    displayItems(items, itemCount);

    int n;
    printf("Enter number of customers: ");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        Customer c;
        printf("\nCustomer %d:\n", i+1);
        printf("Enter customer name: ");
        scanf(" %[^\n]", c.Name);
        printf("Enter product name: ");
        scanf(" %[^\n]", c.itemName);
        printf("Enter quantity to buy: ");
        scanf("%d", &c.buyAmount);

        enqueue(&q, c);
    }

    displayWaitingCustomers(&q);

    printf("=== START PROCESSING PAYMENTS ===\n\n");

    while(!isEmpty(&q)){
        Customer c = dequeue(&q);
        printf(">> Processing customer: %s...\n", c.Name);

        int idx = findItemIndexByName(items, itemCount, c.itemName);
        if(idx == -1){
            printf("   [FAILED] Product '%s' not found.\n\n", c.itemName);
            continue;
        }
        if(items[idx].quantity >= c.buyAmount){
            items[idx].quantity -= c.buyAmount;
            float total = items[idx].price * c.buyAmount;
            printf("   [SUCCESS] Bought %d x %s.\n", c.buyAmount, c.itemName);
            printf("   -> Total price: $%.2f\n", total);
            printf("   -> Remaining stock: %d\n\n", items[idx].quantity);
        } else if(items[idx].quantity == 0){
            printf("   [FAILED] Product '%s' is sold out.\n\n", c.itemName);
        } else {
            printf("   [FAILED] Insufficient stock for '%s' (Requested: %d, Available: %d).\n\n", c.itemName, c.buyAmount, items[idx].quantity);
        }
    }

    printf("=== ALL CUSTOMERS HAVE BEEN PROCESSED ===\n");

    // Print item list one last time to show remaining stock
    displayItems(items, itemCount);

    return 0;
}
