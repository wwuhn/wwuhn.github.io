#include <iostream>
#include <vector>
using namespace std;

int Fib ( int n ) 
{
    if(n <= 1)
	    return n; 
	int twoback = 0;
    int oneback = 1; 
	int Current;
    for(int i = 2; i <= n; i++)    
    {
        Current = twoback + oneback; 
	    twoback = oneback;
        oneback = Current;
    }
    return Current;
}

int fib_dp(int n);
vector<int> vec;
vector<int> ::iterator iter;
/*每一个数字代表一对兔子，1、2表示一对1、2个月大的兔子，3表示超过3个月大的兔子
1
|
2
|
3→              1
|                 \
3→      1，       2
|         \         \
3→  1，   2，       3→      1
|     \     \         \        \
3→ 1，2，   3→   1， 3→   1，2
|    \  \     \     \   \     \  \
3→1，2，3→1，3→1，2， 3→1，2，3→1
*/
/*
动态规划是把原问题分解为若干为若干子问题，然后自底向上，先求解最小的子问题，把结果存储在表格中，
再求解大的子问题时，直接从表格中查询小的子问题的解，避免重复计算。
分治算法是自顶向下求解子问题，合并子问题的解；
能采用动态规划求解的问题的一般要具有3个性质：
（1）最优子结构：如果问题的最优解所包含的子问题的解也是最优的，就称该问题具有最优子结构，
即满足最优化原理。
（2）无后效性：即某阶段状态一旦确定，就不受这个状态以后决策的影响。也就是说，
某状态以后的过程不会影响以前的状态，只与当前状态有关。
（3）有重叠子问题：即子问题之间是不独立的，一个子问题在下一阶段决策中可能被多次使用到。
（该性质并不是动态规划适用的必要条件，但是如果没有这条性质，动态规划算法同其他算法相比就
不具备优势）
 */
int fib_dp_vector(int n)//斐波那契数列的动态规划用vector来实现
{
	vec.push_back(1);
	vec.push_back(1);
	
	if(n>2)
		for(int i=2; i<n; ++i)
			vec.push_back(vec[i-1]+vec[i-2]);
	return vec[n-2];
}
//output: 1 1 2 3 5 8 13 21 34 55 89 144

int fib_dp_arr(int n)//斐波那契数列的动态规划用数组实现
{
	if(n<1)
		return -1;
	int* arr = new int[n+1];
	arr[1]=1;
	arr[2]=1;
	for(int i=3;i<=n+1;i++)
		arr[i]=arr[i-1]+arr[i-2];
	return arr[n];
	delete [] arr;
}


int fib_recursive(int n)//斐波那契数列的递归实现
{
	if(n==1 ||n==2)
		return 1;
	else 
		return (fib_recursive(n-1)+fib_recursive(n-2));
} 


int fib_iterative(int n) //斐波那契数列的迭代实现
{
	int fn, fn_1=1, fn_2=1;
	if(n==1 ||n==2)
		fn_1 = 1, fn_2 = 1;
	for (int i=3; i<=n; ++i)
	{
		fn = fn_1 + fn_2;
		fn_1 = fn_2; 
		fn_2 = fn;
	}
	return fn;
}
/*迭代
fn_1 fn_2 fn
     fn_1 fn_2 fn
r=b
loops
r = a%b
a b r
  a b r
*/

int additiveSequence(int n,int a, int b)
{
	if(n==0) return a;
	if(n==1) return b;
	return additiveSequence(n-1,b,a+b);
}

int fib(int n) // wrapper functions, as if provide default parameter
{
    return additiveSequence(n,0,1);
}

int main()
{
	int n;
	cout<<"三个月的兔子开始繁殖，计算n月第繁殖数量，请输入n：";
	cin>>n;
	fib_dp_vector(n);
	for(iter=vec.begin();iter!=vec.end();iter++)
		cout<<*iter<<" ";
	cout<<endl;
	cout<<fib_dp_arr(n)<<endl;
	//cout<<fib_recursive(n)<<endl;
	//cout<<fib_iterative(n)<<endl;
	cout<<additiveSequence(n,0,1)<<endl;
    cout<<fib(n)<<endl;
	cin.get();cin.get();
	return 0;
}