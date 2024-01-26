#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int data;

    struct Node* left;
    struct Node* right;
} Node;

Node* insert(Node* root, int data)
{
    Node *temp = (Node*) malloc(sizeof(Node));

    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    if(root == NULL)
    {
        root = temp;
    } else {
        Node *current = root;
        Node *parent = NULL;
        while(1)
        {
            parent = current;
            if(data < parent->data){
                current = parent->left;
                if(current == NULL)
                {
                    parent->left = temp;
                    return root;
                }
            } else {
                current = parent->right;
                if(current == NULL)
                {
                    parent->right = temp;
                    return root;
                }
            }
        }
    }
    return root;
}

Node* search(struct Node* root, int value)
{
    printf("%d ", root->data);
    if(!root)
    {
        return root;
    }
    if(root->data == value)
    {
        return root;
    } 
    else if(value >= root->data)
    {
        if(root->right)
        {
            search(root->right, value);
        }
        else {
            return root->right;
        }
    } 
    else if(value < root->data) 
    {
        if(root->left)
        {
            search(root->left, value);
        }
        else {
            return root->left;
        }
    }
}

void inorder(struct Node* node)
{
    if(node)
    {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

int main()
{
    int array[9] = {89, 57, 900, 56, 78, 3, 7, 15, 42};
    Node *root = NULL;

    for(int i = 0; i < 9; i++)
    {
        root = insert(root, array[i]);
    }
    printf("Inorder: \n");
    inorder(root);

    printf("\nSearch function:\n");
    Node *searchResult = search(root, 57);
    if(searchResult)
    {
        printf("[%d] Found.\n", searchResult->data);
    } else {
        printf("[%d] Not Found.\n", searchResult->data);
    }

    Node *searchResult2 = search(root, 77);
    if(searchResult2)
    {
        printf("[%d] Found.\n", 77);
    } else {
        printf("[%d] Not Found.\n", 77);
    }

    return 0;
}