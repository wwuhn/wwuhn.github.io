#include <iostream>		// Huffman Tree and Code
using namespace std;

#define MAXBIT 100
#define MAXVALUE 10000
#define MAXLEAF 30
#define MAXNODE MAXLEAF*2 -1

typedef struct		// 结点结构体
{
	double weight;	// 权值
	int parent;
	int lchild;
	int rchild;
	char value;		// 该节点表示的字符
}HNodeType;

typedef struct		// 编码结构体
{
	int bit[MAXBIT];// 存放结点编码
	int start;		// 编码开始下标
}HCodeType;

HNodeType HuffNode[MAXNODE];	// 定义一个结点结构体数组
HCodeType HuffCode[MAXLEAF];	// 定义一个编码结构体数组
//———————————————————————————————构造哈夫曼树
void HuffmanTree(HNodeType HuffNode[MAXNODE], int n)
{
	int i, j;		// 循环变量
	int x1, x2;		// 构造哈夫曼树不同过程中两个最小权值结点在数组中的序号
	double m1,m2;	// 构造哈夫曼树不同过程中两个最小权值结点的权值
	for(i=0; i<2*n-1; i++)		// 初始化存放哈夫曼树数组 HuffNode[] 中的结点
	{
		HuffNode[i].weight = 0;	//权值
		HuffNode[i].parent =-1;
		HuffNode[i].lchild =-1;
		HuffNode[i].rchild =-1;
	}
	
	for(i=0; i<n; i++)			// 输入 n 个叶子结点的权值
	{
		cout<<"Please input value and weight of leaf node "<<i + 1<<endl;
		cin>>HuffNode[i].value>>HuffNode[i].weight;
	}
	
	for(i=0; i<n-1; i++)		// 构造 Huffman 树，执行n-1次合并
	{
		m1=m2=MAXVALUE;			// m1、m2中存放两个无父结点且结点权值最小的两个结点
		x1=x2=-1;	// 找出所有结点中权值最小、无父结点的两个结点，并合并之为一棵二叉树
		for(j=0; j<n+i; j++)
		{
			if(HuffNode[j].weight < m1 && HuffNode[j].parent==-1)
			{
				m2 = m1;
				x2 = x1;
				m1 = HuffNode[j].weight;
				x1 = j;
			}
			else if(HuffNode[j].weight < m2 && HuffNode[j].parent==-1)
			{
				m2=HuffNode[j].weight;
				x2=j;
			}
		}						// 设置找到的两个子结点 x1、x2 的父结点信息
		
		HuffNode[x1].parent = n+i;
		HuffNode[x2].parent = n+i;
		HuffNode[n+i].weight = m1+m2;
		HuffNode[n+i].lchild = x1;
		HuffNode[n+i].rchild = x2;
		cout<<"x1.weight and x2.weight in round "<<i+1<<"	"; // 用于测试
		cout<<HuffNode[x1]. weight<<"	"<<HuffNode[x2].weight<<endl;
	}
}
//——————————————————————————————哈夫曼树编码
void HuffmanCode(HCodeType HuffCode[MAXLEAF], int n)
{
	HCodeType cd;				// 定义一个临时变量来存放求解编码时的信息
	int i,j,c,p;
	for(i = 0;i < n; i++)		// 从0号结点开始，逐个结点构建，i代表各结点编号
	{
		cd.start = n-1;			// 每个结点的编码数组从数组最后一个元素开始构建
		c = i;
		p = HuffNode[c].parent;	// 找父结点
		while(p != -1)			// p=-1时为根结点
		{
			if(HuffNode[p].lchild == c)	// 左子树为0，右子树为1
				cd.bit[cd.start] = 0;
			else
				cd.bit[cd.start] = 1;
			cd.start--;					// 求编码的低一位
			c = p;						// c,p↓变量上移，准备下一个循环
			p = HuffNode[c].parent;		// 设置下一循环条件
		}
		// 把叶子结点的编码信息从临时编码cd中复制出来，放入编码结构体数组
		for(j=cd.start+1; j<n; j++)
			HuffCode[i].bit[j] = cd.bit[j];
		HuffCode[i].start = cd.start;
	}
}

int main()
{
	int i,j,n;
	cout<<"Please input n："<<endl;
	cin>>n;
	HuffmanTree(HuffNode, n);	// 构造哈夫曼树
	HuffmanCode(HuffCode, n);	// 哈夫曼树编码
	
	for(i = 0;i < n;i++)		// 输出已保存好的所有存在编码的哈夫曼编码
	{
		cout<<HuffNode[i].value<<": Huffman code is: ";
		for(j=HuffCode[i].start+1; j < n; j++)
			cout<<HuffCode[i].bit[j];
		cout<<endl;
	}
	system("pause");
	return 0;
}
/*
输入
6
a 0.05
b 0.32
c 0.18
d 0.07
e 0.25
f 0.13

    t5
   /   \
  t3   t4
 / \   / \
c  e  t2  b
      / \
     t1  f
     / \
    a  d

Please input n：

6

Please input value and weight of leaf node 1

a 0.05

Please input value and weight of leaf node 2

b 0.32

Please input value and weight of leaf node 3

c 0.18

Please input value and weight of leaf node 4

d 0.07

Please input value and weight of leaf node 5

e 0.25

Please input value and weight of leaf node 6

f 0.13

输出
x1.weight and x2.weight in round 1 0.05 0.07
x1.weight and x2.weight in round 2 0.12 0.13
x1.weight and x2.weight in round 3 0.18 0.25
x1.weight and x2.weight in round 4 0.25 0.32
x1.weight and x2.weight in round 5 0.43 0.57
a: Huffman code is: 1000
b: Huffman code is: 11
c: Huffman code is: 00
d: Huffman code is: 1001
e: Huffman code is: 01
f: Huffman code is: 101
a  0.05  1000
b  0.32  11
c  0.18  00
d  0.07  1001
e  0.25  01
f  0.13  101
*/