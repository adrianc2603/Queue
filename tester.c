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

    int *a = malloc(sizeof(int));
    *a = 2;
    enqueue(queue, a);
    printf("The first element in the queue is %d\n", *(int*) first(queue)); // The first element in the queue is 2
    printf("The size of the queue is %d\n", size(queue)); // The size of the queue is 1
    printf("Is the queue empty? %d\n", is_empty(queue)); // Is the queue empty? 0 (False);
    print_queue(queue); // 2 - 

    int *b = malloc(sizeof(int));
    *b = 5;
    enqueue(queue, b);
    printf("The first element in the queue is %d\n", *(int*) first(queue)); // The first element in the queue is 2
    printf("The size of the queue is %d\n", size(queue)); // The size of the queue is 2
    printf("Is the queue empty? %d\n", is_empty(queue)); // Is the queue empty? 0 (False);
    print_queue(queue); // 2 - 5 -

    int *c = malloc(sizeof(int));
    *c = 3;
    enqueue(queue, c);
    printf("The first element in the queue is %d\n", *(int*) first(queue)); // The first element in the queue is 2
    printf("The size of the queue is %d\n", size(queue)); // The size of the queue is 3
    printf("Is the queue empty? %d\n", is_empty(queue)); // Is the queue empty? 0 (False);
    print_queue(queue); // 2 - 5 - 3 - 

    int *rem_elem = (int*) dequeue(queue);
    printf("The removed element is %d\n", *rem_elem); // The removed element is 2
    printf("The first element in the queue is %d\n", *(int*) first(queue)); // The first element in the queue is 5
    printf("The size of the queue is %d\n", size(queue)); // The size of the queue is 2
    printf("Is the queue empty? %d\n", is_empty(queue)); // Is the queue empty? 0 (False);
    print_queue(queue); // 5 - 3 - 

    rem_elem = (int*) dequeue(queue);
    printf("The removed element is %d\n", *rem_elem); // The removed element is 5
    printf("The first element in the queue is %d\n", *(int*) first(queue)); // The first element in the queue is 3
    printf("The size of the queue is %d\n", size(queue)); // The size of the queue is 1
    printf("Is the queue empty? %d\n", is_empty(queue)); // Is the queue empty? 0 (False);
    print_queue(queue); // 3 - 

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

    if (dequeue(queue) == NULL) {
        printf("Dequeue is NULL because the queue is empty\n"); // This should print
    }
    else {
        printf("Dequeue should be NULL, but it isn't");
    }

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