/*

线性表的折半查找
*/
#if 1

#include <stdio.h>
#define MAXL 100
typedef int KeyType;
typedef char InfoType[10];
typedef struct
{
    KeyType key;                    //KeyType为关键字的数据类型
    InfoType data;                  //其他数据
} NodeType;
typedef NodeType SeqList[MAXL];     //顺序表类型

int BinSearch(SeqList R,int n,KeyType k)
{
    int low=0,high=n-1,mid;
    while (low<=high)
    {
        mid=(low+high)/2;
        if (R[mid].key==k)      //查找成功返回
            return mid+1;
        if (R[mid].key>k)       //继续在R[low..mid-1]中查找
            high=mid-1;
        else
            low=mid+1;          //继续在R[mid+1..high]中查找
    }
    return 0;
}

int main()
{
    int i,n=10;
    int result;
    SeqList R;
    KeyType a[]= {1,3,9,12,32,41,45,62,75,77},x=75;
    for (i=0; i<n; i++)
        R[i].key=a[i];
    result = BinSearch(R,n,x);
    if(result>0)
        printf("序列中第 %d 个是 %d\n",result, x);
    else
        printf("木有找到！\n");
    printf("\n-End-\n");
    while(1);
    return 0;
}

#else

#include <stdio.h>
#define MAXL 100
typedef int KeyType;
typedef char InfoType[10];
typedef struct
{
    KeyType key;                    //KeyType为关键字的数据类型
    InfoType data;                  //其他数据
} NodeType;
typedef NodeType SeqList[MAXL];     //顺序表类型

int BinSearch1(SeqList R,int low,int high,KeyType k)
{
    int mid;
    if (low<=high)          //查找区间存在一个及以上元素
    {
        mid=(low+high)/2;  //求中间位置
        if (R[mid].key==k) //查找成功返回其逻辑序号mid+1
            return mid+1;
        if (R[mid].key>k)  //在R[low..mid-1]中递归查找
            BinSearch1(R,low,mid-1,k);
        else              //在R[mid+1..high]中递归查找
            BinSearch1(R,mid+1,high,k);
    }
    else
        return 0;
}

int main()
{
    int i,n=10;
    int result;
    SeqList R;
    KeyType a[]= {1,3,9,12,32,41,45,62,75,77},x=75;
    for (i=0; i<n; i++)
        R[i].key=a[i];
    result = BinSearch1(R,0,n-1,x);
    if(result>0)
        printf("序列中第 %d 个是 %d\n",result, x);
    else
        printf("木有找到！\n");
    printf("\n-End-\n");
    while(1);
    return 0;
}



#endif

#if 0


#endif
/*
    printf("\nend\n");
    while(1);
*/