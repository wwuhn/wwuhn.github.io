// 有序的结构体数组

/*
* 程序的版权和版本声明部分
* Copyright (c)2013, 烟台大学计算机学院学生
* All rights reserved.
* 文件名称：score.cpp                           
* 作    者：                            
* 完成日期：  年  月   日
* 版本号： v1.0      
* 输入描述：已经在程序中初始化
* 问题描述：将学生成绩信息存储在结构体数组中，对结构体排序并输出
* 输出：按C++降序和按学号升序排序后的学生成绩单
*/
#include <iostream>
#include <cstring>
using namespace std;

struct Score
{
    char num[14];
    int cpp;
    int math;
    int english;
};
void sort1(Score [],int);
void sort2(Score [],int);
void output(Score [],int);

int main()
{
    Score score[]={{"201152501104",65,69 ,68 },
    {"201152501114",94 ,89 ,63 },
    {"201152501138",67 ,62 ,84 },
    {"201152501204",100 ,65 ,91 },
    {"201152501202",59 ,80 ,55 },
    {"201152501115",92 ,84 ,60 },
    {"201152501201",80 ,92 ,71 },
    {"201152501145",88 ,56 ,67 },
    {"201152501203",62 ,62 ,95 },
    {"201152501140",80 ,60 ,86 },
    {"201152501205",73 ,90 ,94}};
    int stuNum=sizeof(score)/sizeof(score[0]);
    //将所有同学按C++降序排序后输出
    sort1(score,stuNum);
    cout<<"按C++降序排序后:"<<endl;
    output(score,stuNum);
    //将所有同学按学号升序排序后输出	
    sort2(score,stuNum);
    cout<<"按学号升序排序后:"<<endl;
    output(score,stuNum);
    while(1);
    return 0;
}

void sort1(Score s[],int n)// 依C++的成绩进行比较
{
    int i,j;
    Score t;  
    for(j=0;j<n-2;j++) 
    {
        for(i=0;i<n-j-1;i++)   
            if (s[i].cpp<s[i+1].cpp)    // 依C++的成绩进行比较
            {  
                t=s[i];  //交换的是结构体，结构体可以直接赋值，这一点容易被忽视
                s[i]=s[i+1];  
                s[i+1]=t;  
            }  
    }
    return;  
}

void sort2(Score s[],int n)
{
    int i,j;
    Score t;  
    for(j=0;j<n-2;j++) 
    {
        for(i=0;i<n-j-1;i++)   
            if (strcmp(s[i].num,s[i+1].num)>0)  
            {  
                t=s[i];   
                s[i]=s[i+1];  
                s[i+1]=t;  
            }  
    }
    return;
}

void output(Score s[],int n)
{
    int i;  
    for(i=0;i<n;i++)  
        cout<<s[i].num<<","<<s[i].cpp<<","<<s[i].math<<","<<s[i].english<<endl;  
    return; 
}