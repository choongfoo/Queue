#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define l 1000

typedef struct node
{
	char registNum[l];
	char type[l];
	char capacity[l];
	struct node *link;
}NODE;

void Insert();
int  Delete();
void Display();
NODE *front, *rear;   /* Global Declarations */

int validplate()
{
	char s[10], d[5], c[2];
	printf("Bus number plate: ");
	// able to match putrajaya1234a
	int matched = scanf("%9[a-zA-Z]%4[0-9]%1[a-zA-Z]", s, d, c);
	while (matched != 3){
		scanf("%*[^\n]%*1[\n]"); // another method to clear input buffer
		printf("You are not entering a valid number plate!\nPlease make sure there is no space in the number plate\n");
		printf("and is typed correctly.\nBus Numer Plate : ");
		matched = scanf("%9[a-zA-Z]%4[0-9]%1[a-zA-Z]", s, d, c);
	}
	if (c != '\n') scanf("%*[^\n]%*1[\n]");
	for (int i = 0; i < strlen(s); i++) s[i] = toupper(s[i]);
	printf("The bus number plate is: %s%s%c\n", s, d, c == '\n' ? '\0' : toupper(c));
	system("timeout -t 30");
}

main()
{
	/* Main Program */
	int opn, elem;
	front = rear = NULL;
	do
	{
		system("cls");
		printf("\n ### Linked List Implementation of QUEUE Operations ### \n\n");
		printf("\n Press 1-Insert, 2-Delete, 3-Display,4-Exit\n");
		printf("\n Your option ? ");
		scanf("%d", &opn);
		switch (opn)
		{
		case 1:
			Insert();
			break;
		case 2:
			elem = Delete();
			if (elem != -1)
				printf(" Deleted Node(From Front)with the Data: %d\n", elem);
			break;
		case 3: printf("Linked List Implementation of Queue: Status:\n");
			Display(); break;
		case 4: printf("\n\n Terminating \n\n"); break;
		default: printf("\n\nInvalid Option !!! Try Again !! \n\n");
			break;
		}
		printf("\n\n\n\n  Press a Key to Continue . . . ");
		getch();
	} while (opn != 4);
}

void Insert()
{
	NODE *temp;
	temp = (NODE *)malloc(sizeof(NODE));

	printf("\n\nRead the Element to be Inserted ?");
	fflush(stdin);
	fgets(&temp->registNum, l, stdin);
	printf("\n\nRead the Element to be Inserted ?");
	fflush(stdin);
	fgets(&temp->type, l, stdin);
	printf("\n\nRead the Element to be Inserted ?");
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
	NODE *t;
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
	NODE *t;
	if (front == NULL) printf("Empty Queue\n");
	else
	{
		t = front;
		printf("Front->");
		while (t)
		{
			printf("\n\t[%s \t%s \t%s\t ]->", t->registNum, t->type, t->capacity);
			t = t->link;
		}
		printf("Rear\n");
	}
}