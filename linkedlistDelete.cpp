#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

typedef struct node nd;
nd *head, *previous, *current, *newNode, *p, *temp;

void deleteNum(nd **head, int data) {
  previous = NULL;
  current = *head;

  while (current != NULL && current->data != data) {
    previous = current;
    current = current->next;
  }

  if (current == NULL) {
    printf("Number does not exist");
    return;
  }

  if (previous == NULL) {
    *head = current->next;
  } else {
    previous->next = current->next;
  }
  free(current);
}

void displayList(nd *head) {
  current = head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
}

int main() {
  int data, choice;

  head = (nd *)malloc(sizeof(nd));
  p = head;
  printf("Enter a number: ");
  scanf("%d", &p->data);

  printf("Press 1 to enter another number: ");
  scanf("%d", &choice);

  while (choice == 1) {
    p->next = (nd *)malloc(sizeof(nd));
    p->next->data = data;
    p = p->next;
    printf("Enter a number: ");
    scanf("%d", &p->data);
    printf("Press 1 to enter another number: ");
    scanf("%d", &choice);
  }
  p->next = NULL;

  printf("List: ");
  displayList(head);

  do {
    printf("\nEnter number to delete: ");
    scanf("%d", &data);
    deleteNum(&head, data);
    printf("List: ");
	displayList(head);
    printf("\nPress 1 to delete another number: ");
    scanf("%d", &choice);
  } while (choice == 1);

  printf("List: ");
  displayList(head);

  // free memory
  while (head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }

  free(head); // free the head node

  return 0;
}

