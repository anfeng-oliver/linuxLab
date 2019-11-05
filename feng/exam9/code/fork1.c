#include "my.h"
int g = 99;
main()
{
	int i,pid;
	static int  f = 19;
	pid = fork();
	if(pid<0)
	{
		perror("fork faited!");
		exit (1);
	}
	else if (pid==0)
	{
		printf("child: pid = %d,ppid = %d\n",getpid(),getppid());
		i = 100;
		g = 101;
		f = 238;
		printf("child num:i=%d,g=%d,f=%d\n",i,g,f);
		exit(123);
	}
	printf("parent: pid = %d,ppid = %d\n",getpid(),getppid());
	printf("parent num:i=%d,g=%d,f=%d\n",i,g,f);
	return 0;
}
