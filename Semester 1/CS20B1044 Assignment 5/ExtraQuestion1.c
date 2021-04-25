/* Extra Question1:
Write a c program to read an integer n and calculate its factorial(n!).*/
#include<stdio.h>
void main()
{
 int n,i;
 int factorial;
 printf("Enter the integer for which you want to calculate factorial for: \n");
 scanf("%d", &n);
  if (n < 0)
        printf("Factorial can't be calculated");
    else {
        for (i = 1,factorial = 1; i <= n; ++i) {
            factorial = factorial * i;
        }
          printf("Factorial of %d = %d \n", n, factorial);
        }   
}
