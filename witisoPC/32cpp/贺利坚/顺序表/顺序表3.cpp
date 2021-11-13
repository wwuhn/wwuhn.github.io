#include <iostream>
using namespace std;


#define MaxSize 50
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int length;
} SqList;
void CreateList(SqList *&L, ElemType a[], int n);//用数组创建线性表
void InitList(SqList *&L);//初始化线性表InitList(L)
void DestroyList(SqList *&L);//销毁线性表DestroyList(L)
bool ListEmpty(SqList *L);//判定是否为空表ListEmpty(L)
int ListLength(SqList *L);//求线性表的长度ListLength(L)
void DispList(SqList *L);//输出线性表DispList(L)
bool GetElem(SqList *L,int i,ElemType &e);//求某个数据元素值GetElem(L,i,e)
int LocateElem(SqList *L, ElemType e);//按元素值查找LocateElem(L,e)
bool ListInsert(SqList *&L,int i,ElemType e);//插入数据元素ListInsert(L,i,e)
bool ListDelete(SqList *&L,int i,ElemType &e);//删除数据元素ListDelete(L,i,e)#endif // LIST_H_INCLUDED
void unionList(SqList *LA, SqList *LB, SqList *&LC); // 求集合并集
void delx2y(SqList *&L, ElemType x,  ElemType y);//删除线性表中，元素值在x到y之间的元素
void move(SqList *&L);
void delnode(SqList *&L,ElemType x);  //删除元素
void UnionList(SqList *LA,SqList *LB,SqList *&LC);//合并有序表

#include <stdio.h>
#include <malloc.h>
//#include "list.h"

//用数组创建线性表
void CreateList(SqList *&L, ElemType a[], int n)
{
    int i;
    L=(SqList *)malloc(sizeof(SqList));
    for (i=0; i<n; i++)
        L->data[i]=a[i];
    L->length=n;
}

//初始化线性表InitList(L)
void InitList(SqList *&L)   //引用型指针
{
    L=(SqList *)malloc(sizeof(SqList));
    //分配存放线性表的空间
    L->length=0;
}

