#include<iostream>
#include<cstring>
#include <string>
#include<queue>
using namespace std;
/*
输入三元组 (F、C、L/R) 序列输入一棵二叉树的诸边
      (其中 F 表示双亲结点的标识，
            C 表示孩子结点标识，
L/R 表示 C 为 F 的左孩子或右孩子)，
且在输入的三元组序列中，C 是按层次顺序出现的。
设结点的标识是字符类型。F=NULL时 C 为根结点标识，若 C 亦为NULL，则表示输入结束。
试编写算法，由输入的三元组序列建立二叉树的二叉链表,并以先序、中序、后序序列输出。
*/
/*测试数据
NULL A L
A B L
A C R
B D R
C E L
C F R
D G L
F H L
NULL NULL L
*/
struct biTnode
{
    string data;
    biTnode *lChild,*rChild;
};
biTnode* T=NULL;

void CreatebiTree(biTnode* &T)
{
    string a,b,c;
    biTnode *node,*p;
    queue<biTnode*>q;
    cin>>a>>b>>c;
    if(a=="NULL"&&b!="NULL")    // 创建根结点
    {
        node=new biTnode;
        node->data=b;
        node->lChild=node->rChild=NULL;
        T=node;
        q.push(T);
    }
    cin>>a>>b>>c;
    while(!q.empty()&&a!="NULL"&&b!="NULL")
    {
        p=q.front();
        q.pop();
        while(a==p->data)
        {
            node=new biTnode;
            node->data=b;
            node->lChild=node->rChild=NULL;
            if(c=="L")
            {
                p->lChild=node;
                cout<<p->data<<"'s lChild is "<<node->data<<endl;
            }
            else
            {
                p->rChild=node;
                cout<<p->data<<"'s rChild is "<<node->data<<endl;
            }
            q.push(node);
            cin>>a>>b>>c;
        }
    }
}


void preorder(biTnode* &T)
{
    if(T)
    {
        cout<<T->data<<"  ";
        preorder(T->lChild);
        preorder(T->rChild);
    }
}

void inorder(biTnode* &T)
{
    if(T)
    {
        inorder(T->lChild);
        cout<<T->data<<"  ";
        inorder(T->rChild);
    }
}

void posorder(biTnode* &T)
{
    if(T)
    {
        posorder(T->lChild);
        posorder(T->rChild);
        cout<<T->data<<"  ";
    }
}
int main()
{
    cout<<"输入结点数据a,b,c(a为父亲，b为结点字符，c为‘L’左孩子或‘R’右孩子)"<<endl;
    CreatebiTree(T);
    cout<<"创建树成功!"<<endl;
    cout<<"先序遍历："<<endl;
    preorder(T);
    cout<<endl<<"中序遍历："<<endl;
    inorder(T);
    cout<<endl<<"后序遍历："<<endl;
    posorder(T);
    return 0;
}
