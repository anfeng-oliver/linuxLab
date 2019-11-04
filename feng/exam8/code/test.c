#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int i=getpid();
	int j=getppid();
	printf("pid= %d  ppid= %d\n",i,j);
	
	return 0;
	while (1);
}
