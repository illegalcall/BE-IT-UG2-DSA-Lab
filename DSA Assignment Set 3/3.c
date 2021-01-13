#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode TreeNode;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *newNode(int key);
TreeNode *insert(TreeNode *root, int key);
TreeNode *delete (TreeNode *root, int key);
void findInPredSucc(TreeNode *root, TreeNode *pred, TreeNode *succ, int key);
int search(TreeNode *root, int val);

int main()
{

    // starting BST
    int nodes[] = {2, 3, 1, 5, 6, 8, 7, 4, 9, 10};
    int i, n = sizeof(nodes) / sizeof(nodes[0]);
    TreeNode *root = NULL;
    for (i = 0; i < n; i++)
    {
        root = insert(root, nodes[i]);
    }

    printf("Menu:\n");
    printf("enter 1 to insert a key into BST\n");
    printf("enter 2 to delete a key from BST\n");
    printf("enter 3 to search a key in BST\n");
    printf("enter 4 to find inorder predecessor and successor of a key in BST\n");
    printf("enter -99 to exit the process\n");

    while (1)
    {
        printf("\nENTER YOUR CHOICE\n\n");

        int choice, key;
        scanf("%d", &choice);

        if (choice == -99)
        {
            printf("EXITTING...");
            break;
        }
        switch (choice)
        {
        case 1:
            printf("enter key to insert:\n");
            scanf("%d", &key);
            root = insert(root, key);
            break;
        case 2:
            printf("enter key to delete:\n");
            scanf("%d", &key);
            root = delete (root, key);
            break;
        case 3:
            printf("enter key to be searched:\n");
            scanf("%d", &key);
            int pos = search(root, key);
            if (pos == -1)
                printf("key not found!\n");
            else
                printf("key is present in BST\n");
            break;
        case 4:
            printf("enter key whose inorder predecessor and successor are to be found:\n");
            scanf("%d", &key);
            TreeNode *pred = NULL;
            TreeNode *succ = NULL;
            findInPredSucc(root, pred, succ, key);
            if (pred)
                printf("predecessor has key = %d\n", pred->data);
            if (succ)
                printf("Successor has key = %d\n", succ->data);
            if (pred == NULL && succ == NULL)
                printf("key not found!\n");
            break;
        default:
            printf("Invalid Choice entered!\n");
        }
    }
}

TreeNode *newNode(int key)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->data = key;
    node->left = node->right = NULL;
    return node;
}

TreeNode *insert(TreeNode *root, int key)
{
    if (root == NULL)
    {
        root = newNode(key);
        return root;
    }
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}

TreeNode *delete (TreeNode *root, int key)
{
    // TODO: implement deleting node from BST
}

int search(TreeNode *root, int key)
{
    if (root == NULL)
        return -1;
    if (key == root->data)
        return 1;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

void findInPredSucc(TreeNode *root, TreeNode *pred, TreeNode *succ, int key)
{
    // TODO:find inorder successor and predecessor of a node in BST
}