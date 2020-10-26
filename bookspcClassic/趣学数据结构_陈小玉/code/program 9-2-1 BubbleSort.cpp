#include<iostream>
using namespace std;
#define Maxsize 100

void BubbleSort(int r[],int n) //冒泡排序
{
  	int i,j,temp;
  	bool flag;
  	i=n-1;
  	flag=true;
  	while(i>0&&flag)
    {
        flag=false;
        for(j=0;j<i;j++) //进行一趟排序
            if(r[j]>r[j+1])
            {
                flag=true;
                temp=r[j]; //交换两个记录
                r[j]=r[j+1];
                r[j+1]=temp;
            }
        for(j=0;j<=i;j++)//测试每趟排序结果
            cout<<r[j]<<" ";
        cout<<endl;
        i--;
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
    BubbleSort(r,n);
    cout<<"冒泡排序结果："<<endl;
    for(i=0;i<n;i++)
       cout<<r[i]<<" ";
    return 0;
}
