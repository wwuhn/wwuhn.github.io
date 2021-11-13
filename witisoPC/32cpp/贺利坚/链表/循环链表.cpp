#ifndef CLINKLIST_H_INCLUDED
#define CLINKLIST_H_INCLUDED

//循环单链表基本运算函数
typedef int ElemType;
typedef struct LNode        //定义单链表结点类型
{
    ElemType data;
    struct LNode *next;
} CLinkList;

void CreateListF(CLinkList *&L,ElemType a[],int n);//头插法建立循环单链表
void CreateListR(CLinkList *&L,ElemType a[],int n);//尾插法建立循环单链表
void InitList(CLinkList *&L); //初始化链表
void DestroyList(CLinkList *&L); //销毁链表
bool ListEmpty(CLinkList *L);  //判断链表是否为空
int ListLength(CLinkList *L);  //求链表长度
void DispList(CLinkList *L);  //输出链表
bool GetElem(CLinkList *L,int i,ElemType &e);  //取链表元素
int LocateElem(CLinkList *L,ElemType e);  //查找元素
bool ListInsert(CLinkList *&L,int i,ElemType e);  //插入节点
bool ListDelete(CLinkList *&L,int i,ElemType &e);   //删除节点

#endif // CLINKLIST_H_INCLUDED
//循环单链表基本运算函数
#include <stdio.h>
#include <malloc.h>
//#include "clinklist.h"
void CreateListF(CLinkList *&L,ElemType a[],int n)//头插法建立循环单链表
{
    CLinkList *s;
    int i;
    L=(CLinkList *)malloc(sizeof(CLinkList));   //创建头结点
    L->next=NULL;
    for (i=0; i<n; i++)
    {
        s=(CLinkList *)malloc(sizeof(CLinkList));//创建新结点
        s->data=a[i];
        s->next=L->next;            //将*s插在原开始结点之前,头结点之后
        L->next=s;
    }
    s=L->next;
    while (s->next!=NULL)           //查找尾结点,由s指向它
        s=s->next;
    s->next=L;                      //尾结点next域指向头结点

}

void CreateListR(CLinkList *&L,ElemType a[],int n)//尾插法建立循环单链表
{
    CLinkList *s,*r;
    int i;
    L=(CLinkList *)malloc(sizeof(CLinkList));   //创建头结点
    L->next=NULL;
    r=L;                    //r始终指向终端结点,开始时指向头结点
    for (i=0; i<n; i++)
    {
        s=(CLinkList *)malloc(sizeof(CLinkList));//创建新结点
        s->data=a[i];
        r->next=s;          //将*s插入*r之后
        r=s;
    }
    r->next=L;              //尾结点next域指向头结点
}

void InitList(CLinkList *&L) //初始化链表
{
    L=(CLinkList *)malloc(sizeof(CLinkList));   //创建头结点
    L->next=L;
}

void DestroyList(CLinkList *&L) //销毁链表
{
    CLinkList *p=L,*q=p->next;
    while (q!=L)
    {
        free(p);
        p=q;
        q=p->next;
    }
    free(p);
}

bool ListEmpty(CLinkList *L)  //判断链表是否为空
{
    return(L->next==L);
}

int ListLength(CLinkList *L)  //求链表长度
{
    CLinkList *p=L;
    int i=0;
    while (p->next!=L)
    {
        i++;
        p=p->next;
    }
    return(i);
}

void DispList(CLinkList *L)  //输出链表
{
    CLinkList *p=L->next;
    while (p!=L)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

bool GetElem(CLinkList *L,int i,ElemType &e)  //取链表元素
{
    int j=0;
    CLinkList *p;
    if (L->next!=L)     //单链表不为空表时
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
    else                //单链表为空表时
        return false;
}

int LocateElem(CLinkList *L,ElemType e)  //查找元素
{
    CLinkList *p=L->next;
    int n=1;
    while (p!=L && p->data!=e)
    {
        p=p->next;
        n++;
    }
    if (p==L)
        return(0);
    else
        return(n);
}

bool ListInsert(CLinkList *&L,int i,ElemType e)  //插入节点
{
    int j=0;
    CLinkList *p=L,*s;
    if (p->next==L || i==1)     //原单链表为空表或i==1时
    {
        s=(CLinkList *)malloc(sizeof(CLinkList));   //创建新结点*s
        s->data=e;
        s->next=p->next;        //将*s插入到*p之后
        p->next=s;
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
            s=(CLinkList *)malloc(sizeof(CLinkList));   //创建新结点*s
            s->data=e;
            s->next=p->next;                        //将*s插入到*p之后
            p->next=s;
            return true;
        }
    }
}

bool ListDelete(CLinkList *&L,int i,ElemType &e)   //删除节点
{
    int j=0;
    CLinkList *p=L,*q;
    if (p->next!=L)                 //原单链表不为空表时
    {
        if (i==1)                   //i==1时
        {
            q=L->next;              //删除第1个结点
            e=q->data;
            L->next=q->next;
            free(q);
            return true;
        }
        else                        //i不为1时
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
                q=p->next;          //q指向要删除的结点
                e=q->data;
                p->next=q->next;    //从单链表中删除*q结点
                free(q);            //释放*q结点
                return true;
            }
        }
    }
    else
        return 0;
}


//#include "clinklist.h"

int main()
{
    CLinkList *A;
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