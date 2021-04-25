/* Question 3 : Write a program to delete the elements of an array based on the following.
• At every itertion, the deleted array index should be from a geometric progression (G.P) series (1, 2, 4, 8, 16....). Example: At 1st iteration - element present at index 1 will be deleted, at 2nd iteration - element present at index 2 will be deleted, at 3rd iteration - element present at index 4 will be deleted, and so on. Continue this opration until you reach the end of the array, or all the elements are deleted.
• To fill the array, use random number generator Function (rand() or srand()) instead of
using scanf() functionality.
• After every iteration, show the contents of the array.
• At the end of execution, your program should also display the number of operations
performed.
• What is the asymptotic complexity of this algorithm and why?
This Question has been done by CS20B1044 Avinash R Changrani */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{ 
  int n, count = 0;
  int *arr;
  printf("Enter the size of the array\n");
  scanf("%d", &n);
  arr = (int *)malloc(n * sizeof(int));
// Getting elements of the array from rand() function
  srand(time(NULL));
  for(int i = 0 ;i < n;i++){
    *(arr + i) = rand()%100;
  }
// Initial array 
  printf("The Initial array is : \n");
  for(int i = 0 ;i < n;i++){      
      printf(" %d" , *(arr + i));
    }
    printf("\n"); 
  
  for(int i = 1 ; i < n;i *= 2){
    for (int c = i ; c < n - 1  ; c++ )  
         *(arr + c) = *(arr + c+1); 
    count += (n - 1 - i);      
    printf("The array is : \n");
    n--;
    arr = (int *) realloc(arr, n*sizeof(int));  
    for(int k = 0 ;k < n;k++){      
      printf(" %d" , *(arr + k));
    }
    printf("\n"); 
    
        
  }   
  printf("The number of operations performed by the program is %d\n", count);   
  
  // Freeing the dynamically allocated memory
  free(arr);   
      
}
