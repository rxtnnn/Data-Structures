#include <stdio.h>

int deleteNumber(int list[], int *size, int deleteNum);

int main() {
    int size = 5;
    int deleteNum, choice, newSize;
    int list[size];
    
    printf("Enter %d integers: ", size);
    for(int i = 0; i<size; i++){
        scanf("%d", &list[i]);
    }
    do{
        printf("Enter the number to delete: ");
        scanf("%d", &deleteNum);
    
        newSize = deleteNumber(list, &size, deleteNum);
  
		if(newSize != 0 && newSize != -1){ //If there is still elements in array
            printf("New list: ");
            for (int i = 0; i < newSize; i++) {
                printf("%d ", list[i]);
            }
        }else if(newSize == -1){ //If number is not in the list
        	printf("Number is not in the list");
		}else{ // If list is empty, prompt;
            printf("Array list is empty");
            break;
        }
        printf("\nDo you want to continue? (1-YES 0-NO): ");
        scanf("%d", &choice);
        printf("\n");
    }while(choice != 0);
    return 0;
}

int deleteNumber(int list[], int *size, int deleteNum) {
    int newSize = *size; //size = 5
	int i, j, found = 0;
	
	for (i = 0; i < newSize; i++) { //newSize: 5
        if (list[i] == deleteNum) { //1 2 3 1 5 delete: 1
            // Shift elements to the left to fill the gap
            for (j = i; j < newSize - 1; j++) { // newSize - 1 since array starts at index 0
                list[j] = list[j + 1]; // 
            }
            newSize--; // Decrease the size of the array
            i--; // Decrement 'i' to avoid skipping other numbers
            found = 1; //indicates that number is present in array
        }
    }
    
	if(!found){ //if number is not in the list
		return -1;
	}
	
	*size = newSize;
    return newSize;
}

