/* 程序头部注释开始
* 程序的版权和版本声明部分         动态链表统计成绩
* Copyright(c) 2011, 烟台大学计算机学院学生
* All rightsreserved.
* 文件名称：  link.cpp                           
* 作    者：  贺利坚                           
* 完成日期：  2011 年 12 月 19 日
* 版 本 号：  v1.0       

  * 对任务及求解方法的描述部分
  * 输入描述：score.txt
  * 问题描述：在程序中建立一个动态链表：每读入一个同学的数据，计算总分，分配结点的存储空间并赋值，
  并建立起前后相链的关系。在建立链表的同时，要进行统计，以便于求出所有同学总分的平均成绩。
  动态链表建立后，从头结点开始，依次输出所有总分高于平均总分且没有挂科的同学的学号、姓名、总分。
  * 程序输出：所有总分高于平均总分且没有挂科的同学的学号、姓名、总分。
*/
#include  <iostream>
#include  <fstream>
using namespace std;
struct Student
{
    char num[13];   //尽管都是由数字构成，但看作为字符更合适。
    char name[10];  //每个汉字占两个字节，中国人的名字，5个汉字够用
    int cpp;
    int math;
    int english;
    int grade;
    struct Student *next;   //指向下一节点的指针
};
const int N=20;

int main( )
{
    Student *head=NULL,*p,*q;
    int i;
    int sum=0,ave;                          //用于求平均
    ifstream infile("score.txt",ios::in);   //以输入的方式打开文件
    if(!infile)                             //测试是否成功打开
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    //下面从文件中读取数据，同时建立动态链表，并为求总分之和
    for(i=0;i<N;i++)
    {
        p = new Student;
        infile>>p->num>>p->name>>p->cpp>>p->math>>p->english;
        p->grade = p->cpp + p->math +p->english;
        sum+=p->grade;
        p->next=NULL;
        if (i==0)
            head=p;         //是第一个节点
        else
            q->next=p;      //用q记录刚刚产生的结点，如果有下一个，需要q将之连起来
        q=p;
    }
    infile.close();
    
    //求平均成绩
    ave=sum/N;
    cout<<"总分平均为："<<ave<<endl;
    
    //依次输出所有总分高于平均总分且没有挂科的同学的学号、姓名、总分。
    p=head;
    i=1;
    while(p!=NULL)
    {
        if(p->grade>=ave&&p->cpp>=60&&p->math>=60&&p->english>=60)
        {
            cout<<i<<" "<<p->num<<" "<<p->name<<" "<<p->grade<<endl;
            i++;
        }
        p=p->next;
        
    }
    while(1);
    return 0;
}