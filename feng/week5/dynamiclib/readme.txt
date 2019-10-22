gcc -fPIC -shared -o libdynamiclib.so -fun1.c fun2.c  //create dynamiclib file .so
gcc -rdynamic -o main main.c -ldl
