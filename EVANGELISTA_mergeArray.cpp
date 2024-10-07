#include<stdio.h>
#define SIZE_A 7
#define SIZE_B 5

void mergeArray(int A[], int B[], int C[], int *newSize);

int main(){
	int newSize = SIZE_A + SIZE_B;
	int A[SIZE_A], B[SIZE_B], C[newSize];
	
	printf("Enter %d integers in A:", SIZE_A);
	for(int i=0; i<SIZE_A; i++){
		scanf("%d", &A[i]);
	}
	
	printf("Enter %d integers in B:", SIZE_B);
	for(int i=0; i<SIZE_B; i++){
		scanf("%d", &B[i]);
	}

	mergeArray(A, B, C, &newSize);
	
    //prints the elements
	printf("Elements after merging: ");
	for(int i=0; i< newSize; i++){
		printf("%d\n", C[i]);
	}
	return 0;
}

void mergeArray(int A[], int B[], int C[], int *newSize){
	int i = 0, j = 0, k = 0;
	int temp, flag;
    
    //merge elements of A and B in array C
	for (int i = 0; i < SIZE_A; i++) {
        C[i] = A[i];
    }

    // Copy elements from array B to C
    for (int i = 0; i < SIZE_B; i++) {
        C[SIZE_A + i] = B[i];
    }
    
    //sorts the elements of array
    do {
        flag = 0;
        for (int i = 1; i < *newSize; i++) {
            if (C[i - 1] > C[i]) {
                // Swap arr[i - 1] and arr[i]
                temp = C[i - 1]; 
                C[i - 1] = C[i];
                C[i] = temp;

                flag = 1; // Set the flag to indicate a swap occurred
            }
        }
    }while (flag);
}
