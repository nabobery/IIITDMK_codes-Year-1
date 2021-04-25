// This program is done by CS20B1044 Avinash R Changrani
// Question 1 : Write a C program to find the sum of elements in the odd columns and even rows.
#include<stdio.h>
void main()
{
int m,n,i,j;
printf("This is a program to find sum of elements in odd columns and even rows in a matrix\n");
// Ask user for number of rows and columns
printf("Enter the value for number of rows of the matrix m :\n");
scanf("%d", &m);
printf("Enter the value for number of columns of the matrix n :\n");
scanf("%d", &n);
int mat[m][n];
// Ask user for elements of the matrix
printf("Enter the value of elements of the matrix\n");
for(i=1; i<=m; i++) {
 for(j=1;j<=n;j++) {
   printf("Enter value for mat[%d][%d]:", i, j);
   scanf("%d", &mat[i][j]);
  }
}
// Calculating sum of elements in odd columns and rows 
int sum = 0;
for(i=1; i<=m; i++) {
 for(j=1;j<=n;j++) {
  if ( i % 2 == 0 && j % 2 != 0){
    sum += mat[i][j];
   }
 }
}
printf("The sum of elements of the matrix is %d\n", sum);
    
}


