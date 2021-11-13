// 归并排序算法的改进
/*
采用归并排序、快速排序等高效算法进行排序，当数据元素较少时(如n≤64)，经常直接使用直接
插入排序算法等高复杂度的算法。这样做，会带来一定的好处，例如归并排序减少分配、回收临时
存储区域的频次，快速排序减少递归层次等。
*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#define MinLength 64        //最短分段长度
typedef int KeyType;    //定义关键字类型
typedef char InfoType[10];
typedef struct          //记录类型
{
    KeyType key;        //关键字项
    InfoType data;      //其他数据项,类型为InfoType
} RecType;              //排序的记录类型定义

void GetData(RecType *&R, int n)
{
    srand(time(0));
    R=(RecType*)malloc(sizeof(RecType)*n);
    for(int i=0; i<n; i++)
        R[i].key= rand();
    printf("生成了%d条记录\n", n);
}

//对R[low..high]按递增有序进行直接插入排序
void InsertSort(RecType R[],int low,int high)
{
    int i,j;
    RecType tmp;
    for (i=low; i<=high; i++)
    {
        tmp=R[i];
        j=i-1;            //从右向左在有序区R[low..i-1]中找R[i]的插入位置
        while (j>=low && tmp.key<R[j].key)
        {
            R[j+1]=R[j]; //将关键字大于R[i].key的记录后移
            j--;
        }
        R[j+1]=tmp;      //在j+1处插入R[i]
    }
}

//合并两个有序表
void Merge(RecType R[],int low,int mid,int high)
{
    RecType *R1;
    int i,j,k;
    i=low,j=mid+1,k=0; //k是R1的下标,i、j分别为第1、2段的下标
    R1=(RecType *)malloc((high-low+1)*sizeof(RecType));  //动态分配空间
    while (i<=mid && j<=high)       //在第1段和第2段均未扫描完时循环
        if (R[i].key<=R[j].key)     //将第1段中的记录放入R1中
        {
            R1[k]=R[i];
            i++;
            k++;
        }
        else                            //将第2段中的记录放入R1中
        {
            R1[k]=R[j];
            j++;
            k++;
        }
    while (i<=mid)                      //将第1段余下部分复制到R1
    {
        R1[k]=R[i];
        i++;
        k++;
    }
    while (j<=high)                 //将第2段余下部分复制到R1
    {
        R1[k]=R[j];
        j++;
        k++;
    }
    for (k=0,i=low; i<=high; k++,i++) //将R1复制回R中
        R[i]=R1[k];
}

//一趟合并
void MergePass(RecType R[],int length,int n)    //对整个数序进行一趟归并
{
    int i;
    for (i=0; i+2*length-1<n; i=i+2*length)     //归并length长的两相邻子表
        Merge(R,i,i+length-1,i+2*length-1);
    if (i+length-1<n)                       //余下两个子表,后者长度小于length
        Merge(R,i,i+length-1,n-1);          //归并这两个子表
}

//自底向上的二路归并算法，但太短的分段，用直接插入完成
void MergeSort(RecType R[],int n)
{
    int length, i;
    for(i=0;i<n;i+=MinLength)   //先按最短分段，用插入排序使之分段有序
        InsertSort(R, i, ((i+MinLength-1<n)?(i+MinLength-1):n));
    for (length=MinLength; length<n; length=2*length) //进行归并
    {
        MergePass(R,length,n);
    }
}
int main()
{
    int i,n=10000;
    RecType *R;
    GetData(R, n);
    MergeSort(R,n);
    printf("排序后（前300个）:\n");
    i=0;
    while(i<300)
    {
        printf("%12d ",R[i].key);
        i++;
        if(i%5==0)
            printf("\n");
    }
    printf("\n");
    printf("排序后（后300个）:\n");
    i=0;
    while(i<300)
    {
        printf("%12d ",R[n-300+i].key);
        i++;
        if(i%5==0)
            printf("\n");
    }
    printf("\n");
    free(R);
    return 0;
}