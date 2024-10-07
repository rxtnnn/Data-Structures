#include <stdio.h>
#define max 10 

int linearSearch(int x, int arr[]);

int main() {
    int x, choice, y;
    int arr[max] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};

    printf("Array Contents: ");
    for (int i = 0; i < max; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    do {
        printf("\nEnter number to search: ");
        scanf("%d", &x);
        y = linearSearch(x, arr);
        if (y != -1)
            printf("Number is in the list at index %d\n", y);
        else
            printf("Number is not in the list.\n");
        printf("1-yes, 0-no: ");
        scanf("%d", &choice);
    } while (choice != 0);

    return 0;
}

int linearSearch(int x, int arr[]) {
    for (int i = 0; i < max; i++) {
        if (x == arr[i])
            return i; // Return the index where the element is found
    }
    return -1; // Return -1 to indicate element is not found
}

