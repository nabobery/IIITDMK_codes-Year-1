/* Question 1 : Write a program to create an array of N integer elements. Find out the summation and store it in another variable and print it on the console.
This question is done by CS20B1044 Avinash R Changrani */
#include<stdio.h>
void main()
{
  int n, sum = 0, result;
// Asking User for number of elements
  printf("Enter the number of elements of the array\n");
  scanf("%d", &n);
// Getting the elements from the User  
  int array[n];
  printf("Enter the elements in the array\n");
  for(int i = 0;i < n;i++){
    scanf("%d", &array[i]);
  }
// Calculating the sum of elements in the array
  for(int i = 0;i < n;i++){
    sum += array[i];
  }
  result = sum;
  printf("The sum of elements in the array is %d \n", result);  
    
}
