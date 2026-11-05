/* DSA Lab 5: expression tree. Reviewed in 2026. */
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(char data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode) { perror("malloc"); exit(EXIT_FAILURE); }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int evalExpr(struct Node *v)
{
    if (v == NULL)
        return 0;

    if (!isOperator(v->data))
        return v->data - '0';

    int x = evalExpr(v->left);
    int y = evalExpr(v->right);

    switch (v->data)
    {
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        if (y != 0)
            return x / y;
        else
        {
            printf("Error: Division by zero!\n");
            exit(EXIT_FAILURE);
        }
    default:
        return 0;
    }
}

int main(void)
{

    struct Node *root = createNode('*');
    root->left = createNode('+');
    root->left->left = createNode('6');
    root->left->right = createNode('7');
    root->right = createNode('-');
    root->right->left = createNode('2');
    root->right->right = createNode('1');

    int result = evalExpr(root);
    printf("Result of the expression tree: %d\n", result);
    free(root->left->left);
    free(root->left->right);
    free(root->right->left);
    free(root->right->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
