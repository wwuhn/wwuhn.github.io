#include <stdio.h>
#include <malloc.h>
#include "linklist.h"


void CreateListF(LinkList *&L,ElemType a[],int n)//头插法建立单链表
{
    LinkList *s;
    int i;
    L=(LinkList *)malloc(sizeof(LinkList));     //创建头结点
    L->next=NULL;
    for (i=0; i<n; i++)
    {
        s=(LinkList *)malloc(sizeof(LinkList));//创建新结点
        s->data=a[i];
        s->next=L->next;            //将*s插在原开始结点之前,头结点之后
        L->next=s;
    }
}

void CreateListR(LinkList *&L,ElemType a[],int n)//尾插法建立单链表
{
    LinkList *s,*r;
    int i;
    L=(LinkList *)malloc(sizeof(LinkList));     //创建头结点
    L->next=NULL;
    r=L;                    //r始终指向终端结点,开始时指向头结点
    for (i=0; i<n; i++)
    {
        s=(LinkList *)malloc(sizeof(LinkList));//创建新结点
        s->data=a[i];
        r->next=s;          //将*s插入*r之后
        r=s;
    }
    r->next=NULL;           //终端结点next域置为NULL
}

void InitList(LinkList *&L)
{
    L=(LinkList *)malloc(sizeof(LinkList));     //创建头结点
    L->next=NULL;
}

void DestroyList(LinkList *&L)
{
    LinkList *p=L,*q=p->next;
    while (q!=NULL)
    {
        free(p);
        p=q;
        q=p->next;
    }
    free(p);    //此时q为NULL,p指向尾结点,释放它
}

bool ListEmpty(LinkList *L)
{
    return(L->next==NULL);
}

int ListLength(LinkList *L)
{
    LinkList *p=L;
    int i=0;
    while (p->next!=NULL)
    {
        i++;
        p=p->next;
    }
    return(i);
}

void DispList(LinkList *L)
{
    LinkList *p=L->next;
    while (p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

bool GetElem(LinkList *L,int i,ElemType &e)
{
    int j=0;
    LinkList *p=L;
    while (j<i && p!=NULL)
    {
        j++;
        p=p->next;
    }
    if (p==NULL)            //不存在第i个数据结点
        return false;
    else                    //存在第i个数据结点
    {
        e=p->data;
        return true;
    }
}

int LocateElem(LinkList *L,ElemType e)
{
    LinkList *p=L->next;
    int n=1;
    while (p!=NULL && p->data!=e)
    {
        p=p->next;
        n++;
    }
    if (p==NULL)
        return(0);
    else
        return(n);
}

bool ListInsert(LinkList *&head,int i,ElemType e)
{
    int j=0;
    LinkList *pMove=head,*pNew;
    while (j<i-1 && pMove!=NULL) //查找第i-1个结点
    {
        j++;
        pMove=pMove->next; // 移动
    }
    if (pMove==NULL)            //未找到位序为i-1的结点
        return false;
    else            //找到位序为i-1的结点*p
    {
        pNew=(LinkList *)malloc(sizeof(LinkList));//创建新结点*s
        pNew->data=e;
        pNew->next=pMove->next;                        //将*s插入到*p之后
        pMove->next=pNew;   // 连接
        return true;
    }
}

bool ListDelete(LinkList *&L,int i,ElemType &e)
{
    int j=0;
    LinkList *p=L,*q;
    while (j<i-1 && p!=NULL)    //查找第i-1个结点
    {
        j++;
        p=p->next;
    }
    if (p==NULL)                //未找到位序为i-1的结点
        return false;
    else                        //找到位序为i-1的结点*p
    {
        q=p->next;              //q指向要删除的结点
        if (q==NULL)
            return false;           //若不存在第i个结点,返回false
        e=q->data;
        p->next=q->next;        //从单链表中删除*q结点
        free(q);                //释放*q结点
        return true;
    }
}
