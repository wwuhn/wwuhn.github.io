#include <iostream>
#include <algorithm> //sort()
using namespace std;
// Kruskal算法：将所有边按权值从小到大排序后，从最小权值的边开始做避圈判断
const int N = 100;
												// ① 数据结构
int nodeset[N];				//集合号（顶点序号）数组，用于避圈
int n, m;
struct Edge {				//边的存储结构(两个顶点和一个权值)
	int u;
	int v;
	int w;
}e[N*N];

												// ② 初始化
void Init(int n)
{
	for(int i = 1; i <= n; i++)
		nodeset[i] = i;		//每个结点赋值一个集合号（顶点序号）
}
												// ③ 定义优先级，按边值进行升序排序
bool comp(Edge x, Edge y)
{
	return x.w < y.w;		
}
												// ④ 合并集合
int Merge(int a, int b)
{
	int p = nodeset[a];	//p为a结点的集合号（顶点序号）
	int q = nodeset[b];	//q为b结点的集合号（顶点序号）
	if(p==q) 
		return 0;			//集合号相同，什么也不做，返回
	for(int i=1;i<=n;i++)	//检查所有结点，把集合号是q的全部改为p
	{
		if(nodeset[i]==q)
			nodeset[i] = p;	//a的集合号赋值给b集合号
	}
	return 1;
}

int Kruskal(int n)
{
	int ans = 0;			//点连通成树后边值求和后的最小值
	for(int i=0;i<m;i++)
		if(Merge(e[i].u, e[i].v)) //如果执行了合并
		{
			ans += e[i].w;
			n--;
			cout<<e[i].u<<" - "<<e[i].v<<"："<<e[i].w<<endl;
			if(n==1)
				return ans;
		}
		return 0;
}

int main()
{
	cout <<"输入结点数n和边数m："<<endl;
	cin >> n >> m;
	Init(n);
	cout <<"输入结点序号u、v和边值w："<<endl;
	for(int i=0;i<m;i++)
		cin >> e[i].u>> e[i].v >>e[i].w;
	sort(e, e+m, comp);		//三个参数：待排序数组的首地址、尾地址，排序方式

	cout <<"输出排序后的结点序号u、v和边值w："<<endl;
	for(int j=0;j<m;j++)
		cout<<e[j].u<<" - "<<e[j].v<<"："<<e[j].w<<endl;
	cout<<"选中的各边的两个结点序号和其边值："<<endl;
	int ans = Kruskal(n);
	cout << "点连通成树后边值求和后的最小值：" << ans << endl;
	system("pause");
	return 0;
}
/*
7 12
1 2 23
1 6 28
1 7 36
2 3 20
2 7 1
3 4 15
3 7 4
4 5 3
4 7 9
5 6 17
5 7 16
6 7 25
输出

  输出排序后的结点序号u、v和边值w：
  2 - 7：1
  4 - 5：3
  3 - 7：4
  4 - 7：9
  3 - 4：15
  5 - 7：16
  5 - 6：17
  2 - 3：20
  1 - 2：23
  6 - 7：25
  1 - 6：28
  1 - 7：36
  选中的各边的两个结点序号和其边值：
  2 - 7：1
  4 - 5：3
  3 - 7：4
  4 - 7：9
  5 - 6：17
  1 - 2：23
  点连通成树后边值求和后的最小值：57
*/

int Find(int x)				//找祖宗
{
	if(x != nodeset[x])
		nodeset[x] = Find(nodeset[x]);
	//把当前结点到其祖宗路径上的所有结点的集合号改为祖宗集合号
	return nodeset[x];		//返回其祖宗的集合号
}
int Merge2(int a, int b)		//两结点合并集合号
{
	int p = Find(a);		//找a的集合号
	int q = Find(b);		//找b的集合号
	if(p==q) return 0;
	if(p > q)
		nodeset[p] = q;		//小的集合号赋值给大的集合号
	else
		nodeset[q] = p;
	return 1;
}