//Question 2 : Write a C function that takes an integer and prints it's binary.
#include<stdio.h>
//Function to convert Integer to binary
   int int_to_bin(int num)
   {
     if (num == 0)
     {
        return 0;
     }
     else
     {
        return (num % 2) + 10 * int_to_bin(num / 2);
     }
   }

void main()
{ 
 
   int num, bin;
   printf("Enter a positive integer: \n");
   scanf("%d",&num);
   bin = int_to_bin(num);
   printf("The binary equivalent of %d is %d \n", num, bin);
   if ( num < 0)
     printf("Enter a Positive Integer and Try again \n");    

}
