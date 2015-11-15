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
		printf("\n### Linked List Implementation of QUEUE Operations ###\n\n");
		printf("THE SIZE OF QUEUE IS %d", N);
		printf("\n1 - Arrive\n2 - Leave\n3 - Print\n4 - Search\n5 - Exit\n");
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
			Search();
			system("pause");
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