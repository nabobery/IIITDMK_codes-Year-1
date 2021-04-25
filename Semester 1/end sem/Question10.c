#include<stdio.h>
int x = 10;

void g(void)
{
int x = 100;
++x;
printf("%d", x);
}

void f(void)
{
static int x = -5;
x++;
printf("%d", x);
}

int main(void)
{
int i;
printf("\n values of the static variable x in f() : \n");
for(i=50; i<60; ++i)
 f();
printf("\n values of the non-static variable x in g() : \n");
for(i=-10; i<0; ++i)
 g();
{ 
int x =100;
printf("\nThe value of local variable x :  ");
printf("%d", x);
}
printf("\nThe value of global variable x : ");
printf("%d", x);

return(0);
}
