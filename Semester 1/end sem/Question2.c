// In this program I take the array such that it's index starts from 1 to n.
#include <stdio.h>
void main(){
int n;
printf("Enter the number of elements in The array\n");
scanf("%d",&n);
int prime_number = 2,prime_test = 1,array[n],average,prime_arr[n],number = 0;
for (int i = 1; i <= n; ++i) {
    prime_arr[i] = 0;
 }   
for (int i = 1; i <= n; ++i) {
    printf("enter the element %d of the array \n",i );
    scanf("%d",&array[i]);
    }
if (n > 2){
    prime_arr[1] = array[2];
    }
while (prime_number < n){
    for (int i = 3; i < prime_number ; ++i) {
      if((prime_number % i) == 0){
        prime_test = 0;
        break;
     }
}
if (prime_test == 1){
   for (int i = 2; i <= n; ++i) {
     prime_arr[i] = array[prime_number];
     number++;
 }
    prime_test = 1;
    prime_number += 1;
    }
}
float sum = 0,avg;
for (int i = 1; i <= n; ++i) {
   sum = sum + prime_arr[i];
   }
avg = sum/(number+1);
printf("the average of integers in prime number location is %f \n, avg); 
}
