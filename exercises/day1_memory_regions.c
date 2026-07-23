#include <stdio.h>
#include <stdlib.h>

int global_var = 42;
int global_unint;

int main()
{
    int local_var = 10;
    static int static_var =20;
    char *literal = "hello";
    int *heap_var = malloc(sizeof(int));

    *heap_var = 30;

    printf("=== 内存四区观察 ===\n");
    printf("局部变量 locacl_var   :%p\n",  (void *)&local_var);
    printf("全局变量 global_var   :%p\n",  (void *)&global_var);
    printf("未初始化全局变量       :%p\n",  (void *)&global_unint);
    printf("静态变量 static_var   :%p\n",  (void *)&static_var);
    printf("字符串常量 hello      :%p\n",  (void *)literal);
    printf("malloc 分配的内存     :%p\n",  (void *)heap_var);
    printf("main 函数本身         :%p\n",  (void *)&main);

    free(heap_var);
    return 0;
}   