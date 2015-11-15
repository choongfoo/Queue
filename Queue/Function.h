#ifndef FUNCTION
#define FUNCTION
#define l 1000
#define N 2

typedef struct NODE
{
	char s[10], d[5], c[2];
	char type[l];
	char capacity[l];
	struct NODE *link;
}node;

node *front, *rear, *temp;

void Insert();
int  Delete();
void Display();
void Search();
_Bool validnum();
_Bool validchar();
#endif