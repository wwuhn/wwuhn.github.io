#include <stdio.h>
#include "btree.h"

void PreOrder(BTNode *b)        //先序遍历的递归算法
{
    if (b!=NULL)
    {
        printf("%c ",b->data);  //访问根节点
        PreOrder(b->lchild);    //递归访问左子树
        PreOrder(b->rchild);    //递归访问右子树
    }
}

void InOrder(BTNode *b)         //中序遍历的递归算法
{
    if (b!=NULL)
    {
        InOrder(b->lchild);     //递归访问左子树
        printf("%c ",b->data);  //访问根节点
        InOrder(b->rchild);     //递归访问右子树
    }
}

void PostOrder(BTNode *b)       //后序遍历的递归算法
{
    if (b!=NULL)
    {
        PostOrder(b->lchild);   //递归访问左子树
        PostOrder(b->rchild);   //递归访问右子树
        printf("%c ",b->data);  //访问根节点
    }
}

int main()
{
    BTNode *b;
    CreateBTNode(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    printf("二叉树b:");
    DispBTNode(b);
    printf("\n");
    printf("先序遍历序列:\n");
    PreOrder(b);
    printf("\n");
    printf("中序遍历序列:\n");
    InOrder(b);
    printf("\n");
    printf("后序遍历序列:\n");
    PostOrder(b);
    printf("\n");
    DestroyBTNode(b);
    printf("-endl-");
    while(1);
    return 0;
}
