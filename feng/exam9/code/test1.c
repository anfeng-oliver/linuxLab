#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int x = 100;
int main(int argc,char* argv[])
{
	int y = 0;
	static int w = 33;
	printf("test1:pid = %d,ppid = %d\n",getpid(),getppid());
	for(int i=0;i<argc;i++)
	printf("%s\n",argv);

	printf("test1 adress : x = %d,y = %d,w = %d\n",&x,&y,&w);
	sleep(2);
	return 0;
}
