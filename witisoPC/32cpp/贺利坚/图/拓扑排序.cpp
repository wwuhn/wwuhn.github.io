#include <stdio.h>
#include <malloc.h>
#include "graph.h"

void TopSort(ALGraph *G)
{
    int i,j;
    int St[MAXV],top=-1;            //栈St的指针为top
    ArcNode *p;
    for (i=0; i<G->n; i++)          //入度置初值0
        G->adjlist[i].count=0;
    for (i=0; i<G->n; i++)          //求所有顶点的入度
    {
        p=G->adjlist[i].firstarc;
        while (p!=NULL)
        {
            G->adjlist[p->adjvex].count++;
            p=p->nextarc;
        }
    }
    for (i=0; i<G->n; i++)
        if (G->adjlist[i].count==0)  //入度为0的顶点进栈
        {
            top++;
            St[top]=i;
        }
    while (top>-1)                  //栈不为空时循环
    {
        i=St[top];
        top--;              //出栈
        printf("%d ",i);            //输出顶点
        p=G->adjlist[i].firstarc;   //找第一个相邻顶点
        while (p!=NULL)
        {
            j=p->adjvex;
            G->adjlist[j].count--;
            if (G->adjlist[j].count==0)//入度为0的相邻顶点进栈
            {
                top++;
                St[top]=j;
            }
            p=p->nextarc;       //找下一个相邻顶点
        }
    }
}

int main()
{
    ALGraph *G;
    int A[7][7]=
    {
        {0,0,1,0,0,0,0},
        {0,0,0,1,1,0,1},
        {0,0,0,1,0,0,0},
        {0,0,0,0,1,1,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0}
    };
    ArrayToList(A[0], 7, G);
    DispAdj(G);
    printf("\n");
    printf("拓扑序列:");
    TopSort(G);
    printf("\n");
    return 0;
}

// https://helijian.blog.csdn.net/article/details/49847159