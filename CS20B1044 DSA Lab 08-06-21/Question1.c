/* Question 1 : Create an integer Binary Tree (height>=3) of your choice using Linked List. Fill the integers
randomly. After creation of the Tree, Write the recursive functions for Pre-Order, In-Order and
Post-Order traversals. While traversing, find the Mean and Standard Deviation of the elements
in the tree.
This code is done by CS20B1044 Avinash R Changrani */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

// Structure of Binary Tree node
struct Binary_tree{
    int data;
    struct Binary_tree *left;
    struct Binary_tree *right;
};

struct Binary_tree* newnode(int data){
    struct Binary_tree *node = (struct Binary_tree*)malloc(sizeof(struct Binary_tree));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
};

// Function Declarations for Preorder, Inorder and Postorder
void Preorder(struct Binary_tree *root);
void Inorder(struct Binary_tree *root);
void Postorder(struct Binary_tree *root);
void deleteBinary_tree(struct Binary_tree *root);
int add(struct Binary_tree *root);
int sizeofBinarytree(struct Binary_tree *root);
float sum_deviation(struct Binary_tree *root, float mean);

void main(){
    struct Binary_tree *root = (struct Binary_tree*)malloc(sizeof(struct Binary_tree));
    srand(time(NULL));
    root->data = rand()%100;
    root->left = newnode(rand()%100); 
    root->right = newnode(rand()%100);
    root->left->left = newnode(rand()%100);
    root->left->right = newnode(rand()%100);
    root->left->left->left = newnode(rand()%100);
    root->right->right = newnode(rand()%100);
    printf("The Preorder traversal of the given Binary tree is : \n");
    Preorder(root);
    printf("\n");
    printf("The Inorder traversal of the given Binary tree is : \n");
    Inorder(root);
    printf("\n");
    printf("The Postorder traversal of the given Binary tree is : \n");
    Postorder(root);
    printf("\n");
    float sum = add(root);
    int size = sizeofBinarytree(root);
    float mean = sum / size;
    printf("The mean of the given Binary tree is : %f \n", mean);
    float sum_dev = sum_deviation(root, mean);
    float variance = sum_dev/size;
    float strandard_deviation = sqrt(variance);
    printf("The Standard deviation of the given Binary tree is : %f \n", strandard_deviation);
    deleteBinary_tree(root);
}

// Function Definitions for Preorder, Inorder and Postorder
void Preorder(struct Binary_tree *root){
    if(root){
        printf("%d ",root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Inorder(struct Binary_tree *root){
    if(root){
        Inorder(root->left);
        printf("%d ", root->data);
        Inorder(root->right);
    }
}

void Postorder(struct Binary_tree *root){
    if(root){
        Postorder(root->left);
        Postorder(root->right);
        printf("%d ", root->data);
    }
}

// Freeing the Binary Tree
void deleteBinary_tree(struct Binary_tree *root){
    if (root == NULL)
        return;
    deleteBinary_tree(root->left);
    deleteBinary_tree(root->right);
    free(root);    
}

int sizeofBinarytree(struct Binary_tree *root){
    if (root == NULL)
        return 0;
    else 
        return (sizeofBinarytree(root->left) + 1 + sizeofBinarytree(root->right));  
}

int add(struct Binary_tree *root){
    if (root == NULL)
        return 0;
    else
        return ((root->data) + add(root->left) + add(root->right));    
}

float sum_deviation(struct Binary_tree *root, float mean){
    if (root == NULL)
        return 0;
    else 
        return (((root->data - mean)*(root->data + mean)) + sum_deviation(root->left, mean) + sum_deviation(root->right, mean));    
}