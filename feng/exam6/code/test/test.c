#include "../my.h"
#include <dlfcn.h>
int main()
{
	void *hd=NULL;
	void (*f1)(),(*f2)();
	void (*f3)(),(*f4)();
	char *error;
	int a[N];
	hd=dlopen("../dynamiclib.so",RTLD_LAZY);
		if(!hd)
		{
			fprintf(stderr,"%s\n",dlerror());
			exit(1);
		}

	f1=dlsym(hd,"show");
	error=dlerror();
	if(error!=NULL)
	{
		fprintf(stderr,"%s\n",error);
		exit(1);
	}
	f2=dlsym(hd,"init");
	error=dlerror();
	if(error!=NULL)
	{
		fprintf(stderr,"%s\n",error);
		exit(1);
	}
	f3=dlsym(hd,"max");
	error=dlerror();
	if(error!=NULL)
	{
		fprintf(stderr,"%s\n",error);
		exit(1);
	}
	f4=dlsym(hd,"sum");
	error=dlerror();
	if(error!=NULL)
	{
		fprintf(stderr,"%s\n",error);
		exit(1);
	}
	printf("Before init \n");
	(*f1)(a,N);
	(*f2)(a,N);
	printf("After init \n");
	(*f1)(a,N);
	printf("max= %4d\n",(*f3)(a,N));x`
	printf("sum= %4d\n",(*f4)(a,N));
	dlclose(hd);

	
}
