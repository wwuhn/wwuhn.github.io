#include<iostream>
using namespace std;

#define maxN 1000
int r[maxN];

void Sink(int k,int n)//下沉操作
{
    while(2*k<=n)//如果有左孩子
    {
        int j=2*k;//j指向左孩子
        if(j<n&&r[j]<r[j+1])//如果有右孩子且左孩子比右孩子小
            j++;    //j指向右孩子
        if(r[k]>=r[j])//比较大的孩子大
            break;    //已满足堆
        else
            swap(r[k],r[j]);//与较大的孩子交换
        k=j;//k指向交换后的新位置，继续向下比较，一直下沉到叶子
    }
}

void CreatHeap(int n)//构建初始堆
{
    for(int i=n/2;i>0;i--)//从最后一个分支结点n/2开始调整为堆，直到第一个结点
        Sink(i,n);
}

void HeapSort(int n)//堆排序
{
    CreatHeap(n);//构建初始堆
    while(n>1)
    {
        swap(r[1],r[n--]);//堆顶和最后一个记录交换，交换后n减1
        Sink(1,n);//堆顶下沉
    }
}

void print(int n)//输出
{
    for(int i=1;i<=n;i++)
        cout<<r[i]<<"\t";
    cout<<endl;
}

int main()
{
    int n;
    cout<<"请输入待排序记录个数："<<endl;
    cin>>n;
    cout<<"请输入n个整数："<<endl;
    for(int i=1;i<=n;i++)
        cin>>r[i];
    HeapSort(n);//堆排序
    print(n);
    return 0;
}
