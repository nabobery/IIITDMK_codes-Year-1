/* Question 2 : Create a two-way Linked List of N Fibonacci numbers. N should be given as user input.
WAP to delete the nodes in the two-way linked list based on a given GP series. The factor of
the GP series will be taken as an user input. (Ex: 1, 2, 4, 8, 16..... : Factor 2).
This code is done by CS20B1044 Avinash R Changrani */
#include<stdio.h>
#include<stdlib.h>
#include <time.h>

// Declaration of structure (node) of the Two-way Linked List
struct linkedlist{
	long long fib_number;
	struct linkedlist* next; // Pointer to next node in TWL
    struct linkedlist* prev; // Pointer to prev node in TWL
}; 

void main ()
{
    int n;
	// Asking size of fibonacci linked list (Number of fibonacci numbers in the linked list) from user
	printf("Please enter the size of fibonacci linked list you want\n");
	scanf("%d", &n);
	struct linkedlist *head = (struct linkedlist*)malloc(sizeof(struct linkedlist));
	struct linkedlist *ptr = head; // current node's pointer
	struct linkedlist *tail = (struct linkedlist*)malloc(sizeof(struct linkedlist));
	long long fib1 = 1, fib2 = 1;
    // Entering and printing the fibonacci numbers of the linked list 
	printf("The elements of the linked list before deleting elements of the linked list is : \n");
    for (int i = 1; i < n + 1; i++){
	    if (i == 1){
			ptr->fib_number = fib1;
	    	printf("%lld ", ptr->fib_number);
			ptr->prev = NULL;
			ptr->next = (struct linkedlist*)malloc(sizeof(struct linkedlist));
			ptr->next->prev = ptr;
	    	ptr = ptr->next;
        } 
		else if (i == 2){
			ptr->fib_number = fib2;
	    	printf("%lld ", ptr->fib_number);
			ptr->next = (struct linkedlist*)malloc(sizeof(struct linkedlist));
	    	ptr->next->prev = ptr;
	    	ptr = ptr->next;	
		}       
		else if (i < n){
			ptr->fib_number = fib1 + fib2;
	    	printf("%lld ", ptr->fib_number);
	    	fib1 = fib2;
	    	fib2 = ptr->fib_number;
			ptr->next = (struct linkedlist*)malloc(sizeof(struct linkedlist));
			ptr->next->prev = ptr;
	    	ptr = ptr->next;	
		}
		else {
			ptr->fib_number = fib1 + fib2;
	    	printf("%lld ", ptr->fib_number);
	    	fib1 = fib2;
	    	fib2 = ptr->fib_number;
			tail = ptr;
			ptr = ptr ->next = NULL;
		}
	}
	// Asking the user for factor of GP series to delete the elements present at index of the linked list based on the GP 
	int factor, index = 1, count = 1;
	printf("\nPlease Enter the factor of GP Series using which the linked list elements at the index of GP series is deleted : \n");
	scanf("%d", &factor);
	struct linkedlist *free_ptr;
	ptr = head;
	while (ptr != NULL) {
		if (index == count && count == 1){
			ptr->next->prev = NULL;
			head = ptr->next;
			free_ptr = ptr;
			ptr = ptr->next;
			free(free_ptr);
			index *= factor;
		}
		// for factor = 2 
		else if (index == count && count == 2){
			ptr->next->prev = NULL;
			head = ptr->next;
			free_ptr = ptr;
			ptr = ptr->next;
			free(free_ptr);
			index *= factor;
		}
		else if (index == count && count != n){
			ptr->next->prev = ptr->prev;
			ptr->prev->next = ptr->next;
			free_ptr = ptr;
			ptr = ptr->next;
			free(free_ptr);
			index *= factor;
		}
		else if (index == count && count == n){
			ptr->prev->next = NULL;
			free_ptr = ptr;
			ptr = ptr->next;
			free(free_ptr);
			index *= factor;
		}
		else {
			ptr = ptr->next;
		}
		count += 1;
	}
	//Printing the linked list after deletion of elements at the index of the GP series
	ptr = head; 
	printf("The elements of the linked list after deleting elements at the index of GP series of the linked list is : \n");
	while (ptr != NULL){
        printf("%lld ", ptr->fib_number);
    	ptr = ptr->next;
       }
    printf("\n");
	//Freeing the dynamically allocated memory
	ptr = head;
	struct linkedlist *temp = NULL;
	while (ptr != NULL){
		temp = ptr->next;
		free(ptr);
		ptr = temp;       
	} 

}