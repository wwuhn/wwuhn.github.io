/* 程序头部注释开始             成绩统计
* 程序的版权和版本声明部分
* Copyright (c) 2011, 烟台大学计算机学院学生
* All rights reserved.
* 文件名称： fun.cpp                            
* 作    者： 贺利坚                           
* 完成日期： 2011 年 11 月 29 日
* 版本号： v1.2       

  * 对任务及求解方法的描述部分
  * 输入描述：学生人数和成绩
  * 问题描述：(函数及数组的简单应用) 在数组score中将要存储某小组C++程序设计的成绩，
  请设计完成下面功能函数，并将它们组合成一个完整的应用：
  （1）输入小组人数及成绩；
  （2）输出该小组的最高成绩、最低成绩、平均成绩和成绩的标准偏差；
  （3）输出考得最高成绩和最低成绩的同学的人数及对应的学号（设成绩对应的下标即学号，
  可能有相同的成绩）
  * 程序输出：小组的最高成绩、最低成绩、平均成绩和成绩的标准偏差；
  最高成绩和最低成绩的同学的人数及对应的学号
  * 程序头部的注释结束
*/
#include <iostream>
#include<Cmath>
using namespace std;
//在这个问题中，成绩和人数是核心数据，适合作为全局变量处理
int score[50];      //将score设为全局变量，在各个函数中可以直接使用
int num;            //小组人数也设为全局变量
void input_score();
int get_max_score();
int get_min_score();
double get_avg_score();
double get_stdev_score();
int count(int);
void output_index(int);

int main(void)
{
    int max_score,min_score;
    cout<<"小组共有多少名同学?";
    cin>>num;
    cout<<endl<<"请输入学生成绩："<<endl;
    input_score();  //要求成绩在0-100之间
    max_score=get_max_score();
    cout<<endl<<"最高成绩为："<<max_score<<"，共有"<<count(max_score )<<" 人。";
    min_score=get_min_score();
    cout<<endl<<"最低成绩为："<<min_score<<"，共有"<<count(min_score )<<" 人。";
    cout<<endl<<"平均成绩为："<<get_avg_score();
    cout<<endl<<"标准偏差为："<<get_stdev_score();
    cout<<endl<<"获最高成绩的学生(学号)有：";
    output_index(max_score);
    cout<<endl<<"获最低成绩的学生(学号)有：";
    output_index(min_score);  
    system("PAUSE");
    return 0;
}

// input_score函数提供给同学们参考
// input_score函数的功能是输入小组成员的成绩
void input_score()
{
    int i;
    for(i=0;i<num;i++)
        do
        {
            cout<<"输入第"<<i<<" 位同学的成绩：";
            cin>>score[i];
        }while(score[i]<0 ||score[i]>100);
        return;
}

// get_max_score()函数的功能是求出num名同学的最高成绩
int get_max_score()
{
    int max = -1;
    int i;
    for(i=0;i<num;i++)
        if(max<score[i]) 
            max= score[i];
        return max;
}

// get_min_score()函数的功能是求出num名同学的最低成绩
int get_min_score()
{
    int min = 999;
    int i;
    for(i=0;i<num;i++)
        if(min>score[i]) 
            min= score[i];
        return min;
}

// get_avg_score()函数的功能是求出num名同学的平均成绩
double get_avg_score()
{
    double sum = 0;
    int i;
    for(i=0;i<num;i++)
        sum+=score[i];
    return sum/num;
}

// get_ stdev _score()函数的功能是求出num名同学成绩的标准偏差
double get_stdev_score()
{
    double sum = 0,mean_score, x;
    int i;
    mean_score =get_avg_score();  //此处通过调用函数求均值，体会函数的意义
    for(i=0;i<num;i++)
        x=score[i]-mean_score;
    sum+=x*x;
    return sqrt(sum/(num-1));
}

// count(int s)函数的功能是返回值score数组中为s的元素的个数
int count(int s)
{
    int iCount=0;
    int i;
    for(i=0;i<num;i++)
        if(score[i]==s)
            iCount++;
        return iCount;
}

// output_index函数的功能是输出score数组中值为s的元素的下标(index)
//注意：值为s的元素可能有多个
void output_index(int s)
{
    int i;
    for(i=0;i<num;i++)
        if(score[i]==s)
            cout<<i<<" ";
        return;
}