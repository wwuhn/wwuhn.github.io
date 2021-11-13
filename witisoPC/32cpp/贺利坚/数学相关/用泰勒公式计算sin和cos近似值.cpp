/* 程序头部注释开始         用泰勒公式计算sin和cos近似值
* 程序的版权和版本声明部分
* Copyright (c) 2011, 烟台大学计算机学院学生
* All rights reserved.
* 文件名称： sin_and_cos.cpp                           
* 作    者： 贺利坚                           
* 完成日期： 2011 年 11 月 22 日
* 版本 号： v2.0        

  * 对任务及求解方法的描述部分
  * 输入描述：无
  * 问题描述：自定义函数，用泰勒公式实现计算sin和cos的近似值，要求：
  （1）求sin、cos时，不能用数学库函数(即不得用#include<Cmath>)，而是自己编函数实现，
  为区别，可以分别起名为mysin和mycos；
  （2）自定义函数要写在main函数之后；
  （3）自定义函数的效率问题必须考虑；
  （4）关于精度：当最后一项的绝对值小于0.00001时，累加结束。
  * 程序输出：sin(π/2)、cos(87°)的值（提示：用泰勒公式在π/2附近误差较大，
  输出分别为0.911557和-0.26322，而真值分别为1和0.052336，当度数较小时，效果要好一些。）
  * 算法设计：使用泰勒公式
  * 程序头部的注释结束（此处也删除了斜杠）
  对于复杂的计算，不妨多设几个变量
  设置变量的原则是，每个变量的功能尽可能单一。
*/
#include <iostream> 
#include<Cmath>  //为便于对比结果，main函数中调用了Cmath中的库函数sin和cos
using namespace std;
const double pi=3.1415926;
double mysin(double);
double mycos(double);
double myabs(double);   //程序中需要求精度的绝对值，也用自定义函数完成吧
int main( )
{
    cout<<"sin(π/2)的值为"<<mysin(pi/2)<<endl;
    cout<<"cos(87°)的值为"<<mycos((87.0/180)*pi)<<endl;
    cout<<"利用库函数求得sin(π/2)的值为"<<sin(pi/2)<<endl;
    cout<<"利用库函数求得cos(87°)的值为"<<cos((87.0/180)*pi)<<endl;
    system("PAUSE");
    return 0;
}
//下面定义mysin函数
double mysin(double x)
{
    double sum=x,x_pow=x,item;
    int n=1,fact=1,sign=1;      //定义变量时赋初值，已经将第一项考虑到累加和sum中
    do
    {
        fact=fact*(n+1)*(n+2);  //fact用于表示阶乘，在公式中作分母
        x_pow*=x*x;             //x_pow是分子中用于表示阶乘，在公式中作分母
        sign=-sign;             //确定即将要累加的这一项的符号
        item =x_pow/fact*sign;  //计算出要累加的项
        sum+=item;              //将该项累加上去
        n+=2;
    }while(myabs(item)>1e-5);
    return sum;
}

//下面定义mycos函数
double mycos(double x)
{
    double sum=1,x_pow=1,item;
    int n=0,fact=1,sign=-1;
    do
    {
        fact=fact*(n+1)*(n+2);
        x_pow*=x*x;
        item =x_pow/fact*sign;
        sum+=item;
        sign=-sign;
        n+=2;
    }while(myabs(item)>0.00001);
    return sum;
}

//下面定义myabs函数
double myabs(double x)
{
    return ((x>=0)?x:-x);
}