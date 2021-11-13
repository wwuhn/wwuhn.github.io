#include <stdio.h>
#include <malloc.h>

#define MaxSize 50    //Maxsize将用于后面定义存储空间的大小
typedef int ElemType;  //ElemType在不同场合可以根据问题的需要确定，在此取简单的int
typedef struct
{
    ElemType data[MaxSize];  //利用了前面MaxSize和ElemType的定义
    int length;
} SqList;

//自定义函数声明部分
void CreateList(SqList *&L, ElemType a[], int n);//用数组创建线性表
void DispList(SqList *L);//输出线性表DispList(L)
bool ListEmpty(SqList *L);//判定是否为空表ListEmpty(L)
int ListLength(SqList *L); //求线性表的长度ListLength(L)
bool GetElem(SqList *L,int i,ElemType &e); //求某个数据元素值GetElem(L,i,e)
int LocateElem(SqList *L, ElemType e); //按元素值查找LocateElem(L,e)

//实现测试函数
int main()
{
    SqList *sq;
    ElemType x[6]= {5,8,7,2,4,9};
    ElemType a;
    int loc;
    CreateList(sq, x, 6);
    DispList(sq);

    printf("表长度：%d\n", ListLength(sq));  //测试求长度

    if(GetElem(sq, 3, a))  //测试在范围内的情形
        printf("找到了第3个元素值为：%d\n", a);
    else
        printf("第3个元素超出范围！\n");

    if(GetElem(sq, 15, a))  //测试不在范围内的情形
        printf("找到了第15个元素值为：%d\n", a);
    else
        printf("第15个元素超出范围！\n");

    if((loc=LocateElem(sq, 8))>0)  //测试能找到的情形
        printf("找到了，值为8的元素是第 %d 个\n", loc);
    else
        printf("值为8的元素木有找到！\n");

    if((loc=LocateElem(sq, 17))>0)  //测试不能找到的情形
        printf("找到了，值为17的元素是第 %d 个\n", loc);
    else
        printf("值为17的元素木有找到！\n");

    return 0;
}

//下面实现要测试的各个自定义函数
//用数组创建线性表
void CreateList(SqList *&L, ElemType a[], int n)
{
    int i;
    L=(SqList *)malloc(sizeof(SqList));
    for (i=0; i<n; i++)
        L->data[i]=a[i];
    L->length=n;
}

//输出线性表DispList(L)
void DispList(SqList *L)
{
    int i;
    if (ListEmpty(L))
        return;
    for (i=0; i<L->length; i++)
        printf("%d ",L->data[i]);
    printf("\n");
}

//判定是否为空表ListEmpty(L)
bool ListEmpty(SqList *L)
{
    return(L->length==0);
}

//求线性表的长度ListLength(L)
int ListLength(SqList *L)
{
    return(L->length);
}

//求某个数据元素值GetElem(L,i,e)
bool GetElem(SqList *L,int i,ElemType &e)
{
    if (i<1 || i>L->length)
        return false;
    e=L->data[i-1];
    return true;
}

//按元素值查找LocateElem(L,e)
int LocateElem(SqList *L, ElemType e)
{
    int i=0;
    while (i<L->length && L->data[i]!=e) i++;
    if (i>=L->length)
        return 0;
    else
        return i+1;
}