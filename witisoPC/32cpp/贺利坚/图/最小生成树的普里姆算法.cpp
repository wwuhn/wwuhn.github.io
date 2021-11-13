// 最小生成树的普里姆算法

#include <stdio.h>
#include <malloc.h>
#include "graph.h"

void Prim(MGraph g,int v)
{
    int lowcost[MAXV];              //顶点i是否在U中
    int min;
    int closest[MAXV],i,j,k;
    for (i=0; i<g.n; i++)           //给lowcost[]和closest[]置初值
    {
        lowcost[i]=g.edges[v][i];
        closest[i]=v;
    }
    for (i=1; i<g.n; i++)           //找出n-1个顶点
    {
        min=INF;
        for (j=0; j<g.n; j++)       //在(V-U)中找出离U最近的顶点k
            if (lowcost[j]!=0 && lowcost[j]<min)
            {
                min=lowcost[j];
                k=j;                //k记录最近顶点的编号
            }
        printf(" 边(%d,%d)权为:%d\n",closest[k],k,min);
        lowcost[k]=0;               //标记k已经加入U
        for (j=0; j<g.n; j++)       //修改数组lowcost和closest
            if (g.edges[k][j]!=0 && g.edges[k][j]<lowcost[j])
            {
                lowcost[j]=g.edges[k][j];
                closest[j]=k;
            }
    }
}

int main()
{
    MGraph g;
    int A[6][6]=
    {
        {0,6,1,5,INF,INF},
        {6,0,5,INF,3,INF},
        {1,5,0,5,6,4},
        {5,INF,5,0,INF,2},
        {INF,3,6,INF,0,6},
        {INF,INF,4,2,6,0}
    };
    ArrayToMat(A[0], 6, g);
    printf("最小生成树构成:\n");
    Prim(g,0);
    while(1);
    return 0;
}
//https://helijian.blog.csdn.net/article/details/49699939