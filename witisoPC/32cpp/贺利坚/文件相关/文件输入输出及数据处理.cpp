/* 程序头部注释开始
* 程序的版权和版本声明部分       文件输入输出及数据处理
* Copyright (c) 2011, 烟台大学计算机学院学生
* All rights reserved.
* 文件名称：  file.cpp
* 作    者：     贺利坚
* 完成日期：  2011  年   12  月   4 日
* 版 本 号：    v1.0
* 对任务及求解方法的描述部分
* 输入描述：文件salary.txt
* 问题描述：从文件salary.txt中读入500名工人的工资，全部增加100元后进行排序（好事，涨工资了），将排序后的结果在屏幕上输出，并保存到文件ordered_salary.txt中
* 程序输出：ordered_salary.txt
* 程序头部的注释结束
*/
//下面是程序
#include <fstream>
#include<iostream>
using namespace std;
int main( )
{
    float a[500],t;
    int i,j;
    ifstream infile("salary.txt",ios::in);  //以输入的方式打开文件
    if(!infile)       //测试是否成功打开
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    for(i=0;i<500;i++)
        infile>>a[i];   //从文件中读取数据
    infile.close();
    for(i=0;i<10;i++)
        a[i]+=100; //涨工资了
    //排序，用冒泡法，其他法类似
    for(j=0;j<500-2;j++)
        for(i=0;i<500-j-1;i++)
        if (a[i]>a[i+1])
        {
            t=a[i];
            a[i]=a[i+1];
            a[i+1]=t;
        }
    //输出结果
    ofstream outfile("ordered_salary.txt",ios::out);
    if(!outfile)    //测试文件打开操作是否成功，不成功则提示后退出。
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    for(i=0;i<500;i++)
    {
        outfile<<a[i]<<endl;
        if(i%5==0) cout<<endl;
            cout<<a[i]<<"\t";
    }
    outfile.close();     //关闭文件。用完了必须关闭，否则会丢失数据
    return 0;
}
