// Question 1 : Write a C program to check whether the sum of digits is equal to a given number or not using function
#include<stdio.h>

//Function to calculate sum of digits 
int Sumofdigits(int n) 
{  
   int sum = 0; 
   while (n > 0) 
   { 
       sum = sum + n % 10; 
       n = n/10; 
   } 
   return sum; 
} 

void main()
{
  int n,number; 
  printf("Enter the integer to calculate sum of digits : \n"); 
  scanf("%d",&n);
  printf("Enter the number you would like to check the sum of digits with : \n");
  scanf("%d",&number);
  
// To check sum of digits of the integer with the number given
  if(Sumofdigits(n) == number)
    printf("The number you entered is equal to sum of digits of the integer you've entered \n");
  else
    printf("The number you entered isn't equal to sum of digits of the integer you've entered :( \nTry again \n");   
       
}
