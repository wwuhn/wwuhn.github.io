#include<iostream>
using namespace std;
#define Maxsize 100

void ShellInsert(int r[],int n,int dk)  //直接插入排序
{
 	int i,j;
	for(i=dk+1;i<=n;i++)  //r[i]插入有序子表
        if(r[i]<r[i-dk]) //r[i]和前一个元素r[i-dk]比较
		{
		    r[0]=r[i];			//r[i]暂存到r[0]中，r[0]有监视哨的作用
            for(j=i-dk;j>0&&r[j]>r[0];j-=dk) //从后向前寻找插入位置,逐个后移，直到找到插入位置
				r[j+dk]=r[j];		//r[j]后移dk位
            r[j+dk]=r[0];		//将r[0]插入到r[j+dk]位置
		}
}

void ShellSort(int r[],int n,int dt[],int t) //按增量序列dt[0..t-1]对顺序表L作t趟希尔排序
{
  	for(int k=0;k<t;k++)
    {
        ShellInsert(r,n,dt[k]);	//一趟增量为dt[k]的希尔插入排序
        for(int i=1;i<=n;i++)      //测试每趟排序结果
            cout<<r[i]<<" ";
        cout<<endl;
    }
}

int main()
{
    int i,n,t,r[Maxsize+1],dt[Maxsize];
    cout<<"请输入数列中的元素个数n为："<<endl;
    cin>>n;
    cout<<"请依次输入数列中的元素："<<endl;
    for(i=1;i<=n;i++)
       cin>>r[i];
    cout<<"请输入增量个数："<<endl;
	cin>>t;
    cout<<"请依次输入增量："<<endl;
    for(i=0;i<t;i++)
       cin>>dt[i];
    ShellSort(r,n,dt,t);
    cout<<"希尔排序结果："<<endl;
    for(i=1;i<=n;i++)
       cout<<r[i]<<" ";
    return 0;
}
