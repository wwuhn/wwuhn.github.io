#include<iostream>
using namespace std;
#define Maxsize 100

void StraightInsertSort(int r[],int n)  //直接插入排序
{
 	int i,j;
	for(i=2;i<=n;i++)  //r[i]插入有序子表
        if(r[i]<r[i-1]) //r[i]和前一个元素r[i-1]比较
        {
            r[0]=r[i];			//r[i]暂存到r[0]中，r[0]有监视哨的作用
            r[i]=r[i-1];	    //r[i-1]后移一位
            for(j=i-2;r[j]>r[0];j--) //从后向前寻找插入位置,逐个后移，直到找到插入位置
                r[j+1]=r[j];		//r[j]后移一位
            r[j+1]=r[0];		//将r[0]插入到r[j+1]位置
        }
}

int main()
{
    int i,n,r[Maxsize+1];
    cout<<"请输入数列中的元素个数n为："<<endl;
    cin>>n;
    cout<<"请依次输入数列中的元素："<<endl;
    for(i=1;i<=n;i++)
       cin>>r[i];
    StraightInsertSort(r,n);
    cout<<"直接插入排序结果："<<endl;
    for(i=1;i<=n;i++)
       cout<<r[i]<<" ";
    return 0;
}
