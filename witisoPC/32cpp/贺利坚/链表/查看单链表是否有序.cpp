#include <stdio.h>
#include <malloc.h>
#include "linklist.h"

bool increase(LinkList *L)
{
    LinkList *p = L->next, *q;      //p指向第1个数据节点
    if(p != NULL)
    {
        while(p->next != NULL)
        {
            q = p->next;            //q是p的后继
            if (q->data > p->data)  //只要是递增的，就继续考察其后继
                p = q;
            else
                return false;       //只要有一个不是后继大于前驱，便不是递增
        }
    }
    return true;
}

int main()
{
    LinkList *A, *B;
    int i;
    ElemType a[]= {1, 3, 2, 9};
    ElemType b[]= {0, 4, 5 ,6, 7, 8};
    InitList(A);
    for(i=3; i>=0; i--)
        ListInsert(A, 1, a[i]);
    InitList(B);
    for(i=5; i>=0; i--)
        ListInsert(B, 1, b[i]);
    printf("A: %c\n", increase(A)?'Y':'N');
    printf("B: %c\n", increase(B)?'Y':'N');
    DestroyList(A);
    DestroyList(B);
    return 0;
}