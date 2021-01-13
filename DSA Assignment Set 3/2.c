// Write a program to create a binary tree from its pre-order and in-order traversal.

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode TreeNode;

struct TreeNode
{
    char data;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *newNode(char);
TreeNode *buildTree(char in[], char pre[], int inStart, int inEnd, int *preIndex);
void printInOrderUsingNode(TreeNode *root);
void printPreOrderUsingNode(TreeNode *root);
int search(char arr[], int start, int end, char ch);

int main()
{
    char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};

    int length = sizeof(in) / sizeof(in[0]);
    int preIndex = 0;

    TreeNode *root = buildTree(in, pre, 0, length - 1, &preIndex);

    printf("Verification by printing the traversals using the root returned by buildTree() method\n");
    printf("Inorder traversal:\n");
    printInOrderUsingNode(root);
    printf("\nPreorder traversal:\n");
    printPreOrderUsingNode(root);
}

TreeNode *newNode(char ch)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->data = ch;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode *buildTree(char in[], char pre[], int inStart, int inEnd, int *preIndex)
{
    if (inStart > inEnd)
        return NULL;

    TreeNode *node = newNode(pre[(*preIndex)++]);

    if (inStart == inEnd)
        return node;

    int inIndex = search(in, inStart, inEnd, node->data);

    node->left = buildTree(in, pre, inStart, inIndex - 1, preIndex);
    node->right = buildTree(in, pre, inIndex + 1, inEnd, preIndex);

    return node;
}

int search(char arr[], int start, int end, char ch)
{
    int i;
    for (i = start; i <= end; i++)
    {
        if (arr[i] == ch)
            break;
    }
    return i;
}

void printPreOrderUsingNode(TreeNode *root)
{
    if (root == NULL)
        return;
    printf("%c ", root->data);
    printPreOrderUsingNode(root->left);
    printPreOrderUsingNode(root->right);
}
void printInOrderUsingNode(TreeNode *root)
{
    if (root == NULL)
        return;
    printInOrderUsingNode(root->left);
    printf("%c ", root->data);
    printInOrderUsingNode(root->right);
}
