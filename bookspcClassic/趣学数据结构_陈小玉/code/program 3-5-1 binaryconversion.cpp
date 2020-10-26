#include<iostream>
typedef int Elemtype;//先类型定义为int 
#include"sqstack.h"//引入自定义头文件,源码目录下名为sqstack.h的文件  
using namespace std;

void binaryconversion(int n)
{
    SqStack S;//定义一个栈S
    int e;
    InitStack(S);//初始化栈
    while(n)
    {
        Push(S,n%2);
        n=n/2;
    }
    while(!Empty(S))//如果栈不空
    {
        Pop(S,e);//出栈
        cout<<e<<"\t";//输出栈顶元素
    }
}

int main()
{
    int n;
    cout<<"请输入一个大于0的十进制整数："<<endl;
    cin>>n;
    binaryconversion(n);
    return 0;
}
