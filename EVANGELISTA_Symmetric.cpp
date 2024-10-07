#include<stdio.h>
#define N 3

int isSymmetricMatrix(int A[N][N]);


int main(){
	int A[N][N];
    
    printf("Enter the Matrix: ");
    for(int i=0; i<N; i++){
    	for(int j=0; j<N; j++){
    		scanf("%d", &A[i][j]);
		}
		printf("\n");
	}
	
	
	if (isSymmetricMatrix(A)){
	    printf("\nThe matrix is symmetric.\n");
	} else {
	    printf("\nThe matrix is not symmetric.\n");
	}
	 
	return 0;
}

int isSymmetricMatrix(int A[N][N]){
	

	for (int row = 0; row<N; row++) {
        for (int column = 0; column < row; column++) {
            if (A[row][column] != A[column][row]) {
                return 0; // Not symmetric
            }
        }
    }
    return  -1; // Symmetric
}
