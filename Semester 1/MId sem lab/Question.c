// This Program was done by CS20B1044 Avinash R Changrani
#include<stdio.h>
void main()
{
// Declaration of recursive function P(n)
int recursivef(int, int);
int n,a,result;
printf("This is a program to calculate P(n) for given n and a values using recursive function\n");
printf("Please enter the value of n for calculating the value of P(n)\n");
scanf("%d", &n);
printf("Please enter the value of a for calculating the value of P(n)\n");
scanf("%d", &a);
result = recursivef(n,a);
printf("The value of P(n) for the given n = %d and a = %d is %d\n", n, a, result);
}
// Function definition
/* P(n) = (2n-1)*a*P(n-1) - (n-1)P(n-2)
   P(0) = 1
   P(1) = a  */
int recursivef(int n, int a){
if (n >= 0) {
if (n == 0)
   return 1;
if (n == 1)
   return a;
else
   return(((((2*n)-1)*a*recursivef(n-1,a)) - ((n-1)*recursivef(n-2,a))));  
 }
if ( n < 0)
  printf("Recursive function P(n) is not defined for negative values of n");      
}

