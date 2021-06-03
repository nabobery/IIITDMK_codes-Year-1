/* Question 1 : Implement a Circular QUEUE using an array.
This code is done by CS20B1044 Avinash R Changrani */

#include <stdio.h>
#include <stdlib.h>
// Structure of Queue
struct Queue {
    int front, rear, size;
    int *arr;
} *circular_queue;

// Function Declarations for Insertion, Deletion and Display
void enqueue(struct Queue *q,int data); 
int dequeue(struct Queue *q);
void displayqueue(struct Queue *q);
void deletequeue(struct Queue *q);

void main(){
    int n, choice, number;
    printf("Please enter the size of the circular queue \n");
    scanf("%d",&n);
    circular_queue = malloc(sizeof(struct Queue));
    circular_queue->size = n;
    circular_queue->front = circular_queue->rear = -1;
    circular_queue->arr = malloc(circular_queue->size * sizeof(int));
    do {
        printf("Circular Queue : \n 1) Insert Element \n 2) Delete Element \n 3) Display Queue \n 0) Exit");
        printf("\nEnter any choice between 0-2 : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter number: \n");
                scanf("%d", &number);
                enqueue(circular_queue, number);
                break;
            case 2:
                dequeue(circular_queue);
                break;
            case 3:
                displayqueue(circular_queue);
                break;    
        }
    } while (choice != 0);
    deletequeue(circular_queue);
}

// Function Definitions for Insertion, Deletion and Display
void enqueue(struct Queue *q, int data){
    if ((q->front == q->rear + 1) || (q->front == 0 && q->rear == q->size - 1)){
        printf("Queue Overflow \n");
    }
    else
    {
        if (q->front == -1) 
            q->front = 0;    
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = data;
    }    
}

int dequeue(struct Queue *q){
    int data = 0; 
    if (q->front == -1){
        printf("Queue Underflow \n");
        return -1;
    }
    else
    {
        data = q->arr[q->front];
        if (q->front == q->rear) 
        {
            q->front = q->rear = -1 ;
        } 
        else 
        {
            q->front = (q->front + 1) % q->size;
        }
    }    
    return data;
}

void displayqueue(struct Queue *q){
    if (q->front == -1){
        printf("Empty Queue\n");
    } 
    else {
        printf("The elements in the Queue are : \n");
        int i;
        for (i = q->front; i != q->rear; i = (i + 1) % q->size) {
            printf("%d ", q->arr[i]);
        }
        printf("%d \n", q->arr[i]);
    }   
}

// for freeing queue
void deletequeue(struct Queue *q){
    if(q){
        if(q->arr)
            free(q->arr);
        free(q);        
    }
}


