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
		
		printf("\nType of bus: ");
		do
		{
			fflush(stdin);
			fgets(&temp->type, l, stdin);
			if (temp->type[strlen(temp->type) - 1] == '\n')
				temp->type[strlen(temp->type) - 1] = 0;
		} while (validchar(true));
		
		printf("\nCapacity of bus: ");
		do
		{
			fflush(stdin);
			fgets(&temp->capacity, l, stdin);
			if (temp->capacity[strlen(temp->capacity) - 1] == '\n')
				temp->capacity[strlen(temp->capacity) - 1] = 0;
		} while (validnum(true));

		temp->link = NULL;

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
		printf("\nNew bus has been arrived!!\n");
		system("pause");
	}

	else
	{
		printf("\nBus stop is overflow!\a\n");
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
			printf("Type of bus shall not consist of numbers! Please try again\n");
			return true;
		}
	}
	return false;
}

int validplate(void)
{
	node *t;

	t = front;

	printf("\nBus registration number: ");
	// able to match putrajaya1234a
	fflush(stdin); //Better if i use fflush stdin.
	int matched = scanf("%9[a-zA-Z]%4[0-9]%c", temp->s, temp->d, &temp->c);
	do{
		while (matched != 3){
			scanf("%*[^\n]%*1[\n]"); //another method to clear input buffer
			fflush(stdin); //Just in case.
			printf("You are not entering a valid number plate!\nPlease make sure there is no space in the number plate\n");
			printf("and is typed correctly.\nBus Numer Plate : ");
			matched = scanf("%9[a-zA-Z]%4[0-9]%c", temp->s, temp->d, &temp->c);
		}

		if (isdigit(temp->c))
		{
			printf("You are not entering a valid number plate!\nPlease make sure there is no space in the number plate\n");
			printf("and is typed correctly.\nBus Numer Plate : ");
			fflush(stdin);
			matched = scanf("%9[a-zA-Z]%4[0-9]%c", temp->s, temp->d, &temp->c);
		}
	} while (isdigit(temp->c));
	if (temp->c != '\n') {
		scanf("%*[^\n]%*1[\n]"); fflush(stdin); //flushing twice 'cuz sometimes scanf("%*...") does not work
	}
	for (int i = 0; i < strlen(temp->s); i++) temp->s[i] = toupper(temp->s[i]);
	temp->c == '\n' ? '\0' : toupper(temp->c);

	if (front != NULL)
	{
		{if (!strcmp(t->s, temp->s) && !strcmp(t->d, temp->d) && !strcmp(t->c, temp->c))
			{
				printf("\nCan't insert a duplicate number!\a\n");
				printf("\nPlease insert again!\n");
				system("pause >nul");
				validplate();
			}
			else
			{
				t = t->link;
			}
		}
	}
}

int Delete()
{
	node *t;

	if (front == NULL)
	{
		printf("No bus has been arrived!\n\a");
		return -1;
	}
	else
	{
		t = front;
		if (front == rear) 
			rear = NULL;

		front = front->link;
		t->link = NULL;
		printf("\nBus left from front: %s%s %c\n", t->s, t->d, t->c);
		free(t);
		count--;
		return(front);
	}
}

void Display()
{
	node *t;

	if (front == NULL) 
		printf("No bus has been arrived!\n\a");
	else
	{
		t = front;
		printf("\n[*Bus registration number, *Bus type, *Bus capacity]\n\n");
		printf("Front->");

		while (t)
		{
			printf("[%s%s %c, %s, %s]->", t->s, t->d, t->c, t->type, t->capacity);
			t = t->link;
		}
		printf("Rear\n\n");
	}
}

void Search()
{
	char s[10], d[5], c;

	temp = front;

	if (temp == NULL)
	{
		printf("No bus has been arrived!\n\a");
		system("pause");
		return 1;
	}

	else
	{
		printf("\nSearch for bus registration number: ");
		fflush(stdin);
		int matched = scanf("%9[a-zA-Z]%4[0-9]%c", s, d, &c);
		do {
			while (matched != 3){
				scanf("%*[^\n]%*1[\n]");
				fflush(stdin);// another method to clear input buffer
				printf("You are not entering a valid number plate!\nPlease make sure there is no space in the number plate\n");
				printf("and is typed correctly.\nBus Number Plate : ");
				matched = scanf("%9[a-zA-Z]%4[0-9]%c", s, d, &c);
			}
			if (isdigit(c))
			{
				printf("You are not entering a valid number plate!\nPlease make sure there is no space in the number plate\n");
				printf("and is typed correctly.\nBus Numer Plate : ");
				fflush(stdin);
				matched = scanf("%9[a-zA-Z]%4[0-9]%c", s, d, &c);
			}
		} while (isdigit(c));
		if (c != '\n'){
			scanf("%*[^\n]%*1[\n]"); fflush(stdin);
		}
		for (int i = 0; i < strlen(s); i++)
			s[i] = toupper(s[i]);
		c == '\n' ? '\0' : toupper(c);

		while (temp != NULL)
		{
			if (!strcmp(temp->s, s) && !strcmp(temp->d, d) && !strcmp(temp->c, c))
			{
				printf("Bus registration number: ");
				printf("%s%s %s", temp->s,temp->d,temp->c);
				printf("\nBus type: ");
				printf("%s", temp->type);
				printf("\nBus capacity: ");
				printf("%s", temp->capacity);
				system("pause >nul");
				return 1;
			}
			else
			{
				temp = temp->link;
			}
		}
		printf("\nBus registration number: %s%s %s not found.\n", s, d, c);
		system("pause");
	}
}