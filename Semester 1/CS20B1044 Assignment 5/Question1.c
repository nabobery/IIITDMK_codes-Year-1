// Question 1 : Write a C program to read n integers into an array and add only the odd numbers in the array
#include<stdio.h>
void main()
{
 int n,i;
 printf("Enter Size of array: \n");
 scanf("%d",&n);
 int a[n];

// To get the n Integers(Elements of the Array)
 printf("Please Enter the Element of the Array: \n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  } 

// To get Sum of Odd Numbers in the array
 int sum = 0;
  for(i=0;i<n;i++)
  {
    if((a[i]%2) != 0)
    {
      sum = sum + a[i];
    }  
  }   
 printf("\nThe sum of Odd Numbers in the given array is %d \n",sum);

}
