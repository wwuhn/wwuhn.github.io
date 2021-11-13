// 线性表的顺序查找

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

int SeqSearch(SeqList R,int n,KeyType k)
{
    int i=0;
    while (i<n && R[i].key!=k)      //从表头往后找
        i++;
    if (i>=n)
        return 0;
    else
        return i+1;
}
int main()
{
    int i,n=10;
    int result;
    SeqList R;
    KeyType a[]= {2,3,1,8,5,4,9,0,7,6},x=9;
    for (i=0; i<n; i++)
        R[i].key=a[i];
    result = SeqSearch(R,n,x);
    if(result>0)
        printf("序列中第 %d 个是 %d\n",result, x);
    else
        printf("木有找到！\n");
    return 0;
}

