
#include <stdio.h> // 简易版加法器 ， 连续输入两个0结束
int main()
{
    freopen("input.txt","r",stdin);  //只加这一句输入将被重定向到文件input.txt
    int a,b;
    while(scanf("%d %d",&a, &b) && (a||b))
	{
		printf("%4d + %-4d = %d\n",a,b,a+b);
	}
    while(1);
	return 0;
}
/* input.txt:
3 4
45 56
23 45
13 25
13 22
45 56
0 0
*/
/* output:
   3 + 4    = 7
  45 + 56   = 101
  23 + 45   = 68
  13 + 25   = 38
  13 + 22   = 35
  45 + 56   = 101
*/