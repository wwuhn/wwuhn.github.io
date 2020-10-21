#if 1
#include <stdio.h>
#include <time.h>
int step=1;

void move(int n,char a,char c)
{
	if(n==1)
		printf("Step %2d: Disk %d %c → %c *\n",step,n,a,c);
	else
		printf("Step %2d: Disk %d %c → %c\n",step,n,a,c);
	++step;
}
/*
void Hanoi(int n,char a,char b,char c)
{
	if(n==1)
	{
		move(n,a,c);	// 当只剩一个盘子时，将第1个盘子直接从a移到c
		return;
	}
	Hanoi(n-1,a,c,b);	// 将n-1个盘子整体从a通过c移动到b
	move(n,a,c);		// 将剩下的第n个盘子直接从a移到c
	Hanoi(n-1,b,a,c);	// 将n-1个盘子整体从b通过a移动到c
}
*/
void Hanoi(int n,char a,char b,char c)
{
	if(n==1)
		move(n,a,c);	// 当只剩一个盘子时，将第1个盘子直接从a移到c
	else{
		Hanoi(n-1,a,c,b);	// 将n-1个盘子整体从a通过c移动到b
		move(n,a,c);		// 将剩下的第n个盘子直接从a移到c
		Hanoi(n-1,b,a,c);	// 将n-1个盘子整体从b通过a移动到c
	}
}
int main(){
	int n;
	time_t a,b,c;
	printf("请输入汉诺塔盘子数(18个需222秒)：");
	scanf("%d",&n);
	a = clock();
	Hanoi(n,'A','B','C');
	b = clock();
	step=1;
	for(int i=1;i<=n;i++)
		step*=2;
	printf("移动了%d次，花费了%d豪秒。每秒计算了%lf次。",step-1,(b-a),double(step)/(b-a)*1000);
	getchar();getchar();
	return 0;
}

#endif



#if 0
/*
1 n-1个盘子：src→mid
2 第n个盘子：src→dst
3 n-1个盘子：mid→dst
                  1 A B C       
                  1 A C B  1 A C B      
         2 A C B  1 C A B  1 C A B  1 C A B           1 B C A  
         1 A B C  1 A B C  1 A B C  1 A B C  1 A B C  1 B A C  1 B A C 
3 A B C  2 B A C  2 B A C  2 B A C  2 B A C  2 B A C  2 B A C  1 A B C  1 A B C  1 A B C

*/
#include <iostream> // 用栈代替递归来处理Hanoi（汉诺塔）问题
#include <stack>
using namespace std;
struct Problem{
	int n;
	char src,mid,dst;// src表示第一个柱子（源），dst表示第三个柱子（目的地）
	Problem(int nn,char s,char m,char d):n(nn),src(s),mid(m),dst(d){}
};					 // 一个Problem变量代表一个子问题，将src上的n个盘子以mid为中介，移动到dst
stack<Problem> stk;  // 一个元素代码一个子问题，若有n个盘子，则栈的高度不超过n*3

