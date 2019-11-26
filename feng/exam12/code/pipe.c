#include "my.h"

int main()
{
	pid_t r;
	int r_num;
	int pipe_fd[2];
	char buf[1];
	memset(buf,0,sizeof(buf));
	if(pipe(pipe_fd)<0)
	{
		perror("pipe failed!\n");
		return -1;
	}
	r=fork();
	if(r<0)
	{
		perror("failed to fork!\n");
		return -1;
	}
	else if(r==0)
	{
		char b='a';
		close(pipe_fd[0]);
		for(int i=0;i<65537;i++)
		{
			printf("child write %d times!\n",i);
			write(pipe_fd[1],&b,1);
		}
		printf("child write over!\n");	
		close(pipe_fd[1]);
		exit(0);
	}
	else
	{
		wait(NULL);
		close(pipe_fd[1]);
		for(int i=0;i<65536;i++)
		{
			read(pipe_fd[0],buf,1);
			printf("%d:parent read from pipe: %s\n",i,buf);
		}
		close(pipe_fd[0]);
		return 0;
	}
}
