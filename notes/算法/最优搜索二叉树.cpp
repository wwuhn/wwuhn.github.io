/*
int arr[6]={5,9,12,15,20,24}
考虑搜索一个有序序列，折半查找可获得logn的效率；
如果这个有序序列还要考虑查找每个结点出现的频率，如下：
每个关键字的搜索概率:   0.04 0.09 0.08 0.02 0.12 0.14
每个虚结点的搜索概率:0.06 0.08 0.10 0.07 0.05 0.05 0.10 
//如要查找18，定位在15－20之间，每个这样的位置定义为一个虚结点，要对应一个搜索概率
以下数字为概率*100
深度
0          12
        /       \
1     9        14
     /    \     / \
2   4      8   5  10
   / \    / \
3 6   8  10  2
         / \ 
4       7   5

每个关键字节点的搜索成本概率*(深度-1)
每个虚    节点的搜索成本概率*深度
可能很多人会想到，搜索概率大的离根越近，那么总成本越低，这其实是哈夫曼思想。
但是二叉搜索树需要满足左子树<根，右子树>根的性质；
1 具有最优子解结构和重叠性质，可以应用动态规划算法来求解；
2 
*/
#include<iostream>
#include<cmath>   //求绝对值函数需要引入该头文件
using namespace std;

const int M=1000+5;
double p[M],q[M];	// 实结点、虚结点的搜索概率
double c[M][M];		// T(i,j)的搜索成本
double w[M][M];		// T(i,j)的搜索成本和

int s[M][M];		// T(i,j)的根节点序号
int n,i,j,k;
void Optimal_BST()
{
	for(i=1;i<=n+1;i++)
	{
		c[i][i-1]=0.0;
		w[i][i-1]=q[i-1];
	}
	for(int t=1;t<=n;t++)//t为关键字的规模
		//从下标为i开始的关键字到下标为j的关键字
		for(i=1;i<=n-t+1;i++)
		{
			j=i+t-1;
			w[i][j]=w[i][j-1]+p[j]+q[j];
			int i1=s[i][j-1]>i?s[i][j-1]:i;
            int j1=s[i+1][j]<j?s[i+1][j]:j;
			c[i][j]=c[i][i1-1]+c[i1+1][j];//初始化
			s[i][j]=i1;//初始化
			//选取i1+1到j1之间的某个下标的关键字作为从i到j的根，如果组成的树的期望值当前最小，则k为从i到j的根节点
			for(k=i1+1;k<=j1;k++)
			{
				double temp=c[i][k-1]+c[k+1][j];
                if(temp<c[i][j]&&fabs(temp-c[i][j])>1E-6)//C++中浮点数因为精度问题不可以直接比较
				{
					c[i][j]=temp;
					s[i][j]=k;//k即为从下标i到j的根节点
				}
			}
			c[i][j]+=w[i][j];
		}
}
void Construct_Optimal_BST(int i,int j,bool flag)
{
	if(flag==0)
	{
		cout<<"S"<<s[i][j]<<" 是根"<<endl;
		flag=1;
	}
	int k=s[i][j];
	//如果左子树是叶子
	if(k-1<i)
	{
		cout<<"e"<<k-1<<" is the left child of "<<"S"<<k<<endl;
	}
	//如果左子树不是叶子
	else
	{
		cout<<"S"<<s[i][k-1]<<" is the left child of "<<"S"<<k<<endl;
		Construct_Optimal_BST(i,k-1,1);
	}
	//如果右子树是叶子
	if(k>=j)
	{
		cout<<"e"<<j<<" is the right child of "<<"S"<<k<<endl;
	}
	//如果右子树不是叶子
	else
	{
		cout<<"S"<<s[k+1][j]<<" is the right child of "<<"S"<<k<<endl;
		Construct_Optimal_BST(k+1,j,1);
	}
}
int main()
{
	cout << "请输入关键字的个数 n:";
    cin >> n;
    cout<<"请依次输入每个关键字的搜索概率:";
    for (i=1; i<=n; i++ )
        cin>>p[i];
    cout << "请依次输入每个虚结点的搜索概率:";
    for (i=0; i<=n; i++)
        cin>>q[i];
	Optimal_BST();
	// /*用于测试
	for(i=1; i<=n+1;i++)
    {
          for (j=1; j<i;j++)
            cout <<"\t" ;
          for(j=i-1;j<=n;j++)
            cout << w[i][j]<<"\t" ;
          cout << endl;
    }
     for(i=1; i<=n+1;i++)
    {
          for (j=1; j<i;j++)
            cout <<"\t" ;
          for(j=i-1; j<=n;j++)
            cout << c[i][j]<<"\t" ;
          cout << endl;
    }
    for(i=1; i<=n;i++)
    {
          for (j=1; j<i;j++)
            cout << "\t" ;
          for(j=i-1; j<=n;j++)
            cout << s[i][j]<<"\t" ;
          cout << endl;
    }
    cout << endl;
    // */用于测试
	cout<<"最小的搜索成本为:"<<c[1][n]<<endl;
    cout<<"最优二叉搜索树为:";
	Construct_Optimal_BST(1,n,0);
	system("pause");
	return 0;
}
/*
6
0.04 0.09 0.08 0.02 0.12 0.14
0.06 0.08 0.10 0.07 0.05 0.05 0.10


请输入关键字的个数 n:6
请依次输入每个关键字的搜索概率:0.04 0.09 0.08 0.02 0.12 0.14
请依次输入每个虚结点的搜索概率:0.06 0.08 0.10 0.07 0.05 0.05 0.10
0.06    0.18    0.37    0.52    0.59    0.76    1
        0.08    0.27    0.42    0.49    0.66    0.9
                0.1     0.25    0.32    0.49    0.73
                        0.07    0.14    0.31    0.55
                                0.05    0.22    0.46
                                        0.05    0.29
                                                0.1
0       0.18    0.55    0.95    1.23    1.76    2.52
        0       0.27    0.67    0.9     1.38    2.09
                0       0.25    0.46    0.94    1.48
                        0       0.14    0.45    0.98
                                0       0.22    0.68
                                        0       0.29
                                                0
0       1       2       2       2       3       5
        0       2       2       3       3       5
                0       3       3       3       5
                        0       4       5       5
                                0       5       6
                                        0       6

最小的搜索成本为:2.52
最优二叉搜索树为:S5 是根
S2 is the left child of S5
S1 is the left child of S2
e0 is the left child of S1
e1 is the right child of S1
S3 is the right child of S2
e2 is the left child of S3
S4 is the right child of S3
e3 is the left child of S4
e4 is the right child of S4
S6 is the right child of S5
e5 is the left child of S6
e6 is the right child of S6
请按任意键继续. . .
*/