#include <stdio.h>
#include <malloc.h>
#include "linklist.h"

void Link(LinkList *&L1, LinkList *&L2)
{
    LinkList *p = L1;
    while(p->next != NULL)   //找到L1的尾节点
        p = p->next;
    p->next = L2->next;  //将L2的首个数据节点连接到L1的尾节点后
    free(L2);   //释放掉已经无用的L2的头节点
}

int main()
{
    LinkList *A, *B;
    int i;
    ElemType a[]= {1,3,2,9};
    ElemType b[]= {0,4,7,6,5,8};
    InitList(A);
    for(i=3; i>=0; i--)
        ListInsert(A, 1, a[i]);
    InitList(B);
    for(i=5; i>=0; i--)
        ListInsert(B, 1, b[i]);
    Link(A, B);
    printf("A:");
    DispList(A);
    DestroyList(A);
    return 0;
}