// 选择排序之堆排序
// 讲解：https://helijian.blog.csdn.net/article/details/50295637
#include <stdio.h>
#define MaxSize 20
typedef int KeyType;    //定义关键字类型
typedef char InfoType[10];
typedef struct          //记录类型
{
    KeyType key;        //关键字项
    InfoType data;      //其他数据项,类型为InfoType
} RecType;              //排序的记录类型定义

//调整堆
void sift(RecType R[],int low,int high)
{
    int i=low,j=2*i;                        //R[j]是R[i]的左孩子
    RecType temp=R[i];
    while (j<=high)
    {
        if (j<high && R[j].key<R[j+1].key)  //若右孩子较大,把j指向右孩子
            j++;                                //变为2i+1
        if (temp.key<R[j].key)
        {
            R[i]=R[j];                          //将R[j]调整到双亲结点位置上
            i=j;                                //修改i和j值,以便继续向下筛选
            j=2*i;
        }
        else break;                             //筛选结束
    }
    R[i]=temp;                                  //被筛选结点的值放入最终位置
}

//堆排序
void HeapSort(RecType R[],int n)
{
    int i;
    RecType temp;
    for (i=n/2; i>=1; i--) //循环建立初始堆
        sift(R,i,n);
    for (i=n; i>=2; i--) //进行n-1次循环,完成推排序
    {
        temp=R[1];       //将第一个元素同当前区间内R[1]对换
        R[1]=R[i];
        R[i]=temp;
        sift(R,1,i-1);   //筛选R[1]结点,得到i-1个结点的堆
    }
}

int main()
{
    int i,n=10;
    RecType R[MaxSize];
    KeyType a[]= {0,6,8,7,9,0,1,3,2,4,5};//a[0]空闲，不作为关键字
    for (i=1; i<=n; i++)
        R[i].key=a[i];
    printf("排序前:");
    for (i=1; i<=n; i++)
        printf("%d ",R[i].key);
    printf("\n");
    HeapSort(R,n);
    printf("排序后:");
    for (i=1; i<=n; i++)
        printf("%d ",R[i].key);
    printf("\n");
    return 0;
}