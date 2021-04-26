/* Question 3 : WAP to find out the mean ans Standard deviation of the elements in a LinkedList. What is the complexity of the algorithm? Please state the reason.
This question is done by CS20B1044 Avinash R Changrani */
#include<stdio.h>
#include <stdlib.h>
#include<malloc.h>
#include<math.h>
// Declaration of structure (node) of the Linked List
struct linkedlist{
  int data;
  struct linkedlist *nextnode_ptr;
};

void main()
{
   struct linkedlist *head = NULL;
   head = (struct linkedlist*)malloc(sizeof(struct linkedlist));
// Asking the user for number of elements(nodes) for the linked list
  int n;
  printf("Please enter the number of elements(nodes) for the linked list\n");
  scanf("%d", &n);   
  struct linkedlist *ptr = head;
// if ptr is null, there's no space in memory  
  if(ptr == NULL){  
     printf("Unable to allocate memory \n");
     exit(0);
  } 
  for(int i = 0; i < n; i++){ 
     printf("Enter the Element (Node) number %d of the linked list\n", i + 1);
// For nodes other than the end, take and  assign the data then allocate memory for the next node pointer and change the pointer from current node to the next one      
     if ( i < n-1){
        scanf("%d", &ptr->data);
        ptr->nextnode_ptr = (struct linkedlist*)malloc(sizeof(struct linkedlist));
        ptr = ptr->nextnode_ptr;
     }
// for the final node, we take the data and assign the pointer to  next node's pointer as null     
     else{
        scanf("%d", &ptr->data);
        ptr->nextnode_ptr = NULL;
     }
  } 
// To calculate mean we firat calculate sum by counting elements starting rom the head node and then divide by n elements  
  int sum = 0;
  struct linkedlist *pointer = head;
  while (pointer != NULL){
      sum += pointer->data;
      pointer = pointer->nextnode_ptr;
  }
  float mean = sum/n;
  printf("The mean of elements(nodes) for the linked list is %f\n", mean);
  
// To calculate standard deviation, we first calculate variance then find out the square root to get standard deviation    
  float variance = 0;
  struct linkedlist *pointer1 = head;
  while (pointer1 != NULL){
      variance += ((pointer1->data - mean) * (pointer1->data - mean))/n;
      pointer1 = pointer1->nextnode_ptr;
  }
  float std_deviation = sqrt(variance);
  printf("The standard deviation of elements(nodes) for the linked list is %f\n", std_deviation);

}
