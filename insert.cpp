#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

void insertNum(int elements[], int num, int pos);

int main() {
    int num, pos, choice, list_count;
    int elements[SIZE] = {0};

    printf("Enter 6 integers: ");
    for (int i = 0; i < 6; i++) {
        scanf("%d", &elements[i]);
    }
    
    do {
    	list_count = 0; // list counter
    	
        printf("Enter number to insert: ");
        scanf("%d", &num);
        
        printf("Enter position to insert: ");
        scanf("%d", &pos);
        if (pos < 0 || pos > SIZE-1) 
	        printf("Invalid position\n");
		
        insertNum(elements, num, pos);
        printf("New list:");
        for (int i = 0; i < SIZE; i++) {
            printf(" %d", elements[i]);
        }	
        //exit if array is full
        for(int i = 0; i < SIZE; i++){
    		if(elements[i] != 0)
    		list_count++;
		}
        if(list_count == SIZE){
			printf("\nArray is full");
			exit(1);
		}
        printf("\nDo you want to continue? (1-YES 0-NO): ");
        scanf("%d", &choice);
        printf("\n");
        
    } while (choice != 0);
    
    return 0;
}

void insertNum(int elements[], int num, int pos) {
    
    //shift elements to the right
    for (int i = SIZE - 1; i > pos; i--) {
        elements[i] = elements[i-1];
    }
    elements[pos] = num;
}	

