#include <stdio.h>
#include <malloc.h>
#include "graph.h"

//功能：由一个反映图中顶点邻接关系的二维数组，构造出用邻接矩阵存储的图
//参数：Arr - 数组名，由于形式参数为二维数组时必须给出每行的元素个数，在此将参数Arr声明为一维数组名（指向int的指针）
//      n - 矩阵的阶数
//      g - 要构造出来的邻接矩阵数据结构
void ArrayToMat(int *Arr, int n, MGraph &g) //用普通数组构造图的邻接矩阵Matrix
{
    int i,j,count=0;  //count用于统计边数，即矩阵中非0元素个数
    g.n=n;
    for (i=0; i<g.n; i++)
        for (j=0; j<g.n; j++)
        {
            g.edges[i][j]=Arr[i*n+j]; //将Arr看作n×n的二维数组，Arr[i*n+j]即是Arr[i][j]，计算存储位置的功夫在此应用
            if(g.edges[i][j]!=0 && g.edges[i][j]!=INF)
                count++;
        }
    g.e=count;
}

void ArrayToList(int *Arr, int n, ALGraph *&G)//用普通数组构造图的邻接表adjacent list
{
    int i,j,count=0;                    //count用于统计边数，即矩阵中非0元素个数
    ArcNode *p;
    G=(ALGraph *)malloc(sizeof(ALGraph));
    G->n=n;
    for (i=0; i<n; i++)                 //给邻接表中所有头节点的指针域置初值
        G->adjlist[i].firstarc=NULL;
    for (i=0; i<n; i++)                 //检查邻接矩阵中每个元素
        for (j=n-1; j>=0; j--)
            if (Arr[i*n+j]!=0)          //存在一条边，将Arr看作n×n的二维数组，Arr[i*n+j]即是Arr[i][j]
            {
                p=(ArcNode *)malloc(sizeof(ArcNode));   //创建一个节点*p
                p->adjvex=j;
                p->info=Arr[i*n+j];
                p->nextarc=G->adjlist[i].firstarc;      //采用头插法插入*p
                G->adjlist[i].firstarc=p;
            }
    G->e=count;
}

void MatToList(MGraph g, ALGraph *&G)       //将邻接矩阵g转换成邻接表G
{
    int i,j;
    ArcNode *p;
    G=(ALGraph *)malloc(sizeof(ALGraph));
    for (i=0; i<g.n; i++)                   //给邻接表中所有头节点的指针域置初值
        G->adjlist[i].firstarc=NULL;
    for (i=0; i<g.n; i++)                   //检查邻接矩阵中每个元素
        for (j=g.n-1; j>=0; j--)
            if (g.edges[i][j]!=0)           //存在一条边
            {
                p=(ArcNode *)malloc(sizeof(ArcNode));   //创建一个节点*p
                p->adjvex=j;
                p->info=g.edges[i][j];
                p->nextarc=G->adjlist[i].firstarc;      //采用头插法插入*p
                G->adjlist[i].firstarc=p;
            }
    G->n=g.n;
    G->e=g.e;
}

void ListToMat(ALGraph *G,MGraph &g) //将邻接表G转换成邻接矩阵g
{
    int i,j;
    ArcNode *p;
    g.n=G->n;               //根据一楼同学“举报”改的。g.n未赋值，下面的初始化不起作用
    g.e=G->e;
    for (i=0; i<g.n; i++)   //先初始化邻接矩阵
        for (j=0; j<g.n; j++)
            g.edges[i][j]=0;
    for (i=0; i<G->n; i++)  //根据邻接表，为邻接矩阵赋值
    {
        p=G->adjlist[i].firstarc;
        while (p!=NULL)
        {
            g.edges[i][p->adjvex]=p->info;
            p=p->nextarc;
        }
    }
}

void DispMat(MGraph g)//输出邻接矩阵g
{
    int i,j;
    for (i=0; i<g.n; i++)
    {
        for (j=0; j<g.n; j++)
            if (g.edges[i][j]==INF)
                printf("%3s","∞");
            else
                printf("%3d",g.edges[i][j]);
        printf("\n");
    }
}

void DispAdj(ALGraph *G) //输出邻接表G
{
    int i;
    ArcNode *p;
    for (i=0; i<G->n; i++)
    {
        p=G->adjlist[i].firstarc;
        printf("%3d: ",i);
        while (p!=NULL)
        {
            printf("-->%d/%d ",p->adjvex,p->info);
            p=p->nextarc;
        }
        printf("\n");
    }
}