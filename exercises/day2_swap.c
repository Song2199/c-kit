#include <stdio.h>

void swap_wrong(int a,int b)
{
int tmp = a;
a = b;
b = tmp;
printf("swap_wrong 内部: a=%d,b=%d \n", a,b);
}

void swap_right(int *a,int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
    printf("swap_right 内部: *a =%d.*b=%d \n", *a, *b);
}
int main(void)
{
    int x=10,y=20;
    printf("调用前: x=%d,y=%d", x,y);
    printf("---swap_wrong---\n");
    swap_wrong(x,y);
    printf("调用后: x=%d,y=%d\n", x,y);

    printf("---swap_right---\n");
    swap_right(&x,&y);
    printf("调用后: x=%d,y=%d\n", x,y);

    return 0;

}

