#include "mylib.h"

void init(int *a ,int n)
{
	srand(time(NULL));
	int i;
	for(i=0;i<n;i++)
		a[i] = rand()%1000;
}
void show(int * a,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%4d\n",a[i]);
}
