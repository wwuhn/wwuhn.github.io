#include <stdio.h>  // 二叉树非递归遍历
#include "btree.h"

void PreOrder1(BTNode *b)
{
    BTNode *St[MaxSize],*p;
    int top=-1;
    if (b!=NULL)
    {
        top++;                      //根节点入栈
        St[top]=b;
        while (top>-1)              //栈不为空时循环
        {
            p=St[top];              //退栈并访问该节点
            top--;
            printf("%c ",p->data);
            if (p->rchild!=NULL)    //右孩子入栈
            {
                top++;
                St[top]=p->rchild;
            }
            if (p->lchild!=NULL)    //左孩子入栈
            {
                top++;
                St[top]=p->lchild;
            }
        }
        printf("\n");
    }
}

void InOrder1(BTNode *b)
{
    BTNode *St[MaxSize],*p;
    int top=-1;
    if (b!=NULL)
    {
        p=b;
        while (top>-1 || p!=NULL)
        {
            while (p!=NULL)
            {
                top++;
                St[top]=p;
                p=p->lchild;
            }
            if (top>-1)
            {
                p=St[top];
                top--;
                printf("%c ",p->data);
                p=p->rchild;
            }
        }
        printf("\n");
    }
}

void PostOrder1(BTNode *b)
{
    BTNode *St[MaxSize];
    BTNode *p;
    int flag,top=-1;                        //栈指针置初值
    if (b!=NULL)
    {
        do
        {
            while (b!=NULL)                 //将t的所有左节点入栈
            {
                top++;
                St[top]=b;
                b=b->lchild;
            }
            p=NULL;                         //p指向当前节点的前一个已访问的节点
            flag=1;
            while (top!=-1 && flag)
            {
                b=St[top];                  //取出当前的栈顶元素
                if (b->rchild==p)           //右子树不存在或已被访问,访问之
                {
                    printf("%c ",b->data);  //访问*b节点
                    top--;
                    p=b;                    //p指向则被访问的节点
                }
                else
                {
                    b=b->rchild;            //t指向右子树
                    flag=0;
                }
            }
        }
        while (top!=-1);
        printf("\n");
    }
}

int main()
{
    BTNode *b;
    CreateBTNode(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    printf("二叉树b: ");
    DispBTNode(b);
    printf("\n");
    printf("先序遍历序列:\n");
    PreOrder1(b);
    printf("中序遍历序列:\n");
    InOrder1(b);
    printf("后序遍历序列:\n");
    PostOrder1(b);
    DestroyBTNode(b);
    printf("end");
    while(1);
    return 0;
}
