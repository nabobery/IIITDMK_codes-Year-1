// Question 2 :  Write a C program to read n integers into an array and check if the array is sorted in ascending order or not.
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
  
 // To check if the elements are in ascending order or not 
  for(i=1;i<(n-1);i++)
  { 
     if(a[i] > a[i-1])
       printf("\nThe given set of n integers are sorted in ascending order\n");
     else
       printf("\nThe given set of integers are not sorted in ascending order\n");
    break;
   }   
            
}
