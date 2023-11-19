#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
};

// Function to create a new node with a given key
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1; // New node is initially added as a leaf node
    return newNode;
}

// Function to get the height of a node
int height(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

// Function to get the balance factor of a node
int getBalance(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

// Function to perform a right rotation
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + maxi(height(y->left), height(y->right));
    x->height = 1 + maxi(height(x->left), height(x->right));

    return x;
}

// Function to perform a left rotation
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + maxi(height(x->left), height(x->right));
    y->height = 1 + maxi(height(y->left), height(y->right));

    return y;
}

// Function to find the minimum key node in a tree
struct Node* findMin(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to insert a node with a given key into the AVL tree
struct Node* insert(struct Node* root, int key) {
    // Perform standard BST insertion
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    } else {
        // Duplicate keys are not allowed in AVL trees
        return root;
    }

    // Update the height of the current node
    root->height = 1 + maxi(height(root->left), height(root->right));

    // Get the balance factor
    int balance = getBalance(root);

    // Perform rotations if necessary
    if (balance > 1 && key < root->left->key) {
        return rightRotate(root);
    }

    if (balance < -1 && key > root->right->key) {
        return leftRotate(root);
    }

    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to delete a node with a given key from the AVL tree
struct Node* deleteNode(struct Node* root, int key) 
{
    if (root == NULL) {
        return root;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with the key found, delete it
        if (root->left == NULL || root->right == NULL) {
            struct Node* temp = (root->left) ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }

            free(temp);
        } else {
            // Node with two children: Get the in-order successor (smallest in the right subtree)
            struct Node* temp = findMin(root->right);

            // Copy the in-order successor's data to this node
            root->key = temp->key;

            // Delete the in-order successor
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL) {
        return root;
    }

    // Update the height of the current node
    root->height = 1 + maxi(height(root->left), height(root->right));

    // Get the balance factor
    int balance = getBalance(root);

    // Perform rotations if necessary
    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to print the AVL tree in a visual format
void printTreeToFile(FILE* file, struct Node* root, int space) {
    if (root == NULL) {
        return;
    }

    space += 5;

    printTreeToFile(file, root->right, space);

    fprintf(file, "\n");
    for (int i = 5; i < space; i++) {
        fprintf(file, " ");
    }
    fprintf(file, "%d\n", root->key);

    printTreeToFile(file, root->left, space);
}

// Function to find the maxiimum of two integers
int maxi(int a, int b) 
{
    return (a > b) ? a : b;
}

int main() 
{
    struct Node* root = NULL;
    while(1)
    {
        system("cls");
        printf("1.ADD\n2.DELETE\n\n");
        int choice ;
        scanf("%d" , &choice);
        if( choice ==1 )
        {
            printf("ENTER ELEMENT :");
            int ele;
            scanf("%d",&ele);
            root = insert(root, ele);
            FILE* outputFile = fopen("avltree.txt", "w");
            printTreeToFile(outputFile, root, 0);
            fclose(outputFile);
        }
        if( choice == 2 )
        {
            printf("ENTER ELEMENT TO DEL:");
            int ele;
            scanf("%d",&ele);
            root = deleteNode(root, ele);
            FILE* outputFile = fopen("avltree.txt", "w");
            printTreeToFile(outputFile, root, 0);
            fclose(outputFile);
        }
    }

    return 0;
}
