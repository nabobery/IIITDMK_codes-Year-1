// PSP Assignment Question 20 done by CS20B1044 Avinash R Changrani
#include<stdio.h>
#include <stdlib.h>
int main()
{
    int input, array[31], carry = 1,mod_input;
    printf("This is a program that reads an integer and outputs 2's complement representation of the integer using 32 bits.\n");
    printf("Please Enter an integer between -2147483648 and 2147483647\n");
    scanf("%d", &input);
    mod_input = abs(input);
    if (input < -21474836478) {
        printf("Underflow Error\nPlease Enter an integer between -2147483648 and 2147483647\n");
    } else if (input > 2147483647) {
        printf("Overflow Error\nPlease Enter an integer between -2147483647 and 2147483647\n");
    } else if (input == 0)
        printf("The required integer in signed representation is 00000000000000000000000000000000");
// For Positive Integers
    if (input > 0 && input <=2147483647)
    {
        for(int i=0;i<=31;i++)
        {
            array[i]=0;
        }
        for(int i=0;input > 0;i++)
        {
            array[i] = input % 2;
            input = input / 2;
        }
        for(int i=31;i>=0;i--)
        {
            printf("%d",array[i]);
        }
        printf("\n");
    }
// For negative integers
    if (input < 0 && input >= -2147483647)
    {
        for(int i=0;i<32;i++)
        {
            array[i]=0;
        }
        for(int i=0;mod_input > 0;i++)
        {
            array[i] = mod_input % 2;
            mod_input = mod_input / 2;
        }
// To get one's complement
        for(int i = 0; i < 32; i++)
        {
            if(array[i] == 0)
            {
                array[i] = 1;
            }
            else
            {
                array[i] = 0;
            }
        }
// Now to add 1 to the one's complement
        for(int i = 0; i < 32; i++)
        {
            if(array[i] == 1 && carry == 1)
            {
                array[i] = 0;
                carry = 1;
            }
            else if(array[i] == 0 && carry == 1)
            {
                array[i] = 1;
                carry = 0;
            }
            else if(array[i] == 1 && carry == 0)
            {
                array[i] = 1;
                carry = 0;
            }
            else if(array[i] == 0 && carry == 0)
            {
                array[i] = 0;
                carry = 0;
            }
        }
        for (int i = 31; i >= 0; i--)
        {
            printf("%d", array[i]);
        }
        printf("\n");
    }
 
 
 
 
}
