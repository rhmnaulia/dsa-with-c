#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node* next;
    time_t creation_time;
} Node;

Node* create_node(int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        fprintf(stderr, "Memory allocation failed! Exiting...\n");
        exit(1);
    }
    new_node->data = value;
    new_node->next = NULL;
    new_node->creation_time = time(NULL);
    return new_node;
}

void insert_front(Node** head, int value) {
    Node* new_node = create_node(value);
    new_node->next = *head;
    *head = new_node;
}

void print_list(Node* head) {
    Node* current = head;
    while (current) {
        printf("Value: %d (Created: %s)", current->data, ctime(&current->creation_time));
        current = current->next;
    }
}

void free_list(Node* head) {
    Node* tmp;
    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    Node* head = NULL;

    insert_front(&head, 42);
    insert_front(&head, 13);
    insert_front(&head, 7);

    printf("Linked List Contents:\n");
    print_list(head);

    free_list(head);
    return 0;
}
