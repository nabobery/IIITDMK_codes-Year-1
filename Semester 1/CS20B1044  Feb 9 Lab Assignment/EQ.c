// This program is done by CS20B1044 Avinash R Changrani
// Extra Question : To find if square matrix of order nxn is symmetric using transpose
#include<stdio.h>
void main()
{
int n,i,j;
printf("This is a program to find variance of elements in a matrix\n");
// Ask user for number of rows and columns
printf("Enter the value for order of the square matrix n :\n");
scanf("%d", &n);
int mat[n][n];
// Ask user for elements of the matrix
printf("Enter the value of elements of the matrix\n");
for(i=1; i<=n; i++) {
 for(j=1;j<=n;j++) {
   printf("Enter value for mat[%d][%d]:", i, j);
   scanf("%d", &mat[i][j]);
  }
}  

// Printing the original matrix
printf("The Original matrix is\n");
for(i=1; i<=n; i++) {
 for(j=1;j<=n;j++) {
  printf("%d ", mat[i][j]);
 }
printf("\n");
}

// Tranpose matrix   
int mattranspose[n][n];
for(i=1; i<=n; i++) {
 for(j=1;j<=n;j++) {
   mattranspose[i][j] = mat[j][i];
  }
}
// Printing the transpose matrix
printf("The Transpose matrix is\n");
for(i=1; i<=n; i++) {
 for(j=1;j<=n;j++) { 
  printf("%d ", mattranspose[i][j]);
  }
 printf("\n"); 
}  
int not = 0 ; // Number of asymmetries
//Checking if it's Symmetric as when A = A(T) it's symmetric
for(i=1; i<=n; i++) {
 for(j=1;j<=n;j++) {
  if( mat[i][j] != mattranspose[i][j])
   not++;   
 }
}
if (not == 0)
 printf("Matrix is Symmetric\n");  
else
 printf("Matrix is not symmetric\n");  
     
}
