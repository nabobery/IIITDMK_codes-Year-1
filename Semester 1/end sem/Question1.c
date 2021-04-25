#include<stdio.h>
void main()
{
int m,n,k,i,j,output;
// Ask user for number of rows and columns
printf("Enter the value for number of rows and columns of the matrix k :\n");
scanf("%d", &k);
int mat[k][k];
// reading a 2D array
printf("Enter the value of elements of the matrix\n");
for(i=1; i<=k; i++) {
 for(j=1;j<=k;j++) {
   printf("Enter value for mat[%d][%d]:", i, j);
   scanf("%d", &mat[i][j]);
  }
}    
m = mat[1][1]; // maximum of upper triangular matrix
n = mat[1][1]; // minimum of lower triangular matrix
for (i = 1; i <= k; i++){
    for (j = 1; j <= k; j++){
      if (j >= i && mat[i][j] > m)
        m = mat[i][j];  
      if (i >= j && mat[i][j] < n)  
        n = mat[i][j];
     }   
}
output = 3*(m*m) - 2*(n*n);
printf("The output = 3m^2 -2n^2 where m is maximum of upper triangular matrix and n is minimum of lower triangular matrix is %d \n", output);
}
