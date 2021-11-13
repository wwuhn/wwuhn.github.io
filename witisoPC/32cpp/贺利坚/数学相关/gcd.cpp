#include <stdio.h>
#include <iostream>
using namespace std;
int gcd2(int a,int b)
{
    while(b>0)
    {
        int tmp = a%b;
        a=b;
        b=tmp;
    }
    return a;
}
int gcd3(int a,int b)
{
    if(b==0)
        return a;
    return gcd3(b,a%b);
}
int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}
int gcd4(int m, int n)
{
    int r;
    if (m<n){r=m;m=n;n=r;}
    while(r=m%n)  // 求m，n的最大公约数
    {
        m=n;
        n=r;
    }
    return n;
}
int gcd5(int m, int n)
{
    int r;
    //if (m<n){r=m;m=n;n=r;}
    while(r=m%n)  // 求m，n的最大公约数
    {
        m=n;
        n=r;
    }
    return n;
}
int main()
{
    
printf("%-2d ",gcd2(104,195));
printf("%-2d ",gcd2(195,104));
printf("%-2d ",gcd4(104,195));
printf("%-2d ",gcd5(195,104));
printf("%-2d ",gcd4(195,104));;
printf("%-2d ",gcd5(104,195));

a:   
    goto a;
    return 0;
}
/*

*/