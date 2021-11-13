// 用二叉树求解代数表达式

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "btree.h"
/*
1+2?3?4/5
       -
      /\
   +     /
  /\    /\
 1  *  4  5
    /\
   2  3
*/
//用s[i]到s[j]之间的字符串，构造二叉树的表示形式
BTNode *CRTree(char s[],int i,int j)
{
    BTNode *p;
    int k,plus=0,posi;
    if (i==j)    //i和j相同，意味着只有一个字符，构造的是一个叶子节点
    {
        p=(BTNode *)malloc(sizeof(BTNode));   //分配存储空间
        p->data=s[i];                         //值为s[i]
        p->lchild=NULL;
        p->rchild=NULL;
        return p;
    }
    //以下为i!=j的情况
    for (k=i; k<=j; k++)
        if (s[k]=='+' || s[k]=='-')
        {
            plus++;
            posi=k;              //最后一个+或-的位置
        }
    if (plus==0)                 //没有+或-的情况(因为若有+、-，前面必会执行plus++)
        for (k=i; k<=j; k++)
            if (s[k]=='*' || s[k]=='/')
            {
                plus++;
                posi=k;
            }
    //以上的处理考虑了优先将+、-放到二叉树较高的层次上
    //由于将来计算时，运用的是后序遍历的思路
    //处于较低层的乘除会优先运算
    //从而体现了“先乘除后加减”的运算法则
    //创建一个分支节点，用检测到的运算符作为节点值
    if (plus!=0)
    {
        p=(BTNode *)malloc(sizeof(BTNode));
        p->data=s[posi];                //节点值是s[posi]
        p->lchild=CRTree(s,i,posi-1);   //左子树由s[i]至s[posi-1]构成
        p->rchild=CRTree(s,posi+1,j);   //右子树由s[poso+1]到s[j]构成
        return p;
    }
    else       //若没有任何运算符，返回NULL
        return NULL;
}

double Comp(BTNode *b)
{
    double v1,v2;
    if (b==NULL)
        return 0;
    if (b->lchild==NULL && b->rchild==NULL)  //叶子节点，应该是一个数字字符（本项目未考虑非法表达式）
        return b->data-'0';    //叶子节点直接返回节点值，结点中保存的数字用的是字符形式，所以要-'0'
    v1=Comp(b->lchild); //先计算左子树
    v2=Comp(b->rchild); //再计算右子树
    switch(b->data)     //将左、右子树运算的结果再进行运算，运用的是后序遍历的思路
    {
    case '+':
        return v1+v2;
    case '-':
        return v1-v2;
    case '*':
        return v1*v2;
    case '/':
        if (v2!=0)
            return v1/v2;
        else
            abort();
    }
}

int main()
{
    BTNode *b;
    char s[MaxSize]="1+2*3-4/5";
    printf("代数表达式%s\n",s);
    b=CRTree(s,0,strlen(s)-1);
    printf("对应二叉树:");
    DispBTNode(b);
    printf("\n表达式的值:%g\n",Comp(b));
    DestroyBTNode(b);
    printf("end");
    while(1);
    return 0;
}

