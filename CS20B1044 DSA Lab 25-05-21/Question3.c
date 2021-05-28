/* Question 3 : Evaluation of a Prefix expression using stack. Your program should do the following.
• User should take an infix expression as input
• WAP to convert this infix expression to Prefix expression
• WAP to evaluate the above Prefix expression using stack.
This code is done by CS20B1044 Avinash R Changrani and only works for single digit operands*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Declaration of structure (node) of stack using Linked List
struct Node {
	char term;
	struct Node *next;
};

struct stack{
    struct Node *top;
};

struct Node_int {
    int term;
    struct Node_int *next;
};

struct final_stack{
    struct Node_int *top;
};

// Function Declaration of push and pop of stack and other
void push(struct stack *stack,char term);
char pop(struct stack *stack);
int check_operator(char ch);
int getPriority(char ch);
char get_top(struct stack *stack);
char *reverse(char *expr,int size);  // for reversing the infix expression
char *reverse_prefix(char *reversed_infix); // for getting the nearly postfix (reversed prefix) from the reversed infix 
void push_int(struct final_stack *stack,int term); // for final stack
char pop_int(struct final_stack *stack); // for final stack
int get_top_int(struct final_stack *stack); // for final stack
int evaluate_prefix(char *prefix); // for evaluation of the prefix expression 

void main() {
    char* infix;
    infix = (char*)malloc(100*sizeof(char));
    printf("Please enter the infix expression you want : \n"); // without space between operands
    scanf("%s", infix);
    int size = strlen(infix);
    printf("The given infix expression is %s \n", infix);
    char *reversed_infix = reverse(infix,size); // Reversing the infix expression and changing the brackets
    char *reversed_prefix = reverse_prefix(reversed_infix);
    char *prefix = reverse(reversed_prefix, strlen(reversed_prefix));
    printf("The Prefix expression is %s \n", prefix);
    int result = evaluate_prefix(prefix);
    printf("The evaluation of the given expression : %s using stack is %d \n", infix, result);
}

// Function Definition of push and pop of stack and other
void push(struct stack *stack, char term) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->term = term;
    temp->next = stack->top;
    stack->top = temp;
}

char pop(struct stack *stack){
    char term;
    struct Node *temp;
    temp = stack->top;
    stack->top = stack->top->next;
    term = temp->term;
    free(temp);
    return term;
}

char get_top(struct stack *stack){
    if(stack->top == NULL){
        printf("Stack is empty\n");
        exit(0);
    }
    return stack->top->term;
}

char *reverse(char *expr,int size){
    char *reversed_expr =(char*)malloc(100 * sizeof(char));
    *(reversed_expr + size) = '\0'; // first element is NULL
    for (int i = 0; i < size; i++){
        if (*(expr + i) == '('){
            *(reversed_expr + size - i - 1) = ')';
        }    
        else if (*(expr + i) == ')'){
            *(reversed_expr + size - i - 1) = '(';
        }
        else {
            *(reversed_expr + size - i - 1) = *(expr + i);
        }
    }
    return reversed_expr;
} 

int getPriority(char ch)
{
    if (ch == '-' || ch == '+')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    return 0;
}

int check_operator(char ch){
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'||ch=='('||ch==')'){
        return 1;
    }
    return 0;
}

char *reverse_prefix(char *reversed_infix){
    char *reverse_prefix = (char*)malloc(sizeof(strlen(reversed_infix)*sizeof(char)));
    struct stack *result_stack =(struct stack*)malloc(sizeof(struct stack));
    result_stack->top =NULL; 
    int i,k;
    for (i = 0, k = -1;*(reversed_infix + i) != '\0';++i){
        if(!check_operator(*(reversed_infix + i)))
            *(reverse_prefix + (++k)) = *(reversed_infix + i);
        else if(*(reversed_infix + i) == '(')
            push(result_stack,*(reversed_infix + i));
        else if(*(reversed_infix + i) == ')'){
            while(result_stack->top != NULL && get_top(result_stack) != '(')
                *(reverse_prefix + (++k)) = pop(result_stack);
            pop(result_stack);
        }
        else{
            if(*(reversed_infix + i) == '^'){
                while(result_stack->top != NULL && getPriority(*(reversed_infix + i)) <= getPriority(get_top(result_stack)))
                    *(reverse_prefix + (++k)) = pop(result_stack);
 
            }
            else{
                while(result_stack->top != NULL && getPriority(*(reversed_infix + i)) < getPriority(get_top(result_stack)))
                    *(reverse_prefix + (++k)) = pop(result_stack);
 
            }
            push(result_stack,*(reversed_infix + i));
        }
 
 
    }
    while(result_stack->top != NULL){
        *(reverse_prefix + (++k)) = pop(result_stack);
    }
    *(reverse_prefix + (++k)) = '\0';
    return reverse_prefix;  
}

void push_int(struct final_stack *stack,int term){
    struct Node_int *temp = (struct Node_int*)malloc(sizeof(struct Node_int));
    temp->term = term;
    temp->next = stack->top;
    stack->top = temp;
}

char pop_int(struct final_stack *stack){
    int term;
    struct Node_int *temp;
    temp = stack->top;
    stack->top = stack->top->next;
    term = temp->term;
    free(temp);
    return term;
}

int get_top_int(struct final_stack *stack){
    if(stack->top == NULL){
        printf("Stack is empty\n");
        exit(0);
    }
    return stack->top->term;    
}

int evaluate_prefix(char *prefix){
    struct final_stack *result_stack =(struct final_stack*)malloc(sizeof(struct final_stack));
    result_stack->top = NULL;
    int size = strlen(prefix);
    while (size != 0){
        if(!check_operator(*(prefix + size - 1)))
            push_int(result_stack,*(prefix + size - 1)-48);
        else{
            int a,b,result = 1;
            b = pop_int(result_stack);
            a = pop_int(result_stack);
            if(*(prefix + size - 1) == '+')
                result = b+a;
            else if(*(prefix + size - 1) == '-')
                result = b-a;
            else if(*(prefix + size - 1) == '*')
                result = b*a;
            else if(*(prefix + size - 1) == '/')
                result = b/a;
            else if(*(prefix + size - 1) == '^'){
                for (int i = 0; i < a; ++i) {
                    result *= b;
                }
            }
            push_int(result_stack,result);
        }
        size -= 1;
    }
    return get_top_int(result_stack);
}



