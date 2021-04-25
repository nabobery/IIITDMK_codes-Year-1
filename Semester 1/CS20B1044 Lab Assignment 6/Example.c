// Question 2 : Write a C program to implement the bubble sort for sorting in descending order and also print the number of comparison and swaps(comparisons of the array elements only to be considered)

#include<stdio.h>
void main()
{
 int n,i,j,temp,swaps,comparisons;
 printf("Enter Size of array: \n");
 scanf("%d",&n);
 
 int a[n];
// To get the n Integers(Elements of the Array)
 printf("Enter the Elements of the Array: \n");
 for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  } 
 
 for (i = 0,swaps = 0,comparisons = 0 ; i < n; ++i)
  {
    for (j = 0; j < (n-1-i); ++j)
    {
     if (a[j] < a[j+1])
     {
      temp = a[j+1];
      a[j+1] = a[j];
      a[j] = temp;
      swaps++;
     }
     comparisons++;  
    }
   
  }
 printf("\nThe Sorted array in descending order is : \n");
 for(i=0; i<n; ++i)
   printf(" %d ", a[i]); 
   
 printf("\n");  
 printf("Number of swaps is %d \n",swaps);
 printf("Number of Comparisons is %d \n",comparisons);
  
}
