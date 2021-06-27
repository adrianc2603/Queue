#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
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

    assert(first(queue) == NULL);
    assert(size(queue) == 0);
    assert(is_empty(queue) == true);
    print_queue(queue); // Prints nothing

    // Insert 2
    int *a = create_enqueue_element(queue, 2);
    assert((*(int*) first(queue)) == 2);
    assert(size(queue) == 1);
    assert(is_empty(queue) == false);
    print_queue(queue); // 2 - 

    // Insert 6
    int *b = create_enqueue_element(queue, 5);
    assert((*(int*) first(queue)) == 2);
    assert(size(queue) == 2);
    assert(is_empty(queue) == false);
    print_queue(queue); // 2 - 5 -

    // Insert 3
    int *c = create_enqueue_element(queue, 3);
    assert((*(int*) first(queue)) == 2);
    assert(size(queue) == 3);
    assert(is_empty(queue) == false);
    print_queue(queue); // 2 - 5 - 3 - 

    // Remove 2
    int *rem_elem = (int*) dequeue(queue);
    assert(*rem_elem == 2);
    assert((*(int*) first(queue)) == 5);
    assert(size(queue) == 2);
    assert(is_empty(queue) == false);
    print_queue(queue); // 5 - 3 - 

    // Remove 5
    rem_elem = (int*) dequeue(queue);
    assert(*rem_elem == 5);
    assert((*(int*) first(queue)) == 3);
    assert(size(queue) == 1);
    assert(is_empty(queue) == false);
    print_queue(queue); // 3 - 

    // Remove 3
    rem_elem = (int*) dequeue(queue);
    assert(*rem_elem == 3);
    assert(first(queue) == NULL);
    assert(size(queue) == 0);
    assert(is_empty(queue) == true);
    print_queue(queue); // Prints nothing

    // Try to dequeue, but it's NULL as there is nothing in the list
    assert(dequeue(queue) == NULL);

    // Add back in to ensure destroy_queue frees all nodes and the queue itself
    enqueue(queue, a);
    print_queue(queue); // 2 - 
    assert((*(int*) first(queue)) == 2);
    assert(size(queue) == 1);
    assert(is_empty(queue) == false);

    free(a);
    free(b);
    free(c);
    destroy_queue(queue);
}

int main() {

    test_all_functions_regular_cases();

}