#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node_t {
    void *element;
    struct node_t *next;
} node_t;

typedef struct queue_t {
    node_t *head;
    node_t *tail;
    int size;
} queue_t;

queue_t *create_queue();

void enqueue(queue_t *queue, void *e);

void *dequeue(queue_t *queue);

void *first(queue_t *queue);

int size(queue_t *queue);

bool is_empty(queue_t *queue);

void destroy_queue(queue_t *queue);