/* Question 2 : Create a Binary Search Tree (BST) from random N numbers. N should be taken as input from
the user. Using the same N numbers, create the corresponding AVL tree. Show the height
difference between both these trees (BST vs AVL).
This Code was done by CS20B1044 Avinash R Changrani */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Structure of Binary Search Tree and AVL tree node and other functions
struct BST_node {
    int data;
    struct BST_node *left;
    struct BST_node *right;
};

struct BST_node* newnode(int data){
    struct BST_node *node = (struct BST_node*)malloc(sizeof(struct BST_node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
};

struct AVL_Node{
    int data;
    struct AVL_Node *left;
    struct AVL_Node *right;
    int height;
}; 

struct BST_node *insert(struct BST_node *root, int data){
    if (root == NULL){
        root = newnode(data);
    }
    else if (data < root->data){
        root->left = insert(root->left, data);
    }
    else if (data > root->data){
        root->right = insert(root->right, data);
    }
    return root;
};

int max(int a, int b){
    return (a > b)? a : b; // if a > b return a else return b
}

int height(struct AVL_Node *node){
    if (node == NULL)
        return 0;
    return node->height;
}

int getbalance(struct AVL_Node *node){
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

struct AVL_Node* Newnode(int data){
    struct AVL_Node *temp = (struct AVL_Node*)malloc(sizeof(struct AVL_Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;
    return (temp);
};

struct AVL_Node *rightRotate(struct AVL_Node *z){
    struct AVL_Node *y = z->left;
    struct AVL_Node *T3 = y->right;
    // Performing rotation
    y->right = z;
    z->left = T3;
    // Updating heights
    z->height = (max(height(z->left), height(z->right)) + 1);
    y->height = (max(height(y->left), height(y->right)) + 1);
    // Returning node
    return y;
};

struct AVL_Node *leftRotate(struct AVL_Node *z){
    struct AVL_Node *y = z->right;
    struct AVL_Node *T3 = y->left;
    // Performing rotation
    y->left = z;
    z->right = T3;
    // Updating heights
    z->height = (max(height(z->left), height(z->right)) + 1);
    y->height = (max(height(y->left), height(y->right)) + 1);
    return y;
};

struct AVL_Node *Insert(struct AVL_Node *root, int data){
    if (root == NULL){
        root = Newnode(data);
    }
    else if (data < root->data){
        root->left = Insert(root->left, data);
    }
    else if (data > root->data){
        root->right = Insert(root->right, data);
    }
     else // Equal values are not allowed in BST
        return root;
    // Updating height of the node    
    root->height = 1 + max(height(root->left), height(root->right));
    // Getting balance factor of the node to check if it's balanced or not
    int balance = getbalance(root);
    // If this node becomes unbalanced, then there are 4 cases
    // Left Left Case
    if (balance > 1 && data < root->left->data)
        return rightRotate(root);
    // Right Right Case
    if (balance < -1 && data > root->right->data)
        return leftRotate(root);
    // Left Right Case
    if (balance > 1 && data > root->left->data){
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }
    // Right Left Case
    if (balance < -1 && data < root->right->data){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    // returning unchanged pointer
    return root;
};

// Function Declarations
int get_height (struct BST_node *root);
void delete_BST(struct BST_node *root);
void delete_AVL(struct AVL_Node *root);

void main(){
    int n;
    int data;
    printf("Please enter the amount of random numbers needed to fill the tree\n");
    scanf("%d",&n);
    srand(time(NULL));
    struct BST_node *root = NULL;
    struct AVL_Node *r = NULL;
    printf("Random numbers are inserted in this order:\n");
    for (int i=0; i<n; i++) {
        data = rand()%100;
        printf("%d ",data);
        root = insert(root,data);
        r = Insert(r,data);
    }
    printf("\n");
    int BST_height = get_height(root);
    printf("The height of the Binary Search tree is %d\n", BST_height);
    int AVL_height = height(r);
    printf("The height of the AVL tree is %d\n", AVL_height);
    delete_BST(root);
    delete_AVL(r);
}


int get_height (struct BST_node *root){
    // If the root is null, this is the bottom of the tree (height 0)
    if (root == NULL)
        return 0;
    else
    {
        // Get the height from both left and right subtrees to check which is highest
        int right_h = get_height(root->right);
        int left_h = get_height(root->left); 
        // The final height is the height of the greatest subtree(left or right) plus 1(root's level)
        if (right_h > left_h)
        {
            return (right_h + 1);
        }
        else
        {
            return (left_h + 1);
        }
    }   
}

// Freeing BST
void delete_BST(struct BST_node *root){
    if (root == NULL)
        return;
    delete_BST(root->left);
    delete_BST(root->right);
    free(root);    
}

// Freeing AVL Tree
void delete_AVL(struct AVL_Node *root){
    if (root == NULL)
        return;
    delete_AVL(root->left);
    delete_AVL(root->right);
    free(root);    
}



