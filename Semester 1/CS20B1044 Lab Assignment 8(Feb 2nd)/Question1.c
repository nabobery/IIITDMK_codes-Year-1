//This Program is done by CS20B1044 Avinash R Changrani
// Question 1: Write a recursive function to multiply n numbers
#include<stdio.h>
int multiply(int a[],int n)
{
 if(n == 0)
   return (a[0]);
 else
   return(a[n] * multiply(a,n-1));
}     
void main()
{
int n;
// Asking number of integers n from User
printf("Please enter the value of n so that we can multiply n numbers\n");
scanf("%d", &n);
int a[n];
printf("Please enter the %d numbers you want to multiply\n", n);
for(int i=0;i < n;i++)
   scanf("%d", &a[i]);
int result = multiply(a,n-1);
printf("The result of multiplication of %d numbers is %d\n", n, result); 

}
