#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "Function.h"

int queue[N] = { 0 }; //The bus stop length
int count = 0; // we use count to determine number of our structures

void Insert() //Insert a new queue for new bus arrived
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
			/* fgets actually takes \n as 1 char. for example
			input aaaa and then enter, the strlen will be 5 because "aaaa\n". below is the fix */
		} while (validchar(true)); //This is the boolean function to check the input is non-numeric
		
		printf("\nCapacity of bus: ");
		do
		{
			fflush(stdin);
			fgets(&temp->capacity, l, stdin);
			if (temp->capacity[strlen(temp->capacity) - 1] == '\n')
				temp->capacity[strlen(temp->capacity) - 1] = 0;
		} while (validnum(true)); //This is the boolean function to check the input is numeric

		temp->next = NULL;

		if (front == NULL)
		{
			queue[count] = front = rear = temp; // First bus
			count++;
		}
		else
		{
			rear->next = temp;
			queue[count] = rear = temp;
			count++;
			//Insert bus from the end
		}       
		printf("\nNew bus has been arrived!!\n");
		system("pause");
	}

	else
	{
		printf("\nBus stop is overflow!\a\n");
		system("pause");
	}
}

_Bool validnum() //simple input checking for bus capacity
{
	int len, n;
	/*int length will carry the value of the length of customerNum string.
	For example, strlen("tttt") = 4*/
	len = strlen(temp->capacity);

	if (len == 0)
	{
		printf("Please at least enter something\n");
		return true;
	}
	for (n = 0; n < len; n++)
	{
		/*checks every characters whether one or more do carry something other than numerical value.
		isdigit requires <ctype.h>*/
		if (!isdigit(temp->capacity[n]))
		{
			printf("You need to input numerical values only! Please try again\n");
			return true;
		}
	}
	return false;
}

_Bool validchar() //simple input checking for bus type
{
	int len, ch;

	len = strlen(temp->type); //string length

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
	

	while (t != NULL)
	{ //For checking duplicate bus number plate to avoid insert existing number plate
		if (t->c != NULL)
		{
			if (!strcmp(t->s, temp->s) && !strcmp(t->d, temp->d) && t->c == temp->c)
			{
				printf("\nCan't insert a duplicate number!\a\n");
				printf("\nPlease insert again!\n");
				validplate();
			}
		}
		if (t->c == NULL)
		{
			if (!strcmp(t->s, temp->s) && !strcmp(t->d, temp->d))
			{
				printf("\nCan't insert a duplicate number!\a\n");
				printf("\nPlease insert again!\n");
				validplate();
			}
		}
		t = t->next;
	}
}

int Delete() //Delete from the front of queue
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

		front = front->next;
		t->next = NULL;
		printf("\nBus left from front: %s%s %c\n", t->s, t->d, t->c);
		free(t);
		count--;
		return(front);
	}
}

void Display() //Display the bus which has been arrive
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
			printf("[%s%s%c, %s, %s]->", t->s, t->d, t->c == '\n' ? '\0' : toupper(t->c), t->type, t->capacity);
			t = t->next;
		}
		printf("Rear\n\n");
	}
}

void Search() //Search by bus registration number
{
	char s[10], d[5], c; //Declaration for comparation

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

		while (temp != NULL)
		{
			if (!strcmp(temp->s, s) && !strcmp(temp->d, d) && temp->c == c) //Bus registration number comparing with the existing registration number
			{
				printf("Bus registration number: ");
				printf("%s%s%c", temp->s, temp->d,
					temp->c == '\n' ? '\0' : toupper(temp->c));
				printf("\nBus type: ");
				printf("%s", temp->type);
				printf("\nBus capacity: ");
				printf("%s", temp->capacity);
				system("pause >nul");
				return 1;
			}
			else
			{
				temp = temp->next;
			}
		}
		printf("\nBus registration number: %s%s %c not found.\n", s, d, c);
		system("pause");
	}
}