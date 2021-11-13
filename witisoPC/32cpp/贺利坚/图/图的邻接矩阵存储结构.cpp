// 图的邻接矩阵存储结构
#include <stdio.h>
#include <malloc.h>
#define MAXV 100 /*最大顶点数设为100*/
#define LIMITLESS 9999

typedef struct
{
    int no;         //顶点编号
    char info[20];  //顶点其他信息,类型视应用而定
} VertexType;       //顶点类型

typedef struct                  //图的定义
{
    int edges[MAXV][MAXV];      //邻接矩阵
    int n, e;                   //顶点数，弧数
    VertexType vexs[MAXV];      //存放顶点信息
} MGraph;

                                //建立一个图的邻接矩阵存储
void CreateMGraph(MGraph *G)
{                               /*建立有向图G 的邻接矩阵存储*/
    int i,j,k,w;
    printf("请输入顶点数和边数(输入格式为:顶点数 边数):");
    scanf("%d %d",&(G->n),&(G->e));                         /*输入顶点数和边数*/
    printf("请输入顶点信息(输入格式为:顶点号 顶点描述):\n");
    for (i=0; i<G->n; i++)
        scanf("%d %s",&(G->vexs[i].no),G->vexs[i].info);    /*输入顶点信息，建立顶点表*/
    for (i=0; i<G->n; i++)                                  /*初始化邻接矩阵*/
        for (j=0; j<G->n; j++)
        {
            if(i==j)
                G->edges[i][j]=0;
            else
                G->edges[i][j]=LIMITLESS;
        }
    printf("请输入每条边对应的两个顶点的序号及权值(输入格式为:i j w):\n");
    for (k=0; k<G->e; k++)
    {
        scanf("%d %d %d",&i,&j,&w);     /*输入e 条边，建立邻接矩阵*/
        G->edges[i][j]=w;               /*若为无权图，直接G->edges[j][i]=1;，无需输入w*/
    }
}/*CreateMGraph*/


void DispMGraph(MGraph *G)   //显示一个用邻接矩阵存储的图
{
    int i,j;
    printf("顶点数: %d，边数: %d\n", G->n, G->e);
    printf("%d 个顶点的信息：:\n", G->n);
    for (i=0; i<G->n; i++)                                          /*输出顶点信息*/
        printf("%5d %5d %s\n", i, G->vexs[i].no, G->vexs[i].info);
    printf("各顶点相连的情况:\n");
    printf("\t");
    for (j=0; j<G->n; j++)
        printf("[%d]\t", j);
    printf("\n");
    for (i=0; i<G->n; i++)
    {
        printf("[%d]\t", i);
        for (j=0; j<G->n; j++)
        {
            if(G->edges[i][j]==LIMITLESS)
                printf("∞\t");
            else
                printf("%d\t", G->edges[i][j]);
        }
        printf("\n");
    }
}/*DispMGraph*/

int main()
{
    MGraph *g;
    g = (MGraph *)malloc(sizeof(MGraph));
    CreateMGraph(g);
    DispMGraph(g);
    printf("end");
    while(1);
    return 0;
}