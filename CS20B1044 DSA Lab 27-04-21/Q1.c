/* Question 1 :  Create a Linked List of size N, where each node will have a random character and pointer to the next node. N should be given as user input. WAP to remove the duplicate characters from the list.  
This question is done by CS20B1044 Avinash R Changrani */
#include<stdio.h>
#include<stdlib.h>
#include <time.h>

// Declaration of structure (node) of the Linked List
struct linkedlist{
	char ch;
	struct linkedlist *nextnode_ptr;
};

void main()
{
	struct linkedlist *head = NULL;
	head = (struct linkedlist*)malloc(sizeof(struct linkedlist));
	int n;
	// Asking size of linked list from user
	printf("Please enter the size of linked list you want\n");
	scanf("%d", &n);
	struct linkedlist *ptr = head;
	srand(time(NULL));	
	for(int i = 0; i < n; i++){
	// Generate random characters for the nodes of the linked list using rand() function	  		 
	  ptr->ch = 'A' + (rand() % 26);	  	  	  
	// For nodes other than the end, take and  assign the data then allocate memory for the next node pointer and change the pointer from current node to the next one  
	  if (i < n-1){	   	    
	    ptr->nextnode_ptr = (struct linkedlist*)malloc(sizeof(struct linkedlist));
	    ptr = ptr->nextnode_ptr;  
	  }
	  else {	    
	    ptr->nextnode_ptr = NULL;
	  }	 
	}
	// Printing the elements of the linked list 	
	ptr = head;
	printf("The elements of the linked list before removing duplicate elements is : \n");
	while (ptr != NULL){
          printf("%c ", ptr->ch);
          ptr = ptr->nextnode_ptr;
       }
       printf("\n");
       // Defining an array that will keep count of number of charcters spotted
       int *arr;
       // Changing all array elements to zero first
       arr = (int *)malloc(26 * sizeof(int));
       for(int i = 0 ;i < n;i++){
	   *(arr + i) = 0;
	}
	// deleting the duplicate eleemtns and preparing the linked list with npn- duplicate elements
	struct linkedlist *prev, *temp;
	for(ptr = head; ptr != NULL;){	   
	   if ( *(arr + (ptr->ch - 65)) == 0){
	         *(arr + (ptr->ch - 65)) = 1; 
	         prev = ptr;
	         ptr = ptr->nextnode_ptr;  
	   }   
	   else {
	         temp = ptr->nextnode_ptr;
	         free(ptr);
	         prev->nextnode_ptr = temp;
	         ptr = temp;
	   }                              
	}	
	// Printing the elements of the linked list after removing the duplicate elements 	
	ptr = head;
	printf("The elements of the linked list after removing duplicate elements is : \n");
	while (ptr != NULL){
          printf("%c ", ptr->ch);
          ptr = ptr->nextnode_ptr;
	}
	printf("\n");
	
	//Freeing the dynamically allocated memory
	free(arr);
	ptr = head;
	struct linkedlist *free_ptr = NULL;
	while (ptr != NULL){
	   free_ptr = ptr->nextnode_ptr;
	   free(ptr);
	   ptr = free_ptr;       
	}   
	
}




