#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "Function.h"

int queue[N] = { 0 };
int count = 0;

void Insert()
{
	if (count < N)
	{
		temp = malloc(sizeof(node));
		validplate();
		
		printf("\n\nType of bus: ");
		do
		{
			fflush(stdin);
			fgets(&temp->type, l, stdin);
			if (temp->type[strlen(temp->type) - 1] == '\n')
				temp->type[strlen(temp->type) - 1] = 0;
		} while (validchar(true));
		
		printf("\n\nCapacity of bus: ");
		do
		{
			fflush(stdin);
			fgets(&temp->capacity, l, stdin);
			if (temp->capacity[strlen(temp->capacity) - 1] == '\n')
				temp->capacity[strlen(temp->capacity) - 1] = 0;
		} while (validnum(true));

		temp->link = NULL;
		//I dont know why i set limit = 1 but i can insert 2 times
		if (front == NULL)
		{
			queue[count] = front = rear = temp; /* First Node */
			count++;
		}
		else
		{
			queue[count] = rear->link = temp;
			queue[count] = rear = temp;
			count++;
		}       /* Insert End */
		printf("\nNode has been inserted at End Successfully !!\n");
		system("pause");
	}

	else
	{
		printf("Overflow!\a\n");
		system("pause");
	}
}

_Bool validnum()
{
	int len, n;

	len = strlen(temp->capacity);

	if (len == 0)
	{
		printf("Please at least enter something\n");
		return true;
	}
	for (n = 0; n < len; n++)
	{
		if (!isdigit(temp->capacity[n]))
		{
			printf("You need to input numerical values only! Please try again\n");
			return true;
		}
	}
	return false;
}

_Bool validchar()
{
	int len, ch;
	len = strlen(temp->type);

	if (len == 0)
	{
		printf("Please at least enter something\n");
		return true;
	}

	for (ch = 0; ch <= len; ch++)
	{
		if (isdigit(temp->type[ch]))
		{
			printf("Name shall not consist of numbers! Please try again\n");
			return true;
		}
	}
	return false;
}

int validplate(void)
{
	printf("\n\nBus number plate: ");
	// able to match putrajaya1234a
	fflush(stdin); //i can't use scanf("%*[^\n]%*1[\n]") here and i don't know why!
	int matched = scanf("%9[a-zA-Z]%4[0-9]%1[a-zA-Z]", temp->s, temp->d, temp->c);
	while (matched != 3){
		scanf("%*[^\n]%*1[\n]");
		fflush(stdin);// another method to clear input buffer
		printf("You are not entering a valid number plate!\nPlease make sure there is no space in the number plate\n");
		printf("and is typed correctly.\nBus Numer Plate : ");
		matched = scanf("%9[a-zA-Z]%4[0-9]%1[a-zA-Z]", temp->s, temp->d, temp->c);
	}
	if (temp->c != '\n') scanf("%*[^\n]%*1[\n]");
	for (int i = 0; i < strlen(temp->s); i++) temp->s[i] = toupper(temp->s[i]);
	temp->c == '\n' ? '\0' : toupper(temp->c);
	//system("timeout -t 30");
}

int Delete()
{
	node *t;
	if (front == NULL)
	{
		printf("Underflow!!!\n");
		return -1;
	}
	else
	{
		t = front;
		if (front == rear) 
			rear = NULL;
		front = front->link;
		t->link = NULL;
		printf("\nDeleted Node(From Front)with the Data: %s%s %s\n", t->s, t->d, t->c);
		free(t);
		return(front);
	}
}

void Display()
{
	node *t;

	if (front == NULL) 
		printf("Empty Queue\n");
	else
	{
		t = front;
		printf("\n[*Bus registration number, *Bus type, *Bus capacity]\n\n");
		printf("Front->");

		while (t)
		{
			printf("[%s%s %s, %s, %s]->", t->s, t->d, t->c, t->type, t->capacity);
			t = t->link;
		}
		printf("Rear\n\n");
	}
}

void Search()
{
	node *t;
	char s[l], d[l], c[l];
	
	printf("Search:");
	fflush(stdin);
	int matched = scanf("%9[a-zA-Z]%4[0-9]%1[a-zA-Z]", s, d, c);
	while (matched != 3){
		scanf("%*[^\n]%*1[\n]");
		fflush(stdin);// another method to clear input buffer
		printf("You are not entering a valid number plate!\nPlease make sure there is no space in the number plate\n");
		printf("and is typed correctly.\nBus Numer Plate : ");
		matched = scanf("%9[a-zA-Z]%4[0-9]%1[a-zA-Z]", s, d, c);
	}
	if (c != '\n') scanf("%*[^\n]%*1[\n]");
	for (int i = 0; i < strlen(s); i++) 
		s[i] = toupper(s[i]);
	c == '\n' ? '\0' : toupper(c);


	while (temp != NULL)
	{
		if (strcmp(temp->s, s), strcmp(temp->d, d), strcmp(temp->c, c))
		{
			printf("key found\n");
		}
	}
	printf("Key not found\n");
}