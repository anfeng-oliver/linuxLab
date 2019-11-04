#include "my.h"

int main()
{
	int ret;
	printf("calling: pid = %d,ppid = %d\n",getpid(),getppid());
	ret = execl("/home/rlk/linuxLab/feng/exam9/code/test1","test1","123","abc",NULL);
	printf("after calling!\n");
	sleep(1);
	return 0;
}
