/* Question 1 : Create a Linked List of size N, where each node will have a random floating point value and
pointer to the next node. WAP to reverse the linked list based on a given GP series. The
factor of the GP series will be taken as an user input. (Ex: 1, 2, 4, 8, 16..... : Factor 2).
This code is done by CS20B1044 Avinash R Changrani */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Declaration of structure (node) of the Linked List
struct linkedlist{
	float data;
	struct linkedlist *next;
};

void main ()
{
    struct linkedlist *head = NULL;
	head = (struct linkedlist*)malloc(sizeof(struct linkedlist));
	int n, factor;
	// Asking size of linked list from user
	printf("Please enter the size of linked list you want\n");
	scanf("%d", &n);
    struct linkedlist *ptr = head;
	srand(time(NULL));	
	for (int i = 0; i < n; i++){
	// Generate random floating point values for the nodes of the linked list using rand() function
		ptr->data = ((float)rand()/(float)(RAND_MAX)) * 100 ;
		if (i < n - 1){
			ptr->next = (struct linkedlist*)malloc(sizeof(struct linkedlist));
			ptr = ptr->next;	
		}
		else {
			ptr->next = NULL;
		}	
	}
	// Printing the linked list before reversing the linked list based on GP series
	ptr = head; 
	printf("The elements of the linked list before reversing the linked list according to GP Series is : \n");
	while (ptr != NULL) {
        printf("%f ", ptr->data);
    	ptr = ptr->next;
    }
    printf("\n");
	// Asking the user for factor of GP series to reverse the linked list based on the factor 
	printf("Please Enter the factor of GP Series using which the linked list is supposed to be reversed : \n");
	scanf("%d", &factor);
	// Reversing the linked list according to the GP series of the factor
	int start = 1, end = factor;
	struct linkedlist* temp = NULL;
	for (int i = 1; i < n + 1; i++){ 
		if (i == 1){
			ptr = ptr->next;
		}
		if (i > start && i < end) { 
			// Reversing part
			struct linkedlist* prev = NULL;
			struct linkedlist* head_ref = ptr;
			struct linkedlist* current = head_ref ;     // ptr = head;
			struct linkedlist* next = NULL;
			while (head_ref != NULL && i < n + 1) {
				temp = ptr->next;
				next = current->next;
				current->next = prev;
				prev = current;
				current = next;
			}
			head_ref = prev;
			ptr = temp;
		}
		start *= factor;
		end *= factor;
	}
	printf("The elements of the linked list after reversing the linked list according to GP Series is : \n");
	ptr = head;
	while (ptr != NULL) {
        printf("%f ", ptr->data);
    	ptr = ptr->next;
    }

	//Freeing the dynamically allocated memory
	ptr = head;
	struct linkedlist *free_ptr = NULL;
	while (ptr != NULL){
		free_ptr = ptr->next;
		free(ptr);
		ptr = free_ptr;       
	} 

	
}


