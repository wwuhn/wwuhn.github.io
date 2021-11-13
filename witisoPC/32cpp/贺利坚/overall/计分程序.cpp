/* 程序头部注释开始（为避免提交博文中遇到的问题，将用于表明注释的斜杠删除了）
* 程序的版权和版本声明部分
* Copyright (c) 2011, 烟台大学计算机学院
* All rights reserved.
* 文件名称： score.cpp
* 作    者： 贺利坚
* 完成日期：  2011 年 11 月 15 日
* 版 本 号：  V1.0

  * 对任务及求解方法的描述部分
  * 输入描述：选手的原始成绩
  * 问题描述：各评委打出的成绩介于0-10之间，计分规则为去掉一个最高分和一个最低分后取平均。其他要求：输出错误要能马上重新输入；评委人数在程序中的修改要尽可能方便；计算完一位选手的成绩后可以连续地计算下一位选手的成绩。
  * 程序输出：各位选手的最高分、最低分及最终成绩
  * 问题分析：用两层的do循环完成，第一层完成每位选手的计分，第二层输入所有评委给出的评分，输入不对时用continue从头开始
  * 算法设计：……
  * 程序头部的注释结束（此处也删除了斜杠）
*/
#include <iostream>
#include <iomanip>
using namespace std;
int main( )
{
    const int n=10;   //学会用常变量
    int i;
    double ave, score, sum, max, min;  //这几个变量涉及成绩，double是合理的
    char choice;  //用于接受用户选择，字符型多合适
    cout<<setiosflags(ios::fixed)<<setprecision(3); //输出格式，只设一次就管用
    do     //计算选手的成绩，至少1次，用do很自然，别的循环不用想
    {
        i=1;    //i代表评委的编号，其实这个变量名起得不好
        max=-1;  //这儿有技巧，第1位评委给的成绩一定大于-1，max将变成第1个成绩
        min=11;  //同样和技巧，要学会这样“设圈套”
        sum=0;   //注意：这4个变量在循环内赋初值是必须的，这意味着计算某一选手成绩的开始
        cout<<"请输入选手的成绩（0-10）"<<endl;
        do  //至少有一位评委，再用do循环
        {
            cout<<"第"<<i<<"位评委给分：";
            cin>>score;
            if(score<0||score>10) continue;  //输入不对就继续输，continue多合适
            sum+=score;
            if(max<score) max=score;  // 联想上一层循环中max的初值，学会技巧
            if(min>score) min=score;   //有不少同学用函数解决，复杂化了
            i++;
        }while(i<=n);
        ave = (sum-max-min)/(n-2);
        cout<<"减去一个最高分:"<<max;
        cout<<", 减去一个最低分:"<<min<<"。"<<endl;
        cout<<"当前选手的最后得分是："<<ave<<endl;
        cout<<"******************* SUCCESS ***********************"<<endl;
        cout<<"按 N 退出，其他键继续....";
        cin>>choice; //用choice=getchar();也行
        cout<<endl;
    }while(choice!='N' && choice!='n'); //不管输入大小写，全算数
    return 0;
}