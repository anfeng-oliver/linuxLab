#include "my.h"

int main()
{
	pid_t result;
	int r_num;
	int pipe_fd[2];
	char buf_r[100];
	memset(buf_r,0,sizeof(buf_r));
	if(pipe(pipe_fd)<0)
	{
		printf("failed to create pipe!\n");
		return -1;
	}
	result = fork();
	if(result<0)
	{
		perror("failed to fork son!\n");
		exit;
	}
	else if(result=0)
	{
		close(pipe_fd[1]);
		if((r_num=read(pipe_fd[0],buf_r,100))>0)
			printf("son read %d stuff from pipe:%s\n",r_num,buf_r);
		close(pipe_fd[0]);
		exit(0);
	}
	else 
	{
		close(pipe_fd[0]);
		if(write(pipe_fd[1],"the first words!",10)!=-1)
			printf("parent write in the first words!\n");
		if(write(pipe_fd[1],"the second word!",10)!=-1)
			printf("parent write in the second word!\n");
		close(pipe_fd[1]);
		waitpid(result,NULL,0);
		exit(0);
	}
}	
