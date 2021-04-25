// PSP Assignment Question 18 done by CS20B1044 Avinash R Changrani 
#include<stdio.h>
#include<math.h>
void main()
{
int i;
double pi, difference, mod_difference;
// Loop to get PI
for (i = 0,pi = 0; i < 10000000; i++)
    {
    pi += 4*((pow(-1,i))/((2*i)+1));      
    }
    
printf("The Value of PI with 8 decimal place approximation is %0.8lf\n",pi);
// 0.8 is used to show hte precision after the decimal point
}
