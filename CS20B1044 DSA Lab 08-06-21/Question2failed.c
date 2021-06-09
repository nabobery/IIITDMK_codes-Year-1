/* Question 2 : Create a Complete Binary Tree made up of all the alphabets (A to Z) using Linked List. A is the
root of the tree. B and C will be the left and right children of A, respectively, and so on. Write
the recursive functions for Pre-Order, In-Order and Post-Order traversals to print the elements
in the Tree.
This code is done by CS20B1044 Avinash R Changrani */

#include<stdio.h>
#include<stdlib.h>

// Structure of Binary Tree node
struct node{
    char ch;
    struct node *left;
    struct node *right;
    struct node *next;
};

struct Queue{
    struct node *front, *rear;
}; 

struct node* newnode(int data){
    struct node *node = (struct node*)malloc(sizeof(struct node));
    node->ch = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
};

// Function Declarations for Enqueue, Dequeue, Preorder, Inorder and Postorder
void enqueue(struct Queue *q,int data); 
char dequeue(struct Queue *q);
void insert(struct node **root, int data, struct Queue *q);
void Preorder(struct node *root);
void Inorder(struct node *root);
void Postorder(struct node *root);
void deleteBinary_tree(struct node *root);

void main(){
    struct node *root = NULL;
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    int count = 65;
    while (count <= 90){
        insert(&root,count,q);
        count += 1;
    }
    printf("The Preorder traversal of the given Binary tree is : \n");
    Preorder(root);
    printf("\n");
    printf("The Inorder traversal of the given Binary tree is : \n");
    Inorder(root);
    printf("\n");
    printf("The Postorder traversal of the given Binary tree is : \n");
    Postorder(root);
    printf("\n");
    deleteBinary_tree(root);
}

// Function Definitions for Enqueue, Dequeue, Preorder, Inorder and Postorder
void enqueue(struct Queue *q, int data) {
    struct node *temp = newnode(data);
    // if empty queue and should add first element
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

char dequeue(struct Queue *q){
    char data;
    struct node *temp;
    if (q->front == NULL)
        return 0;
    else{    
        temp = q->front;
        data = q->front->ch;
        q->front = q->front->next;
        free(temp);   
    } 
    return data;
}

void insert(struct node **root, int data, struct Queue *q){
    struct node *temp = newnode(data);
    if(!*root)
        *root = temp;
    else{    
        struct node *node = q->front;
        //If the left child of this front node doesn't exist, set the left side as the new node
        if(!node->left)
            node->left = temp;
        //If the right child of this front node doesn't exist, set the rigth side as the new node    
        else if (!node->right)
            node->right = temp;
        // If it has both left and right child then dequeue    
        if (node && node->left && node->right)
            dequeue(q);
    }
    enqueue(q,data);
}

void Preorder(struct node *root){
    if(root){
        printf("%c ",root->ch);
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Inorder(struct node *root){
    if(root){
        Inorder(root->left);
        printf("%c ", root->ch);
        Inorder(root->right);
    }
}

void Postorder(struct node *root){
    if(root){
        Postorder(root->left);
        Postorder(root->right);
        printf("%c ", root->ch);
    }
}

// Freeing the Binary tree
void deleteBinary_tree(struct node *root){
    if (root == NULL)
        return;
    deleteBinary_tree(root->left);
    deleteBinary_tree(root->right);
    free(root); 
}