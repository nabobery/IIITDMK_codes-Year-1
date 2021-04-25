// Question1 : Write a C program that reads an array of n integers and also new integer x check if there exist a and b in the array such that a+b=x

#include<stdio.h>
void main()
{
 int n,i,j,x,f;
 printf("Enter Size of array: \n");
 scanf("%d",&n);
 
 int a[n];
// To get the n Integers(Elements of the Array)
 printf("Please Enter the Element of the Array: \n");
 for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  } 
 
 // To get value of x 
 printf("Enter the new integer x : \n");
 scanf("%d",&x);
   
 // To check the sum with x
 for(f=0,i=0;i<n;i++)
  {
    for(j=1;j<n;j++)
     {
      // if pair is found
      if(a[i] + a[j] == x)
        {
          printf("The integers are %d and %d \n",a[i], a[j]);
          f++;
        }  
     }
  }  
     
 // if no pair found          
 if(f == 0)              
  printf("No such pairs exist :( \n");     
   
}
