#include<stdio.h>

int (*p)(int);
int _func(int a)
{
    int func(int b)
    {
        return a+b;
    }
    p = &func;
    return func(a);
}
int main()
{
    _func(5);
    printf("%d\n", p(10));
    return 0;
}
