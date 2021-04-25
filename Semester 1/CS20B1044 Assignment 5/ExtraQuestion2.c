//Write a C program to read n integers into an array and add only the odd numbers in the array using dicvision operator
#include<stdio.h>
#include<math.h>
void main()
{
int n,i;
 printf("Enter Size of array: \n");
 scanf("%d",&n);
 float a[n];

// To get the n Integers(Elements of the Array)
 printf("Please Enter the Element of the Array: \n");
  for(i=0;i<n;i++)
  {
    scanf("%f",&a[i]);
  } 

// To get Sum of Odd Numbers in the array
 int sum = 0;
 float divisor;
 float fracpart;
  for(i=0;i<n;i++)
  {
     divisor = a[i]/(2.0);
     fracpart = divisor - floor(divisor);
    if(fracpart == 0.5 )
    {
      sum = sum + a[i];
    }  
  }   
 printf("\nThe sum of Odd Numbers in the given array is %d \n",sum);
}
