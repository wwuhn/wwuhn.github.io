/* 程序头部注释开始          单纯次数迭代的递归
* 程序的版权和版本声明部分
* Copyright (c) 2011, 烟台大学计算机学院
* All rights reserved.
* 文件名称： fun.cpp                           
* 作    者： 贺利坚                           
* 完成日期： 2011 年 11 月 29 日
* 版本号： v1.0       
* 对任务及求解方法的描述部分
* 输入描述：n的值
* 问题描述：求f(n)=1^3+2^3+…+n^3（在此^表示幂运算，1^3即1的3次方）
* 程序输出：f(n)的值
* 问题分析：首先，可以将f(n)表示为以下的递归式
f(1)=1
f(n)=f(n-1)+n*n*n
* 程序头部的注释结束
*/
#include <iostream> 
using namespace std;
int f(int);
int main( )
{
    int n,m;
    cout<<”请输入n的值：”;
    cin>>n;
    m=f(n);
    cout<<”f(”<<n<<”)的值为: ”<<m;
    return 0;
}
//下面是递归函数f(n)的定义
int f(int n)
{
    int fact;
    if(n==1)
        fact=1;
    else
    {
        fact=f(n-1)+n*n*n;
    }
    return  fact;
}