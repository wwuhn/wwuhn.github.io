#include <stdio.h>

int callee(int f, int g)  // 等价于int __cdecl callee(int f, int g) // 显式声明了调用约定
{
    int h = f + g;
    return h;
}

int func(int a, int b)
{
    int c = a*a;
    int d = b*b;
    int e = callee(c,d);
    return e;
}

int main()
{
    int result=func(3,4);
    return 0;
}
