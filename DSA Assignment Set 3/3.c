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
TreeNode *insertNode(TreeNode *root, int key);
TreeNode *deleteNode(TreeNode *root, int key);
TreeNode *searchNode(TreeNode *root, int val);
void findInPredSucc(TreeNode *root, TreeNode *pred, TreeNode *succ, int key);

void preOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{

    // starting BST
    int nodes[] = {2, 3, 1, 5, 6, 8, 7, 4, 9, 10};
    int i, n = sizeof(nodes) / sizeof(nodes[0]);
    TreeNode *root = NULL;
    for (i = 0; i < n; i++)
    {
        root = insertNode(root, nodes[i]);
    }

    printf("preorder initial tree:\n");
    preOrder(root);

    printf("\nMenu:\n");
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
            printf("EXITTING...\n");
            break;
        }
        switch (choice)
        {
        case 1:
        {
            printf("enter key to insert:\n");
            scanf("%d", &key);
            root = insertNode(root, key);
            break;
        }
        case 2:
        {
            printf("enter key to delete:\n");
            scanf("%d", &key);
            root = deleteNode(root, key);
            break;
        }
        case 3:
        {
            printf("enter key to be searched:\n");
            scanf("%d", &key);
            TreeNode *node = searchNode(root, key);
            if (node == NULL)
                printf("key not found!\n");
            else
                printf("key is present in BST\n");
            break;
        }
        case 4:
        {
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
            {
                TreeNode *temp = searchNode(root, key);
                if (temp)
                    printf("key doesn't have a successor or a predecessor\n");
                else
                    printf("Key not found!\n");
            }
            break;
        }
        default:
            printf("Invalid Choice entered!\n");
        }
    }

    printf("preorder final tree:\n");
    preOrder(root);
}

TreeNode *newNode(int key)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->data = key;
    node->left = node->right = NULL;
    return node;
}

TreeNode *insertNode(TreeNode *root, int key)
{
    if (root == NULL)
    {
        return newNode(key);
    }
    if (key < root->data)
        root->left = insertNode(root->left, key);
    else if (key > root->data)
        root->right = insertNode(root->right, key);
    return root;
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    // TODO: implement deleting node from BST
    if (root)
    {
        if (key < root->data)
            root->left = deleteNode(root->left, key);
        else if (key > root->data)
            root->right = deleteNode(root->right, key);
        else
        {
            if (root->left == NULL)
            {
                TreeNode *temp = root->right;
                free(root);
                return temp;
            }
            else if (root->right == NULL)
            {
                TreeNode *temp = root->left;
                free(root);
                return temp;
            }
            else
            {
                TreeNode *pred = NULL;
                TreeNode *succ = NULL;
                findInPredSucc(root->right, pred, succ, key);
                root->data = succ->data;
                root->right = deleteNode(root->right, succ->data);
            }
        }
    }
    return root;
}

TreeNode *searchNode(TreeNode *root, int key)
{
    if (root == NULL || root->data == key)
        return root;
    else if (key < root->data)
        return searchNode(root->left, key);
    else
        return searchNode(root->right, key);
}

void findInPredSucc(TreeNode *root, TreeNode *pred, TreeNode *succ, int key)
{
    // TODO:find inorder successor and predecessor of a node in BST
    if (root == NULL)
        return;

    if (key < root->data)
    {
        succ = root;
        findInPredSucc(root->left, pred, succ, key);
    }
    else if (key > root->data)
    {
        pred = root;
        findInPredSucc(root->right, pred, succ, key);
    }
    else
    {
        // predecessor => maximal node in left subtree
        if (root->left)
        {
            TreeNode *temp = root->left;
            while (temp && temp->right)
            {
                temp = temp->right;
            }
            pred = temp;
        }
        // successor => minimal node in right subtree
        if (root->right)
        {
            TreeNode *temp = root->right;
            while (temp && temp->left)
            {
                temp = temp->left;
            }
            succ = temp;
        }
        return;
    }
}