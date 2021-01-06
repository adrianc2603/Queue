#include "main.h"

/**
 * Initialise the queue and all its fields. Return a pointer to it
 * Time Complexity: O(1)
 */
queue_t *create_queue() {
    queue_t *queue = malloc(sizeof(queue_t));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    return queue;
}

/**
 * Inserts element e at the end of the queue
 * Time Complexity: O(1)
 */
void enqueue(queue_t *queue, void *e) {
    if (queue == NULL) {
        printf("The queue is NULL\n");
        return;
    }
    node_t *new_node = malloc(sizeof(node_t));
    new_node->element = e;
    new_node->next = NULL;

    if (queue->head == NULL) {
        queue->head = new_node;
    }
    else {
        queue->tail->next = new_node;
    }

    queue->tail = new_node;
    queue->size++;
}

/**
 * Removes and returns the element at the front of the queue
 * Time Complexity: O(1)
 */
void *dequeue(queue_t *queue) {
    if (queue == NULL) {
        printf("The queue is NULL\n");
        return NULL;
    }
    if (is_empty(queue)) {
        printf("The queue is empty\n");
        return NULL;
    }
    node_t *rem_node = queue->head;
    void *rem_elem = queue->head->element;
    queue->head = queue->head->next;
    free(rem_node);
    queue->size--;
    return rem_elem;
}


/**
 * Returns the element at the front without removing it
 * Time Complexity: O(1)
 */
void *first(queue_t *queue) {
    if (queue == NULL) {
        printf("The queue is NULL\n");
        return NULL;
    }
    if (is_empty(queue)) {
        printf("Queue is empty\n");
        return NULL;
    }
    return queue->head->element;
}

/**
 * Returns the number of elements stored
 * Time Complexity: O(1)
 */
int size(queue_t *queue) {
    if (queue == NULL) {
        printf("The queue is NULL\n");
        return 0;
    }
    return queue->size;
} 

/**
 * Returns whether elements are stored or not
 * Time Complexity: O(1)
 */
bool is_empty(queue_t *queue) {
    if (queue == NULL) {
        printf("The queue is NULL\n");
        return true;
    }
    return (queue->size == 0);
} 

/**
 * Free all memory associated with the queue
 * Time Complexity: O(n)
 */
void destroy_queue(queue_t *queue) {
    if (queue == NULL) {
        printf("The queue is NULL\n");
        return;
    }
    while (!is_empty(queue)) {
        dequeue(queue);
    }
    free(queue);
}