/* Question 2 : Write a program to swap every 2nd element of an array with its conjugate position. The element at i-th poisition will be swapped with (n-i)-th position. At the end of execution, your program should also display the number of operations performed. What is the asymptotic complexity of this algorithm and why?
This Question has been done by CS20B1044 Avinash R Changrani */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
  int n, temp, count = 0;
  int *arr;
  printf("Enter the size of the array\n");
  scanf("%d", &n);
  arr = (int *)malloc(n * sizeof(int));
// Getting elements of the array from rand() function
  srand(time(NULL));
  for(int i = 0 ;i < n;i++){
    *(arr + i) = rand()%100;
  }
  printf("The array before being swapped is : \n");
  for(int i = 0 ; i < n;i++){
    printf(" %d ", *(arr + i));
    }
  printf("\n");  
  for(int i = 1 ;i <= (n/2);i+=2){
// Swapping every 2nd element with its conjugate position    
      temp = *(arr + i);
      *(arr + i) = *(arr + n-i-1);
      *(arr + n-i-1) = temp; 
// For calculating number of operations            
      count+= 3;
  }     
  printf("The array after being swapped is : \n");
  for(int i = 0 ; i < n;i++){
    printf(" %d ", *(arr + i));
    }
  printf("\n");  
  printf("The number of operations performed during the program (swaps) is %d\n", count);     

  // Freeing the dynamically allocated memory
  free(arr); 
}
