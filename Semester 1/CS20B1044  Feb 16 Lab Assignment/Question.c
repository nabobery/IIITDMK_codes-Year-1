// Question : Write a c function to implement bubble sort without using array(use pointer to integer, and also use malloc function as  int* a = (int *) malloc(sizeof(int))*100). call the function from main after reading the sequence to sort. After function call, print the sorted sequence in main function
// This program is done by CS20B1044 Avinash R Changrani
#include<stdio.h>
#include<stdlib.h>
// Function to implement buuble sort without array(using pointers)
void bubblesort(int n, int* ptr)
{
int i, j, temp;
// Sorting numbers in ascending order using bubble sort
for(i=0; i<n; i++){
 for(j=0; j<(n-1-i); j++){
     if(*(ptr + j) > *(ptr+(j+1))){
       temp = *(ptr+j);
       *(ptr+j) = *(ptr+(j+1));
       *(ptr+(j+1)) = temp;
     }  
}    
}
}

void main()
{
int n, *ptr;
// Ask user for input of number of integers
printf("Enter the number of integers you would like to sort\n");
scanf("%d", &n);
ptr = (int*)malloc(n*sizeof(int)); 
// Reading the numbers
printf("Enter the integers you would like to sort\n");
for(int i=0; i<n; i++)
  scanf("%d", &ptr[i]);
// Calling the function and printing the sorted numbers
bubblesort(n, ptr);
// To print the numbers
for(int i=0; i < n; i++){
  printf("%d", *(ptr + i));
}
printf("\n");

}

