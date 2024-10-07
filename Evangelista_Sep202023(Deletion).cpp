#include <stdio.h>
#include <stdlib.h>

struct node {
    int x;
    struct node* next;
};

typedef struct node nd;
nd* head, *temp, *p;

int main() {
    int num, choice, counter = 0;
    char reply;

	head = NULL;
    head = (nd*)malloc(sizeof(nd));
    if (head == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit the program with an error code
    }

    printf("Enter a number: ");
    scanf("%d", &num);
    head->x = num; // Store the number in the first node
    head->next = NULL; // Initialize the next pointer to NULL
    counter++;

    printf("Press 1 to enter another number: ");
    scanf("%d", &choice);
    nd* p = head;

    while (choice == 1) {
        p->next = (nd*)malloc(sizeof(nd));
        p = p->next;
        printf("Enter a number: ");
        scanf("%d", &num);
        p->x = num;
        p->next = NULL; // Initialize the next pointer to NULL
        counter++;
        printf("Press 1 to enter another number: ");
        scanf("%d", &choice);
    }

    printf("List: ");
    p = head;
    while (p != NULL) {
        printf("%d ", p->x);
        p = p->next;
    }
    printf("\n");

    // Inserting a number
    printf("Do you want to insert a number (y/n): ");
    scanf(" %c", &reply);

    while (reply == 'y') {
        printf("Enter a number to insert: ");
        scanf("%d", &num); 
        // Create a new node for the new number
        temp = (nd*)malloc(sizeof(nd));
        temp->x = num;
        // Insert the new node in the sorted order
        temp->next = NULL;
        p = head;
        nd* prev = NULL;
        while (p != NULL && p->x < num) {
            prev = p;
            p = p->next;
        }
		if (prev == NULL) {
            // Insert at the beginning
            temp->next = head;
            head = temp;
        } else {
            prev->next = temp;
            temp->next = p;
        }
        printf("New list: ");
        p = head;
        while (p != NULL) {
            printf("%d ", p->x);
            p = p->next;
        }
        printf("\nDo you want to insert a number (y/n): ");
        scanf(" %c", &reply);
    }
    printf("\n");
    
    //Delete a number
    printf("Do you want to delete a number? (y/n): ");
    scanf(" %c", &reply);

    while (reply == 'y') {
        printf("Enter number to delete: ");
        scanf("%d", &num);
        // Deleting a number
        temp = head;
        p = NULL;
        // Finding the spefic number
        while (temp != NULL && temp->x != num) {
            p = temp;
            temp = temp->next;
        }
        if(temp == NULL) {
            printf("Number not found in the list.\n");
        }else{
            // Number found, delete the node
            if (p == NULL) {
                // Deleting the first node
                head = temp->next;
            } else {
                p->next = temp->next;
            }
            free(temp);
        }
        if(head == NULL){
        	printf("List is empty");
        	break;
		}
        printf("List: ");
        p = head;
        while (p != NULL) {
            printf("%d ", p->x);
            p = p->next;
        }
        printf("\nDo you want to delete another number? (y/n): ");
        scanf(" %c", &reply);
    }
    printf("\n");
    //Search a number
    printf("Do you want to search a number?(y/n): ");
    scanf(" %c", &reply);
    
    while(reply == 'y'){
    	printf("Enter a number to search: ");
    	scanf("%d", &num);
    	
    	temp = NULL;
    	p = head;
    	while(p!=NULL & p->x == num){
    		temp = p;
    		p = p->next;
		}
		if(temp == NULL){
			printf("Number is not in the list\n");
		}else{
			printf("Number is found in the list\n");
		}
		printf("Do you want to search a number?(y/n): ");
    	scanf(" %c", &reply);
    	
	}
	
    // Free the memory allocated for the nodes
    p = head;
    while (p != NULL) {
        temp = p;
        p = p->next;
        free(temp);
    }
    return 0;
    // add condition its not the end or null
}

