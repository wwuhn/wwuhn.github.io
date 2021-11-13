// 操作用邻接表存储的图

#include <stdio.h>
#include <malloc.h>
#include "graph.h"

//返回图G中编号为v的顶点的出度
int OutDegree(ALGraph *G,int v)
{
    ArcNode *p;
    int n=0;
    p=G->adjlist[v].firstarc;
    while (p!=NULL)
    {
        n++;
        p=p->nextarc;
    }
    return n;
}

//输出图G中每个顶点的出度
void OutDs(ALGraph *G)
{
    int i;
    for (i=0; i<G->n; i++)
        printf("  顶点%d:%d\n",i,OutDegree(G,i));
}

//输出图G中出度最大的一个顶点
void OutMaxDs(ALGraph *G)
{
    int maxv=0,maxds=0,i,x;
    for (i=0; i<G->n; i++)
    {
        x=OutDegree(G,i);
        if (x>maxds)
        {
            maxds=x;
            maxv=i;
        }
    }
    printf("顶点%d，出度=%d\n",maxv,maxds);
}
//输出图G中出度为0的顶点数
void ZeroDs(ALGraph *G)
{
    int i,x;
    for (i=0; i<G->n; i++)
    {
        x=OutDegree(G,i);
        if (x==0)
            printf("%2d",i);
    }
    printf("\n");
}

//返回图G中是否存在边<i,j>
bool Arc(ALGraph *G, int i,int j)
{
    ArcNode *p;
    bool found = false;
    p=G->adjlist[i].firstarc;
    while (p!=NULL)
    {
        if(p->adjvex==j)
        {
            found = true;
            break;
        }
        p=p->nextarc;
    }
    return found;
}

int main()
{
    ALGraph *G;
    int A[7][7]=
    {
        {0,1,1,1,0,0,0},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,1,0},
        {0,0,0,0,0,0,1},
        {0,0,0,0,0,0,0},
        {0,0,0,1,1,0,1},
        {0,1,0,0,0,0,0}
    };
    ArrayToList(A[0], 7, G);
    printf("(1)各顶点出度:\n");
    OutDs(G);
    printf("(2)最大出度的顶点信息:");
    OutMaxDs(G);
    printf("(3)出度为0的顶点:");
    ZeroDs(G);
    printf("(4)边<2,6>存在吗？");
    if(Arc(G,2,6))
        printf("是\n");
    else
        printf("否\n");
    printf("\n");
    return 0;
}

// https://helijian.blog.csdn.net/article/details/49717317