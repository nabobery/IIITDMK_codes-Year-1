// PSP Assignment Question 16 done by CS20B1044 Avinash R Changrani 
#include<stdio.h>
void main()
{
// Defining variables to store the quantity of the items 
int Iddy_qty = 0, Dosa_qty = 0, Pongal_qty = 0, Chappathy_qty = 0, VegBriyani_qty = 0, Tea_qty = 0, Coffee_qty = 0, Vada_qty = 0; 
// Defining variables to store total amount of items and total bill
int item_qty, bill_total;
// Introduction
printf("Welcome to the restaurent? \nWhat would you like to have?\n");

// Loop to calculate the item bill along with menu
do {
    printf("PLease Enter number between 1 and 8 to view the Menu and the order the quantities of items you want to order and Enter 0 if you want to end your order\n");
    scanf("%d",&item_qty);
    switch(item_qty){
       case 0:
              break;
       case 1:
            printf("Item - Iddy, Price - 10\n");
            printf("Please enter the amount of items you would want to order\n");
            scanf("%d",&Iddy_qty);
            break;
       case 2:
            printf("Item - Dosa, Price - 30\n");
            printf("Please enter the amount of items you would want to order\n");
            scanf("%d",&Dosa_qty);
            break;    
       case 3:
            printf("Item - Pongal, Price - 30\n");
            printf("Please enter the amount of items you would want to order\n");
            scanf("%d",&Pongal_qty);
            break;
       case 4:
            printf("Item - Chappathy, Price - 40\n");
            printf("Please enter the amount of items you would want to order\n");
            scanf("%d",&Chappathy_qty);
            break;
       case 5:
            printf("Item - Veg Briyani, Price - 120\n");
            printf("Please enter the amount of items you would want to order\n");
            scanf("%d",&VegBriyani_qty);
            break;  
       case 6:
            printf("Item- Tea, Price - 10\n");
            printf("Please enter the amount of items you would want to order\n");
            scanf("%d",&Tea_qty);
            break;
       case 7:
            printf("Item- Coffee, Price - 15\n");
            printf("Please enter the amount of items you would want to order\n");
            scanf("%d",&Coffee_qty);
            break;
       case 8:
            printf("Item - Vada,Price - 20\n");
            printf("Please enter the amount of items you would want to order\n");
            scanf("%d",&Vada_qty);
            break;
       default:
            printf("Please enter a number between 1 and 8!\n");  
            
       }
   } while (item_qty != 0);

  bill_total = (Iddy_qty * 10) + (Dosa_qty * 30) + (Pongal_qty * 30) + (Chappathy_qty * 40) + (VegBriyani_qty * 120) + (Tea_qty * 10) + (Coffee_qty * 15) + (Vada_qty * 20);
  printf("The total amount to be paid is  %d\n",bill_total);
  printf("Please Visit again\n");

}    
                      




            
            
                
            

            
               
            
            

    
