#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

typedef struct node nd;
nd *head, *p, *temp;

int getSum(nd *head){
	int sum = 0;
	
	p = head;
	while(p != NULL){
		sum += p->data;
		p = p->next;
	}
	return sum;
}
float getAve(nd *head, int sum, int counter){
	float ave;
	
	p = head;
	while(p != NULL){
		ave = (float) sum / counter;
		p = p->next;
	}
	return ave;
}

int main(){
	int data, ans, sum, counter = 1, max, min;
	float ave;
	head = (nd*)malloc(sizeof(nd));
	p=head;
	printf("Enter a number: ");
	scanf("%d", &p->data);
	
	printf("Press 1 to enter another number: ");
	scanf("%d", &ans);
	
	p=head;
	while(ans == 1){
		p->next = (nd*)malloc(sizeof(nd));
		p->next->data=data;
		p = p->next;
		printf("Enter a number: ");
		scanf("%d", &p->data);
		
		printf("Press 1 to enter another number: ");
		scanf("%d", &ans);
		counter++;
	}
	p->next = NULL;
	

	p=head;
	min = p->data;
	max = p->data;
	while(p!=NULL){
		if(max < p->data){
			max = p->data;
		}else{
			min = p->data;
		}
		p = p->next;
	}
		
	sum = getSum(head);
	ave = getAve(head, sum, counter);
	printf("Sum: %d", sum);
	printf("\nAverage: %.2f", ave);
	printf("\nMinimum: %d", min);
	printf("\nMaximum: %d", max);
	return 0;
}
