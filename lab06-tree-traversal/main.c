/* DSA Lab 6: tree traversal. Reviewed in 2026.
   Final review (2026-11): end the traversal output with a newline. */
#include<stdio.h>
#include<stdlib.h>
struct node
{
  struct node *left;
  struct node *right;
  int data;
};

struct stack
{
  struct node *data;
  struct stack *next;
};

void push (struct stack **top, struct node *n);
struct node *pop (struct stack **top);
int isEmpty (struct stack *top);

void tree_traversal (struct node *root)
{
  struct node *temp = root;
  struct stack *s_temp = NULL;
  int flag = 1;
  while (flag)
    {
      if (temp)
	{
	  printf ("%d ", temp->data);
	  push (&s_temp, temp);
	  temp = temp->left;
	}
      else
	{
	  if (!isEmpty (s_temp))
	    {
	      temp = pop (&s_temp);
	      temp = temp->right;
	    }
	  else
	    flag = 0;
	}
    }
  printf ("\n");
}

void push (struct stack **top, struct node *n)
{
  struct stack *new_n = (struct stack *) malloc (sizeof (struct stack));
  if (!new_n) { perror("malloc"); exit(EXIT_FAILURE); }
  new_n->data = n;
  new_n->next = (*top);
  (*top) = new_n;
}

int isEmpty (struct stack *top)
{
  if (top == NULL)
    return 1;
  else
    return 0;
}

struct node *pop (struct stack **top_n)
{
  struct node *item;
  struct stack *top;
  top = *top_n;
  item = top->data;
  *top_n = top->next;
  free (top);
  return item;
}

struct node *create_node (int data)
{
  struct node *new_n = (struct node *) malloc (sizeof (struct node));
  if (!new_n) { perror("malloc"); exit(EXIT_FAILURE); }
  new_n->data = data;
  new_n->left = NULL;
  new_n->right = NULL;
  return (new_n);
}

void free_tree(struct node *root)
{
    if (!root) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main(void)
{
  struct node *root;
  root = create_node (8);
  root->left = create_node (5);
  root->right = create_node (4);
  root->right->left = create_node (9);
  root->right->right = create_node (8);
  root->left->left = create_node (7);
  root->left->right = create_node (6);
  tree_traversal (root);
  free_tree(root);
  return 0;
}
