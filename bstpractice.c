#include<stdio.h>
#include<stdlib.h>

struct tree 
{
    int data;
    struct tree * left;
    struct tree * right;
};

typedef struct tree * TREE;

TREE create( int x)
{
    TREE newnode = malloc( sizeof(struct tree) );
    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

TREE insert( TREE node , int x)
{
    if( node == NULL )
    {
        return create(x);
    }
    
    if( node->data > x )
    {
        node->left = insert( node->left , x );
    }

    if( node->data < x )
    {
        node->right = insert( node->right, x );
    }

    return node;
}

void inorder(TREE node)
{
    if( node == NULL )
    {
        return;
    }
    inorder(node->left);
    printf("%d " , node->data);
    inorder( node->right );
}
void preorder(TREE node)
{
    if( node == NULL )
    {
        return;
    }
    printf("%d " , node->data);
    preorder(node->left);
    preorder( node->right );
}

void postorder(TREE node)
{
    if( node == NULL )
    {
        return;
    }
    postorder(node->left);
    postorder( node->right );
    printf("%d " , node->data);
}

int main()
{
    int a;
    TREE root = NULL;
    while(1)
    {
        scanf("%d" , &a);
        if( a== -1)
        {
            break;
        }
        root = insert( root , a );
    }

    printf("INORDER : ");
    inorder(root);
    printf("\n");
    printf("PREORDER : ");
    preorder(root);
    printf("\n");
    printf("POSTORDER : ");
    postorder(root);
    printf("\n");

}
