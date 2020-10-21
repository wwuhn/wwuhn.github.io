#if 1
#include <iostream>
#include <stack>
using namespace std;
struct Problem{
	int n;
	char src,mid,dest;
	Problem(int nn,char s,char m,char d):n(nn),src(s),mid(m),dest(d){}
};// 一个Problem变量代表一个子问题，将src上的n个盘子以mid为中介，移动到dest
stack<Problem> stk; // 一个元素代码一个子问题，若有n个盘子，则栈的高度不超过n*3

void main()
{

	system("pause");
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
/*==================================================
函数功能：输出汉诺塔的移动方法
函数输入：盘子数量n、三个柱的编号from,temp,to
函数输出：输出汉诺塔的移动方法
==================================================*/
void hanoi(int n, char from, char temp, char to)
{
	if (n==1)
		printf("将编号为1的盘子从%c移到%c\n",from,to);
	else
	{
		printf("hanoi(%d,%c,%c,%c)\n",n-1,from,to,temp);
		hanoi(n-1,from,to,temp);					//将x上编号为1到n-1的圆盘移到y，z作辅助塔
		printf("盘子从%c移到%c\n",from,to);		//将x上编号为n的圆盘移到z
		printf("hanoi(%d,%c,%c,%c)\n",n-1,temp,from,to);
		hanoi(n-1,temp,from,to);					//将y上编号为1到n-1的圆盘移到z，y作辅助塔
		
	}
}
int main()
{
	int n;
	printf("请输入盘子数量n:\n");
	scanf("%d",&n);
	hanoi(n,'A','B','C');
	system("pause");
	return 0;
}
//http://www.7k7k.com/swf/37623.htm
/*
你如果掌握了第一个（最小的）盘子的移动规模，这个游戏你玩起来就会得心应手。

当n是奇数时，第一个盘子只能在柱子ACBACB……间循环移动；

当n是偶数时，第一个盘子只能在柱子ABCABC……间循环移动；
*/

#endif