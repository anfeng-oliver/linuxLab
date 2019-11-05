#include "my.h"

static void __attribute__ ((constructor))before_main()
{
	printf("Running before main!\n");
}
static void __attribute__ ((destructor)) after_main()
{
	printf("Running after main!\n");
}

static void callback1()
{
	printf("1:Runing after main!\n");
}
static void callback2()
{
	printf("2:Runing after main!\n");
}
static void callback3()
{
	printf("3:Runing after main!\n");
}

int main()
{
	atexit(callback1);
	atexit(callback2);
	atexit(callback3);
	printf("test1: pid= %d,ppid= %d\n",getpid(),getppid());
	//while(1);
	sleep(2);
}
