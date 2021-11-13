#include<stdio.h>   //printf()等
#include<malloc.h>  // malloc()等
#include<process.h> //exit()
#define OK 1
#define OVERFLOW -2
typedef int Status;         //Status是函数的类型,其值是函数结果状态代码，如OK等
typedef int ElemType;       //ElemType是线性表中数据元素的类型，此处用int
#define LIST_INIT_SIZE 10   // 线性表存储空间的初始分配量，为方便测试，改为10

typedef struct 
{
    ElemType *elem; //存储空间基址
    int length;     // 当前长度
    int listsize;   // 当前分配的存储容量(以sizeof(ElemType)为单位)
}SqList;

Status InitList(SqList &L)  // 算法2.3
{                           // 操作结果：构造一个空的顺序线性表
    L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L.elem)
        exit(OVERFLOW);         // 存储分配失败
    L.length=0;                 // 空表长度为0
    L.listsize=LIST_INIT_SIZE;  // 初始存储容量
    return OK;
}

Status ListTraverse(SqList L)
{   // 初始条件：顺序线性表L已存在
    // 操作结果：依次输出L中的每个数据元素，函数名没有用display，而是用了更专业的术语——遍历Traverse
    ElemType *p;
    int i;
    p=L.elem;
    printf("线性表当前容量为: %d，",	L.listsize);
    if (L.length>0)
    {
        printf("线性表中有 %d 个元素，分别是：",L.length);
        for(i=1;i<=L.length;i++)
            printf("%d ",*p++);
    }
    else
        printf("目前还是空线性表。");
    printf("\n");
    return OK;
}

int main()
{
    SqList La;
    Status i;
    i=InitList(La);
    ListTraverse(La);
    while(1);
    return 0;
}  