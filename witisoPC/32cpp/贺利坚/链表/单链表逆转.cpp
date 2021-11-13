#include <stdio.h>
#include <malloc.h>
#include "linklist.h"
void Reverse(LinkList *&L)
{
    LinkList *p=L->next,*q;
    L->next=NULL;
    while (p!=NULL)     //扫描所有的结点
    {
        q=p->next;      //让q指向*p结点的下一个结点
        p->next=L->next;    //总是将*p结点作为第一个数据结点
        L->next=p;
        p=q;            //让p指向下一个结点
    }
}

int main()
{
    LinkList *L;
    ElemType a[]= {1,3,5,7, 2,4,8,10};
    CreateListR(L,a,8);
    printf("L:");
    DispList(L);
    Reverse(L);
    printf("逆置后L： ");
    DispList(L);
    DestroyList(L);
    while(1);
    return 0;
}