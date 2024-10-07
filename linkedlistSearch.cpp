#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};
typedef struct node nd;
nd *head, *temp, *newNode;

int searchNum(nd** head, int data){
	temp = NULL;
	temp = *head;
    while (temp != NULL) {
        if (temp->data == data) {
            return 1; // Found the data in the list
        }
        temp = temp->next;
    }
    return 0; // Data not found in the list
}

void displayList(nd* head){

	temp = head;
  	while (temp != NULL) {
	    printf("%d ", temp->data);
	    temp = temp->next;
  }
}

int main(){
	int choice, data, res;

	head = NULL;
	
	 do {
        printf("Enter a number: ");
        scanf("%d", &data);

        // Create a new node for the entered data
        newNode = (nd*)malloc(sizeof(nd));
        newNode->data = data;
        newNode->next = NULL;

        // Add the new node to the list
        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }

        printf("Press 1 to enter another number: ");
        scanf("%d", &choice);
        printf("\n");
    } while (choice == 1);

	printf("List: ");
	displayList(head);


	do{
		printf("\n");
		printf("Enter number to search: ");
		scanf("%d", &data);
		res = searchNum(&head, data);
			if(res == 1){
	  			printf("\nList is found");
	 		}else{
	 			printf("\nNumber is not in the list");
			}
		printf("\nPress 1 to enter another number: ");
	    scanf("%d", &choice);
	    
	}while(choice == 1);

	return 0;
}

