#include <stdio.h>
#include "btree.h"

int Nodes(BTNode *b)
{
    if (b==NULL)
        return 0;
    else
        return Nodes(b->lchild)+Nodes(b->rchild)+1;
}

void treeHeight()
{
    BTNode *b;
    CreateBTNode(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    printf("二叉树节点个数: %d\n", Nodes(b));
    DestroyBTNode(b);
}




void DispLeaf(BTNode *b)
{
    if (b!=NULL)
    {
        if (b->lchild==NULL && b->rchild==NULL)
            printf("%c ",b->data);
        else
        {
            DispLeaf(b->lchild);
            DispLeaf(b->rchild);
        }
    }
}

void printLeaf()
{
    BTNode *b;
    CreateBTNode(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    printf("二叉树中所有的叶子节点是: ");
    DispLeaf(b);
    printf("\n");
    DestroyBTNode(b);

}


int LeafNodes(BTNode *b)    //求二叉树b的叶子节点个数
{
    int num1,num2;
    if (b==NULL)
        return 0;
    else if (b->lchild==NULL && b->rchild==NULL)
        return 1;
    else
    {
        num1=LeafNodes(b->lchild);
        num2=LeafNodes(b->rchild);
        return (num1+num2);
    }
}

void LeafNodesCal()
{
    BTNode *b;
    CreateBTNode(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    printf("二叉树b的叶子节点个数: %d\n",LeafNodes(b));
    DestroyBTNode(b);
}
//设计一个算法Level(b,x,h)，返回二叉链b中data值为x的节点的层数。


int Level(BTNode *b,ElemType x,int h)
{
    int l;
    if (b==NULL)
        return 0;
    else if (b->data==x)
        return h;
    else
    {
        l=Level(b->lchild,x,h+1);
        if (l==0)
            return Level(b->rchild,x,h+1);
        else
            return l;
    }
}

void levelCal()
{
    BTNode *b;
    CreateBTNode(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    printf("值为\'K\'的节点在二叉树中出现在第 %d 层上n",Level(b,'K',1));
    DestroyBTNode(b);
}
/*
（5）判断二叉树是否相似（关于二叉树t1和t2相似的判断：
①t1和t2都是空的二叉树，相似；
②t1和t2之一为空，另一不为空，则不相似；
③t1的左子树和t2的左子树是相似的，且t1的右子
树与t2的右子树是相似的，则t1和t2相似。）
*/
#include <stdio.h>
#include "btree.h"

int Like(BTNode *b1,BTNode *b2)
{
    int like1,like2;
    if (b1==NULL && b2==NULL)
        return 1;
    else if (b1==NULL || b2==NULL)
        return 0;
    else
    {
        like1=Like(b1->lchild,b2->lchild);
        like2=Like(b1->rchild,b2->rchild);
        return (like1 & like2);
    }
}

void likeTest()
{
    BTNode *b1, *b2, *b3;
    CreateBTNode(b1,"B(D,E(H(J,K(L,M(,N)))))");
    CreateBTNode(b2,"A(B(D(,G)),C(E,F))");
    CreateBTNode(b3,"u(v(w(,x)),y(z,p))");
    if(Like(b1, b2))
        printf("b1和b2相似\n");
    else
        printf("b1和b2不相似\n");
    if(Like(b2, b3))
        printf("b2和b3相似\n");
    else
        printf("b2和b3不相似\n");
    DestroyBTNode(b1);
    DestroyBTNode(b2);
    DestroyBTNode(b3);

}
int main()
{
    treeHeight();
    printLeaf();
    LeafNodesCal();
    levelCal();
    likeTest();
    printf("\nend");
    while(1);
    return 0;
}