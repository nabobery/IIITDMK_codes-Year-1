/* Question 4 : Rewrite the above program by taking the student_name and address as character pointers. Use malloc function to assign dynamic memory.
 This Question is done by CS20B1044 Avinash R Changrani */
#include<stdio.h>
#include<stdlib.h>
// Defining the Structure
struct student {
    char *student_name;
    int age;
    char roll_no[20];
    char *address;
  } ;
void main()
{
  char temp;
  struct student s;
// Using malloc to allocate memory dynamically  
  s.student_name = (char*)malloc(50*sizeof(char));
  s.address = (char*)malloc(100*sizeof(char));
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
 
