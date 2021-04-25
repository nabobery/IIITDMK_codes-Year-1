//This program is done by CS20B1044 Avinash R Changrani
//Question 2 : Write a C program to print an array in reverse order using recursive function
#include<stdio.h>
void main()
{
// Function Declaration
int reversearray(int a[],int start,int end);
int n;
// Asking user for size of array
printf("Enter size of the array: \n");
scanf("%d", &n);
int a[n];
// Reading elements of the array 
printf("Enter elements in the array: \n");
 for(int i=0; i<n; i++) 
  {
    scanf("%d", &a[i]);
  }  
printf("Original array is \n");    
 for (int i = 0; i < n; i++) {     
    printf("%d ", a[i]);  
  }
printf("\n"); 
reversearray(a, 0, n-1);
printf("Array in Reverse order is \n");
 
   for(int i = 0; i < n; i++){
  
        printf("%d ",a[i]);
   }          
printf("\n");           
}
// Defining the reverse array which swaps elements until start less than end
int reversearray(int a[],int start,int end){
int temp;
// Function works if start is less than end
if(start < end){  
// Swap the position of an element
  temp       = a[start];
  a[start] = a[end];
  a[end]   = temp;
// Incrementing start and decrementing end 
  reversearray(a, start+1, end-1);
}    
return(0);     
     }
