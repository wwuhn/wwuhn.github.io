/*

*/
#if 1

#include <stdio.h>
#include <malloc.h>
#include "graph.h"
int visited[MAXV];
void DFS(ALGraph *G, int v)
{
    ArcNode *p;
    int w;
    visited[v]=1;
    printf("%d ", v);
    p=G->adjlist[v].firstarc;
    while (p!=NULL)
    {
        w=p->adjvex;
        if (visited[w]==0)
            DFS(G,w);
        p=p->nextarc;
    }
}

int main()
{
    int i;
    ALGraph *G;
    int A[5][5]=
    {
        {0,1,0,1,0},
        {1,0,1,0,0},
        {0,1,0,1,1},
        {1,0,1,0,1},
        {0,0,1,1,0}
    };
    /*
        1
     /     \
    2 - 3 - 0
     \  |
       4
    */
    ArrayToList(A[0], 5, G);

    for(i=0; i<MAXV; i++) visited[i]=0;
    printf(" 由2开始深度遍历:");
    DFS(G, 2);
    printf("\n");

    for(i=0; i<MAXV; i++) visited[i]=0;
    printf(" 由0开始深度遍历:");
    DFS(G, 0);
    printf("\nend\n");
    while(1);
    return 0;
}
/*
 由2开始深度遍历:2 1 0 3 4
 由0开始深度遍历:0 1 2 3 4
end

*/
#else

#include <stdio.h>
#include <malloc.h>
#include "graph.h"

void BFS(ALGraph *G, int v)
{
    ArcNode *p;
    int w,i;
    int queue[MAXV],front=0,rear=0;     //定义循环队列
    int visited[MAXV];                  //定义存放节点的访问标志的数组
    for (i=0; i<G->n; i++) visited[i]=0;//访问标志数组初始化
    printf("%2d",v);                    //输出被访问顶点的编号
    visited[v]=1;                       //置已访问标记
    rear=(rear+1)%MAXV;
    queue[rear]=v;                  //v进队
    while (front!=rear)             //若队列不空时循环
    {
        front=(front+1)%MAXV;
        w=queue[front];             //出队并赋给w
        p=G->adjlist[w].firstarc;   //找w的第一个的邻接点
        while (p!=NULL)
        {
            if (visited[p->adjvex]==0)
            {
                printf("%2d",p->adjvex); //访问之
                visited[p->adjvex]=1;
                rear=(rear+1)%MAXV;     //该顶点进队
                queue[rear]=p->adjvex;
            }
            p=p->nextarc;               //找下一个邻接顶点
        }
    }
    printf("\n");
}


int main()
{
    ALGraph *G;
    int A[5][5]=
    {
        {0,1,0,1,0},
        {1,0,1,0,0},
        {0,1,0,1,1},
        {1,0,1,0,1},
        {0,0,1,1,0}
    };
    ArrayToList(A[0], 5, G);

    printf(" 由2开始广度遍历:");
    BFS(G, 2);

    printf(" 由0开始广度遍历:");
    BFS(G, 0);
    printf("\nend\n");
    while(1);
    return 0;
}


#endif

#if 0


#endif
/*

*/