/* 程序头部注释开始
* 程序的版权和版本声明部分   结构体数组选择排序
* Copyright(c) 2011, 烟台大学计算机学院学生
* All rightsreserved.
* 文件名称：  struct.cpp
* 作    者：  贺利坚
* 完成日期：  2011 年 12 月 19 日
* 版 本 号：  v1.0

* 对任务及求解方法的描述部分
* 输入描述：score.txt中是一些同学的学号、姓名、C++、高数、英语成绩，定义一个学生成绩的结构体数组，
其中的成员包括学号（char num[12]）、姓名(name)、三门课的成绩（grade）、总分（score））。
* 问题描述：从文件中读出数据，存放到你定义的结构体数组中；求出每名同学的总分（可以读入过程中“顺便”计算）
；按总分排序（降序）；输出排序后的成绩单；有30名同学可以获得奖学金，规则是总分高者优先，
有挂科不能得奖学金(我校就是这样规定的)。请输出得奖学金同学的名单。
*/

#include  <iostream>
#include  <fstream>

using namespace std;
struct Student
{
    char num[13]; //尽管都是由数字构成，但看作为字符更合适。学号12位，定义为13个字符，便于处理成字符串
    char name[10]; //每个汉字占两个字节，中国人的名字，5个汉字够用
    int cpp;
    int math;
    int english;
    int grade;
};
const int N = 20;
int main( )
{
    int i, j, k;
    //定义结构体数组
    Student stu[N];
    //t_stu将用作为排序时交换用的临时变量
    Student t_stu;
    
    //下面从文件中读取数据到结构体数组，在读入的过程中计算总分
    ifstream infile("score.txt",ios::in);       //以输入的方式打开文件
    if(!infile)                         //测试是否成功打开
    {
        cerr<<"openerror!"<<endl;
        exit(1);
    }
    for(i=0;i<N;i++)
    {
        infile>>stu[i].num>>stu[i].name>>stu[i].cpp>>stu[i].math>>stu[i].english;
        stu[i].grade=stu[i].cpp+stu[i].math+stu[i].english;
    }
    infile.close();
    
    //对结构体数组进行降序排序，这儿我用了选择排序，用冒泡腻了
    for(i=0;i<N-1;i++)
    {
        k=i;
        for(j=i+1;j<N;j++)
            if(stu[j].grade>stu[k].grade)k=j;  //排序的依据是总分，此for循环找出当前总分最高的学生的下标k
        t_stu=stu[k];  //交换，结构体变量可以直接赋值。当然，结构体数组元素的值可以赋值给结构体变量
        stu[k]=stu[i];
        stu[i]=t_stu;
    }
    
    //输出排名后的成绩单
    for(i=0;i<N;i++)
        if(stu[i].grade<=400)
        cout<<stu[i].num<<'\t'<<stu[i].name<<'\t'<<stu[i].cpp<<'\t'<<stu[i].math<<'\t'<<stu[i].english<<'\t'<<stu[i].grade<<endl;
    
    //下面输出得奖学金同学的名单(貌似合理的解法)
    cout<<"恭喜以下同学获得奖学金（奖学金用于改善学习条件，杜绝请客吃饭！）"<<endl;
    i=0,j=1;
    while (j<=3)
    {
        if(stu[i].cpp>=60&&stu[i].math>=60&&stu[i].english>=60)
        {
            cout<<j<<'\t'<<stu[i].name<<'\t'<<stu[i].grade<<endl;
            j++;
        }
        i++;
    }
    while(1);
}
/*
struct Student
{
    char num[13]; //尽管都是由数字构成，但看作为字符更合适。学号12位，定义为13个字符，便于处理成字符串
    char name[10]; //每个汉字占两个字节，中国人的名字，5个汉字够用
    int cpp;
    int math;
    int english;
    int grade;
};

111 wwu0 65 88 99
112 wwu1 75 68 89
131 wwu2 95 68 79
141 wwu3 65 98 69
115 wwu4 77 66 84
116 wwu5 78 76 55

  */