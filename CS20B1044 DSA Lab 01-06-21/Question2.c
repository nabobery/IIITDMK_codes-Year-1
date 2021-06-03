/* Question 2 : Implement a Parking Lot problem using a Header Linked List based QUEUE with the
following properties.
• Cars can enter from the REAR end and leave from the FRONT end. Cars are given
sequential integer tokens.
• The user should take input for the Parking Lot size (MAX size) at the beginning.
• The header node in the header linked list should be used to store the current QUEUE
size.
• While the cars enter to the QUEUE, if the current size exceeds the MAX size, it should
give an Overflow error - “Parking Lot FULL”.
• If a car from k-th location wants to leave, all the cars at the FRONT of the k-th car are
first removed and put into a STACK. Then, the k-th car is removed. Then, all the cars
from the STACK are popped out and again inserted at the FRONT of the queue.
• At every step, the header node value, FRONT and REAR need to be updated based on
the operation.
This code is done by CS20B1044 Avinash R Changrani */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for queue, stack and linked list node 

struct Node{
	int token;
	struct Node *next;
};

struct Queue{
    struct Node *front;
    struct Node *rear;
} *queue;

struct stack{
    struct Node *top;
};

int count = 0; // to keep count of cars in the lot
// Function Declarations for stack and queue operations

void push(struct stack *stack, int token);
int pop(struct stack *stack);
void enter_lot(struct Node *head, struct Queue *queue, int Maxsize);
void display_lot(struct Node *head);
int leave_lot(struct Node *head);
int remove_lot(struct Node *head, struct Queue *queue, int remove_car);

void main(){
    int Maxsize;
    printf("Please enter the size of the parking lot : ");
    scanf("%d",&Maxsize);
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    head->next = NULL;
    head->token = 0;
    int remove_car;
    char choice = '1';
    printf(" 1. Press E to enter a new car to the Parking from the REAR end");
    printf("\n 2. Press L to leave a new car from the Parking from the FRONT end");
    printf("\n 3. Press D to display the cars currently present in the Parking Lot:");
    printf("\n 4. Press R to Remove a car from a given Location (K) in the parking");
    printf("\n 5. Press Q to Quit \n");
    while (choice != 'Q'){
        printf(" Enter Your Choice:");
        scanf(" %c", &choice);	
        switch (choice){
            case 'E':
            case 'e':
                enter_lot(head, queue, Maxsize);
                display_lot(head);
                break;
            case 'L':
            case 'l':
                leave_lot(head);
                display_lot(head);
                break;
            case 'D':
            case 'd':
                display_lot(head);
                break;
            case 'R':
            case 'r':
                printf(" Please Enter the poistion of the car you want to remove from the parking lot : \n");
                scanf("%d", &remove_car);
                remove_lot(head, queue, remove_car);
                display_lot(head);
                break;
            case 'Q':
                break;
            default:
                printf("Enter a valid choice..... \n");
	    }		
    }

}

// Function definitions for stack and queue operations
void push(struct stack *stack, int token) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->token = token;
    temp->next = stack->top;
    stack->top = temp;
}

int pop(struct stack *stack) {
    int token;
    struct Node *temp;
    temp = stack->top;
    stack->top = stack->top->next;
    token = temp->token;
    free(temp);
    return token;
}

void enter_lot(struct Node *head, struct Queue *queue, int Maxsize){
    if (head->token == Maxsize){
        printf(" Parking Lot Full\n");
        return;
    }
    count += 1;
    head->token += 1;
    // For First Car entering through rear end
    if (head->next == NULL){
        head->next = (struct Node*) malloc(sizeof(struct Node));
        head->next->token = count;
        queue->front = head->next;
        queue->rear = head->next;
        queue->rear->next = NULL;
    }
    // For other cars entering through rear end
    else {
        queue->rear->next = (struct Node*)malloc(sizeof(struct Node));
        queue->rear = queue->rear->next;
        queue->rear->token = count;
        queue->rear->next = NULL;
    }
}

void display_lot(struct Node *head){
    struct Node *ptr = head->next;
    if (head->next == NULL){
        printf(" Parking Lot Empty\n");
    }
    printf(" The cars (tokens) in the parking lot are : \n");
    while (ptr != NULL){
        printf("%d ", ptr->token);
        ptr = ptr->next;
    }
    printf("\n");
}

// For Leaving from front end
int leave_lot(struct Node *head){
    int data = 0;
    struct Node* temp;
    if(head->next == NULL){
        printf(" Parking Lot Empty\n");
        return -1;
    }
    else {
        temp = head->next;
        data = head->next->token;
        head->next = head->next->next;
        free(temp);
        head->token -= 1;
    }
    count -= 1;
    return data;
}

// For Leaving(Removing) from kth position
int remove_lot(struct Node *head, struct Queue *queue, int remove_car){
    int data;
    struct stack *stack = (struct stack*)malloc(sizeof(struct stack));
    stack->top = NULL;
    if (head->next == NULL){
        printf(" Parking Lot Empty\n");
    }
    while (head->next->token < remove_car){
        data = leave_lot(head);
        push(stack,data);
    }
    leave_lot(head);
    while (stack->top != NULL){
        enter_lot(head, queue, pop(stack));
    }
}


