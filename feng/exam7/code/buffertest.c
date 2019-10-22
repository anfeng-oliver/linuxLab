#include <stdio.h>
#include <stdlib.h>
#define SIZE 512
int main(int argc,char *argv[])
{
	char buf[SIZE];
	if(setvbuf(stdin, buf, _IONBF, SIZE)!=0)
	{
		perror("No buffer stdin setting failed!\n");
		return 1;
	}	
	printf("No buffer stdin setting succeed!\n");
	printf("kind of the stdin :");
	if(stdin->_flags & _IO_UNBUFFERED)
	{
		printf("No buffer!\n");
	}
	else if(stdin->_flags & _IO_LINE_BUF)
	{
		printf("Line buffer!\n");
	}
	else
	{
		printf("Fully buffer!\n");
	}
	printf("Size Of Buffer Area is %ld\n",stdin->_IO_buf_end - stdin->_IO_buf_base);
	printf("File desc symbol is %d\n",fileno(stdin));
	if(setvbuf(stdin,buf,_IOFBF,SIZE)!=0)
	{
		printf("Fully buffer stdin setting failed!\n");
		return 2;
	}
	printf("Modify stdin kind succeed!\n");
	printf("Kind of the stdin is :");
	if(stdin->_flags &_IO_UNBUFFERED)
	{
		printf("No buffer!\n");
	}else if(stdin->_flags &_IO_LINE_BUF)
	{
		printf("Line buffer!\n");
	}
	else
	{
		printf("Fully buffer!\n");
	}
	printf("Size Of Buffer Area is %ld\n",stdin->_IO_buf_end - stdin->_IO_buf_base);
	printf("File desc symbol is %d\n",fileno(stdin));
	return 0;
}

