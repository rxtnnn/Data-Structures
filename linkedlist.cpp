#include <stdio.h>
#include <stdlib.h>

// Define the structure for a singly linked list node
struct Node {
    int data;
    struct Node *next;
};

// Function to reverse a linked list
struct Node* reverseLinkedList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        // Store the next node
        next = current->next;

        // Reverse the link
        current->next = prev;

        // Move prev and current one step forward
        prev = current;
        current = next;
    }

    // The new head is the previous node
    head = prev;
    return head;
}

// Function to print the linked list
void printLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

int main() {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    int numNodes, data;
    
	printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    // Get data for each node from the user and create the linked list
    for (int i = 0; i < numNodes; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = data;
        temp->next = head;
        head = temp;
    }
    printf("Original Linked List: ");
    printLinkedList(head);

    // Reverse the linked list
    head = reverseLinkedList(head);

    printf("\nReversed Linked List: ");
    printLinkedList(head);

    // Free the dynamically allocated memory
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);	
    }

    return 0;
}

