#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

typedef int ElemType;
typedef struct LNode        //定义单链表结点类型
{
    ElemType data;
    struct LNode *next;     //指向后继结点
}LinkList;
void CreateListF(LinkList *&L,ElemType a[],int n);//头插法建立单链表
void CreateListR(LinkList *&L,ElemType a[],int n);//尾插法建立单链表
void InitList(LinkList *&L);        //初始化线性表
void DestroyList(LinkList *&L);     //销毁线性表
bool ListEmpty(LinkList *L);        //判断线性表是否为空
int ListLength(LinkList *L);        //求线性表长度
void DispList(LinkList *L);         //输出线性表
bool GetElem(LinkList *L,int i,ElemType &e);        //求线性表某个数据元素值
int LocateElem(LinkList *L,ElemType e);             //按元素值查找
bool ListInsert(LinkList *&L,int i,ElemType e);     //插入数据元素
bool ListDelete(LinkList *&L,int i,ElemType &e);    //删除数据元素

#endif // LINKLIST_H_INCLUDED