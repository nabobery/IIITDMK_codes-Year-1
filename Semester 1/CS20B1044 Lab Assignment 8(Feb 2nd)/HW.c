// This program is done by CS20B1044 Avinash R Changrani
/* Write a recursive function to compute nCr.
   Note: Formula to compute nCr: nCr = n! / (n – r)! r! */
#include<stdio.h>
// Declaration of recursive function (factorial)
int fact(int x);

void main()
{
int n,r,nCr;
// Asking input from user
printf("This is a program to compute nCr \n");
printf("Please Enter the value of n and r respectively to calculate nCr \n");
scanf("%d%d", &n, &r);
nCr = fact(n)/(fact(n-r)*fact(r));
if(n < r)
  printf("nCr can't be computed when n<r !! \nPlease Try again\n");
else 
  printf("The nCr for the given n and r is %d\n", nCr);
}

// Defining the Recursive Function
int fact(int x) {
if((x==0)||(x==1))
    return(1);
else
    return(fact(x-1)*x);
}

