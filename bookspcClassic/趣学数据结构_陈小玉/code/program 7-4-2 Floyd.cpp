#include<iostream>
#include<cstring>
#include<windows.h>
using namespace std;

#define MaxVnum 100  //顶点数最大值
const int INF=1e7; // 无穷大10000000

typedef string VexType;  //顶点的数据类型，根据需要定义
typedef int EdgeType;  //边上权值的数据类型，若不带权值的图，则为0或1
typedef struct{
	VexType Vex[MaxVnum];
	EdgeType Edge[MaxVnum][MaxVnum];
	int vexnum,edgenum; //顶点数，边数
}AMGragh;

int dist[MaxVnum][MaxVnum],p[MaxVnum][MaxVnum];

int locatevex(AMGragh G,VexType x)
{
    for(int i=0;i<G.vexnum;i++)//查找顶点信息的下标
       if(x==G.Vex[i])
        return i;
    return -1;//没找到
}

void CreateAMGraph(AMGragh &G)//创建无向图的邻接矩阵
{
    int i,j,w;
    VexType u,v;
    cout<<"请输入顶点数："<<endl;
    cin>>G.vexnum;
    cout<<"请输入边数:"<<endl;
    cin>>G.edgenum;
    cout<<"请输入顶点信息:"<<endl;
    for(int i=0;i<G.vexnum;i++)//输入顶点信息，存入顶点信息数组
        cin>>G.Vex[i];
    for(int i=0;i<G.vexnum;i++)//初始化邻接矩阵所有值为0，若是网，则初始化为无穷大
		for(int j=0;j<G.vexnum;j++)
	        if(i!=j)
	            G.Edge[i][j]=INF;
	        else
	            G.Edge[i][j]=0; //注意i==j时，设置为0
    cout<<"请输入每条边依附的两个顶点及权值："<<endl;
    while(G.edgenum--)
    {
       cin>>u>>v>>w;
       i=locatevex(G,u);//查找顶点u的存储下标
       j=locatevex(G,v);//查找顶点v的存储下标
       if(i!=-1&&j!=-1)
			G.Edge[i][j]=w; //有向图邻接矩阵存储权值
    }
}

void Floyd(AMGragh G) //用Floyd算法求有向网G中各对顶点i和j之间的最短路径
{
   	int i,j,k;
    for(i=0;i<G.vexnum;i++)          		//各对结点之间初始已知路径及距离
      for(j=0;j<G.vexnum;j++)
      {
          dist[i][j]=G.Edge[i][j];
          if(dist[i][j]<INF && i!=j)
			p[i][j]=i;  	//如果i和j之间有弧，则将j的前驱置为i
          else p[i][j]=-1;  //如果i和j之间无弧，则将j的前驱置为-1
      }
	for(k=0;k<G.vexnum; k++)
		for(i=0;i<G.vexnum; i++)
			for(j=0;j<G.vexnum; j++)
				if(dist[i][k]+dist[k][j]<dist[i][j])//从i经k到j的一条路径更短
                {
					dist[i][j]=dist[i][k]+dist[k][j]; //更新dist[i][j]
					p[i][j]=p[k][j];       //更改j的前驱为k
				}
}

void print(AMGragh G)
{
    int i,j;
    for(i=0;i<G.vexnum;i++)//输出最短距离数组
    {
        for(j=0;j<G.vexnum;j++)
            cout<<dist[i][j]<<"\t";
        cout<<endl;
    }
    cout<<endl;
    for(i=0;i<G.vexnum;i++)//输出前驱数组
    {
        for(j=0;j<G.vexnum;j++)
            cout<<p[i][j]<<"\t";
        cout<<endl;
    }
}

void DisplayPath(AMGragh G,int s,int t )//显示最短路径
{
	if(p[s][t]!=-1)
    {
		DisplayPath(G,s,p[s][t]);
		cout<<G.Vex[p[s][t]]<<"-->";
	}
}

int main()
{
    VexType start,destination;
    int u,v;
    system("color 0d");
    AMGragh G;
    CreateAMGraph(G);
    Floyd(G);
    print(G);
	cout<<"请依次输入路径的起点与终点的名称：";
	cin>>start>>destination;
	u=locatevex(G,start);
	v=locatevex(G,destination);
	DisplayPath(G,u,v);
	cout<<G.Vex[v]<<endl;
	cout<<"最短路径的长度为："<<dist[u][v]<<endl;
	cout<<endl;
    return 0;
}
