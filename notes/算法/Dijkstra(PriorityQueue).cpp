#include <iostream> //使用优先队列进行广度优先搜索
#include <queue>
#include <windows.h>//min()宏
#include <stack>	//输出最短路径
using namespace std;
//———————————————1 数据结构—————————————————————
const int N = 100;	//城市的个数可修改
const int INF = 1e7;//初始化无穷大为10000000
int map[N][N];		//带权邻接矩阵，表示图的数据结构
int n,m;			//n表示城市的个数，m为城市间路线的条数
int dist[N];		//表示从源点u到城市j的最短路径距离为dist[j]
int p[N];			//表示从源点u到城市j的最短路径的前驱节点为p[j]								//
bool flag[N];		//如果flag[i]等于true，说明顶点i已经加入到集合S;否则顶点i属于集合V-S
					// 集合V表示全部顶点，集合S按贪心策略已搜索的最短路径顶点

struct Node{
	int u,step; //u为顶点，step为源点到顶点u的最短路径
	Node(){};
	Node(int a,int sp){
		u=a;step=sp;
	}
	bool operator<(const Node& a)const{	// 重载 <
		return step>a.step;
	}
};

void Dijkstra(int st){
	for(int i=1; i<=n; i++)		// ①
	{
		dist[i]=INF;						// 初始化所有距离为，无穷大
		if(dist[i]==INF)
			p[i]=-1;			//源点u到该顶点的路径长度为无穷大，说明顶点i与源点u不相邻
		else
			p[i]=st;				//说明顶点i与源点u相邻，设置顶点i的前驱p[i]=u
	}
	priority_queue <Node> Q;				// 优先队列优化
	Q.push(Node(st,0));
	memset(flag,0,sizeof(flag));			// 初始化flag数组为0

	dist[st]=0;
	while(!Q.empty())
	{
		Node it=Q.top();					//优先队列队头元素为最小值
		Q.pop();
		int t=it.u;
		if(flag[t])							//说明已经找到了最短距离，该结点是队列里面的重复元素
			continue;
		flag[t]=1;
		for(int i=1;i<=n;i++)
		{
			if(!flag[i]&&map[t][i]<INF){	// 判断与当前点有关系的点，并且自己不能到自己
				if(dist[i]>dist[t]+map[t][i])
				{							// 求距离当前点的每个点的最短距离,进行松弛操作
					dist[i]=dist[t]+map[t][i];
					Q.push(Node(i,dist[i]));// 把更新后的最短距离压入优先队列，注意：里面的元素有重复
					p[i]=t;
				}
			}
		}
	}
}
void findpath(int u)				// 源点到其它各顶点的最短路径
{
	int x;							// 前驱
	stack<int>s;					// 利用库<stack>创建一个栈s
	for(int i=1;i<=n;i++)
	{
		x=p[i];
		while(x!=-1)
		{
			s.push(x);				//将前驱依次压入栈中
			x=p[x];
		}
		cout<<"源点"<<u<<"到顶点"<<i<<"的最短距离为：";
		if(dist[i] == INF)
			cout << "sorry,无路可达"<<endl;
		else
		{
			cout <<dist[i];
			cout<<"，\t路径为：";
			while(!s.empty())
			{
				cout<<s.top()<<"→";	//依次取栈顶元素
				s.pop();				//出栈
			}
			cout<<i<<endl;
		}
	}
}
void printmatrix(int n)					// 输出图的带权邻接矩阵
{
	cout <<"输出矩阵map："<<endl;
	cout<<"\t";
	for(int k=1;k<=n;++k)
		cout<<"\t"<<k;
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(j==1) 
			{
				cout << "\t" << i;
			}
			if(map[i][j]==INF) 
				cout << "\t" << "∞";
			else 
				cout << "\t" << map[i][j];
			if(j==n) 
			{
				cout<<endl;
			}
		}
	}
}
void initmatrix(int m,int n)
{
	int u,v,w;
	for(int i=1;i<=n;i++)					//初始化图的邻接矩阵
		for(int j=1;j<=n;j++)
		{
			map[i][j]=INF;					//初始化邻接矩阵为无穷大
		}
	while(m--)
	{
		cin >> u >> v >> w;
		map[u][v] =min(map[u][v],w);		//邻接矩阵储存，保留最小的距离
	}
}
int main()
{
	cout << "请输入城市的个数："<<endl;
	cin >> n;
	cout << "请输入城市之间的路线的个数："<<endl;
	cin >>m;
	cout << "请输入城市之间的路线以及距离："<<endl;
	initmatrix(m,n);
	
	int st;
	cout<<"请输入小明所在的位置："<<endl; ;
	cin>>st;
	printmatrix(n);
	Dijkstra(st);
	for(int k=1;k<=n;k++){
		cout <<"小明从"<<st<<" to "<<k;
		if(dist[k] == INF)
			cout << "的最短距离为:sorry,无路可达"<<endl;
		else
			cout << "的最短距离为："<<dist[k]<<endl;
	}
	findpath(st);						//加了int p[N];
	system("pause");
	return 0;
}
/*
5
8
1 2 2
1 3 5
2 3 2
2 4 6
3 4 7
3 5 1
4 3 2
4 5 5
1
*/
/*output:
请输入城市的个数：
5
请输入城市之间的路线的个数：
8
请输入城市之间的路线以及距离：
1 2 2
1 3 5
2 3 2
2 4 6
3 4 7
3 5 1
4 3 2
4 5 5
请输入小明所在的位置：
1
输出矩阵map：
                1       2       3       4       5
        1       ∞      2       5       ∞      ∞
        2       ∞      ∞      2       6       ∞
        3       ∞      ∞      ∞      7       1
        4       ∞      ∞      2       ∞      5
        5       ∞      ∞      ∞      ∞      ∞
小明从1 to 1的最短距离为:0
小明从1 to 2的最短距离为:2
小明从1 to 3的最短距离为:4
小明从1 to 4的最短距离为:8
小明从1 to 5的最短距离为:5
源点1到顶点1的最短距离为：0，   路径为：1
源点1到顶点2的最短距离为：2，   路径为：1→2
源点1到顶点3的最短距离为：4，   路径为：1→2→3
源点1到顶点4的最短距离为：8，   路径为：1→2→4
源点1到顶点5的最短距离为：5，   路径为：1→2→3→5
请按任意键继续. . .
*/