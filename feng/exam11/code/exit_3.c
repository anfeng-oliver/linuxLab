#include "my.h"

int main()
{
	int pid,s;
	if((pid = fork())<0)
	{
		perror("failed to fork!\n");
		return -1;
	}
	else if(pid==0)
	{
		printf("%d:child is running now!\n",getpid());
		
		printf("%d:child is exit now!\n",getpid());
		
		sleep(8);
		//while(1);
		exit(120);
	}
	else
	{
		printf("%d:parent is running now!\n",getpid());
		while((pid = wait(&s))!=-1)
		{
			printf("%d:parent is exiting now!\n",getpid());
			
			if(WIFEXITED(s))
			{
				printf("child %d is exiting normally ,exit code = %d!\n",pid,WEXITSTATUS(s));
			}
			else if(WIFSIGNALED(s))
			{
				printf("child %d exit by signal ,signal nmb = %d!\n",pid,WTERMSIG(s));
			}
			else
			{
				printf("NOt Know!\n");
			}
		}
	}
	exit(0);
}

