#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node Node;
Node *head, *newNode, *temp, *p, *node;

Node* insert(Node** head, int data) {

   	newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    temp = NULL;
    p = *head;
    while (p != NULL && data > p->data) {
        temp = p;
        p = p->next;
    }

    if (temp == NULL) {
        *head = newNode;
    } else {
        temp->next = newNode;
	}	
    newNode->next = p;
    return *head;
}

void printList(Node* head) {
    p = head;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main() {
    int num, sum = 0, count = 0;
    float avg;
    char choice;
    
	head = NULL;
    do {
        printf("Enter a number: ");
        scanf("%d", &num);
        insert(&head, num);

        printf("Press 1 to enter another number: ");
        scanf(" %c", &choice);
    } while (choice == '1');

    printf("List: ");
    printList(head);

    do {
        printf("Do you want to insert a number? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y') {
            int insertNum;
            printf("Enter a number to insert: ");
            scanf("%d", &insertNum);

            insert(&head, insertNum);

            printf("Current list: ");
            printList(head);
        }
    } while (choice == 'y');
    
	p = head;
    while (p != NULL) {
        sum += p->data;
        count++;
        p = p->next;
    }
    printf("Sum: %d", sum);
    
    avg = (float)sum / count;
    printf("\nAverage: %.2f", avg);
    
    while (head != NULL) {
        node = head;
        head = head->next;
        free(node);
    }

    return 0;
}

