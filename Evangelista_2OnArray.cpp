#include<stdio.h>
#include<stdlib.h>

void insertNum(int *, int *, int, int);

int main(){
	int size, num, pos;
	
	
	printf("Enter the size of the list: ");
	scanf("%d", &size);
	
	int *elements = (int *)malloc(sizeof(int) * size);
	printf("Enter elements of the list: \n");
	for(int i = 0; i < size; i++){
		scanf("%d", &elements[i]);
	}
	
	printf("Enter number to be inserted: ");
	scanf("%d", &num);
	
	printf("Enter the position where the no. is to be inserted: ");
	scanf("%d", &pos);
	
	insertNum(&size, elements, num, pos);
	
	printf("List after insertion: \n");
	for(int i = 0; i < size; i++){
		printf("%d ", elements[i]);
	}
	return 0;
}

void insertNum(int *size, int *elements, int num, int pos){
	
	if(pos < 0 || pos > *size)
		printf("Invalid position");

	(*size)++;
	elements = (int *)realloc(elements, sizeof(int) * (*size));

	for (int i = (*size - 1); i > pos; i--) {
        *(elements + i) = *(elements + i - 1);
    }

	*(elements + pos) = num;
}
