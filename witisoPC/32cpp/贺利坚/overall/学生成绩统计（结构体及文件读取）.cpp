#include <iostream>
#include <fstream>  // 学生成绩统计（结构体及文件读取）
#include <cstdlib>  //在codeblocks下，exit(1)需要这个头文件
using namespace std;
struct Student
{
    char num[13];
    char name[10];
    int cpp;
    int math;
    int english;
    int grade;
};
//声明函数
int getData(Student s[]);
void outputData(Student s[],int n);
void sort(Student s[],int n);
void listScholars1(Student s[],int n);
void listScholars2(Student s[],int n);

const int N=200;
int main( )
{
    int stuNum;
    //定义结构体数组
    Student stu[N];
    //（1）从文件中读出数据，存放到结构体数组中；
    //（2）求出每名同学的总分（可以在读入过程中“顺便”计算）；
    stuNum=getData(stu);
    cout<<"数据读取完毕"<<endl;
    bool go=true;
    int ch;
    while(go)
    {
        cout<<"请选择下面的功能："<<endl;
        cout<<"1. 输出成绩单"<<endl;
        cout<<"2. 按总分排序并输出成绩单"<<endl;
        cout<<"3. 输出获得奖学金的同学的名单"<<endl;
        cout<<"4. 输出C++不及格同学姓名和C++成绩"<<endl;
        cout<<"5. 你可以想出的成绩管理系统中的其他功能"<<endl;
        cout<<"0. 结束"<<endl;
        cout<<"请选择(0-5)：";
        cin>>ch;
        switch(ch)
        {
        case 1:
            outputData(stu,stuNum);
            break;
        case 2:
            sort(stu,stuNum);
            outputData(stu,stuNum);
            break;
        case 3:
            listScholars1(stu,stuNum);
            break;
        case 4:
            cout<<"请自行设计函数实现."<<endl;
            cout<<"相信自己能够!"<<endl;
            break;
        case 5:
            cout<<"你可以想出很多这方面的需求，增加、删除数据，各种查询…… "<<endl;
            cout<<"想到就能做到! "<<endl;
            break;
        case 0:
            go=false;
            break;
        }
        cout<<endl;
    }
    cout<<"下次再见！"<<endl;
    return 0;
}

//从文件中读取数据
int getData(Student s[])
{
    ifstream infile("score.txt",ios::in); 	//以输入的方式打开文件
    if(!infile)   				            //测试是否成功打开
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    int i=0;
    while(infile>>s[i].num>>s[i].name>>s[i].cpp>>s[i].math>>s[i].english)
    {
        s[i].grade=s[i].cpp+s[i].math+s[i].english;
        ++i;
    }
    infile.close();
    return i;  //i为学生人数
}

//按总分排序（降序），用了选择排序
void sort(Student s[],int n)
{
    int i,j,k;
    Student t_stu;
    
    for(i=0; i<n-1; i++)
    {
        k=i;
        for(j=i+1; j<n; j++)
            if(s[j].grade>s[k].grade) k=j;
            t_stu=s[k];
            s[k]=s[i];
            s[i]=t_stu;
    }
    return;
}

//输出成绩单；
void outputData(Student s[],int n)
{
    for(int i=0; i<n; ++i)
    {
        cout<<s[i].num<<"\t"<<s[i].name<<"\t"<<s[i].cpp<<"\t"<<s[i].math<<"\t"<<s[i].english<<"\t"<<s[i].grade<<endl;
    }
    cout<<endl;
    return;
}

//输出得奖学金同学的名单
//有30名同学可以获得奖学金，规则是总分高者优先
void listScholars1(Student s[],int n)
{
    sort(s,n);  //在应用中，并不能保证按总分有序，故需要先排序
    cout<<"恭喜以下同学获得奖学金（奖学金用于改善学习条件，杜绝请客吃饭！）"<<endl;
    int i=0,j=1;
    while (j<=30&&j<=n)
    {
        if (s[i].cpp>=60&&s[i].math>=60&&s[i].english>=60)
        {
            cout<<j<<'\t'<<s[i].name<<'\t'<<s[i].grade<<endl;
            j++;
        }
        i++;
    }
}

//另一种奖学金规则
void listScholars2(Student s[],int n)
{
    sort(s,n);  //在应用中，并不能保证按总分有序，故需要先排序
    cout<<"恭喜以下同学获得奖学金（改进版！）"<<endl;
    int i=0,j=1;
    int g;
    while (j<=30&&j<=n)
    {
        if (s[i].cpp>=60&&s[i].math>=60&&s[i].english>=60)
        {
            cout<<j<<'\t'<<s[i].name<<'\t'<<s[i].grade<<endl;
            g=s[i].grade;
            j++;
        }
        i++;
    }
    while(g==s[i].grade)//和刚才输出的最后一个总分相同的同学都有机会获得奖学金
    {
        if (s[i].cpp>=60&&s[i].math>=60&&s[i].english>=60)
        {
            cout<<j<<'\t'<<s[i].name<<'\t'<<s[i].grade<<endl;
            j++;
        }
        i++;
    }
}