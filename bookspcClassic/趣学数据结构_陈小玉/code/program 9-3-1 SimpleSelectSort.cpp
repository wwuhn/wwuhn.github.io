#include<iostream>
using namespace std;
#define Maxsize 100

void SimpleSelectSort(int r[],int n) //简单选择排序
{
  	int i,j,k,temp;
  	for(i=0;i<n-1;i++)//n-1趟排序
    {
        k=i;
        for(j=i+1;j<n;j++)//找最小值
            if(r[j]<r[k])
                k=j;   //记录最小值下标
        if(k!=i)
        {
            temp=r[i];// r[i]与r[k]交换
            r[i]=r[k];
            r[k]=temp;
        }
        for(j=0;j<n;j++)//测试每趟排序结果
            cout<<r[j]<<" ";
        cout<<endl;
    }
}

int main()
{
    int i,n,r[Maxsize];
    cout<<"请输入数列中的元素个数n为："<<endl;
    cin>>n;
    cout<<"请依次输入数列中的元素："<<endl;
    for(i=0;i<n;i++)
       cin>>r[i];
    SimpleSelectSort(r,n);
    cout<<"简单选择排序结果："<<endl;
    for(i=0;i<n;i++)
       cout<<r[i]<<" ";
    return 0;
}
