#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode TreeNode;

struct TreeNode
{
    char data;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *newNode(char ch);
TreeNode *buildTreeLevelOrder(TreeNode *root, char level[], int no_of_nodes, int index);
void postOrder(TreeNode *root);
void inOrder(TreeNode *root);
void preOrder(TreeNode *root);

int main()
{
    char level[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int no_of_nodes = sizeof(level) / sizeof(level[0]);

    TreeNode *root = buildTreeLevelOrder(root, level, no_of_nodes, 0);

    printf("Menu:\n");
    printf("enter 1 for Preorder traversal\n");
    printf("enter 2 for Inorder traversal\n");
    printf("enter 3 for Postorder traversal\n");
    printf("ENTER YOUR CHOICE\n\n");

    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Printing preorder traversal:\n");
        preOrder(root);
        break;
    case 2:
        printf("Printing inorder traversal:\n");
        inOrder(root);
        break;
    case 3:
        printf("Printing postorder traversal:\n");
        postOrder(root);
        break;
    default:
        printf("Invalid Choice entered!\n");
    }
}

TreeNode *newNode(char ch)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->data = ch;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode *buildTreeLevelOrder(TreeNode *root, char level[], int no_of_nodes, int index)
{
    if (index >= no_of_nodes)
        return root;

    TreeNode *temp = newNode(level[index]);
    root = temp;

    root->left = buildTreeLevelOrder(root->left, level, no_of_nodes, 2 * index + 1);
    root->right = buildTreeLevelOrder(root->right, level, no_of_nodes, 2 * index + 2);

    return root;
}

void preOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    printf("%c ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%c ", root->data);
    inOrder(root->right);
}

void postOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%c ", root->data);
}
