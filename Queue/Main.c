#include <stdio.h>
#include <stdlib.h>
#include "Function.h"

node *front, *rear;   /* Global Declarations */

main()
{
	/* Main Program */
	int choice;
	front = rear = NULL;
	while (1)
	{
		system("cls");
		printf("\n ### Linked List Implementation of QUEUE Operations ### \n\n");
		printf("THE SIZE OF QUEUE IS %d", N);
		printf("\n1 - Insert\n2 - Delete\n3 - Display\n4 - search\n5 - Exit\n");
		printf("\nSelection: ");
		fflush(stdin);
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			Insert();
			break;
		case 2:
			Delete();
			system("pause");
			break;
		case 3:
			printf("\nLinked List Implementation of Queue: Status:\n");
			Display();
			system("pause");
			break;
		case 4:
			search();
			break;
		case 5:
			exit(0);
			break;
		default:
			printf("\nInvalid input!!\n\a");
			system("pause");
			break;
		}
	}
}

