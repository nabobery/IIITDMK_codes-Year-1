/* Question 1 : Write a program to search an element inside an array using Linear and Binary search algorithms. At the end of execution, your program should also display the number of operations performed to search a particular element.
This Question has been done by CS20B1044 Avinash R Changrani */
#include<stdio.h>
#include<stdlib.h>
// Declaration of function
void Linearsearch(int *arr, int element, int size);
int Binarysearch(int *arr, int element, int start, int end, int *ptr);

void main()
{
// For counting number of operations in binary search
  int count = 0;
  int *ptr;
  ptr = &count;
  int index;
  
  int size, element;
  int *arr;
  printf("Enter the size of the array\n");
  scanf("%d", &size);
  arr = (int *)malloc(size * sizeof(int));
// Getting elements of the array from user input  
  printf("Enter the elements in the array in Ascending order(Increasing Order)\n") ;
  for(int i = 0 ;i < size;i++){
    scanf("%d", &arr[i]);
  }
  printf("Enter the particular element you would like to find\n");
  scanf("%d", &element);
// Calling the linear search and binary functions to print the number of operations performed to search a particular element
  Linearsearch(arr, element, size);
  index = Binarysearch(arr, element, 0, size-1, ptr);
  if (index != -1){
    printf("The particular element you would like to find is at index %d of the array using Binary Search\n", index);
    printf("The number of operations performed to search a particular element using Binary search is %d\n", *ptr);
  }
  else 
    printf("Element not found in the array. Please try again\n");
// Freeing the dynamically allocated memory
  free(arr);    
}


// Definition of the Linear Search function
void Linearsearch(int *arr, int element, int size){
// Implementing linear search algorithm and sequentially checking for element
  int i;
  for(i = 0 ;i < size;i++){    
    if (arr[i] == element){
       break;
    } 
  }    
  if (i < size){
    printf("The particular element you would like to find is at index %d of the array Using Linear Search\n", i);
    printf("The number of operations performed to search a particular element using Linear search is %d\n", i+1);
  }  
  else 
    printf("Element not found in the array. Please try again\n");
      
} 


// Definition of the Binary Search function
int Binarysearch(int *arr, int element, int start, int end, int *ptr){
  if(end >= start){ 
    int mid = start + (end-start)/2; 
// if the element is at the Middle index    
    if( arr[mid] == element ){
      (*ptr)++; 
      return mid;
    }  
// Left side     
    if( arr[mid] > element ){
      (*ptr)++; 
      return Binarysearch(arr, element, start, mid-1, ptr);  
    }   
// Right side     
    else{
      (*ptr)++; 
      return Binarysearch(arr, element, mid+1, end, ptr);
    }
  }  
// if nothing is found  
  return -1; 
     
  
}
