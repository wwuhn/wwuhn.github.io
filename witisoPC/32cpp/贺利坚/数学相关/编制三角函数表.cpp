/* 程序头部注释开始           编制三角函数表
* 程序的版权和版本声明部分
* Copyright (c) 2011, 烟台大学计算机学院学生
* All rights reserved.
* 文件名称： sintable.cpp                           
* 作    者： 贺利坚                           
* 完成日期： 2011 年 11 月 22 日
* 版本 号： v1.0           

  * 对任务及求解方法的描述部分
  * 输入描述：无
  * 问题描述：编制一个三角函数表，
  要求在main()函数中调用show_sin_table(min_angle, max_angle)，
  显示角度值为min_angle到max_angle之间的所有角度（间隔为1度）的正弦值。
  要求不能用数学库函数，将任务2中的mysin函数拷贝到这个程序中，用于计算sin值。
  例如show_sin_table(0, 90)可以显示出所有0到90度的正弦值。
  为取得更好的效果，可以考虑像英尺到米的转换一样，以速查表格的形式给出结果。
  * 程序输出：三角函数表
  * 程序头部的注释结束（此处也删除了斜杠）
*/
#include <iostream>
#include <iomanip>
using namespace std;
double mysin(double);
double myabs(double);
void show_sin_table(int, int);
const double pi=3.1415926;
int main( )
{
    show_sin_table(0, 90);
    system("PAUSE");
    return 0;
}
//下面定义show_sin_table()函数
void show_sin_table(int iFromAngle, int iToAngle)
{
    int x;
    cout<<setiosflags(ios::fixed)<<setiosflags(ios::right)<<setprecision(3);
    for(x=0; x<3;x++)
        cout<<setw(8)<<" 角度x"<<setw(8)<< "  sin(x)";
    cout<<"\n";   
    for(x=iFromAngle;x<=iToAngle; x++)
    {
        cout<<setw(8)<<x<<setw(8)<<mysin(x*pi/180); 
        if (x%3==0)cout<<"\n";          
    }   
}
//下面定义mysin函数
double mysin(double x)
{
    double sum=x,x_pow=x,item;
    int n=1,fact=1,sign=1;     //定义变量时赋初值，已经将第一项考虑到累加和sum中
    do
    {
        fact=fact*(n+1)*(n+2);  //fact用于表示阶乘，在公式中作分母
        x_pow*=x*x;             //x_pow是分子中用于表示阶乘，在公式中作分母
        sign=-sign;             //确定即将要累加的这一项的符号
        item =x_pow/fact*sign; //计算出要累加的项
        sum+=item;              //将该项累加上去
        n+=2;
    }while(myabs(item)>1e-5);
    return sum;
}
//下面定义myabs函数
double myabs(double x)
{
    return ((x>=0)?x:-x);
}