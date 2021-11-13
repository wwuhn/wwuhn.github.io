#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#define MAXV 100                //最大顶点个数
#define INF 32767               //INF表示∞
typedef int InfoType;

//以下定义邻接矩阵类型
typedef struct
{
    int no;                     //顶点编号
    InfoType info;              //顶点其他信息，在此存放带权图权值
} VertexType;                   //顶点类型

typedef struct                  //图的定义
{
    int edges[MAXV][MAXV];      //邻接矩阵
    int n,e;                    //顶点数，弧数
    VertexType vexs[MAXV];      //存放顶点信息
} MGraph;                       //图的邻接矩阵类型Matrix

//以下定义邻接表类型
typedef struct ANode            //弧的结点结构类型
{
    int adjvex;                 //该弧的终点位置
    struct ANode *nextarc;      //指向下一条弧的指针
    InfoType info;              //该弧的相关信息,这里用于存放权值
} ArcNode;

typedef int Vertex;

typedef struct Vnode            //邻接表头结点的类型
{
    Vertex data;                //顶点信息
    int count;                  //存放顶点入度,只在拓扑排序中用
    ArcNode *firstarc;          //指向第一条弧
} VNode;

typedef VNode AdjList[MAXV];    //AdjList是邻接表类型adjacent list

typedef struct
{
    AdjList adjlist;            //邻接表
    int n,e;                    //图中顶点数n和边数e
} ALGraph;                      //图的邻接表类型adjacent list

//功能：由一个反映图中顶点邻接关系的二维数组，构造出用邻接矩阵存储的图
//参数：Arr - 数组名，由于形式参数为二维数组时必须给出每行的元素个数，
     // 在此将参数Arr声明为一维数组名（指向int的指针）
//      n - 矩阵的阶数
//      g - 要构造出来的邻接矩阵数据结构
void ArrayToMat(int *Arr, int n, MGraph &g);    //用普通数组构造图的邻接矩阵Matrix
void ArrayToList(int *Arr, int n, ALGraph *&);  //用普通数组构造图的邻接表adjacent list
void MatToList(MGraph g,ALGraph *&G);   //将邻接矩阵g转换成邻接表G
void ListToMat(ALGraph *G,MGraph &g);   //将邻接表G转换成邻接矩阵g
void DispMat(MGraph g);     //输出邻接矩阵g
void DispAdj(ALGraph *G);   //输出邻接表G

#endif // GRAPH_H_INCLUDED