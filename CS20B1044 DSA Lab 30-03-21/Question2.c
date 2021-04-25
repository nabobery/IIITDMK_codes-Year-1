/* Question 2 : Write a program to check if a given string is palindrome or not. EX: MADAM
This question is done by CS20B1044 Avinash R Changrani */
#include<stdio.h>
void main()
{
  char string[100];
  int len = 0, var = 0 ;
// To get string from User
  printf("Please Enter the string\n");
  scanf("%s", string);
// Getting the length of string
  for(int i = 0; string[i] != '\0';i++){
    len += 1;
  } 
  if ( len > 1) { 
// Checking if a string is palindrome or not  
   for(int i = 0; i < len; i++){
     if(string[i] != string[len - i - 1])
     {
	 var = 1;
	 break;	
     } 
   }
// Printing out the result for whether the string is palindrome or not   
   if(var == 0)
     {
	 printf("%s is a Palindrome String\n", string);
     }
   else
     {
	 printf("%s is not a Palindrome String\n", string);
     }	
  }      
  else
   printf("A palindrome is a word. So Enter a word and try again\n");
}