void main()
{
	int n;
	printf("请输入盘子数量n:\n");
	cin>>n;
	stk.push(Problem(n,'A','B','C'));	// 初始化问题入栈
	while(!stk.empty())
	{
		Problem cp = stk.top();			// cp表示当前子问题current sub-problem
		stk.pop();
		if(cp.n==1)						// 可以直接输出的情形
			cout<<cp.src<<"->"<<cp.dst<<endl;
		else							// 分解子问题，注意子问题的顺序：；2 
		{
			stk.push(Problem(cp.n-1, cp.mid, cp.src, cp.dst)); // 3 n-1个盘子：mid→dst
			stk.push(Problem(1,      cp.src, cp.mid, cp.dst)); // 2 第n个盘子：src→dst
			stk.push(Problem(cp.n-1, cp.src, cp.dst, cp.mid)); // 1 n-1个盘子：src→mid
		}
	}
	system("pause");
}
#endif
/*
4
A->B
A->C
B->C
A->B
C->A
C->B
A->B
A->C
B->C
B->A
C->A
B->C
A->B
A->C
B->C
*/
#if 0
#include <stdio.h>  // 用递归来处理Hanoi（汉诺塔）问题
#include <stdlib.h>
void hanoi(int n, char from, char temp, char to)
{
	if (n==1)
		printf("%c→%c(1)\n",from,to);
	else
	{
		//printf("hanoi(%d,%c,%c,%c)\n",n-1,from,to,temp);
		hanoi(n-1,from,to,temp);		//将x上编号为1到n-1的圆盘移到y，z作辅助塔
		printf("%c→%c\n",from,to);		//将x上编号为n的圆盘移到z
		//printf("hanoi(%d,%c,%c,%c)\n",n-1,temp,from,to);
		hanoi(n-1,temp,from,to);		//将y上编号为1到n-1的圆盘移到z，y作辅助塔
		
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
/*
请输入盘子数量n:
4
A→B(1)
A→C
B→C(1)
A→B
C→A(1)
C→B
A→B(1)
A→C
B→C(1)
B→A
C→A(1)
B→C
A→B(1)
A→C
B→C(1)
*/
//http://www.7k7k.com/swf/37623.htm
/*
 C
A B
你如果掌握了第一个（最小的）盘子的移动规模，这个游戏你玩起来就会得心应手。

当n是奇数时，第一个盘子只能在柱子ACBACB……间循环移动(顺时钟)；

当n是偶数时，第一个盘子只能在柱子ABCABC……间循环移动(逆时钟)；
请输入盘子数量n:
5
A→C(1)
A→B
C→B(1)
A→C
B→A(1)
B→C
A→C(1)
A→B
C→B(1)
C→A
B→A(1)
C→B
A→C(1)
A→B
C→B(1)
A→C
B→A(1)
B→C
A→C(1)
B→A
C→B(1)
C→A
B→A(1)
B→C
A→C(1)
A→B
C→B(1)
A→C
B→A(1)
B→C
A→C(1)
*/

#endif

# if 0
#include <iostream>
using namespace std;

const int MAX = 64;		// 圆盘的个数最多为64

struct st{				// 用来表示每根柱子的信息
	int s[MAX];			// 柱子上的圆盘存储情况
	int top;			// 栈顶，用来最上面的圆盘
	char name;			// 柱子的名字，可以是A，B，C中的一个
	int Top()			// 取栈顶元素
	{
		return s[top];
	}
	int Pop()			// 出栈
	{
		return s[top--];
	}
	void Push(int x)	// 入栈
	{
		s[++top] = x;
	}
} ;

long Pow(int x, int y);				// 计算x^y
void Creat(st ta[], int n);			// 给结构数组设置初值
void Hannuota(st ta[], long max);	// 移动汉诺塔的主要函数

int main(void)
{
	int n;
	cout << "输入圆盘的个数：" << endl;
	cin >> n;					// 输入圆盘的个数
	st ta[3];					// 三根柱子的信息用结构数组存储
	Creat(ta, n);				// 给结构数组设置初值
	long max = Pow(2, n) - 1;	// 移动的次数应等于2^n - 1
	Hannuota(ta, max);			// 移动汉诺塔的主要函数
	system("pause");
	return 0;
}

void Creat(st ta[], int n)
{
	ta[0].name = 'A';
	ta[0].top = n-1;
	
	for (int i=0; i<n; i++)		// 把所有的圆盘按从大到小的顺序放在柱子A上
		ta[0].s[i] = n - i;
	
	ta[1].top = ta[2].top = 0;	// 柱子B，C上开始没有没有圆盘
	for (i=0; i<n; i++)
		ta[1].s[i] = ta[2].s[i] = 0;
	
	if (n%2 == 0)				// 若n为偶数，按顺时针方向依次摆放 A B C
	{
		ta[1].name = 'B';
		ta[2].name = 'C';
	}
	else						// 若n为奇数，按顺时针方向依次摆放 A C B
	{
		ta[1].name = 'C';
		ta[2].name = 'B';
	}
}

long Pow(int x, int y)
{
	long sum = 1;
	for (int i=0; i<y; i++)
		sum *= x;
	return sum;
}

void Hannuota(st ta[], long max)
{
	int k = 0; //累计移动的次数
	int i = 0;
	int ch;
	while (k < max)
	{
		// 按顺时针方向把圆盘1从现在的柱子移动到下一根柱子
		ch = ta[i%3].Pop();
		ta[(i+1)%3].Push(ch);
		cout << ++k << ": " <<"Move disk " << ch << " from " << ta[i%3].name 
			 <<" to " << ta[(i+1)%3].name << endl;
		i++;
		// 把另外两根柱子上可以移动的圆盘移动到新的柱子上
		if (k < max)
		{	// 把非空柱子上的圆盘移动到空柱子上，当两根柱子都为空时，移动较小的圆盘
			if (ta[(i+1)%3].Top() == 0 ||ta[(i-1)%3].Top() > 0  
				&&ta[(i+1)%3].Top() > ta[(i-1)%3].Top())
			{
				ch = ta[(i-1)%3].Pop();
				ta[(i+1)%3].Push(ch);
				cout << ++k << ": " << "Move disk "<< ch << " from " 
					 << ta[(i-1)%3].name<< " to " << ta[(i+1)%3].name << endl;
			}
			else
			{
				ch = ta[(i+1)%3].Pop();
				ta[(i-1)%3].Push(ch);
				cout << ++k << ": " << "Move disk "<< ch << " from " 
					 << ta[(i+1)%3].name<< " to " << ta[(i-1)%3].name << endl;
			}
		}
	}
}
#endif


/*
void han(int n,char a,char b,char c)
{
    if(n==1)
        printf("%d %c→%c *\n",n,a,c);
    else
    {
        han(n-1,a,c,b);
        printf("%d %c→%c\n",n,a,c);
        han(n-1,b,a,c);
    }
}
*/