// PSP Assignment Question 19 done by CS20B1044 Avinash R Changrani 
#include<stdio.h>
#include<stdlib.h>
void main()
{
int input, array[31],mod_input;
printf("This is a program that reads an integer and outputs signed representation of the integer using 32 bits.\n");
printf("Please Enter an integer between -2147483647 and 2147483647\n"); 
scanf("%d", &input);
mod_input = abs(input);
if (input < -2147483647) {
     printf("Underflow Error\nPlease Enter an integer between -2147483647 and 2147483647\n");
    } else if (input > 2147483647) {
        printf("Overflow Error\nPlease Enter an integer between -2147483647 and 2147483647\n");
    } else if (input == 0) {
        printf("The required integer in signed representation is 00000000000000000000000000000000");
    } 
for(int i=0;i<32;i++)
{
array[i]=0;
}     
if (input > 0 && input <=2147483647)
  array[31] = 0;
else if (input < 0 && input >= -2147483647)
  array[31] = 1;
 
for(int i=0;mod_input > 0;i++)
{
 array[i] = mod_input % 2;
 mod_input = mod_input / 2;
}
for(int i=31;i>=0;i--)
{
  printf("%d",array[i]);
}   
printf("\n");   
    
}
