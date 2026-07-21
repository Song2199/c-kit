#include <stdio.h>

int main()
{
    int a =10;
    int b =20;
    int c =30;

    printf("%p\n",&a);
    printf("%p\n",&b);
    printf("%p\n",&c);

    int arr[] = {1,2,3};
    printf("%p\n",&arr[]);
    printf("%p\n",&arr[1]);
    printf("%p\n",&arr[2]);
}