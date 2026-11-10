/* Exercise the actual lab functions without changing the standalone program. */
#define main lab_demo_main
#include "../../lab02-linked-list/main.c"
#undef main
#include <assert.h>

int main(void)
{
    Node *head = NULL;
    assert(swap(&head, 1) == 0);
    head = createNode(1);
    assert(swap(&head, 1) == 0);
    assert(swap(&head, 0) == 0);
    assert(swap(&head, -1) == 0);
    head->next = createNode(2);
    head->next->next = createNode(3);
    Node *first = head, *second = head->next, *third = second->next;
    assert(swap(&head, 1) == 1);
    assert(head == second && second->next == first && first->next == third);
    assert(swap(&head, 2) == 1);
    assert(head == second && second->next == third && third->next == first);
    assert(first->next == NULL);
    assert(swap(&head, 3) == 0);
    assert(swap(&head, 99) == 0);
    while (head != NULL)
    {
        Node *next = head->next;
        free(head);
        head = next;
    }
    return 0;
}
