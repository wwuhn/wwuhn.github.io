#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>
#define STACK_INCREMENT  10
#define STACK_INIT_SIZE 100
#define MAXSIZE         50
#define OVERFLOW -2
//二叉排序树的链式存储结构
typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
 
//栈的顺序存储结构
typedef struct
{
	BiTree *base;
	BiTree *top;
	int stacksize;
}Sqstack;
 
//初始化一个栈，用于二叉树的中序遍历
void InitStack(Sqstack&S)
{
	S.base=(BiTree*)malloc(STACK_INIT_SIZE*sizeof(BiTNode));
	if(!S.base)
		exit(0);
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
}
 
 
//二叉排序树查找
void SearchBST(BiTree T,int key,BiTree f,BiTree&p)
{
	if(!T) 
		p=f;
	else if(T->data==key)
		p=T;
	else if(T->data<key)
		SearchBST(T->rchild,key,T,p);
	else 
		SearchBST(T->lchild,key,T,p);
}
 
//创建一个二叉排序树
void CreatBST(BiTree &T,int e)
{
	BiTree p,s,q;
	SearchBST(T,e,NULL,p);//找到带插入的位置。
	s=(BiTree)malloc(sizeof(BiTNode));
	s->data=e;
	s->lchild=NULL;
	s->rchild=NULL;
	if(!p)T=s;
	else if(e==p->data)
//当待排序列中有相同的元素时，将其放在相同元素的右孩子位置。
//原来的右子树放在其右节点域。
	{
		q=p->rchild;
		p->rchild=s;
		s->rchild=q;
	}
	else if(e<p->data)
		p->lchild=s;
	else
		p->rchild=s;
}
 
//中序遍历二叉排序树
void InOrderTravese(BiTree T)
{
	BiTree p;
	Sqstack Sqt;
	InitStack(Sqt);
	p=T;
	while(p||Sqt.base!=Sqt.top)
	{
		if(p)
		{
			if(Sqt.top-Sqt.base>=Sqt.stacksize)
			{
				Sqt.base=(BiTree*)realloc(Sqt.base, \
		(Sqt.stacksize+STACK_INCREMENT)*sizeof(BiTNode));
				if(!Sqt.base)
					exit(OVERFLOW);
				Sqt.top=Sqt.base+Sqt.stacksize;
				Sqt.stacksize+=STACK_INCREMENT;
			}
			*Sqt.top++=p;
			p=p->lchild;
		}
		else
		{
			p=*--Sqt.top;
			printf("%d ",p->data);
			p=p->rchild;
		}
	}
	printf("\n");
}
void main()
{
	int length;
	int bst[MAXSIZE];
	BiTree BST;
    BST=(BiTree)malloc(sizeof(BiTNode));
    BST=NULL;
	printf("***************************\n");
	printf("      二叉树排序算法       \n");
	printf("***************************\n");
	printf("请输入待排序序列的个数N (N<%d)：",MAXSIZE);
	scanf("%d",&length);
	printf("\n");
	printf("请输入待排序的数组各元素：\n");
	for(int i=0;i<length;i++)
		scanf("%d",&bst[i]);
	printf("\n");
	for(i=0;i<length;i++)
		CreatBST(BST,bst[i]);
	printf("输出二叉树排序结果：\n");
	InOrderTravese(BST);
	printf("\n");
	free(BST);
	system("pause");
}
/*output:
***************************
      二叉树排序算法
***************************
请输入待排序序列的个数N (N<50)：5

请输入待排序的数组各元素：
44 55 22 33 11

输出二叉树排序结果：
11 22 33 44 55
*/