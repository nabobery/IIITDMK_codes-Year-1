// Write a C program to an integer n and print the sum of all odd numbers upto integer n
#include<stdio.h>
void main()
{
  int i, n, sum=0;
  // Input to find sum of odd numbers from 1 to n 
    printf("Enter the intger n : \n");
    scanf("%d", &n);

    // Find the sum of all odd numbers till n
    for(i=1; i<=n; i= i + 2)
    {
        sum = sum + i;
    }

    printf("Sum of odd numbers till %d = %d \n", n, sum);

}
