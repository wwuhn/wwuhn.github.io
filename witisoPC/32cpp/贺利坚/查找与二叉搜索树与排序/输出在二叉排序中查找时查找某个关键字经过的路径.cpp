// 输出在二叉排序中查找时查找某个关键字经过的路径

#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef int KeyType;                    //定义关键字类型
typedef char InfoType;
typedef struct node                     //记录类型
{
    KeyType key;                        //关键字项
    InfoType data;                      //其他数据域
    struct node *lchild,*rchild;        //左右孩子指针
} BSTNode;
int path[MaxSize];                      //全局变量,用于存放路径
void DispBST(BSTNode *b);               //函数说明
int InsertBST(BSTNode *&p,KeyType k)    //在以*p为根节点的BST中插入一个关键字为k的节点
{
    if (p==NULL)                        //原树为空, 新插入的记录为根节点
    {
        p=(BSTNode *)malloc(sizeof(BSTNode));
        p->key=k;
        p->lchild=p->rchild=NULL;
        return 1;
    }
    else if (k==p->key)
        return 0;
    else if (k<p->key)
        return InsertBST(p->lchild,k);  //插入到*p的左子树中
    else
        return InsertBST(p->rchild,k);  //插入到*p的右子树中
}
BSTNode *CreatBST(KeyType A[],int n)
//由数组A中的关键字建立一棵二叉排序树
{
    BSTNode *bt=NULL;                   //初始时bt为空树
    int i=0;
    while (i<n)
        InsertBST(bt,A[i++]);       //将A[i]插入二叉排序树T中
    return bt;                          //返回建立的二叉排序树的根指针
}

//在二叉排序树中查找，记经过的节点记录在path中，返回值为最后查找节点在path中存储的下标
int SearchBST(BSTNode *bt,KeyType k,KeyType path[],int i)
{
    if (bt==NULL)
        return i;
    else if (k==bt->key)    //找到了节点
    {
        path[i+1]=bt->key;  //输出其路径
        return i+1;
    }
    else
    {
        path[i+1]=bt->key;
        if (k<bt->key)
            SearchBST(bt->lchild,k,path,i+1);  //在左子树中递归查找
        else
            SearchBST(bt->rchild,k,path,i+1);  //在右子树中递归查找
    }
}

//查找并显示经过的路径
void SearchResult(BSTNode *bt, int k1)
{
    int r, j;
    r = SearchBST(bt,k1,path,-1);
    for (j=0; j<=r; j++)
        printf("%3d",path[j]);
    printf("\n");
}

void DispBST(BSTNode *bt)
//以括号表示法输出二叉排序树bt
{
    if (bt!=NULL)
    {
        printf("%d",bt->key);
        if (bt->lchild!=NULL || bt->rchild!=NULL)
        {
            printf("(");
            DispBST(bt->lchild);
            if (bt->rchild!=NULL) printf(",");
            DispBST(bt->rchild);
            printf(")");
        }
    }
}

int main()
{
    BSTNode *bt;
    KeyType k1=65, k2=32;
    int a[]= {43,91,10,18,82,65,33,59,27,73},n=10;
    printf("创建的BST树:");
    bt=CreatBST(a,n);
    DispBST(bt);
    printf("\n");
    printf("  查找%d关键字:",k1);
    SearchResult(bt,k1);
    printf("  查找%d关键字:",k2);
    SearchResult(bt,k2);
    return 0;
}
