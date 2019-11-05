#include "my.h"
int main()
int g=99;
main()
{
	int i,pid;
	static int f=19;
	pid = fork();
	if(pid<0)
	{
		perror("fork fataul!");
		exit 1;
	}
	else if(pid==0)
	{
		printf("child: pid = %d,ppid = %d\n",getpid(),getppid());
		i=100;
		g=101;
		f=384;
		printf("child:i = %d,g = %d,f = %d",i,g,f);
		exit (123);
	}
	//sleep(10);
	printf("parent: pid = %d,ppid = %d\n",getpid(),getppid());
	printf("parent:i = %d,g = %d,f = %d",i,g,f);
	return 0;
} 
