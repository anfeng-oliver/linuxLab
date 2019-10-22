gcc -c fun1.c fun2.c
ar -rc libmy.a fun1.o fun2.o
gcc -o main main.c -L. -lmy

gcc -o main1 main1.c -L/home/rlk/workspace/week5/staticlib/code -lmy
