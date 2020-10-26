#include<iostream>
#include<algorithm>
using namespace std;
const int N=100;
int father[N];
int n, m;

void Init(int n)//初始化
{
    for(int i=1;i<=n;i++)
        father[i]=i;
}

int Find(int x)//找祖宗
{
    if(x!=father[x])
        father[x]=Find(father[x]);
    return father[x];
}

int Merge(int a,int b)//合并集合
{
    int p=Find(a);
    int q=Find(b);
    if(p==q) return 0;
    if(p>q)
        father[p]=q;//小的赋值给大的集合号
    else
        father[q]=p;
    return 1;
}

int main()
{
    int sum=0,u,v;
    cout<<"输入人数n和亲戚关系数m:"<<endl;
    cin>>n>>m;
    Init(n);
    cout<<"输入有亲戚关系的两个人编号u,v"<<endl;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        Merge(u,v);
    }
    for(int i=1;i<=n;i++)//测试
        cout<<father[i];
    for(int i=1;i<=n;i++)//输出有多少个家族
        if(father[i]==i)
            sum++;
    cout<<"家族数为："<<sum<<endl;
    return 0;
}
