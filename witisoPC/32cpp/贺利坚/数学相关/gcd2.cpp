#include <stdio.h>
#include <iostream>
using namespace std;
// Type your code here, or load an example.

int gcd(int a,int b)  // 辗转相除法的递归写法
{
    if(b==0)
        return a;
    return gcd(b,a%b);
    //return b?gcd(b,a%b):a;
}
int gcd2(int a, int b) // 欧拉的辗转相除法
{
    while(b != 0)
    {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}
int gcd3(int a, int b) // 《九章》中的辗转相减法
{
    int t = a;
    a = a>b?a:b;
    b = t<b?t:b;
    while(b != 0)
    {
        t = a - b;
        a = t>b?t:b;
        b = t<b?t:b;
    }
    return a;
}

int main()
{
    
    
    printf("%d\n",gcd(104,195));
    printf("%d\n",gcd2(1680,640));
    printf("%d\n",gcd3(1680,640));
    
restart:   
    
    
    goto restart;
    return 0;
}
/*
#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
printf("");
while(1); // pause
cin.ignore(32767, '\n'); // ignore up to 32767 characters until a \n is removed
system("pause");
getchar();
*/