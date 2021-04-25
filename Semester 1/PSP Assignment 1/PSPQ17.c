// PSP Assignment Question 17 done by CS20B1044 Avinash R Changrani 
#include<stdio.h>
void main()
{
int array[30], i, n;

// To get n from user's input
printf("Please enter the integer 'n' for getting the range of integers between n+10 and n+30 \n");
scanf("%d", &n);

// To get 20 intgers from the user and read it into the array
printf("Please enter any 20 integers between %d and %d \n", n+10, n+30);
for(i=0;i<20;i++)
    {
      scanf("%d", &array[i]);
    }
    
// To find the sum of the array of 20 integers   
int sum = 0;
for (int i = 0; i < 20; i++) 
   {
     sum += array[i]; 
   }       
// To get sum of 21 consecutive integers 
int total_sum;
total_sum = 21*(n +20);
// To get the missing integer
  
int miss_int;
miss_int = total_sum - sum;
printf("The missing integer between %d and %d is %d\n", n+10, n+30, miss_int); 
 
}
