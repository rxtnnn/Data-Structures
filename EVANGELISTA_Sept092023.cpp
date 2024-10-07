#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node nd;
nd* head = NULL, *newNode, *node, *temp, *p;

int main() {
    int num, sum = 0, count = 0;
	float avg;
    char choice;

    do {
        printf("Enter a number: ");
        scanf("%d", &num);
		
        // Allocate memory for a new node
        newNode = (nd*)malloc(sizeof(nd));
        newNode->data = num;
        newNode->next = NULL;

        // Insert the new node in the appropriate position
        temp = NULL;
        p = head;
        while (p != NULL && num > p->data) {
            temp = p;
            p = p->next;
        }

        if (temp == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }

        newNode->next = p;

        printf("Press 1 to enter another number: ");
        scanf(" %c", &choice);
    } while (choice == '1');

    printf("List: ");
    p = head;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
 
    do {
        printf("\nDo you want to insert a number? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y') {
            int insertNum;
            printf("Enter a number to insert: ");
            scanf("%d", &insertNum);

            newNode = (nd*)malloc(sizeof(nd));
            newNode->data = insertNum;
            newNode->next = NULL;

           	temp = NULL;
            p = head;
            while (p != NULL && insertNum > p->data) {
                temp = p;
                p = p->next;
            }

            if (temp == NULL) {
                head = newNode;
            } else {
                temp->next = newNode;
            }
            newNode->next = p;

            printf("Current list: ");
            p = head;
            while (p != NULL) {
                printf("%d ", p->data);
                p = p->next;
            }
            printf("\n");
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

