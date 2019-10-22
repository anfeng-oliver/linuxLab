#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/time.h>
#include <dlfcn.h>
#define num 20

void init(int *a,int n);
void show(int *a,int n);
int max(int *a,int n);
int sum(int *a,int n);
