/* Question 2 : Create a Binary Search Tree (BST) from random N numbers. N should be taken as input from
the user. Using the same N numbers, create the corresponding AVL tree. Show the height
difference between both these trees (BST vs AVL).
This Code was done by CS20B1044 Avinash R Changrani */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define COUNT 10

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
    return (node->height);
}

int getbalance(struct AVL_Node *node){
    if (node == NULL)
        return 0;
    return (height(node->left) - height(node->right));
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

struct AVL_Node *Insert(struct AVL_Node *r, int data){
    if (r == NULL){
        r = Newnode(data);
    }
    else if (data < r->data){
        r->left = Insert(r->left, data);
    }
    else if (data > r->data){
        r->right = Insert(r->right, data);
    }
    else // Equal values are not allowed in BST
        return r;
    // Updating height of the node    
    r->height = 1 + max(height(r->left), height(r->right));
    // Getting balance factor of the node to check if it's balanced or not
    int balance = getbalance(r);
    // If this node becomes unbalanced, then there are 4 cases
    // Left Left Case
    if (balance > 1 && data < r->left->data)
        return rightRotate(r);
    // Right Right Case
    if (balance < -1 && data > r->right->data)
        return leftRotate(r);
    // Left Right Case
    if (balance > 1 && data > r->left->data){
        r->left =  leftRotate(r->left);
        return rightRotate(r);
    }
    // Right Left Case
    if (balance < -1 && data < r->right->data){
        r->right = rightRotate(r->right);
        return leftRotate(r);
    }
    // returning unchanged pointer
    return r;
};

// Function Declarations
void Inorder(struct BST_node *root);
int get_height (struct BST_node *root);
void print2DUtil(struct BST_node *root, int space);
void print2D(struct BST_node *root);
void printAVL(struct AVL_Node *node, int level);
void printBST(struct BST_node *root, int level);

void main(){
    int n;
    int data;
    printf("Please enter the amount of random numbers needed to fill the tree\n");
    scanf("%d",&n);
    srand(time(NULL));
    struct BST_node *root = NULL;
    struct AVL_Node *r = NULL;
    for (int i=0; i<n; i++) {
        data = rand()%100;
        printf("%d ",data);
        root = insert(root,data);
        r = Insert(r,data);
    }
    printf("\n");
    Inorder(root);
    printf("\n");
    int BST_height = get_height(root);
    printf("BST Height: %d\n", BST_height);
    //print2D(root);
    printBST(root,1);
    printf("\n");
    int AVL_height = height(r);
    printf("AVL Height: %d\n", AVL_height);
    printAVL(r,1);

}

// Function Definitions
void Inorder(struct BST_node *root){
    if(root){
        Inorder(root->left);
        printf("%d ", root->data);
        Inorder(root->right);
    }
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

void print2DUtil(struct BST_node *root, int space){
    // Base case
    if (root == NULL)
        return;
  
    // Increase distance between levels
    space += COUNT;
  
    // Process right child first
    print2DUtil(root->right, space);
  
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
  
    // Process left child
    print2DUtil(root->left, space);
}
  
// Wrapper over print2DUtil()
void print2D(struct BST_node *root){
   // Pass initial space count as 0
   print2DUtil(root, 0);
}

void printBST(struct BST_node *root, int level){
    if (root != NULL){
        printBST(root->right, level + 1);
        printf("\n\n");
        for (int i = 0; i <level; i++) printf("\t");
        printf("%d", root->data);
        printBST(root->left, level + 1);
        
    }
}

void printAVL(struct AVL_Node *node, int level){
    int i;
    if (node != NULL){
        printAVL(node->right, level + 1);
        printf("\n\n");

        for (i = 0; i < level; i++) printf("\t");

        printf("%d", node->data);

        printAVL(node->left, level + 1);
    }
}