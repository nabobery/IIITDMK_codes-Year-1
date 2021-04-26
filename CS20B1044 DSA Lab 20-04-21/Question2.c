/* Question 2 : WAP to input the elements of a symmetric matrix as an array (dynamic memory allocation). User should input the dimension of a square matrix. Print the elements of the matrix. What is the
complexity of the algorithm? Please state the reason.
This question is done by CS20B1044 Avinash R Changrani */
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include <time.h>
void main()
{
  int dimension;
  printf("Please enter the dimension of the symmetric matrix you want\n");
  scanf("%d", &dimension);
  int n = sqrt(dimension);
   // Declaring dynamically allocated matrix of m rows and n columns and 1 D array to take in elements for the symmetric matrix
  int *arr;
  int size = ((n*(n+1))/2);
  arr = (int *)malloc( size * sizeof(int));
// Generate random elements for the matrix using rand() function
  srand(time(NULL));
// Filling the whole array using the formula n(n+1)/2
  for(int k = 0;k < size;k++) {        
       *(arr + k) = rand()%90 + 10;       
     }      

// Printing the array elements  
  printf("The 1D array containing the elements is  : \n");
  for(int k = 0 ; k < size;k++){
    printf(" %d ", *(arr + k));
  }  
  
// printing the Symmetric Matrix
  printf("\nThe symmetric matrix using array elements is \n");
  for(int i = 0;i < n;i++) {
     for(int j = 0;j < n;j++) {    
         if (i <= j){
            printf(" %d ", *(arr + (i*n - (((i*i) - i))/2 + j - i))); 
         }   
         else if (j < i) {
            printf(" %d ", *(arr + (j*n - (((j*j) - j))/2 + i - j))); 
         }   
    }
    printf("\n");
  }            
  

  // Freeing the dynamically allocated memory
  free(arr);  
}
