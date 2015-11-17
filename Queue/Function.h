#ifndef FUNCTION
#define FUNCTION
#define l 1000
#define N 10

typedef struct NODE
{
	char s[10], d[5], c;
	char type[l];
	char capacity[l];
	struct NODE *link;
}node;

node *front, *rear, *temp;

void Insert();

int  Delete();

void Display();

void Search();

int validplate(void);

_Bool validnum();

_Bool validchar();

#endif