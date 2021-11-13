//本程序严格讲有个bug，详见1楼
#include <stdio.h>
#include <malloc.h>
#include "linklist.h"
void split(LinkList *&L,LinkList *&L1,LinkList *&L2)
{
    LinkList *p=L->next,*q,*r1; //p指向第1个数据节点
    L1=L;       //L1利用原来L的头节点
    r1=L1;                  //r1始终指向L1的尾节点
    L2=(LinkList *)malloc(sizeof(LinkList));    //创建L2的头节点
    L2->next=NULL;          //置L2的指针域为NULL
    while (p!=NULL)
    {
        r1->next=p;         //采用尾插法将*p(data值为ai)插入L1中
        r1=p;
        p=p->next;          //p移向下一个节点(data值为bi)
        q=p->next;          //由于头插法修改p的next域,故用q保存*p的后继节点
        p->next=L2->next;   //采用头插法将*p插入L2中
        L2->next=p;
        p=q;                //p重新指向ai+1的节点
    }
    r1->next=NULL;          //尾节点next置空
}
/*
这段代码默认了原链表中一定是偶数个结点，也只测试了这种情况。
既然是奇数个结点时出问题，应该猜到就是在处理第偶数个结点时，
p=p->next使p已经为NULL，还要q=p->next，在这儿就出问题了。
所以，在处理第偶数个结点时，用if加一个判断即可
*/
void split2(LinkList *&L,LinkList *&L1,LinkList *&L2)
{
    LinkList *p=L->next,*q,*r1; //p指向第1个数据节点
    L1=L;       //L1利用原来L的头节点
    r1=L1;                  //r1始终指向L1的尾节点
    L2=(LinkList *)malloc(sizeof(LinkList));    //创建L2的头节点
    L2->next=NULL;          //置L2的指针域为NULL
    while (p!=NULL)
    {
        r1->next=p;         //采用尾插法将*p(data值为ai)插入L1中
        r1=p;
        p=p->next;          //p移向下一个节点(data值为bi)
        if(p!=NULL)
        {
            q=p->next;          //由于头插法修改p的next域,故用q保存*p的后继节点
            p->next=L2->next;   //采用头插法将*p插入L2中
            L2->next=p;
            p=q;                //p重新指向ai+1的节点
        }
 
    }
    r1->next=NULL;          //尾节点next置空
}
int main()
{
    LinkList *L,*L1,*L2;
    int i;
    ElemType a[]= {1,2,3,4,5,6,7,8,9,10,11};
    InitList(L);
    InitList(L1);
    InitList(L2);
    for(i=9; i>=0; i--)
        ListInsert(L, 1, a[i]);
    printf("L:");
    DispList(L);
    printf("L->L1,L2\n");

    split2(L,L1,L2);
    printf("L1:");
    DispList(L1);
    printf("L2:");
    DispList(L2);
    DestroyList(L1);
    DestroyList(L2);
    while(1);
    return 0;
}