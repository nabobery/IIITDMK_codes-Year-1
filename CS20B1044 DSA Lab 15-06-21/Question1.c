/* Question 1 : Create a doubly Linked List (Two-way Linked List) from the Calander month names (January,
February, March........December). Convert this to it's corresponding balanced Binary Search
Tree (BST). Perform the In-order traversal.
This Code was done by CS20B1044 Avinash R Changrani */

#include<stdio.h>
#include<stdlib.h>

//Structure for Doubly linked list node and tree node.
struct Node{
    char *month;
    struct Node *prev;
    struct Node *next;
};

struct Node* DLLToBSTRecur(struct Node **head_ref, int n);
// For Tree
struct Node* newnode(char *month){
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->month = month;
    node->prev = NULL;
    node->next = NULL;
    return (node);
};

struct Node* DLLToBST(struct Node *head)
{
    // To Construct BST and return root 
    return DLLToBSTRecur(&head, 12);
};

struct Node* DLLToBSTRecur(struct Node **head_ref, int n)
{
    // Base Case 
    if (n <= 0)
        return NULL;
    // Recursively construct the left subtree 
    struct Node *left = DLLToBSTRecur(head_ref, n/2);
    // Allocate memory for root, and link the above constructed left subtree with root 
    struct Node *root = newnode((*head_ref)->month);
    root->prev = left;
    // Change head pointer of DLL for parent recursive calls 
    *head_ref = (*head_ref)->next;
    // Recursively construct the right subtree and link it with root.
    // The number of nodes in right subtree  is total nodes - nodes in  left subtree - 1 (for root) which is n-n/2-1 
    root->next = DLLToBSTRecur(head_ref, n-n/2-1);
    return root;
}

// Function Declarations
void Inorder(struct Node *root);
void deleteBinary_tree(struct Node *root);

void main(){
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    head->prev = NULL;
    head->month = "January";
    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->prev = head;
    head->next->month = "February";
    head->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->prev = head->next;
    head->next->next->month = "March";
    head->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->next->prev = head->next->next;
    head->next->next->next->month = "April";
    head->next->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->next->next->prev = head->next->next;
    head->next->next->next->next->month = "May";
    head->next->next->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->next->next->next->prev = head->next->next->next->next;
    head->next->next->next->next->next->month = "June"; 
    head->next->next->next->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->next->next->next->next->prev = head->next->next->next->next->next;
    head->next->next->next->next->next->next->month = "July";
    head->next->next->next->next->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->next->next->next->next->next->prev = head->next->next->next->next->next->next;
    head->next->next->next->next->next->next->next->month = "August";
    head->next->next->next->next->next->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->next->next->next->next->next->next->prev = head->next->next->next->next->next->next->next;
    head->next->next->next->next->next->next->next->next->month = "September";
    head->next->next->next->next->next->next->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->next->next->next->next->next->next->next->prev = head->next->next->next->next->next->next->next->next;
    head->next->next->next->next->next->next->next->next->next->month = "October";
    head->next->next->next->next->next->next->next->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->next->next->next->next->next->next->next->next->prev = head->next->next->next->next->next->next->next->next->next;
    head->next->next->next->next->next->next->next->next->next->next->month = "November";
    struct Node *tail = head->next->next->next->next->next->next->next->next->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    tail->prev = head->next->next->next->next->next->next->next->next->next->next;
    tail->month = "December";
    tail->next = NULL;
    struct Node *root = DLLToBST(head);
    printf("The Inorder traversal of the Binary Search Tree is :\n");
    Inorder(root);
    printf("\n");
    deleteBinary_tree(root);
}

// Function Definitions
void Inorder(struct Node *root){
    if(root){
        Inorder(root->prev);
        printf("%s ", root->month);
        Inorder(root->next);
    }
}

// Freeing Binary Search Tree
void deleteBinary_tree(struct Node *root){
    if (root == NULL)
        return;
    deleteBinary_tree(root->prev);
    deleteBinary_tree(root->next);
    free(root);    
}