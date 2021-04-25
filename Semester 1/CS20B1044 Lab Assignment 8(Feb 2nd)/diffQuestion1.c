//This Program is done by CS20B1044 Avinash R Changrani
// Question 1: Write a recursive function to multiply n numbers
#include<stdio.h>
void main()
{
// declaration of function
int multiply(int,int);

int n,result,number,product=1;
// Asking number of integers n from User
printf("Please enter the value of n so that we can multiply n numbers\n");
scanf("%d", &n);
if (n < 0)
 printf("Please Enter a positive number\n");
else if ( n == 0)
 printf("As there are zero numbers the result is not defined\n");
else
 for(int i=0;i < n;i++){
  printf("Please enter the number you want to multiply\n");
  scanf("%d", &number);
  product = multiply(product,number);
  }
result = product;  
printf("The result of multiplication of %d numbers is %d\n", n, result); 
}

// Defining the recursive function
int multiply(int num1,int num2){
if(num1 == 1)
  return num2;
else if(num2 == 1)
  return num1;
else
  return num2 + multiply(num1 - 1, num2);
}
 

