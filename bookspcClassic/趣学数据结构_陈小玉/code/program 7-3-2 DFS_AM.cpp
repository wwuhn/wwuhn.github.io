#include<iostream>
using namespace std;

#define MaxVnum 100    // 顶点数最大值
bool visited[MaxVnum]; // 访问标志数组，其初值为"false"
typedef char VexType;  // 顶点的数据类型，根据需要定义
typedef int EdgeType;  // 边上权值的数据类型，若不带权值的图，则为0或1
typedef struct{
	VexType Vex[MaxVnum];
	EdgeType Edge[MaxVnum][MaxVnum];
	int vexnum,edgenum; // 顶点数，边数
}AMGragh;

int locatevex(AMGragh G,VexType x)
{
    for(int i=0;i<G.vexnum;i++)// 查找顶点信息的下标
		if(x==G.Vex[i])
			return i;
    return -1;                 // 没找到
}

void CreateAMGraph(AMGragh &G) // 创建无向图的邻接矩阵
{
    int i,j;
    VexType u,v;
    cout<<"请输入顶点数："<<endl;
    cin>>G.vexnum;
    cout<<"请输入边数:"<<endl;
    cin>>G.edgenum;
    cout<<"请输入顶点信息:"<<endl;
    for(int i=0;i<G.vexnum;i++)// 输入顶点信息，存入顶点信息数组
        cin>>G.Vex[i];
    for(int i=0;i<G.vexnum;i++)// 初始化邻接矩阵所有值为0，如果是网，则初始化邻接矩阵为无穷大
		for(int j=0;j<G.vexnum;j++)
			G.Edge[i][j]=0;
    cout<<"请输入每条边依附的两个顶点："<<endl;
    while(G.edgenum--)
    {
       cin>>u>>v;
       i=locatevex(G,u);// 查找顶点u的存储下标
       j=locatevex(G,v);// 查找顶点v的存储下标
       if(i!=-1&&j!=-1)
         G.Edge[i][j]=G.Edge[j][i]=1; // 邻接矩阵储置1，若有向图G.Edge[i][j]=1
       else
       {
           cout<<"输入顶点信息错！请重新输入！"<<endl;
           G.edgenum++; // 本次输入不算
       }
    }
}

void print(AMGragh G)   // 输出邻接矩阵
{
    cout<<"图的邻接矩阵为："<<endl;
    for(int i=0;i<G.vexnum;i++)
    {
        for(int j=0;j<G.vexnum;j++)
			cout<<G.Edge[i][j]<<"\t";
        cout<<endl;
    }
}

void DFS_AM(AMGragh G,int v)         // 基于邻接矩阵的深度优先遍历
{
    int w;
    cout<<G.Vex[v]<<"\t";
    visited[v]=true;
    for(w=0;w<G.vexnum;w++)          // 依次检查v的所有邻接点
		if(G.Edge[v][w]&&!visited[w])// v、w邻接而且w未被访问
			DFS_AM(G,w);             // 从w顶点开始递归深度优先遍历
}

int main()
{
    int v;
    VexType c;
    AMGragh G;
    CreateAMGraph(G);
    print(G);
    cout<<"请输入遍历连通图的起始点：";
	cin>>c;
	v=locatevex(G,c);//查找顶点u的存储下标
    if(v!=-1)
    {
        cout<<"深度优先搜索遍历连通图结果："<<endl;
        DFS_AM(G,v);
    }
    else
        cout<<"输入顶点信息错！请重新输入！"<<endl;
    return 0;
}
