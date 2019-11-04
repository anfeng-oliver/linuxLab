#include "my.h"

int main()
{
	int ret;
	printf("calling: pid = %d,ppid = %d\n",getpid(),getppid());
	ret = system("/home/rlk/linuxLab/feng/exam9/code/test1");
	printf("after calling!\n");
	return 0;
}
