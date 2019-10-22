#include "mylib.h"

int main()
{
	int a[num];
	void * handle;
	int (*f1)();
	int (*f2)();
	int (*f3)();
	int (*f4)();
	char *error;
	handle=dlopen("./libdynamiclib.so",RTLD_LAZY);
	if(!handle)
		{
			perror("load failed!\n");
			exit(1);
		}
	f1=dlsym(handle,"init");
	if((error=dlerror())!=NULL)
		{
			fprintf(stderr,"%s\n",error);
			exit(1);
		}
	f1=dlsym(handle,"show");
	if((error=dlerror())!=NULL)
		{
			fprintf(stderr,"%s\n",error);
			exit(1);
		}
	f1=dlsym(handle,"max");
	if((error=dlerror())!=NULL)
		{
			fprintf(stderr,"%s\n",error);
			exit(1);
		}
	f1=dlsym(handle,"sum");
	if((error=dlerror())!=NULL)
		{
			fprintf(stderr,"%s\n",error);
			exit(1);
		}

	f1(a,num);
	f2(a,num);
	printf("max=%d\n",f3(a,num));
	printf("sum=%d\n",f4(a,num));
	if(dlclose(handle)<0)
		{
			fprintf(stderr,"%s\n",error);
			exit(1);
		}
	return 0;
}
