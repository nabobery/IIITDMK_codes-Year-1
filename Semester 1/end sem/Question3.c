#include<stdio.h>
struct mobile
{
   char *name[100];
   int modelno;
   float price;
};
void main()
{
void Cost(struct mobile m[], int n);
int n;
printf(" enter the number of mobile input you wnat to give \n");
scanf("%d", &n);
struct mobile m[n];
int i;
for(i=0; i<n; ++i)
{
  printf("\n Enter  modelno  and price\n");
  scanf("%d %f", &m[i].modelno, &m[i].price);
  printf("Enter mobile name : ");
  for(int j=0;j<100;j++)
    {
        scanf("%s", &m[i].&name[j]);
}
}
// To calculate total cost
Cost(m, n);
}

void Cost(struct mobile m[], int n)
{
int i;
float total = 0;
for(i=0; i<n; ++i)
 {
   total = total + m[i].price;  
 }
printf("The total cost is %f \n", total);
}
