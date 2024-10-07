#include <stdio.h>

void mergeAndSort(int A[], int B[], int C[], int m, int n) {
    int i = 0, j = 0, k = 0;

    // Merge elements from arrays A and B into C
    while (i < m && j < n) {
        if (A[i] < B[j]) {
            C[k++] = A[i++];
        } else {
            C[k++] = B[j++];
        }
    }

    // Copy remaining elements from A (if any)
    while (i < m) {
        C[k++] = A[i++];
    }

    // Copy remaining elements from B (if any)
    while (j < n) {
        C[k++] = B[j++];
    }
}

int main() {
    int sizeA, sizeB;

    printf("Enter number of elements in array A: ");
    scanf("%d", &sizeA);

    printf("Enter number of elements in array B: ");
    scanf("%d", &sizeB);

    int A[sizeA];
    int B[sizeB];
    
    // Input array A elements
    printf("Enter elements of array A:\n");
    for (int i = 0; i < sizeA; i++) {
        scanf("%d", &A[i]);
    }

    // Input array B elements
    printf("Enter elements of array B:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &B[i]);
    }

    int C[m + n]; // Array C to hold the merged and sorted elements

    // Merge elements from arrays A and B into C
    mergeAndSort(A, B, C, m, n);

    // Sort array C in ascending order using insertion sort
    for (int i = 1; i < m + n; i++) {
        int key = C[i];
        int j = i - 1;

        while (j >= 0 && C[j] > key) {
            C[j + 1] = C[j];
            j--;
        }

        C[j + 1] = key;
    }

    // Print the sorted array C
    printf("Sorted Array C: ");
    for (int i = 0; i < m + n; i++) {
        printf("%d ", C[i]);
    }
    printf("\n");

    return 0;
}

