// 每对顶点之间的最短路径Floyd
#include <stdio.h>
#include <malloc.h>
#include "graph.h"
#define MaxSize 100

void Ppath(int path[][MAXV],int i,int j)  //前向递归查找路径上的顶点
{
    int k;
    k=path[i][j];
    if (k==-1) return;  //找到了起点则返回
    Ppath(path,i,k);    //找顶点i的前一个顶点k
    printf("%d,",k);
    Ppath(path,k,j);    //找顶点k的前一个顶点j
}
void Dispath(int A[][MAXV],int path[][MAXV],int n)
{
    int i,j;
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
        {
            if (A[i][j]==INF)
            {
                if (i!=j)
                    printf("从%d到%d没有路径\n",i,j);
            }
            else
            {
                printf("  从%d到%d=>路径长度:%d 路径:",i,j,A[i][j]);
                printf("%d,",i);    //输出路径上的起点
                Ppath(path,i,j);    //输出路径上的中间点
                printf("%d\n",j);   //输出路径上的终点
            }
        }
}
void Floyd(MGraph g)
{
    int A[MAXV][MAXV],path[MAXV][MAXV];
    int i,j,k;
    for (i=0; i<g.n; i++)
        for (j=0; j<g.n; j++)
        {
            A[i][j]=g.edges[i][j];
            path[i][j]=-1;
        }
    for (k=0; k<g.n; k++)
    {
        for (i=0; i<g.n; i++)
            for (j=0; j<g.n; j++)
                if (A[i][j]>A[i][k]+A[k][j])
                {
                    A[i][j]=A[i][k]+A[k][j];
                    path[i][j]=k;
                }
    }
    Dispath(A,path,g.n);   //输出最短路径
}
int main()
{
    MGraph g;
    int A[4][4]=
    {
        {0,  5,INF,7},
        {INF,0,  4,2},
        {3,  3,  0,2},
        {INF,INF,1,0}
    };
    ArrayToMat(A[0], 4, g);
    Floyd(g);
    return 0;
}
// https://helijian.blog.csdn.net/article/details/49847007