#include <stdio.h>
#include <malloc.h>
#include "graph.h"

int main()
{
    MGraph g1,g2;
    ALGraph *G1,*G2;
    int A[6][6]=
    {
        {0,5,0,7,0,0},
        {0,0,4,0,0,0},
        {8,0,0,0,0,9},
        {0,0,5,0,0,6},
        {0,0,0,5,0,0},
        {3,0,0,0,1,0}
    };

    ArrayToMat(A[0], 6, g1);  //取二维数组的起始地址作实参，用A[0]，因其实质为一维数组地址，与形参匹配
    printf(" 有向图g1的邻接矩阵:\n");
    DispMat(g1);

    ArrayToList(A[0], 6, G1);
    printf(" 有向图G1的邻接表:\n");
    DispAdj(G1);

    MatToList(g1,G2);
    printf(" 图g1的邻接矩阵转换成邻接表G2:\n");
    DispAdj(G2);

    ListToMat(G1,g2);
    printf(" 图G1的邻接表转换成邻接邻阵g2:\n");
    DispMat(g2);
    printf("\nend\n");
    while(1);
    return 0;
}