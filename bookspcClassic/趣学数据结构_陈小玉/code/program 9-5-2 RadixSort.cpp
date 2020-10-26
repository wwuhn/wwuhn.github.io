#include<iostream>
#define Maxsize 10000
using namespace std;

int A[Maxsize];
int Maxbit(int A[],int n)//求待排序序列最大元素位数
{
    int maxvalue=A[0],digits=0;//初始化最大元素为A[0],最大位数为0
    for(int i=1;i<n;i++) //找到序列中最大元素
        if(A[i]>maxvalue)
            maxvalue=A[i];
    while(maxvalue!=0)//分解得到最大元素的位数
    {
        digits++;
        maxvalue/=10;
    }
    return digits;
}

int Bitnumber(int x,int bit)//求x第bit位上的数字，例如238第2位上的数字为3
{
    int temp=1;
    for(int i=1;i<bit;i++)
        temp*=10;
    return (x/temp)%10;
}

void RadixSort(int A[],int n)//基数排序
{
    int i,j,k,bit,maxbit;
    maxbit=Maxbit(A,n);//求最大元素位数
    cout<<maxbit<<endl;
    int **B=new int *[10];
    for(i=0;i<10;i++)
        B[i]=new int[n+1];
    for(i=0;i<10;i++)
        B[i][0]=0;//统计第i个桶的元素个数
    //从个位到高位，对不同的位数进行桶排序
    for(bit=1;bit<=maxbit;bit++)
    {
        for(j=0;j<n;j++)//分配
        {
            int num=Bitnumber(A[j],bit);//取A[j]第bit位上的数字
            int index=++B[num][0];
            B[num][index]=A[j];
        }
        for(i=0,j=0;i<10;i++)//收集
        {
            for(k=1;k<=B[i][0];k++)
                A[j++]=B[i][k];
            B[i][0]=0;//收集后元素个数置零
        }
    }
    for(int i=0;i<10;i++)
         delete []B[i];
    delete B;
}
int main()
{
    int n;
    cout<<"请输入数列中的元素个数n为："<<endl;
    cin>>n;
    cout<<"请依次输入数列中的元素："<<endl;
    for(int i=0;i<n;i++)
       cin>>A[i];
    RadixSort(A,n);
    cout<<"基数排序结果："<<endl;
    for(int i=0;i<n;i++)
       cout<<A[i]<<" ";
    cout<<endl;
    return 0;
}
