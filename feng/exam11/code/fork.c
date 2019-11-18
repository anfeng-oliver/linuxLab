#include "my.h"

int g = 10;
int main()
{
	int s = 20;
	static int k = 30;
	pid_t pid[2];
	int i;
	int status;
	for(i=0;i<2;i++)
	{
		pid[i] = fork();
		if(pid[i]==0||pid[i]==1)
		{
			break;		
		}
	}
	if(pid[i]==-1)
	{
		perror("failed to fork!\n");
		exit(1);
	}
	if(pid[i]==0)
	{
		printf("son[%d]:pid=%d\n&g=%16p\n&k=%16p\n&s=%16p\n",i,getpid(),&g,&k,&s);
		g = 100;
		s = 200;
		k = 300;
		sleep(1);
		//execl("./pro1","pro1",NULL);
		printf("child after g = %d,s = %d,k = %d\n",g,s,k);
		exit(0);
	}else
	{
		wait(&status);
		printf("child exit code = %d\n",WEXITSTATUS(status));
		printf("parent pid = %d : \n&g=%16p\n&k=%16p\n&s=%16p\n",getpid(),&g,&k,&s);
		printf("parent after g = %d,s = %d,k = %d\n",g,s,k);
		exit(0);
	}
}
