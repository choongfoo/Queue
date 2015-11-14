#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Function.h"

int validplate()
{
	printf("Bus number plate: ");
	// able to match putrajaya1234a
	int matched = scanf("%9[a-zA-Z]%4[0-9]%1[a-zA-Z]", temp->s, temp->d, temp->c);
	while (matched != 3){
		scanf("%*[^\n]%*1[\n]"); // another method to clear input buffer
		printf("You are not entering a valid number plate!\nPlease make sure there is no space in the number plate\n");
		printf("and is typed correctly.\nBus Numer Plate : ");
		matched = scanf("%9[a-zA-Z]%4[0-9]%1[a-zA-Z]", temp->s, temp->d, temp->c);
	}
	if (temp->c != '\n') scanf("%*[^\n]%*1[\n]");
	for (int i = 0; i < strlen(temp->s); i++) temp->s[i] = toupper(temp->s[i]);
	temp->c == '\n' ? '\0' : toupper(temp->c);
	//system("timeout -t 30");
}

void Insert()
{
	temp = malloc(sizeof(node));
	validplate();
	printf("\n\nType of bus ? ");
	fflush(stdin);
	fgets(&temp->type, l, stdin);
	printf("\n\nCapacity of bus ? ");
	fflush(stdin);
	fgets(&temp->capacity, l, stdin);

	if (temp == NULL)
		printf(" Out of Memory !! Overflow !!!");
	else
	{
		temp->link = NULL;
		if (front == NULL) { front = rear = temp; } /* First Node? */
		else
		{
			rear->link = temp; rear = temp;
		}       /* Insert End */
		printf(" Node has been inserted at End Successfully !!");
	}
}

int Delete()
{
	int info;
	node *t;
	if (front == NULL) { printf(" Underflow!!!"); return -1; }
	else
	{
		t = front;
		if (front == rear) rear = NULL;
		front = front->link;
		t->link = NULL;
		free(t);
		return(front);
	}
}

void Display()
{
	node *t;
	if (front == NULL) printf("Empty Queue\n");
	else
	{
		t = front;
		printf("Front->");
		while (t)
		{
			printf("\n\t[%s%s%c \t%s \t%s\t ]->", t->s, t->d, t->c, t->type, t->capacity);
			t = t->link;
		}
		printf("Rear\n");
	}
}