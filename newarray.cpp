#include <stdio.h>
#include <stdlib.h>

void insert_list(int **list, int *size) {
    int num, temp, swap;
    for (int i = 0; i < *size; i++) {
        scanf("%d", &(*list)[i]);
    }

    do {
        swap = 0;
        for (int i = 0; i < *size - 1; i++) {
            if ((*list)[i] > (*list)[i + 1]) {
                temp = (*list)[i];
                (*list)[i] = (*list)[i + 1];
                (*list)[i + 1] = temp;
                swap = 1;
            }
        }
    } while (swap);
}

int delete_list(int **list, int *size, int pos) {
    if (pos < 1 || pos > *size) {
        return 1;
    }

    for (int i = pos - 1; i < *size - 1; i++) {
        (*list)[i] = (*list)[i + 1];
    }
    (*size)--;
    *list = realloc(*list, (*size) * sizeof(int)); // Resize the array

    return 0;
}

void display_list(int *list, int size) {
    printf("Array elements are: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

int main() {
    int size = 0, choice, pos, res;
    int *list = NULL;

    do {
        printf("Choose an operation:\n");
        printf("1 - Add an element\n");
        printf("2 - Delete an element\n");
        printf("3 - Display the list\n");
        printf("4 - Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of elements to add: ");
                scanf("%d", &size);
                list = (int *)malloc(size * sizeof(int));
                printf("Enter %d elements: ", size);
                insert_list(&list, &size);
                break;
            case 2:
                if (list != NULL) {
                    printf("Enter position to delete: ");
                    scanf("%d", &pos);
                    res = delete_list(&list, &size, pos);
                    if (res == 1)
                        printf("Invalid position\n");
                } else {
                    printf("List is empty\n");
                }
                break;
            case 3:
                if (list != NULL) {
                    display_list(list, size);
                } else {
                    printf("List is empty\n");
                }
                break;
            case 4:
                free(list); // Free allocated memory
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
        printf("\n");
    } while (choice != 4);

    return 0;
}

