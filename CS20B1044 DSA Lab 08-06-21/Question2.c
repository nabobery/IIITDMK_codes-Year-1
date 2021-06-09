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
};

struct Qnode{
    struct node *Node;
    struct Qnode *next;
};

struct Queue{
    struct Qnode *front, *rear;
}; 

struct node* newnode(int data){
    struct node *node = (struct node*)malloc(sizeof(struct node));
    node->ch = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
};

struct node* Dequeue(struct Queue *q)
{
	if (q->front == NULL)
		return NULL;

	struct Qnode* temp = q->front;

	if (q->front == q->rear)
		q->front = q->rear = NULL;
	else
		q->front = q->front->next;

	free(temp);
}

// Function Declarations for Enqueue, Dequeue, Preorder, Inorder and Postorder
void Enqueue(struct node *root, struct Queue *q);
void insert(struct node **root, int data, struct Queue *q);
void Preorder(struct node *root);
void Inorder(struct node *root);
void Postorder(struct node *root);
void deleteBinary_tree(struct node *root);

void main(){
    struct node *root = NULL;
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    for(int i = 65; i <= 90; ++i)
		insert(&root, i, q);
    printf("The Preorder traversal of the given Binary tree is : \n");
    Preorder(root);
    printf("\n");
    printf("The Inorder traversal of the given Binary tree is : \n");
    Inorder(root);
    printf("\n");
    printf("The Postorder traversal of the given Binary tree is : \n");
    Postorder(root);
    printf("\n");    
}

void Enqueue(struct node *root, struct Queue *q)
{
	struct Qnode *temp = (struct Qnode *)malloc(sizeof(struct Qnode));
    temp->Node = root;
    temp->next = NULL;
    if (q->rear == NULL){
        q->rear = q->front = temp;
    }
	else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

void insert(struct node **root, int data, struct Queue* q)
{
	// Create a new node for given data
	struct node *temp = newnode(data);

	// If the tree is empty, initialize the root with new node.
	if (!*root)
		*root = temp;

	else
	{
        // get the front node of the queue.
		struct node* front = q->front->Node;
    	// If the left child of this front node doesn’t exist, set the
		// left child as the new node
		if (!front->left)
			front->left = temp;

		// If the right child of this front node doesn’t exist, set the
		// right child as the new node
		else if (!front->right)
			front->right = temp;

		// If the front node has both the left child and right child,
		// Dequeue() it.
		if (front && front->left && front->right)
			Dequeue(q);
	}

	// Enqueue() the new node for later insertions
	Enqueue(temp, q);
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