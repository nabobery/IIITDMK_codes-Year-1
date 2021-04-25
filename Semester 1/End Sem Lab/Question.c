// This Program is done by CS20B1044 Avinash R Changrani
// Question : Write a recursive function that calls a recursive function f(n) which is defined as f(n)=2f(n-1)+3f(n-2)+4f(n-3); f(0)=0, f(1)=1 and f(2)=2, and prints the value of f(n) for given n
#include<stdio.h>
void main()
{
// Declaration of recursive function f(n)
int recursivef(int);
int n,result;
printf("This is a program to calculate f(n) for given n and a values using recursive function\n");
printf("Please enter the value of n for calculating the value of f(n)\n");
scanf("%d", &n);
// Getting and printing the result
result = recursivef(n);
printf("The value of f(n) for the given n = %d and is %d\n", n, result);
}
// Function definition
/* f(n) = 2f(n-1) + 3f(n-2) + 4f(n-3)
   f(0) = 0
   f(1) = 1  
   f(2) = 2  */
int recursivef(int n){   
if (n >= 0) {
if (n == 0)
   return 0;
if (n == 1)
   return 1;
if (n == 2)
   return 2;   
else
   return((2*recursivef(n-1)) + (3*recursivef(n-2)) + (4*recursivef(n-3)));  
}
if ( n < 0)
  printf("Recursive function f(n) is not defined for values of n less than 0\n");
}

// Trace of code
/*
f(7) = 2f(6) + 3f(5) + 4f(4) = 508 + 231 + 96 = 835
f(6) = 2f(5) + 3f(4) + 4f(3) = 154 + 72 + 28 = 254
f(5) = 2f(4) + 3f(3) + 4f(2) = 48 + 21 + 8 = 77
f(4) = 2f(3) + 3f(2) + 4f(1) = 14 + 6 + 4 = 24
f(3) = 2f(2) + 3f(1) + 4f(0) = 4 + 3+ 0 = 7 
f(2) = 2
f(1) = 1
f(0) = 0
*/
