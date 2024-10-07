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
    
	//Insert at the end 
	printf("Do you want to insert? (y/n): ");
	scanf(" %c", &reply);
	
	while(reply == 'y'){
		printf("Enter number to insert: ");
		scanf("%d", &num);
		
		temp = (nd*)malloc(sizeof(nd));
		temp->x = num;
		
		if(head == NULL){
			head = temp;
		}
	 
		while(head->next!=NULL){
			head = head->next;
		}
		head->next = temp;
		
		printf("List: ");
	    while(head != NULL) {
	        printf("%d ", head->x);
	        head = head->next;
	    }
		printf("Do you want to insert? (y/n): ");
		scanf(" %c", &reply);
		printf("\n");
	}
	
    printf("List: ");
    p = head;
    while (p != NULL) {
        printf("%d ", p->x);
        p = p->next;
    }
    printf("\n");
    
    return 0;
}
