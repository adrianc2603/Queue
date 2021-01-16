#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * This helper method prints each element in the queueß.
 * Note it assumes that elements stored are of type int*
 */
void print_queue(queue_t *queue) {
    printf("\n");

    node_t *current_node = queue->head;
    while (current_node != NULL) {
        int *address = (int*) current_node->element;
        printf("%d - ", *address);
        current_node = current_node->next;
    }

    printf("\n\n");
}

/**
 * Helper function to heap allocate an integer, enqueue the integer and
 * return a pointer to the integer
 */
int *create_enqueue_element(queue_t *queue, int e) {
    int *p = malloc(sizeof(int));
    *p = e;
    enqueue(queue, p);
    return p;
}

void test_all_functions_regular_cases() {
    queue_t *queue = create_queue();

    if (first(queue) == NULL) {
        printf("First is NULL because the queue is empty\n"); // This should print
    }
    else {
        printf("First is not NULL, but it should be");
    }
    printf("The size of the queue is %d\n", size(queue)); // The size of the queue is 0
    printf("Is the queue empty? %d\n", is_empty(queue)); // Is the queue empty? 1 (True)
    print_queue(queue); // Prints nothing

    // Insert 2
    int *a = create_enqueue_element(queue, 2);
    printf("The first element in the queue is %d\n", *(int*) first(queue)); // The first element in the queue is 2
    printf("The size of the queue is %d\n", size(queue)); // The size of the queue is 1
    printf("Is the queue empty? %d\n", is_empty(queue)); // Is the queue empty? 0 (False);
    print_queue(queue); // 2 - 

    // Insert 6
    int *b = create_enqueue_element(queue, 5);
    printf("The first element in the queue is %d\n", *(int*) first(queue)); // The first element in the queue is 2
    printf("The size of the queue is %d\n", size(queue)); // The size of the queue is 2
    printf("Is the queue empty? %d\n", is_empty(queue)); // Is the queue empty? 0 (False);
    print_queue(queue); // 2 - 5 -

    // Insert 3
    int *c = create_enqueue_element(queue, 3);
    printf("The first element in the queue is %d\n", *(int*) first(queue)); // The first element in the queue is 2
    printf("The size of the queue is %d\n", size(queue)); // The size of the queue is 3
    printf("Is the queue empty? %d\n", is_empty(queue)); // Is the queue empty? 0 (False);
    print_queue(queue); // 2 - 5 - 3 - 

    // Remove 2
    int *rem_elem = (int*) dequeue(queue);
    printf("The removed element is %d\n", *rem_elem); // The removed element is 2
    printf("The first element in the queue is %d\n", *(int*) first(queue)); // The first element in the queue is 5
    printf("The size of the queue is %d\n", size(queue)); // The size of the queue is 2
    printf("Is the queue empty? %d\n", is_empty(queue)); // Is the queue empty? 0 (False);
    print_queue(queue); // 5 - 3 - 

    // Remove 5
    rem_elem = (int*) dequeue(queue);
    printf("The removed element is %d\n", *rem_elem); // The removed element is 5
    printf("The first element in the queue is %d\n", *(int*) first(queue)); // The first element in the queue is 3
    printf("The size of the queue is %d\n", size(queue)); // The size of the queue is 1
    printf("Is the queue empty? %d\n", is_empty(queue)); // Is the queue empty? 0 (False);
    print_queue(queue); // 3 - 

    // Remove 3
    rem_elem = (int*) dequeue(queue);
    printf("The removed element is %d\n", *rem_elem); // The removed element is 3
     if (first(queue) == NULL) {
        printf("First is NULL because the queue is empty\n"); // This should print
    }
    else {
        printf("First is not NULL, but it should be");
    }
    printf("The size of the queue is %d\n", size(queue)); // The size of the queue is 0
    printf("Is the queue empty? %d\n", is_empty(queue)); // Is the queue empty? 1 (True);
    print_queue(queue); // Prints nothing

    // Try to dequeue, but it's NULL as there is nothing in the list
    if (dequeue(queue) == NULL) {
        printf("Dequeue is NULL because the queue is empty\n"); // This should print
    }
    else {
        printf("Dequeue should be NULL, but it isn't");
    }

    // Add back in to ensure destroy_queue frees all nodes and the queue itself
    printf("Adding a back in now\n");
    enqueue(queue, a);
    print_queue(queue); // 2 - 

    free(a);
    free(b);
    free(c);
    destroy_queue(queue);
}

int main() {

    test_all_functions_regular_cases();

}