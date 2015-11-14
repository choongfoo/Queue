#include <stdio.h>
#include <stdlib.h>
#include "Function.h"

#define l 1000



node *front, *rear;   /* Global Declarations */



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

