#ifndef CDLINKLIST_H_INCLUDED
#define CDLINKLIST_H_INCLUDED

//循环双链表基本运算函数
typedef int ElemType;
typedef struct DNode        //定义双链表结点类型
{
    ElemType data;
    struct DNode *prior;    //指向前驱结点
    struct DNode *next;     //指向后继结点
} CDLinkList;

void CreateListF(CDLinkList *&L,ElemType a[],int n); //头插法建立循环双链表
void CreateListR(CDLinkList *&L,ElemType a[],int n); //尾插法建立循环双链表
void InitList(CDLinkList *&L); //初始化循环双链表
void DestroyList(CDLinkList *&L);  //销毁
bool ListEmpty(CDLinkList *L); //判断是否为空
int ListLength(CDLinkList *L); //求链表长度
void DispList(CDLinkList *L);  //输出链表
bool GetElem(CDLinkList *L,int i,ElemType &e);  //取链表元素
int LocateElem(CDLinkList *L,ElemType e);  //查找元素
bool ListInsert(CDLinkList *&L,int i,ElemType e);  //插入节点
bool ListDelete(CDLinkList *&L,int i,ElemType &e);  //删除节点

#endif // CDLINKLIST_H_INCLUDED

//循环双链表基本运算函数
#include <stdio.h>
#include <malloc.h>
//#include "cdlinklist.h"
void CreateListF(CDLinkList *&L,ElemType a[],int n) //头插法建立循环双链表
{
    CDLinkList *s;
    int i;
    L=(CDLinkList *)malloc(sizeof(CDLinkList));     //创建头结点
    L->next=NULL;
    for (i=0; i<n; i++)
    {
        s=(CDLinkList *)malloc(sizeof(CDLinkList));//创建新结点
        s->data=a[i];
        s->next=L->next;            //将*s插在原开始结点之前,头结点之后
        if (L->next!=NULL) L->next->prior=s;
        L->next=s;
        s->prior=L;
    }
    s=L->next;
    while (s->next!=NULL)           //查找尾结点,由s指向它
        s=s->next;
    s->next=L;                      //尾结点next域指向头结点
    L->prior=s;                     //头结点的prior域指向尾结点

}

void CreateListR(CDLinkList *&L,ElemType a[],int n) //尾插法建立循环双链表
{
    CDLinkList *s,*r;
    int i;
    L=(CDLinkList *)malloc(sizeof(CDLinkList));  //创建头结点
    L->next=NULL;
    r=L;                    //r始终指向尾结点,开始时指向头结点
    for (i=0; i<n; i++)
    {
        s=(CDLinkList *)malloc(sizeof(CDLinkList));//创建新结点
        s->data=a[i];
        r->next=s;
        s->prior=r; //将*s插入*r之后
        r=s;
    }
    r->next=L;              //尾结点next域指向头结点
    L->prior=r;             //头结点的prior域指向尾结点
}

void InitList(CDLinkList *&L) //初始化循环双链表
{
    L=(CDLinkList *)malloc(sizeof(CDLinkList));     //创建头结点
    L->prior=L->next=L;
}

void DestroyList(CDLinkList *&L)  //销毁
{
    CDLinkList *p=L,*q=p->next;
    while (q!=L)
    {
        free(p);
        p=q;
        q=p->next;
    }
    free(p);
}

bool ListEmpty(CDLinkList *L) //判断是否为空
{
    return(L->next==L);
}
int ListLength(CDLinkList *L) //求链表长度
{
    CDLinkList *p=L;
    int i=0;
    while (p->next!=L)
    {
        i++;
        p=p->next;
    }
    return(i);
}
void DispList(CDLinkList *L)  //输出链表
{
    CDLinkList *p=L->next;
    while (p!=L)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
bool GetElem(CDLinkList *L,int i,ElemType &e)  //取链表元素
{
    int j=0;
    CDLinkList *p;
    if (L->next!=L)     //双链表不为空表时
    {
        if (i==1)
        {
            e=L->next->data;
            return true;
        }
        else            //i不为1时
        {
            p=L->next;
            while (j<i-1 && p!=L)
            {
                j++;
                p=p->next;
            }
            if (p==L)
                return false;
            else
            {
                e=p->data;
                return true;
            }
        }
    }
    else                //双链表为空表时
        return 0;
}
int LocateElem(CDLinkList *L,ElemType e)  //查找元素
{
    int n=1;
    CDLinkList *p=L->next;
    while (p!=NULL && p->data!=e)
    {
        n++;
        p=p->next;
    }
    if (p==NULL)
        return(0);
    else
        return(n);
}
bool ListInsert(CDLinkList *&L,int i,ElemType e)  //插入节点
{
    int j=0;
    CDLinkList *p=L,*s;
    if (p->next==L)                 //原双链表为空表时
    {
        s=(CDLinkList *)malloc(sizeof(CDLinkList)); //创建新结点*s
        s->data=e;
        p->next=s;
        s->next=p;
        p->prior=s;
        s->prior=p;
        return true;
    }
    else if (i==1)                  //原双链表不为空表但i=1时
    {
        s=(CDLinkList *)malloc(sizeof(CDLinkList)); //创建新结点*s
        s->data=e;
        s->next=p->next;
        p->next=s;  //将*s插入到*p之后
        s->next->prior=s;
        s->prior=p;
        return true;
    }
    else
    {
        p=L->next;
        while (j<i-2 && p!=L)
        {
            j++;
            p=p->next;
        }
        if (p==L)               //未找到第i-1个结点
            return false;
        else                    //找到第i-1个结点*p
        {
            s=(CDLinkList *)malloc(sizeof(CDLinkList)); //创建新结点*s
            s->data=e;
            s->next=p->next;    //将*s插入到*p之后
            if (p->next!=NULL) p->next->prior=s;
            s->prior=p;
            p->next=s;
            return true;
        }
    }
}
bool ListDelete(CDLinkList *&L,int i,ElemType &e)  //删除节点
{
    int j=0;
    CDLinkList *p=L,*q;
    if (p->next!=L)                 //原双链表不为空表时
    {
        if (i==1)                   //i==1时
        {
            q=L->next;              //删除第1个结点
            e=q->data;
            L->next=q->next;
            q->next->prior=L;
            free(q);
            return true;
        }
        else                        //i不为1时
        {
            p=L->next;
            while (j<i-2 && p!=NULL)
            {
                j++;
                p=p->next;
            }
            if (p==NULL)                //未找到第i-1个结点
                return false;
            else                        //找到第i-1个结点*p
            {
                q=p->next;              //q指向要删除的结点
                if (q==NULL) return 0;  //不存在第i个结点
                e=q->data;
                p->next=q->next;        //从单链表中删除*q结点
                if (p->next!=NULL) p->next->prior=p;
                free(q);                //释放*q结点
                return true;
            }
        }
    }
    else
        return false;   //原双链表为空表时
}


int main()
{
    CDLinkList *A;
    ElemType a[]= {1, 3, 2, 9, 0, 4, 5 ,6, 7, 8};
    InitList(A);
    CreateListF(A, a, 10);
    printf("length: %d\n", ListLength(A));
    ListInsert(A, 4, 12);
    printf("After Insert: ");
    DispList(A);
    DestroyList(A);
    while(1);
    return 0;
}