//销毁线性表DestroyList(L)
void DestroyList(SqList *&L)
{
    free(L);
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

//输出线性表DispList(L)
void DispList(SqList *L)
{
    int i;
    if (ListEmpty(L)) return;
    for (i=0; i<L->length; i++)
        printf("%d ",L->data[i]);
    printf("\n");
}

//求某个数据元素值GetElem(L,i,e)
bool GetElem(SqList *L,int i,ElemType &e)
{
    if (i<1 || i>L->length)  return false;
    e=L->data[i-1];
    return true;
}

//按元素值查找LocateElem(L,e)
int LocateElem(SqList *L, ElemType e)
{
    int i=0;
    while (i<L->length && L->data[i]!=e) i++;
    if (i>=L->length)  return 0;
    else  return i+1;
}

//插入数据元素ListInsert(L,i,e)
bool ListInsert(SqList *&L,int i,ElemType e)
{
    int j;
    if (i<1 || i>L->length+1)
        return false;   //参数错误时返回false
    i--;            //将顺序表逻辑序号转化为物理序号
    for (j=L->length; j>i; j--) //将data[i..n]元素后移一个位置
        L->data[j]=L->data[j-1];
    L->data[i]=e;           //插入元素e
    L->length++;            //顺序表长度增1
    return true;            //成功插入返回true
}

//删除数据元素ListDelete(L,i,e)
bool ListDelete(SqList *&L,int i,ElemType &e)
{
    int j;
    if (i<1 || i>L->length)  //参数错误时返回false
        return false;
    i--;        //将顺序表逻辑序号转化为物理序号
    e=L->data[i];
    for (j=i; j<L->length-1; j++) //将data[i..n-1]元素前移
        L->data[j]=L->data[j+1];
    L->length--;              //顺序表长度减1
    return true;              //成功删除返回true
}

void unionList(SqList *LA, SqList *LB, SqList *&LC)  //求集合并集
{
    int lena,i;
    ElemType e;
    InitList(LC);
    for (i=1; i<=ListLength(LA); i++) //将LA的所有元素插入到Lc中
    {
        GetElem(LA,i,e);
        ListInsert(LC,i,e);
    }
    lena=ListLength(LA);         //求线性表LA的长度
    for (i=1; i<=ListLength(LB); i++)
    {
        GetElem(LB,i,e);         //取LB中第i个数据元素赋给e
        if (!LocateElem(LA,e)) //LA中不存在和e相同者,插入到LC中
            ListInsert(LC,++lena,e);
    }
}
//删除线性表中，元素值在x到y之间的元素
void delx2y(SqList *&L, ElemType x,  ElemType y)
{
    int k=0,i; //k记录非x的元素个数
    ElemType t;
    if(x>y)
    {
        t=x;
        x=y;
        y=t;
    }
    for (i=0; i<L->length; i++)
        if (L->data[i]<x || L->data[i]>y )  //复制不在[x, y]之间的元素
        {
            L->data[k]=L->data[i];
            k++;
        }
    L->length=k;
}
//移动结束后，奇数居左，偶数居右
void move(SqList *&L)
{
    int i=0,j=L->length-1;
    ElemType tmp;
    while (i<j)
    {
        while ((i<j) && (L->data[j]%2==0))  //从右往左，找到第一个奇数(偶数就忽略不管)
            j--;
        while ((i<j) && (L->data[i]%2==1))  //从左往右，找到第一个偶数(奇数就忽略不管)
            i++;
        if (i<j)   //如果未到达“分界线”，将右边的奇数和左边的偶数交换
        {
            tmp=L->data[i];
            L->data[i]=L->data[j];
            L->data[j]=tmp;
        }
    }   //待循环上去后，继续查找，并在必要时交换
}
void move1(SqList *&L) //将所有小于它的元素移到该元素的前面，将所有大于它的元素移到该元素的后面
{
    int i=0,j=L->length-1;
    ElemType pivot=L->data[0];  //以data[0]为基准
    ElemType tmp;
    while (i<j)             //从区间两端交替向中间扫描,直至i=j为止
    {
        while (i<j && L->data[j]>pivot)
            j--;            //从右向左扫描,找第1个小于等于pivot的元素
        while (i<j && L->data[i]<=pivot)
            i++;            //从左向右扫描,找第1个大于pivot的元素
        if (i<j)
        {
            tmp=L->data[i]; //L->data[i]和L->data[j]进行交换
            L->data[i]=L->data[j];
            L->data[j]=tmp;
        }
    }
    tmp=L->data[0];         //L->data[0]和L->data[j]进行交换
    L->data[0]=L->data[j];
    L->data[j]=tmp;
}

void delnode(SqList *&L,ElemType x)  //删除元素
{
    int k=0,i; //k记录非x的元素个数
    for (i=0; i<L->length; i++)
        if (L->data[i]!=x)
        {
            L->data[k]=L->data[i];
            k++;
        }
    L->length=k;
}
void UnionList(SqList *LA,SqList *LB,SqList *&LC)//合并有序表
{
    int i=0,j=0,k=0;    //i、j、k分别作为LA、LB、LC的下标
    LC=(SqList *)malloc(sizeof(SqList));
    LC->length=0;
    while (i<LA->length && j<LB->length)
    {
        if (LA->data[i]<LB->data[j])
        {
            LC->data[k]=LA->data[i];
            i++;
            k++;
        }
        else                //LA->data[i]>LB->data[j]
        {
            LC->data[k]=LB->data[j];
            j++;
            k++;
        }
    }
    while (i<LA->length)    //LA尚未扫描完,将其余元素插入LC中
    {
        LC->data[k]=LA->data[i];
        i++;
        k++;
    }
    while (j<LB->length)  //LB尚未扫描完,将其余元素插入LC中
    {
        LC->data[k]=LB->data[j];
        j++;
        k++;
    }
    LC->length=k;
}

//#include "list.h"
int main()
{
    SqList *sq_1;
    ElemType x[6]= {5,8,7,2,4,9};
    CreateList(sq_1, x, 6);
    DispList(sq_1);

    SqList *sq_a, *sq_b, *sq_c;
    ElemType a[6]= {5,8,7,2,4,9};
    CreateList(sq_a, a, 6);
    printf("LA: ");
    DispList(sq_a);

    ElemType b[6]= {2,3,8,6,0};
    CreateList(sq_b, b, 5);
    printf("LB: ");
    DispList(sq_b);
    unionList(sq_a, sq_b, sq_c);
    printf("LC: ");
    DispList(sq_c);


    SqList *sq;
    ElemType arr[]= {5,8,7,0,2,4,9,6,7,3,55,12,44,66,36,25,11,88,20};
    CreateList(sq, arr, sizeof(arr)/sizeof*arr);
    printf("删除前 ");
    DispList(sq);

    delx2y(sq, 4, 7);

    printf("删除后 ");
    DispList(sq);

    move(sq);

    printf("移动结束后，奇数居左，偶数居右\n");
    DispList(sq);
    printf("删除前 ");
    DispList(sq);

    delnode(sq, 3);

    printf("删除后 ");
    DispList(sq);


    printf("移动前 ");
    DispList(sq);

    move1(sq);

    printf("移动后 ");
    DispList(sq);

   SqList *L1,*L2,*L3;
    ElemType aa[]= {1,3,5};
    ElemType bb[]= {2,4,8,10};
    CreateList(L1,aa,3);
    printf("L1:");
    DispList(L1);
    CreateList(L2,bb,4);
    printf("L2:");
    DispList(L2);
    printf("归并\n");
    UnionList(L1,L2,L3);
    printf("L3:");
    DispList(L3);
    DestroyList(L1);
    DestroyList(L2);
    DestroyList(L3);
    while(1);
    return 0;
}