#include<iostream>
using namespace std;

typedef struct Bnode{ 	/*定义二叉树存储结构*/
	char data;
	struct Bnode *lchild,*rchild;
}Bnode,*Btree;

void createtree(Btree &T)	/*创建二叉树函数*/
{
    char check;					/*判断是否创建左右孩子*/
    T=new Bnode;
    cout<<"请输入结点信息:"<<endl;	/*输入根结点数据*/
    cin>>T->data;
    cout<<"是否添加 "<<T->data<<"的左孩子? (Y/N)"<<endl; /*询问是否创建T的左子树*/
    cin>>check;
    if(check=='Y')
        createtree(T->lchild);
    else
        T->lchild=NULL;
    cout<<"是否添加"<<T->data<<"的右孩子? (Y/N)"<<endl; /*询问是否创建T的右子树*/
    cin>>check;
    if(check=='Y')
        createtree(T->rchild);
    else
        T->rchild=NULL;
    return;
}

int main()
{
    Btree mytree;
    createtree(mytree);/*创建二叉树*/
    return 0;
}
