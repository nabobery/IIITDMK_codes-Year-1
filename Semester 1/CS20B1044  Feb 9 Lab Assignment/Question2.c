// This program is done by CS20B1044 Avinash R Changrani
// Question 2 : Write a C program to find variance of the elements in the matrix
#include<stdio.h>
void main()
{
int m,n,i,j;
printf("This is a program to find variance of elements in a matrix\n");
// Ask user for number of rows and columns
printf("Enter the value for number of rows of the matrix m :\n");
scanf("%d", &m);
printf("Enter the value for number of columns of the matrix n :\n");
scanf("%d", &n);
int mat[m][n];
// Ask user for elements of the matrix
printf("Enter the value of elements of the matrix\n");
for(i=0; i<m; i++) {
 for(j=0;j<n;j++) {
   printf("Enter value for mat[%d][%d]:", i, j);
   scanf("%d", &mat[i][j]);
  }
}
// To Calculate Mean of elements in a Matrix
float sum = 0,mean;
for(i=0; i<m; i++) {
 for(j=0;j<n;j++) {
   sum = sum + mat[i][j];
 }
} 
mean = sum/(m*n);
// To Calculate Variance of elements in the Matrix
float Variance = 0;
for(i=0; i<m; i++) {
 for(j=0;j<n;j++) {
   Variance += ((mat[i][j] - mean)*(mat[i][j] - mean))/ (m*n);
   }
} 
printf("The Variance of elements in  %d rows and %d columns of the matrix is %f\n", m, n, Variance);     

}
