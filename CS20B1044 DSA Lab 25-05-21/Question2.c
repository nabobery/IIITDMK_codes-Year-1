/* Question 2 : Implement a character stack using Linked List. PUSH and POP operations should be clearly
defined. WAP to take a random string as user-input. String should be a combination of
alphabets. Traverse through the string and do the following operations.
• If a consonant is encounterd, PUSH to the stack.
• If a vowel is encounterd, POP from the stack
• Show the content of the top of the stack after each operation
This code is done by CS20B1044 Avinash R Changrani */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Declaration of structure (node) of stack using Linked List
struct Node {
	char ch;
	struct Node *next;
} *top;

// Function Declaration of push and pop of stack and other
void push(char ch);
char pop();
int check_vowel(char ch);

void main() {
    // Getting random string based on user input of size
    int size;
    char *string;
    printf("Please enter the size of the random string : \n");
    scanf("%d", &size);
    string = (char*)malloc(size*sizeof(char));
    printf("Please enter the random string of the size %d : \n", size);
    scanf("%s", string);
    top = NULL;
    for (int i = 0; i < size; i++){
        if (check_vowel(string[i])){
            if (top == NULL){
                printf("The stack is empty \n");
            }
            else{
                pop();
                if (top == NULL){
                    printf("The stack is empty \n");     
                }
                else {
                    printf("The top of the stack currently is %c \n", top->ch);
                }    
            }
        }
        else if (!check_vowel(string[i])) {
            push(string[i]);
            printf("The top of the stack currently is %c \n", top->ch);
        }
    }

}

// Function Definition of push and pop of stack and other
void push(char ch) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->ch = ch;
    temp->next = top;
    top = temp;
}

char pop(){
    char ch;
    struct Node *temp;
    temp = top;
    top = top->next;
    ch = temp->ch;
    free(temp);
    return ch;
}

int check_vowel(char ch){
    if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
        return 1; // True if ch is a vowel
    }
    return 0; // False if ch is a consonant
}