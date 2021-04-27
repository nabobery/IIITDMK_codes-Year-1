/* Question 3 : Create a structure for a student database having different variables, such as student_name, age, roll_no and address. Use this structure in your program to store the infomration about you and then print it on the console.
This Question has been done by CS20B1044 Avinash R Changrani */
#include<stdio.h>
// Defining the Structure
struct student {
    char student_name[50];
    int age;
    char roll_no[20];
    char address[100];
  } ;
void main()
{  
  char temp;
  struct student s;
// Getting information from User and storing it 
  printf("Enter information about yourself:\n");
  printf("Enter name: \n");
  scanf("%[^\n]", s.student_name);
  printf("Enter age: \n");
  scanf("%d", &s.age);
  printf("Enter roll number: \n");
  scanf("%s", s.roll_no);
  printf("Enter address: \n");
  scanf("%c",&temp); 
  scanf("%[^\n]", s.address);
// Printing the Information stored
  printf("Information about the student : \n");
  printf("Name: %s \n", s.student_name);
  printf("Age: %d\n", s.age);
  printf("Roll number: %s\n", s.roll_no);
  printf("Address: %s \n", s.address);
  
  
}
