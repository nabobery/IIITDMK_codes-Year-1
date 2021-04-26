/* Question 1 : Encryption and Decryption using Matrix: Dynamically allocate a matrix with row and column values as user input. Assign random values to the matrix elements. For encryption, WAP to increase the boundary element values of the matrix by the corresponding row number, and decrease the non-boundary elements by the corresponding (row+column) number. Also, write the corresponding decryption algorithm. What would be complexity of both the encryption and decryption algorithms? Please state the reason.
This question is done by CS20B1044 Avinash R Changrani */
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
// Declaration of Encryption and Decryption function
void Encryption(int *mat, int m, int n);
void Decryption(int *mat, int m, int n);

void main()
{
// Asking number of rows and columns of matrix from user 
  int m, n; 
  printf("Please enter the number of rows of the matrix you want to encrypt\n");
  scanf("%d", &m);
  printf("Please enter the number of columns of the matrix you want to encrypt\n");
  scanf("%d", &n);
  // Declaring dynamically allocated matrix of m rows and n columns
  int *mat1;
  mat1 = (int *)malloc( (m*n) * sizeof(int));   
  
  int p, q; 
  printf("Please enter the number of rows of the matrix you want to decrypt\n");
  scanf("%d", &p);
  printf("Please enter the number of columns of the matrix you want to decrypt\n");
  scanf("%d", &q);
  // Declaring dynamically allocated matrix of m rows and n columns
  int *mat2;
  mat2 = (int *)malloc( (p*q) * sizeof(int)); 
// Generate random elements for the matrix using rand() function
  srand(time(NULL));
  for(int i = 0;i < m;i++) {
     for(int j = 0;j < n;j++) {
       *(mat1 + i*n + j) = rand()%100;  
     } 
  }
  
  for(int i = 0;i < m;i++) {
     for(int j = 0;j < n;j++) {
       *(mat2 + i*n + j) = rand()%100;  
     } 
  }
// Calling the Encryption and decryption functions and printing out the encrypted and decrypted matrices
  Encryption(mat1, m, n);
  Decryption(mat2, m, n);
  
  
  // Freeing the dynamically allocated memory
  free(mat1);  
  free(mat2); 
}

// Definition of the Encryption function
void Encryption(int *mat, int m, int n){
// printing matrix before Encryption
  printf("The matrix before encrytpion is \n");
  for(int i = 0;i < m;i++) {
     for(int j = 0;j < n;j++) {
       printf(" %d ", *(mat+ i*n + j));  
     } 
     printf("\n"); 
  }   
// Encrytpion by increase the boundary element values of the matrix by the corresponding row number, and decrease the non-boundary elements by the corresponding (row+column) number
  for(int i = 0;i < m;i++) {
     for(int j = 0;j < n;j++) {
       if ((i == 0 || i == m-1) || (j == 0 || j == n-1)){       
         *(mat + i*n + j) += i;
       } 
       else 
         *(mat + i*n + j) -= (i+j); 
     }
  }     
// printing matrix after Encryption
  printf("The matrix after encrytpion is \n");
  for(int i = 0;i < m;i++) {
     for(int j = 0;j < n;j++) {
       printf(" %d ", *(mat+ i*n + j));  
     } 
     printf("\n"); 
  }   

}

// Definition of the Decryption function
void Decryption(int *mat, int m, int n){
// printing matrix before Encryption
  printf("The matrix before decrytpion is \n");
  for(int i = 0;i < m;i++) {
     for(int j = 0;j < n;j++) {
       printf(" %d ", *(mat + i*n + j));  
     } 
     printf("\n"); 
  }   
// Decrytpion by decrease the boundary element values of the matrix by the corresponding row number, and increase the non-boundary elements by the corresponding (row+column) number
  for(int i = 0;i < m;i++) {
     for(int j = 0;j < n;j++) {
       if ((i == 0 || i == m-1) || (j == 0 || j == n-1)){       
         *(mat + i*n + j) -= i;
       } 
       else 
         *(mat + i*n + j) += (i+j); 
     }
  }     
// printing matrix after Encryption
  printf("The matrix after encrytpion is \n");
  for(int i = 0;i < m;i++) {
     for(int j = 0;j < n;j++) {
       printf(" %d ", *(mat+ i*n + j));  
     } 
     printf("\n"); 
  }     


}












