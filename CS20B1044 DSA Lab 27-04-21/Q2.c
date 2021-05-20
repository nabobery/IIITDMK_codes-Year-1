/* Question 2 : Create a Linked List of N Fibonacci numbers. N should be given as user input. WAP to find the summation of odd and even Fibonacci numbers in the series. The program should be run in one pass (only one for/while loop in the entire program). 
This question is done by CS20B1044 Avinash R Changrani */
#include<stdio.h>
#include<stdlib.h>
// Declaration of structure (node) of the Linked List
struct linkedlist{
	long long fib_number;
	struct linkedlist *nextnode_ptr;
};

void main()
{
	int n;
	// Asking size of fibonacci linked list (Number of fibonacci numbers in the linked list) from user
	printf("Please enter the size of fibonacci linked list you want\n");
	scanf("%d", &n);
	struct linkedlist *head = (struct linkedlist*)malloc(sizeof(struct linkedlist));
	struct linkedlist *ptr = head;
	long long fib1 = 1, fib2 = 1;
	long long even_sum = 0, odd_sum = 0;
	// Entering and printing the fibonacci numbers of the linked list 
	for (int i = 1; i < n + 1; i++){
	   if (i == 1){
	      ptr->fib_number = fib1;
	      printf("%lld ", ptr->fib_number);
	      odd_sum += 1;
	      ptr->nextnode_ptr = (struct linkedlist*)malloc(sizeof(struct linkedlist));
	      ptr = ptr->nextnode_ptr;	   
	   }
	   else if (i == 2){
	      ptr->fib_number = fib2;
	      printf("%lld ", ptr->fib_number);	      
	      odd_sum += 1;
	      ptr->nextnode_ptr = (struct linkedlist*)malloc(sizeof(struct linkedlist));
	      ptr = ptr->nextnode_ptr;	   
	   }
	   else if (i < n){
	      ptr->fib_number = fib1 + fib2;
	      printf("%lld ", ptr->fib_number);
	      fib1 = fib2;
	      fib2 = ptr->fib_number;
	      if ( ptr->fib_number % 2 == 0){
	         even_sum += ptr->fib_number;
	      }
	      else {
	         odd_sum += ptr->fib_number;
	      }
	      ptr->nextnode_ptr = (struct linkedlist*)malloc(sizeof(struct linkedlist));
	      ptr = ptr->nextnode_ptr;
	   }
	   else {
	      ptr->fib_number = fib1 + fib2;
	      printf("%lld ", ptr->fib_number);
	      fib1 = fib2;
	      fib2 = ptr->fib_number;
	      if ( ptr->fib_number % 2 == 0){
	         even_sum += ptr->fib_number;
	      }
	      else {
	         odd_sum += ptr->fib_number;
	      }
	      ptr = ptr->nextnode_ptr = NULL;
	   }
	}
	  
	// Printing the sum of odd and even fibonacci numbers
	printf("\n");
	printf("The sum of even numbers in the fibonacci is %lld\n", even_sum );
	printf("The sum of  odd numbers in the fibonacci is %lld\n", odd_sum );
		   
	//Freeing the dynamically allocated memory
	ptr = head;
	struct linkedlist *free_ptr = NULL;
	while (ptr != NULL){
	   free_ptr = ptr->nextnode_ptr;
	   free(ptr);
	   ptr = free_ptr;       
	}  	   
	   
}
