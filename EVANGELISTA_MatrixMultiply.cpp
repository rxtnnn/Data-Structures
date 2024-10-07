#include <stdio.h>
#define N 3

void MultiplyMatrix(int A[N][N], int B[N][N], int C[N][N]);
int isSymmetricMatrix(int A[N][N]);

int main() {
    int A[N][N], B[N][N], C[N][N];
    
    printf("Enter the First Matrix: ");
    for(int i=0; i<N; i++){
    	for(int j=0; j<N; j++){
    		scanf("%d", &A[i][j]);
		}
		printf("\n");
	}
	
	printf("Enter the Second Matrix: ");
    for(int i=0; i<N; i++){
    	for(int j=0; j<N; j++){
    		scanf("%d", &B[i][j]);
		}
		printf("\n");
	}
	
	//print the matrixes;
	printf("First Matrix: \n");
    for(int i=0; i<N; i++){
    	for(int j=0; j<N; j++){
    		printf("| %d ", A[i][j]);
		}
		printf("\n");
	}
	
	printf("Second Matrix: \n");
    for(int i=0; i<N; i++){
    	for(int j=0; j<N; j++){
    		printf("| %d ", B[i][j]);
		}
		printf("\n");
	}
	
	MultiplyMatrix(A, B, C);
	
	printf("Result: \n");
    for(int i=0; i<N; i++){
    	for(int j=0; j<N; j++){
    		printf(" %d |", C[i][j]);
		}
		printf("\n");
	}
	
    // Check if the result matrix is symmetric
	if (isSymmetricMatrix(C)) {
	    printf("\nThe matrix is symmetric.\n");
	} else {
	    printf("\nThe matrix is not symmetric.\n");
	}
	
    return 0;
}

void MultiplyMatrix(int A[N][N], int B[N][N], int C[N][N]){
	
	for (int row = 0; row < N; row++) { //rows of C
        for (int column = 0; column < N; column++) { // columns of C
            C[row][column] = 0; // result 0; accumulate all sum values
            for (int k = 0; k < N; k++) { //iterates the elements
                C[row][column] += A[row][k] * B[k][column]; //3+2+12
            }
        }
    }
}

int isSymmetricMatrix(int A[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (A[i][j] != A[j][i]) {
                return 0; // Not symmetric
            }
        }
    }
    return 1; // Symmetric
}

