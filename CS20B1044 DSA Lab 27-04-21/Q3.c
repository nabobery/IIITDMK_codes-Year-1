/* Question 3 :  Create a Linked List of N students. Each student node will have roll_no, percentage of marks, and the corresponding grade. The roll_no will vary from 1 to N. Percentage of marks will be taken as a random input.
This question is done by CS20B1044 Avinash R Changrani */
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
// Declaration of structure (node) of the Linked List containing list of students
struct studentlist{
	int roll_no;
	float percentage;	
	char grade;
	struct studentlist *next;	
};	

// A function to free dynamically allocated memory of the linked lists
void freelist(void *head){
	struct studentlist *ptr = head;
	struct studentlist *free_ptr = NULL;
	while (ptr != NULL){
	   free_ptr = ptr->next;
	   free(ptr);
	   ptr = free_ptr;       
	}   
}

void main()
{
	struct studentlist *head = NULL;
	head = (struct studentlist*)malloc(sizeof(struct studentlist));
	int n;
	// Asking size of linked list(number of students) from user
	printf("Please enter the size of linked list you want\n");
	scanf("%d", &n);
	struct studentlist *ptr = head;
	srand(time(NULL));
	for(int i = 0; i < n; i++){
	    ptr->roll_no = i+1;
	    // Generate random percenatges for the nodes(stduent) of the linked list using rand() function
	    ptr->percentage = ((float)rand()/(float)(RAND_MAX)) * 100 ;
	    if (ptr->percentage >= 90) 
	       ptr->grade = 'A';
	    else if (ptr->percentage >= 80 && ptr->percentage < 90)  
	       ptr->grade = 'B';   
	    else if (ptr->percentage >= 70 && ptr->percentage < 80)  
	       ptr->grade = 'C';    
	    else if (ptr->percentage >= 60 && ptr->percentage < 70)  
	       ptr->grade = 'D'; 
	    else if (ptr->percentage >= 50 && ptr->percentage < 60)  
	       ptr->grade = 'E'; 
	    else if (ptr->percentage >= 35 && ptr->percentage < 50)  
	       ptr->grade = 'P'; 
	    else if (ptr->percentage < 35)  
	       ptr->grade = 'F'; 
	    if (i < n-1){	   	    
	      ptr->next = (struct studentlist*)malloc(sizeof(struct studentlist));
	      ptr = ptr->next;  
	    }
	    else {	    
	    ptr->next = NULL;
	  }	 
	}
	
	// Printing the elements(student details) of the linked list before splitting into assigned grade lists 	
	ptr = head;
	printf("The Students list before being listed grade wise : \n");
	while (ptr != NULL){	  
	  printf("Roll number: %d, Percentage : %f and Grade : %c of the student \n", ptr->roll_no, ptr->percentage, ptr->grade);
	  ptr = ptr->next;
        }
        // Creating heads of lists grade wise and assigninfg the pointer to it and a temporary pointer
	struct studentlist *head_a =(struct studentlist*) malloc(sizeof(struct studentlist));
	struct studentlist *head_b =(struct studentlist*) malloc(sizeof(struct studentlist));
	struct studentlist *head_c =(struct studentlist*) malloc(sizeof(struct studentlist));
	struct studentlist *head_d =(struct studentlist*) malloc(sizeof(struct studentlist));
	struct studentlist *head_e =(struct studentlist*) malloc(sizeof(struct studentlist));
	struct studentlist *head_p =(struct studentlist*) malloc(sizeof(struct studentlist));
	struct studentlist *head_f =(struct studentlist*) malloc(sizeof(struct studentlist));   
	struct studentlist *ptr_a = head_a, *temp_a = NULL;
	struct studentlist *ptr_b = head_b, *temp_b = NULL;
	struct studentlist *ptr_c = head_c, *temp_c = NULL;
	struct studentlist *ptr_d = head_d, *temp_d = NULL;
	struct studentlist *ptr_e = head_e, *temp_e = NULL;
	struct studentlist *ptr_p = head_p, *temp_p = NULL;
	struct studentlist *ptr_f = head_f, *temp_f = NULL;
	// dividing the list into lists based on grades 
	int a = 0,b = 0, c = 0, d = 0, e = 0, p = 0, f = 0; // to keep count of the number of elements of the grade based lists
	for(ptr = head; ptr != NULL; ptr = ptr->next){
	   if (ptr->grade == 'A'){
	      a =+ 1;
	      ptr_a->grade = ptr->grade;
	      ptr_a->percentage = ptr->percentage;
	      ptr_a->roll_no = ptr->roll_no;
	      ptr_a->next = (struct studentlist*)malloc(sizeof(struct studentlist));
	      temp_a = ptr_a;
	      ptr_a = ptr_a->next;
	   }
	   else if (ptr->grade == 'B'){
	      b =+ 1;
	      ptr_b->grade = ptr->grade;
	      ptr_b->percentage = ptr->percentage;
	      ptr_b->roll_no = ptr->roll_no;
	      ptr_b->next = (struct studentlist*)malloc(sizeof(struct studentlist));
	      temp_b = ptr_b;
	      ptr_b = ptr_b->next;
	   }
	   else if (ptr->grade == 'C'){
	      c =+ 1;
	      ptr_c->grade = ptr->grade;
	      ptr_c->percentage = ptr->percentage;
	      ptr_c->roll_no = ptr->roll_no;
	      ptr_c->next = (struct studentlist*)malloc(sizeof(struct studentlist));
	      temp_c = ptr_c;
	      ptr_c = ptr_c->next;
	   }
	   else if (ptr->grade == 'D'){
	      d =+ 1;
	      ptr_d->grade = ptr->grade;
	      ptr_d->percentage = ptr->percentage;
	      ptr_d->roll_no = ptr->roll_no;
	      ptr_d->next = (struct studentlist*)malloc(sizeof(struct studentlist));
	      temp_d = ptr_d;
	      ptr_d = ptr_d->next;
	   }
	   else if (ptr->grade == 'E'){
	      e =+ 1;
	      ptr_e->grade = ptr->grade;
	      ptr_e->percentage = ptr->percentage;
	      ptr_e->roll_no = ptr->roll_no;
	      ptr_e->next = (struct studentlist*)malloc(sizeof(struct studentlist));
	      temp_e = ptr_e;
	      ptr_e = ptr_e->next;
	   }
	   else if (ptr->grade == 'P'){
	      p =+ 1;
	      ptr_p->grade = ptr->grade;
	      ptr_p->percentage = ptr->percentage;
	      ptr_p->roll_no = ptr->roll_no;
	      ptr_p->next = (struct studentlist*)malloc(sizeof(struct studentlist));
	      temp_p = ptr_p;
	      ptr_p = ptr_p->next;
	   }
	   else if (ptr->grade == 'F'){
	      f =+ 1;
	      ptr_f->grade = ptr->grade;
	      ptr_f->percentage = ptr->percentage;
	      ptr_f->roll_no = ptr->roll_no;
	      ptr_f->next = (struct studentlist*)malloc(sizeof(struct studentlist));
	      temp_f = ptr_f;
	      ptr_f = ptr_f->next;
	   }
	}
	// Keeping the end pointer which is temp as NULL if we get a grade and if not just keep the head is NULL (list is empty)
	if (a > 0)
	   temp_a->next = NULL; 
	else 
	   head_a = NULL;
	if (b > 0)
	   temp_b->next = NULL; 
	else 
	   head_b = NULL;	      
	if (c > 0)
	   temp_c->next = NULL; 
	else 
	   head_c = NULL;
	if (d > 0)
	   temp_d->next = NULL; 
	else 
	   head_d = NULL;	      	       
	if (e > 0)
	   temp_e->next = NULL; 
	else 
	   head_e = NULL;
	if (p > 0)
	   temp_p->next = NULL; 
	else 
	   head_p = NULL;	      
	if (f > 0)
	   temp_f->next = NULL; 
	else 
	   head_f = NULL;
	// Printing the elements(student details) of the linked list after splitting into assigned grade lists 	
	printf("The Students list after being listed grade wise : \n");
	printf("Grade A : \n");
	for(ptr_a = head_a; ptr_a != NULL; ptr_a = ptr_a->next){	  
	  printf("Roll number: %d, Percentage : %f and Grade : %c of the student \n", ptr_a->roll_no, ptr_a->percentage, ptr_a->grade);
        }
        printf("Grade B : \n");
        for(ptr_b = head_b; ptr_b != NULL; ptr_b = ptr_b->next){	  
	  printf("Roll number: %d, Percentage : %f and Grade : %c of the student \n", ptr_b->roll_no, ptr_b->percentage, ptr_b->grade);
        }
	printf("Grade C : \n");
	for(ptr_c = head_c; ptr_c != NULL; ptr_c = ptr_c->next){	  
	  printf("Roll number: %d, Percentage : %f and Grade : %c of the student \n", ptr_c->roll_no, ptr_c->percentage, ptr_c->grade);
        }
        printf("Grade D : \n");
	for(ptr_d = head_d; ptr_d != NULL; ptr_d = ptr_d->next){	  
	  printf("Roll number: %d, Percentage : %f and Grade : %c of the student \n", ptr_d->roll_no, ptr_d->percentage, ptr_d->grade);
        }	
        printf("Grade E : \n");
	for(ptr_e = head_e; ptr_e != NULL; ptr_e = ptr_e->next){	  
	  printf("Roll number: %d, Percentage : %f and Grade : %c of the student \n", ptr_e->roll_no, ptr_e->percentage, ptr_e->grade);
        }	
        printf("Grade P : \n");
	for(ptr_p = head_p; ptr_p != NULL; ptr_p = ptr_p->next){	  
	  printf("Roll number: %d, Percentage : %f and Grade : %c of the student \n", ptr_p->roll_no, ptr_p->percentage, ptr_p->grade);
        }	
        printf("Grade F : \n");
	for(ptr_f = head_f; ptr_f != NULL; ptr_f = ptr_f->next){	  
	  printf("Roll number: %d, Percentage : %f and Grade : %c of the student \n", ptr_f->roll_no, ptr_f->percentage, ptr_f->grade);
	}
	// Freeeing the dynamically allocated memory		   
	freelist(head);  
	freelist(head_a); 
	freelist(head_b); 
	freelist(head_c); 
	freelist(head_d); 
	freelist(head_e); 
	freelist(head_p); 
	freelist(head_f); 

}
