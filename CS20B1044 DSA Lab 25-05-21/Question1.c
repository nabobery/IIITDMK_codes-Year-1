/* Question 1 : Implement an integer stack using Linked List. PUSH and POP operations should be clearly
defined. WAP to calculate the factorial of a number N using the above defined stack. The number N should be taken 
as an user input.
This code is done by CS20B1044 Avinash R Changrani */
#include<stdio.h>
#include<stdlib.h>

// Declaration of structure (node) of stack using Linked List
struct Node {
	int number;
	struct Node *next;
} *top;

// Function Declaration of push and pop of stack
void push(int n);
int pop();

void main() {
    int n;
    printf("Please Enter the value of N to calculate factorial using stack \n");
    scanf("%d", &n);
    int count = n;
    top = NULL;
    while (count != 1){
        push(count);
        count -= 1; 
    }
    // Freeing the stack and calculating the factorial
    unsigned long long result = 1;
    while (count <= n && top != NULL){
        result *= top->number;
        pop();
        count += 1; 
    }
    printf("The factorial of given number N = %d using stack is %llu \n", n, result);
}

// Function Definition of push and pop of stack
void push(int n) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->number = n;
    temp->next = top;
    top = temp;
}

int pop(){
    int number;
    struct Node *temp;
    temp = top;
    number = temp->number;
    top = top->next;
    free(temp);
    return number;
}