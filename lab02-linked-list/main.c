/* DSA Lab 2: linked list. Reviewed in 2026. */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) { perror("malloc"); exit(EXIT_FAILURE); }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int swap(Node **head, int position)
{
    if (position < 1) return 0;
    Node **link = head;
    for (int i = 1; i < position && *link != NULL; i++)
        link = &(*link)->next;
    Node *current = *link;
    if (current == NULL || current->next == NULL) return 0;
    Node *next = current->next;
    current->next = next->next;
    next->next = current;
    *link = next;
    return 1;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(void)
{
    Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    printf("Original list: ");
    printList(head);

    int position = 2;
    swap(&head, position);

    printf("List after swapping at position %d: ", position);
    printList(head);

    while (head != NULL) { Node *next = head->next; free(head); head = next; }
    return 0;
}
