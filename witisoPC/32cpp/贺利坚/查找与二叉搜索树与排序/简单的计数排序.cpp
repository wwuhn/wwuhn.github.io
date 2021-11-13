// 简单的计数排序

#include <stdio.h>
#include <malloc.h>
#define MaxSize 20
#define MaxNum 100
typedef int KeyType;    //定义关键字类型
typedef char InfoType[10];
typedef struct          //记录类型
{
    KeyType key;        //关键字项
    InfoType data;      //其他数据项,类型为InfoType
} RecType;          //排序的记录类型定义

void CountSort(RecType R[],int n)
{
    int i, j, k;
    int C[MaxNum+1] = {0};  /*用于计数的C数组的所有元素初值为0*/
    for(i=0; i<n; i++)
        C[R[i].key]++;    /*例如，R[i].key为6时，C[6]++，C[R[i].key]是R[i].key出现的次数*/
    k=0;
    for(j=0; j<=MaxNum; j++)    /*考察每一个j*/
        for(i=1; i<=C[j]; i++)   /*j=R[j].key出现过C[j]个，此即是排序的结果*/
            R[k++].key=j;
}

int main()
{
    int i,n=10;
    RecType R[MaxSize];
    KeyType a[]= {6,1,12,6,18,1,18,7,0,6};
    for (i=0; i<n; i++)
        R[i].key=a[i];
    printf("排序前:");
    for (i=0; i<n; i++)
        printf("%d ",R[i].key);
    printf("\n");
    CountSort(R,n);
    printf("排序后:");
    for (i=0; i<n; i++)
        printf("%d ",R[i].key);
    printf("\n");
    return 0;
}