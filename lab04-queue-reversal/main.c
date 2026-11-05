#include "../include/read_int.h"
/* DSA Lab 4: queue reversal. Reviewed in 2026. */
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

struct Queue* createQueue() {
    struct Queue* q = malloc(sizeof(struct Queue));
    if (q == NULL) { perror("malloc"); exit(EXIT_FAILURE); }
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(struct Queue* q) {
    return q->rear == -1;
}

void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX_SIZE - 1)
        printf("\nQueue is Full!!");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(struct Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("[]");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

struct Stack {
    int items[MAX_SIZE];
    int top;
};

struct Stack* createStack() {
    struct Stack* s = malloc(sizeof(struct Stack));
    if (s == NULL) { perror("malloc"); exit(EXIT_FAILURE); }
    s->top = -1;
    return s;
}

int isStackEmpty(struct Stack* s) {
    return s->top == -1;
}

void push(struct Stack* s, int value) {
    if (s->top == MAX_SIZE - 1)
        printf("\nStack Overflow");
    else {
        s->top++;
        s->items[s->top] = value;
    }
}

int pop(struct Stack* s) {
    int item;
    if (isStackEmpty(s)) {
        printf("Stack Underflow");
        item = -1;
    } else {
        item = s->items[s->top];
        s->top--;
    }
    return item;
}

int reverseLastK(struct Queue *q, int k)
{
    int size = isEmpty(q) ? 0 : q->rear - q->front + 1;
    if (k < 0 || k > size) return 0;
    struct Stack s = {{0}, -1};
    int first = q->rear - k + 1;
    for (int i = first; i <= q->rear; i++) push(&s, q->items[i]);
    for (int i = first; i <= q->rear; i++) q->items[i] = pop(&s);
    return 1;
}

void printQueue(struct Queue* q) {
    int i = q->front;
    if (isEmpty(q)) {
        printf("[]");
    } else {
        printf("[");
        for (i = q->front; i < q->rear + 1; i++) {
            printf("%d", q->items[i]);
            if (i < q->rear) printf(",");
        }
        printf("]");
    }
    printf("\n");
}

int main(void) {
    struct Queue* q = createQueue();
    int k, n;

    printf("Enter the value of k: ");
    if (!read_int(&k)) {
        free(q);
        fputs("Invalid input.\n", stderr);
        return 1;
    }
    printf("Enter the number of elements in the queue: ");
    if (!read_int(&n) || n < 0 || n > MAX_SIZE || k < 0 || k > n) {
        free(q);
        fputs("Invalid input.\n", stderr);
        return 1;
    }

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        int element;
        if (!read_int(&element)) {
        free(q);
        fputs("Invalid input.\n", stderr);
        return 1;
    }
        enqueue(q, element);
    }

    printf("Original Queue: ");
    printQueue(q);

    reverseLastK(q, k);

    printf("After reversing last %d elements: ", k);
    printQueue(q);

    free(q);
    return 0;
}
