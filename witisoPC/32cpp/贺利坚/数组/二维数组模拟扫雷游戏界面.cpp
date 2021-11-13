/* 程序头部注释开始            二维数组模拟扫雷游戏界面
* 程序的版权和版本声明部分
* Copyright (c) 2011, 烟台大学计算机学院学生
* All rights reserved.
* 文件名称：  array.cpp                           
* 作    者：  贺利坚                           
* 完成日期：  2011 年 12 月 22 日
* 版 本号：  v1.0       

  * 对任务及求解方法的描述部分
  * 输入描述：由程序产生随机数作为初始值
  * 问题描述：……
  * 程序输出：……
*/
#include  <iostream>
#include <time.h>
using namespace std;

void setdata(int a[8][8]);          //设置随机数
void out(int a[8][8]);              //输出数组
void outDiagonal(int a[8][8]);      //输出对角线元素的值
void mine(int a[8][8],int x, int y);//按“扫雷”游戏的规则输出相邻格子
void change(int a[8][8]);           //按要求改变数值

int main()
{
    int a[8][8],x,y;
    setdata(a);
    out(a); 
    outDiagonal(a);
    cout<<"输入一个位置，如2 3:";
    cin>>x>>y;
    mine(a,x,y);
    change(a);
    out(a);
    while(1);
    return 0;
}

void setdata(int a[8][8])
{
    int i,j;
    srand(time(NULL));              //需要用当前时间作“种子”，以便每次运行取得的序列不同
    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            a[i][j]=rand()%50+1;    //了解rand()函数，请阅读有关系统函数的文档
        return;
}

void out(int a[8][8])
{
    int i,j;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
            cout<<a[i][j]<<'\t';
        cout<<endl;
    }
    cout<<endl;
    return;
}

void outDiagonal(int a[8][8])
{
    int i;
    //输出从左上到右下对角线上的元素的值
    cout<<"出从左上到右下对角线上的元素的值为："<<endl;
    for(i=0;i<8;i++)
        cout<<a[i][i]<<" ";   //不少同学还在刻意用a[i][j]形式，很麻烦地保持i和j的关系
    cout<<endl;
    //输出从右上到左下对角线上的元素的值
    cout<<"出右上到左下对角线上的元素的值为："<<endl;
    for(i=0;i<8;i++)
        cout<<a[i][7-i]<<'\t';   // a[i][7-i]，不正是斜对角的表示吗？
    cout<<endl;
    cout<<endl;
}

void mine(int a[8][8],int x, int y)
{
    int i,j,sum=0;
    cout<<"a["<<x<<"]["<<y<<"]周围的数是："<<endl;
    for (i = x - 1; i <= x +1; i++)
    {
        for (j = y - 1; j<= y + 1; j++)
        {
            if ( (i>= 0) && (i <= 7) && (j >= 0) && (j <= 7)&& !((i == x ) && (j == y))) //用if中的条件将不可以输出的所有元素“屏蔽”掉，要学会这种简洁的思路，不要一来就一一列举，需要写出很多if语句来完成
            {
                cout<<a[i][j]<<'\t';
                sum+=a[i][j];
            }
        }
    }
    cout<<"这些数的和是:"<<sum<<endl<<endl;
}

void change(int a[8][8])
{
    int i,j;
    for(i=1;i<8;i++)
        for(j=0;j<8;j++)
            a[i][j]=a[i-1][j]+a[i-1][(j+1)%8];  //(j+1)%8将使j=7时，访问到a[i][0]元素
        return;
}