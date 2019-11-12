#include "my.h"

int g = 10;

int main()
{
	int s=20;
	static int k = 30;
	pid_t pid;
	//int status;
	pid = vfork();
	if(pid<0)
	{
		perror("fork failed!\n");
		return -1;
	}
	else if(pid==0)
	{
		printf("child pid = %d : \n&g=%16p\n&k=%16p\n&s=%16p\n",getpid(),&g,&k,&s);
		g = 100;
		s = 200;
		k = 300;
		//execl("./pro1","pro1",NULL);
		sleep(2);
		printf("child after g = %d,s = %d,k = %d\n",g,s,k);
		//_exit(12);		
		//return 0;
	}
	else
	{
		//wait(&status);
		//printf("child exit code = %d\n",WEXITSTATUS(status));
		//sleep(2);
		printf("parent pid = %d : \n&g=%16p\n&k=%16p\n&s=%16p\n",getpid(),&g,&k,&s);
		printf("parent after g = %d,s = %d,k = %d\n",g,s,k);
		return 0;
	}
}
